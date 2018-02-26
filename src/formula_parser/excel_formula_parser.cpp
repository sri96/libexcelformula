#include "excel_formula_parser.h"
#include "../shared/i_excel_formula_token.h"
#include <future>

using namespace ExcelFormula;
using namespace ExcelFormula::Parser;

std::pair<ParserError, ExcelFormulaParseTree> ExcelFormulaParser::BuildParseTreeFromTokens(const std::vector<std::unique_ptr<ExcelFormula::IExcelFormulaToken>>& inputLexedTokens) const noexcept
{
    // There are three kinds of formula compositions in Excel

    // 1. Formulas that start with a equivalent sign Eg: =SUM(5,6)
    // 2. Formulas that don't have an equivant sign SUM(5,6)
    // 3. An array formula {=SUM(5,6)}

    std::vector<TokenInformationForParseTree> _tokenInformationToBuildParseTree{};
    for (size_t index = 0; index < inputLexedTokens.size(); index++)
    {
        TokenInformationForParseTree tokenInformation{inputLexedTokens.at(index)->GetTokenType(), inputLexedTokens.at(index)->GetTokenData()};
        _tokenInformationToBuildParseTree.push_back(tokenInformation);
    }
    
    // As soon as we get the tokens, we are going to send three threads to go and find out if the input
    // tokens can be parsed into a compliant parse tree
    std::future<std::experimental::optional<ExcelFormulaParseTree>> potentialFormulaParseTreeFuture = std::async(TryConvertingTokensToFormulaParseTree, _tokenInformationToBuildParseTree);
    std::future<std::experimental::optional<ExcelFormulaParseTree>> potentialFormulaEqParseTreeFuture = std::async(TryConvertingTokensToFormulaWithEquivalentSignParseTree, _tokenInformationToBuildParseTree);
    std::future<std::experimental::optional<ExcelFormulaParseTree>> potentialArrayFormulaParseTreeFuture = std::async(TryConvertingTokensToArrayFormulaParseTree, _tokenInformationToBuildParseTree);
    std::experimental::optional<ExcelFormulaParseTree> potentialFormulaParseTree = potentialFormulaParseTreeFuture.get();
    std::experimental::optional<ExcelFormulaParseTree> potentialFormulaEqParseTree = potentialFormulaEqParseTreeFuture.get();
    std::experimental::optional<ExcelFormulaParseTree> potentialArrayFormulaParseTree = potentialArrayFormulaParseTreeFuture.get();
    
    ParserError outputError = ParserError::Error;
    ExcelFormulaParseTree outputTree{};
    return std::make_pair(outputError, outputTree);
}

std::unique_ptr<IExcelFormulaParser> ExcelFormula::Parser::CreateExcelFormulaParserInstance()
{
    return std::make_unique<ExcelFormulaParser>();
}

std::experimental::optional<ExcelFormulaParseTree> ExcelFormula::Parser::TryConvertingTokensToFormulaParseTree(const std::vector<TokenInformationForParseTree>& /*inputLexedTokens*/)
{
    return {};
}
std::experimental::optional<ExcelFormulaParseTree> ExcelFormula::Parser::TryConvertingTokensToFormulaWithEquivalentSignParseTree(const std::vector<TokenInformationForParseTree>& /*inputLexedTokens*/)
{
    return {};
}
std::experimental::optional<ExcelFormulaParseTree> ExcelFormula::Parser::TryConvertingTokensToArrayFormulaParseTree(const std::vector<TokenInformationForParseTree>& /*inputLexedTokens*/)
{
    return {};
}