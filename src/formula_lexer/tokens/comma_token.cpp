#include "comma_token.h"
#include <limits>

using namespace ExcelFormula;
using namespace ExcelFormula::Lexer;
using namespace ExcelFormula::Lexer::Tokens;

CommaToken::CommaToken()
{
    _stringViewRepresentation = L",";
    _regexRepresentation = std::regex(",");
    _variableLengthToken = false;
    _outputTokenType = TokenType::CommaToken;
    _tokenPriority = -1; // Just a dummy value for now
}

bool CommaToken::IsVariableLengthToken() const noexcept
{
    return _variableLengthToken;
}

std::wstring_view CommaToken::GetTerminalRepresentation() const noexcept
{
    return _stringViewRepresentation;
}

std::regex CommaToken::GetRegexRepresentation() const noexcept
{
    return _regexRepresentation;
}

size_t CommaToken::GetTokenMaxLength() const noexcept
{
    return _stringViewRepresentation.size();
}

int CommaToken::GetTokenPriority() const noexcept
{
    return _tokenPriority;
}

bool CommaToken::MatchToken(const std::wstring_view inputString) noexcept
{
    if (inputString.substr(0, _stringViewRepresentation.size()) == _stringViewRepresentation)
    {
        _extractedTokenData = _stringViewRepresentation;
        return true;
    }
    else
    {
        return false;
    }
}

TokenType CommaToken::GetTokenType() const noexcept
{
    return _outputTokenType;
}

std::wstring_view CommaToken::GetTokenData() const noexcept
{
    return _extractedTokenData;
}

size_t CommaToken::GetTokenMatchStartingPosition() const noexcept
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

void CommaToken::SetTokenData(const std::wstring_view inputStringView) noexcept
{
    _extractedTokenData = inputStringView;
}

void CommaToken::SetTokenMatchStartingPosition(const size_t inputTokenMatchStartingPosition) noexcept 
{
    _startingPosOfMatchedStringView = inputTokenMatchStartingPosition;
}

std::unique_ptr<IExcelFormulaToken> ExcelFormula::Lexer::Tokens::CreateCommaTokenInstance()
{
    return std::make_unique<CommaToken>();
}