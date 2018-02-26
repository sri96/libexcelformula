#include "excel_formula_lexer.h"
#include "tokens/equal_operation_token.h"
#include "tokens/open_curly_paren_token.h"
#include "tokens/close_curly_paren_token.h"
#include "tokens/open_paren_token.h"
#include "tokens/close_paren_token.h"
#include "tokens/excel_function_token.h"
#include "tokens/comma_token.h"
#include "tokens/integer_token.h"
#include "tokens/cell_token.h"

using namespace ExcelFormula;
using namespace ExcelFormula::Lexer;
using namespace ExcelFormula::Lexer::Tokens;

ExcelFormulaLexer::ExcelFormulaLexer()
{
    // Please don't change the order of the push_backs. They have been arranged in token 
    // priority order. In the future, I think this should be just sorted by the priority
    // field in each token. 

    _testingTokenInstances.push_back(std::move(CreateCellTokenInstance()));
    _testingTokenInstances.push_back(std::move(CreateIntegerTokenInstance()));
    _testingTokenInstances.push_back(std::move(CreateExcelFunctionTokenInstance()));
    _testingTokenInstances.push_back(std::move(CreateEqualOperationTokenInstance()));
    _testingTokenInstances.push_back(std::move(CreateOpenCurlyParenTokenInstance()));
    _testingTokenInstances.push_back(std::move(CreateCloseCurlyParenTokenInstance()));
    _testingTokenInstances.push_back(std::move(CreateOpenParenTokenInstance()));
    _testingTokenInstances.push_back(std::move(CreateCloseParenTokenInstance()));
    _testingTokenInstances.push_back(std::move(CreateCommaTokenInstance()));
}

std::pair<LexerError, std::vector<std::unique_ptr<IExcelFormulaToken>>> ExcelFormulaLexer::LexFormulaIntoTokens(const std::wstring_view inputFormulaString) const noexcept
{
    // Currently, the lexer is just a big while loop that goes through the input string and tries to find the longest possible matches
    // and extracts those matches into strings. We should benchmark this and see if a prefix tree might be faster way to do this.
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
                
                if (matchedToken != nullptr)
                {
                    matchedToken->SetTokenData(matchedTokenStringViewRepresentation);
                    outputTokens.push_back(std::move(matchedToken));
                    break;
                }
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

// A map should be more suitable replacement for this function. But, I still haven't figured out how to use functors as keys.
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

        case TokenType::OpenParenToken:
        {
            return CreateOpenParenTokenInstance();
        }
        break;

        case TokenType::CloseParenToken:
        {
            return CreateCloseParenTokenInstance();
        }
        break;

        case TokenType::ExcelFunctionToken:
        {
            return CreateExcelFunctionTokenInstance();
        }
        break;

        case TokenType::CommaToken:
        {
            return CreateCommaTokenInstance();
        }
        break;

        case TokenType::IntegerToken:
        {
            return CreateIntegerTokenInstance();
        }
        break;

        case TokenType::CellToken:
        {
            return CreateCellTokenInstance();
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