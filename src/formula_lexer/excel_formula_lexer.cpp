#include "excel_formula_lexer.h"
#include "tokens/equal_operation_token.h"
#include "tokens/open_curly_paren_token.h"
#include "tokens/close_curly_paren_token.h"


using namespace ExcelFormula;
using namespace ExcelFormula::Lexer;
using namespace ExcelFormula::Lexer::Tokens;

ExcelFormulaLexer::ExcelFormulaLexer()
{
    _testingTokenInstances.push_back(std::move(CreateEqualOperationTokenInstance()));
    _testingTokenInstances.push_back(std::move(CreateOpenCurlyParenTokenInstance()));
    _testingTokenInstances.push_back(std::move(CreateCloseCurlyParenTokenInstance()));
}

std::pair<LexerError, std::vector<std::unique_ptr<IExcelFormulaToken>>> ExcelFormulaLexer::LexFormulaIntoTokens(const std::wstring_view inputFormulaString) const noexcept
{
    // Currently, the lexer is just a big while loop that goes through the input string and tries to find the longest possible matches
    // and extracts those matches into strings. 
    std::vector<std::unique_ptr<IExcelFormulaToken>> outputTokens{};

    // Adding a loop safety valve. Since while loops can keep going for infinite amount of time and block, release this value if 
    // a bound is reached and we will reach a lexer error.
    size_t loopSafetyValve = 0;
    const size_t loopSafetyValveBound = inputFormulaString.size()*_testingTokenInstances.size();

    // Lexer will start at index zero and will continue until it reaches a match. Then it will move to the match size + 1 and 
    // start again. 
    size_t matchIndex = 0;
    
    while(true)
    {
        const std::wstring_view _substringToMatch = inputFormulaString.substr(matchIndex);
        bool isMatchingTokenFound = false;

        for (size_t index = 0; index < _testingTokenInstances.size(); index++)
        {
            isMatchingTokenFound = _testingTokenInstances.at(index)->MatchToken(_substringToMatch);
            if (isMatchingTokenFound && _testingTokenInstances.at(index)->GetTokenMatchStartingPosition() == 0)
            {
                const std::wstring_view matchedTokenStringViewRepresentation = _testingTokenInstances.at(index)->GetTokenData();
                matchIndex += matchedTokenStringViewRepresentation.size();

                const TokenType matchedTokenType = _testingTokenInstances.at(index)->GetTokenType();
                std::unique_ptr<IExcelFormulaToken> matchedToken = GetNewTokenInstanceForExport(matchedTokenType);
                matchedToken->SetTokenData(matchedTokenStringViewRepresentation);
                outputTokens.push_back(std::move(matchedToken));
                break;
            }
        }

        // The real exit condition if the matchIndex has reached the end of the string
        if (matchIndex == inputFormulaString.size())
        {
            return std::make_pair(LexerError::None, std::move(outputTokens));
        }

        if (loopSafetyValve == loopSafetyValveBound)
        {
            break;
        }
        loopSafetyValve++;
    }

    return std::make_pair(LexerError::Error, std::vector<std::unique_ptr<IExcelFormulaToken>>{});
}

std::unique_ptr<IExcelFormulaToken> ExcelFormulaLexer::GetNewTokenInstanceForExport(const TokenType& inputTokenType) const noexcept
{
    switch(inputTokenType)
    {
        case TokenType::EqualOperationToken:
        {
            return CreateEqualOperationTokenInstance();
        }
        break;

        case TokenType::OpenCurlyParenToken:
        {
            return CreateOpenCurlyParenTokenInstance();
        }
        break;

        case TokenType::CloseCurlyParenToken:
        {
            return CreateCloseCurlyParenTokenInstance();
        }   
        break;

        default:
            return nullptr;
    }
}

std::unique_ptr<IExcelFormulaLexer> ExcelFormula::Lexer::CreateExcelFormulaLexerInstance()
{
    return std::make_unique<ExcelFormulaLexer>();
}