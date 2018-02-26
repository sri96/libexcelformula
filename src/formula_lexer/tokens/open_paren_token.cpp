#include "open_paren_token.h"
#include <limits>

using namespace ExcelFormula;
using namespace ExcelFormula::Lexer;
using namespace ExcelFormula::Lexer::Tokens;

OpenParenToken::OpenParenToken()
{
    _stringViewRepresentation = L"(";
    _regexRepresentation = std::regex("\\(");
    _variableLengthToken = false;
    _outputTokenType = TokenType::OpenParenToken;
    _tokenPriority = -1; // Just a dummy value for now
}

bool OpenParenToken::IsVariableLengthToken() const noexcept
{
    return _variableLengthToken;
}

std::wstring_view OpenParenToken::GetTerminalRepresentation() const noexcept
{
    return _stringViewRepresentation;
}

std::regex OpenParenToken::GetRegexRepresentation() const noexcept
{
    return _regexRepresentation;
}

size_t OpenParenToken::GetTokenMaxLength() const noexcept
{
    return _stringViewRepresentation.size();
}

int OpenParenToken::GetTokenPriority() const noexcept
{
    return _tokenPriority;
}

bool OpenParenToken::MatchToken(const std::wstring_view inputString) noexcept
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

TokenType OpenParenToken::GetTokenType() const noexcept
{
    return _outputTokenType;
}

std::wstring_view OpenParenToken::GetTokenData() const noexcept
{
    return _extractedTokenData;
}

size_t OpenParenToken::GetTokenMatchStartingPosition() const noexcept
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

void OpenParenToken::SetTokenData(const std::wstring_view inputStringView) noexcept
{
    _extractedTokenData = inputStringView;
}

void OpenParenToken::SetTokenMatchStartingPosition(const size_t inputTokenMatchStartingPosition) noexcept 
{
    _startingPosOfMatchedStringView = inputTokenMatchStartingPosition;
}

std::unique_ptr<IExcelFormulaToken> ExcelFormula::Lexer::Tokens::CreateOpenParenTokenInstance()
{
    return std::make_unique<OpenParenToken>();
}