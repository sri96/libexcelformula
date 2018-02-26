#include "integer_token.h"
#include <limits>

using namespace ExcelFormula;
using namespace ExcelFormula::Lexer;
using namespace ExcelFormula::Lexer::Tokens;

IntegerToken::IntegerToken()
{
    _stringViewRepresentation = L"";
    _regexRepresentation = std::wregex(L"[0-9]\\d*|0");
    _variableLengthToken = true;
    _outputTokenType = TokenType::IntegerToken;
    _tokenPriority = -1; // Just a dummy value for now
}

bool IntegerToken::IsVariableLengthToken() const noexcept
{
    return _variableLengthToken;
}

std::wstring_view IntegerToken::GetTerminalRepresentation() const noexcept
{
    return _stringViewRepresentation;
}

std::regex IntegerToken::GetRegexRepresentation() const noexcept
{
    // Dummy return. 
    return std::regex{};
}

size_t IntegerToken::GetTokenMaxLength() const noexcept
{
    return _stringViewRepresentation.size();
}

int IntegerToken::GetTokenPriority() const noexcept
{
    return _tokenPriority;
}

bool IntegerToken::MatchToken(const std::wstring_view inputString) noexcept
{
    std::wsmatch matcher;
    // Regex can only applied on strings. So, convert the input string_view into a string
    const std::wstring temporaryString = std::wstring(inputString);
    if (std::regex_search(temporaryString, matcher, _regexRepresentation))
    {
        for(size_t index = 0; index < matcher.size(); index++)
        {
            if (matcher.position(index) == 0)
            {
                _extractedTokenData = std::wstring_view(matcher[index].str());
                return true;
            }
        }
    }
    
    return false;
}

TokenType IntegerToken::GetTokenType() const noexcept
{
    return _outputTokenType;
}

std::wstring_view IntegerToken::GetTokenData() const noexcept
{
    return _extractedTokenData;
}

size_t IntegerToken::GetTokenMatchStartingPosition() const noexcept
{
    if (!_extractedTokenData.empty())
    {
        return 0;
    }
    else
    {
        return std::numeric_limits<size_t>::max();
    }
}

void IntegerToken::SetTokenData(const std::wstring_view inputStringView) noexcept
{
    _extractedTokenData = inputStringView;
}

void IntegerToken::SetTokenMatchStartingPosition(const size_t inputTokenMatchStartingPosition) noexcept 
{
    _startingPosOfMatchedStringView = inputTokenMatchStartingPosition;
}

std::unique_ptr<IExcelFormulaToken> ExcelFormula::Lexer::Tokens::CreateIntegerTokenInstance()
{
    return std::make_unique<IntegerToken>();
}