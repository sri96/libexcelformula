#include "excel_formula_parser.h"
#include "../shared/i_excel_formula_token.h"
#include "../shared/token_types.h"
#include <future>

using namespace ExcelFormula;
using namespace ExcelFormula::Parser;

std::pair<ParserError, ExcelFormulaParseTree> ExcelFormulaParser::BuildParseTreeFromTokens(const std::vector<std::unique_ptr<ExcelFormula::IExcelFormulaToken>>& inputLexedTokens) const noexcept
{
    ParserError outputError = ParserError::Error;
    ExcelFormulaParseTree outputTree{};

    if (inputLexedTokens.empty())
    {
        return std::make_pair(outputError, outputTree);
    }

    std::vector<TokenInformationForParseTree> _tokenInformationToBuildParseTree{};
    for (size_t index = 0; index < inputLexedTokens.size(); index++)
    {
        TokenInformationForParseTree tokenInformation{inputLexedTokens.at(index)->GetTokenType(), inputLexedTokens.at(index)->GetTokenDataString()};
        _tokenInformationToBuildParseTree.push_back(tokenInformation);
    }
    
    // There are three kinds of formula compositions in Excel

    // 1. Formulas that start with a equivalent sign Eg: =SUM(5,6)
    // 2. Formulas that don't have an equivant sign SUM(5,6)
    // 3. An array formula {=SUM(5,6)}

    // As soon as we get the tokens, we are going to send three threads to go and find out if the input
    // tokens can be parsed into a compliant parse tree
    std::future<std::experimental::optional<ExcelFormulaParseTree>> potentialFormulaParseTreeFuture = std::async(TryConvertingTokensToFormulaParseTree, _tokenInformationToBuildParseTree);
    std::future<std::experimental::optional<ExcelFormulaParseTree>> potentialFormulaEqParseTreeFuture = std::async(TryConvertingTokensToFormulaWithEquivalentSignParseTree, _tokenInformationToBuildParseTree);
    std::future<std::experimental::optional<ExcelFormulaParseTree>> potentialArrayFormulaParseTreeFuture = std::async(TryConvertingTokensToArrayFormulaParseTree, _tokenInformationToBuildParseTree);
    std::experimental::optional<ExcelFormulaParseTree> potentialFormulaParseTree = potentialFormulaParseTreeFuture.get();
    std::experimental::optional<ExcelFormulaParseTree> potentialFormulaEqParseTree = potentialFormulaEqParseTreeFuture.get();
    std::experimental::optional<ExcelFormulaParseTree> potentialArrayFormulaParseTree = potentialArrayFormulaParseTreeFuture.get();

    // Unable to get a parse tree from any of the three threads. This definitely means a parse error
    if(!potentialFormulaParseTree && !potentialFormulaEqParseTree && !potentialArrayFormulaParseTree)
    {
        return std::make_pair(outputError, outputTree);
    }
    
    if (potentialFormulaParseTree)
    {
        return std::make_pair(ParserError::None, *potentialFormulaParseTree);
    }

    if (potentialFormulaEqParseTree)
    {
        return std::make_pair(ParserError::None, *potentialFormulaEqParseTree);
    }

    if (potentialArrayFormulaParseTree)
    {
        return std::make_pair(ParserError::None, *potentialArrayFormulaParseTree);
    }

    return std::make_pair(outputError, outputTree);
}

std::unique_ptr<IExcelFormulaParser> ExcelFormula::Parser::CreateExcelFormulaParserInstance()
{
    return std::make_unique<ExcelFormulaParser>();
}

std::experimental::optional<ExcelFormulaParseTree> ExcelFormula::Parser::TryConvertingTokensToFormulaParseTree(const std::vector<TokenInformationForParseTree>& inputLexedTokens)
{
    // For now, we have a simple grammar. We can use handwritten logic. As the grammar gets complicated, we will need to deal with things like recursion.
    // First check if there are enough tokens to use
    if (inputLexedTokens.empty())
    {
        return {};
    }

    // We only support function calls currently. Function calls require at least two tokens. One for the function call and the other for the closing paren. Let's check that. 
    if (inputLexedTokens.size() < 2 || inputLexedTokens.at(0)._tokenType != TokenType::ExcelFunctionToken || inputLexedTokens.back()._tokenType != TokenType::CloseParenToken)
    {
        return {};
    }

    ExcelFormulaParseTree outputParseTree{};
    outputParseTree.GetRootNode().AddNodeTag(L"Formula");
    
    ExcelFormulaParseTreeNode functionCallNode{};
    functionCallNode.AddNodeTag(L"FunctionCall");
    
    ExcelFormulaParseTreeNode functionNameNode{};
    functionNameNode.AddNodeTag(L"FunctionName");
    
    ExcelFormulaParseTreeNode excelFunctionNameNode{};
    excelFunctionNameNode.AddNodeTag(L"ExcelFunction");
    excelFunctionNameNode.AddTokenInformation(inputLexedTokens.at(0));
    
    ExcelFormulaParseTreeNode argumentsNode{};
    argumentsNode.AddNodeTag(L"Arguments");
    
    size_t argumentIndex = 1;
    for (argumentIndex = 1; argumentIndex < inputLexedTokens.size()-1; argumentIndex++)
    {
        const TokenInformationForParseTree tokenInfo = inputLexedTokens.at(argumentIndex);
        if (tokenInfo._tokenType != TokenType::IntegerToken &&  tokenInfo._tokenType != TokenType::CellToken && tokenInfo._tokenType != TokenType::CommaToken)
        {
            return {};
        }

        if (tokenInfo._tokenType != TokenType::CommaToken)
        {
            ExcelFormulaParseTreeNode argumentNode{};
            argumentNode.AddNodeTag(L"Argument");
            
            // Arguments to function calls can be formulas. But, this hasn't been implemented yet
            ExcelFormulaParseTreeNode formulaNode{};
            formulaNode.AddNodeTag(L"Formula");
            
            if (tokenInfo._tokenType == TokenType::IntegerToken)
            {
                ExcelFormulaParseTreeNode constantNode{};
                constantNode.AddNodeTag(L"Constant");
                
                // For constants, only integer constants are currently supported
                ExcelFormulaParseTreeNode numberNode{};
                numberNode.AddNodeTag(L"Number");
                
                // Add the Integer token
                ExcelFormulaParseTreeNode numberTokenNode{};
                numberTokenNode.AddNodeTag(L"NumberToken");
                numberTokenNode.AddTokenInformation(tokenInfo);
                
                numberNode.AddChildNode(numberTokenNode);
                constantNode.AddChildNode(numberNode);
                formulaNode.AddChildNode(constantNode);
            }
            else
            {
                ExcelFormulaParseTreeNode referenceNode{};
                referenceNode.AddNodeTag(L"Reference");
                
                // For reference types, only cell references are currently supported
                ExcelFormulaParseTreeNode cellNode{};
                cellNode.AddNodeTag(L"Cell");
                
                // Add the Cell Token
                ExcelFormulaParseTreeNode cellTokenNode{};
                cellTokenNode.AddNodeTag(L"CellToken");
                cellTokenNode.AddTokenInformation(tokenInfo);
                
                cellNode.AddChildNode(cellTokenNode);
                referenceNode.AddChildNode(cellNode);
                formulaNode.AddChildNode(referenceNode);
            }

            argumentNode.AddChildNode(formulaNode);
            argumentsNode.AddChildNode(argumentNode);
        }
    }

    functionCallNode.AddChildNode(argumentsNode);
    functionNameNode.AddChildNode(excelFunctionNameNode);
    functionCallNode.AddChildNode(functionNameNode);
    outputParseTree.GetRootNode().AddChildNode(functionCallNode);

    return outputParseTree;
}
std::experimental::optional<ExcelFormulaParseTree> ExcelFormula::Parser::TryConvertingTokensToFormulaWithEquivalentSignParseTree(const std::vector<TokenInformationForParseTree>& inputLexedTokens)
{
    // For now, we have a simple grammar. We can use handwritten logic. As the grammar gets complicated, we will need to deal with things like recursion.
    // First check if there are enough tokens to use. We need at least two tokens minimum.
    if (inputLexedTokens.empty() && inputLexedTokens.size() < 3)
    {
        return {};
    }

    // For Formulas with equivalent sign, the very first token needs to be an equivalent sign. Second needs to be an equivalent sign. The last token needs to be }.
    if (inputLexedTokens.at(0)._tokenType != TokenType::EqualOperationToken)
    {
        return {};
    }

    // We only support function calls currently. Function calls require at least two tokens. One for the function call and the other for the closing paren. Let's check that. 
    if (inputLexedTokens.at(1)._tokenType != TokenType::ExcelFunctionToken || inputLexedTokens.back()._tokenType != TokenType::CloseParenToken)
    {
        return {};
    }

    ExcelFormulaParseTree outputParseTree{};
    outputParseTree.GetRootNode().AddNodeTag(L"FormulaWithEq");

    ExcelFormulaParseTreeNode equivalentOpNode{};
    equivalentOpNode.AddNodeTag(L"=");
    
    ExcelFormulaParseTreeNode fNode{};
    fNode.AddNodeTag(L"Formula");
    
    ExcelFormulaParseTreeNode functionCallNode{};
    functionCallNode.AddNodeTag(L"FunctionCall");
    
    ExcelFormulaParseTreeNode functionNameNode{};
    functionNameNode.AddNodeTag(L"FunctionName");
    
    ExcelFormulaParseTreeNode excelFunctionNameNode{};
    excelFunctionNameNode.AddNodeTag(L"ExcelFunction");
    excelFunctionNameNode.AddTokenInformation(inputLexedTokens.at(0));
    
    ExcelFormulaParseTreeNode argumentsNode{};
    argumentsNode.AddNodeTag(L"Arguments");
    
    size_t argumentIndex = 2;
    for (argumentIndex = 2; argumentIndex < inputLexedTokens.size()-1; argumentIndex++)
    {
        const TokenInformationForParseTree tokenInfo = inputLexedTokens.at(argumentIndex);
        if (tokenInfo._tokenType != TokenType::IntegerToken &&  tokenInfo._tokenType != TokenType::CellToken && tokenInfo._tokenType != TokenType::CommaToken)
        {
            return {};
        }

        if (tokenInfo._tokenType != TokenType::CommaToken)
        {
            ExcelFormulaParseTreeNode argumentNode{};
            argumentNode.AddNodeTag(L"Argument");
            
            // Arguments to function calls can be formulas. But, this hasn't been implemented yet
            ExcelFormulaParseTreeNode formulaNode{};
            formulaNode.AddNodeTag(L"Formula");
            
            if (tokenInfo._tokenType == TokenType::IntegerToken)
            {
                ExcelFormulaParseTreeNode constantNode{};
                constantNode.AddNodeTag(L"Constant");
                
                // For constants, only integer constants are currently supported
                ExcelFormulaParseTreeNode numberNode{};
                numberNode.AddNodeTag(L"Number");
                
                // Add the Integer token
                ExcelFormulaParseTreeNode numberTokenNode{};
                numberTokenNode.AddNodeTag(L"NumberToken");
                numberTokenNode.AddTokenInformation(tokenInfo);
                
                numberNode.AddChildNode(numberTokenNode);
                constantNode.AddChildNode(numberNode);
                formulaNode.AddChildNode(constantNode);
            }
            else
            {
                ExcelFormulaParseTreeNode referenceNode{};
                referenceNode.AddNodeTag(L"Reference");
                
                // For reference types, only cell references are currently supported
                ExcelFormulaParseTreeNode cellNode{};
                cellNode.AddNodeTag(L"Cell");
                
                // Add the Cell Token
                ExcelFormulaParseTreeNode cellTokenNode{};
                cellTokenNode.AddNodeTag(L"CellToken");
                cellTokenNode.AddTokenInformation(tokenInfo);
                
                cellNode.AddChildNode(cellTokenNode);
                referenceNode.AddChildNode(cellNode);
                formulaNode.AddChildNode(referenceNode);
            }

            argumentNode.AddChildNode(formulaNode);
            argumentsNode.AddChildNode(argumentNode);
        }
    }

    functionNameNode.AddChildNode(excelFunctionNameNode);
    functionCallNode.AddChildNode(functionNameNode);
    functionCallNode.AddChildNode(argumentsNode);
    fNode.AddChildNode(functionCallNode);
    outputParseTree.GetRootNode().AddChildNode(equivalentOpNode);
    outputParseTree.GetRootNode().AddChildNode(fNode);

    return outputParseTree;
}
std::experimental::optional<ExcelFormulaParseTree> ExcelFormula::Parser::TryConvertingTokensToArrayFormulaParseTree(const std::vector<TokenInformationForParseTree>& inputLexedTokens)
{
    // For now, we have a simple grammar. We can use handwritten logic. As the grammar gets complicated, we will need to deal with things like recursion.
    
    // First check if there are enough tokens to use. We need at least four tokens for array formula
    if (inputLexedTokens.empty() && inputLexedTokens.size() < 4)
    {
        return {};
    }

    // For array formula, the first token needs to be a OpenCurlyParenToken. If not, then it can't be a Array Formula
    if (inputLexedTokens.at(0)._tokenType != TokenType::OpenCurlyParenToken || inputLexedTokens.at(1)._tokenType != TokenType::EqualOperationToken || inputLexedTokens.back()._tokenType != TokenType::CloseCurlyParenToken)
    {
        return {};
    }

    // We only support function calls currently. Function calls require at least two tokens. One for the function call and the other for the closing paren. Let's check that. 
    if (inputLexedTokens.at(2)._tokenType != TokenType::ExcelFunctionToken || inputLexedTokens.at(inputLexedTokens.size()-2)._tokenType != TokenType::CloseParenToken)
    {
        return {};
    }

    ExcelFormulaParseTree outputParseTree{};
    outputParseTree.GetRootNode().AddNodeTag(L"ArrayFormula");

    ExcelFormulaParseTreeNode equivalentOpNode{};
    equivalentOpNode.AddNodeTag(L"=");
    
    ExcelFormulaParseTreeNode fNode{};
    fNode.AddNodeTag(L"Formula");
    
    ExcelFormulaParseTreeNode functionCallNode{};
    functionCallNode.AddNodeTag(L"FunctionCall");
    
    ExcelFormulaParseTreeNode functionNameNode{};
    functionNameNode.AddNodeTag(L"FunctionName");
    
    ExcelFormulaParseTreeNode excelFunctionNameNode{};
    excelFunctionNameNode.AddNodeTag(L"ExcelFunction");
    excelFunctionNameNode.AddTokenInformation(inputLexedTokens.at(0));
    
    ExcelFormulaParseTreeNode argumentsNode{};
    argumentsNode.AddNodeTag(L"Arguments");
    
    size_t argumentIndex = 3;
    for (argumentIndex = 3; argumentIndex < inputLexedTokens.size()-1; argumentIndex++)
    {
        const TokenInformationForParseTree tokenInfo = inputLexedTokens.at(argumentIndex);
        if (tokenInfo._tokenType != TokenType::IntegerToken &&  tokenInfo._tokenType != TokenType::CellToken && tokenInfo._tokenType != TokenType::CommaToken)
        {
            return {};
        }

        if (tokenInfo._tokenType != TokenType::CommaToken)
        {
            ExcelFormulaParseTreeNode argumentNode{};
            argumentNode.AddNodeTag(L"Argument");
            
            // Arguments to function calls can be formulas. But, this hasn't been implemented yet
            ExcelFormulaParseTreeNode formulaNode{};
            formulaNode.AddNodeTag(L"Formula");
            
            if (tokenInfo._tokenType == TokenType::IntegerToken)
            {
                ExcelFormulaParseTreeNode constantNode{};
                constantNode.AddNodeTag(L"Constant");
                
                // For constants, only integer constants are currently supported
                ExcelFormulaParseTreeNode numberNode{};
                numberNode.AddNodeTag(L"Number");
                
                // Add the Integer token
                ExcelFormulaParseTreeNode numberTokenNode{};
                numberTokenNode.AddNodeTag(L"NumberToken");
                numberTokenNode.AddTokenInformation(tokenInfo);
                
                numberNode.AddChildNode(numberTokenNode);
                constantNode.AddChildNode(numberNode);
                formulaNode.AddChildNode(constantNode);
            }
            else
            {
                ExcelFormulaParseTreeNode referenceNode{};
                referenceNode.AddNodeTag(L"Reference");
                
                // For reference types, only cell references are currently supported
                ExcelFormulaParseTreeNode cellNode{};
                cellNode.AddNodeTag(L"Cell");
                
                // Add the Cell Token
                ExcelFormulaParseTreeNode cellTokenNode{};
                cellTokenNode.AddNodeTag(L"CellToken");
                cellTokenNode.AddTokenInformation(tokenInfo);
                
                cellNode.AddChildNode(cellTokenNode);
                referenceNode.AddChildNode(cellNode);
                formulaNode.AddChildNode(referenceNode);
            }

            argumentNode.AddChildNode(formulaNode);
            argumentsNode.AddChildNode(argumentNode);
        }
    }

    functionNameNode.AddChildNode(excelFunctionNameNode);
    functionCallNode.AddChildNode(functionNameNode);
    functionCallNode.AddChildNode(argumentsNode);
    fNode.AddChildNode(functionCallNode);
    outputParseTree.GetRootNode().AddChildNode(equivalentOpNode);
    outputParseTree.GetRootNode().AddChildNode(fNode);

    return outputParseTree;
}