#include "close_curly_paren_token.h"
#include <limits>

using namespace ExcelFormula;
using namespace ExcelFormula::Lexer;
using namespace ExcelFormula::Lexer::Tokens;

CloseCurlyParenToken::CloseCurlyParenToken()
{
    _stringViewRepresentation = L"}";
    _regexRepresentation = std::regex("\\}");
    _variableLengthToken = false;
    _outputTokenType = TokenType::CloseCurlyParenToken;
    _tokenPriority = -1; // Just a dummy value for now
}

bool CloseCurlyParenToken::IsVariableLengthToken() const noexcept
{
    return _variableLengthToken;
}

std::wstring_view CloseCurlyParenToken::GetTerminalRepresentation() const noexcept
{
    return _stringViewRepresentation;
}

std::regex CloseCurlyParenToken::GetRegexRepresentation() const noexcept
{
    return _regexRepresentation;
}

size_t CloseCurlyParenToken::GetTokenMaxLength() const noexcept
{
    return _stringViewRepresentation.size();
}

int CloseCurlyParenToken::GetTokenPriority() const noexcept
{
    return _tokenPriority;
}

bool CloseCurlyParenToken::MatchToken(const std::wstring_view inputString) noexcept
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

TokenType CloseCurlyParenToken::GetTokenType() const noexcept
{
    return _outputTokenType;
}

std::wstring_view CloseCurlyParenToken::GetTokenData() const noexcept
{
    return _extractedTokenData;
}

size_t CloseCurlyParenToken::GetTokenMatchStartingPosition() const noexcept
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

void CloseCurlyParenToken::SetTokenData(const std::wstring_view inputStringView) noexcept
{
    _extractedTokenData = inputStringView;
}

void CloseCurlyParenToken::SetTokenMatchStartingPosition(const size_t inputTokenMatchStartingPosition) noexcept 
{
    _startingPosOfMatchedStringView = inputTokenMatchStartingPosition;
}

std::unique_ptr<IExcelFormulaToken> ExcelFormula::Lexer::Tokens::CreateCloseCurlyParenTokenInstance()
{
    return std::make_unique<CloseCurlyParenToken>();
}