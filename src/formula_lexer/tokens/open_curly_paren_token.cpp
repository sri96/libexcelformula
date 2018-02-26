#include "open_curly_paren_token.h"
#include <limits>

using namespace ExcelFormula;
using namespace ExcelFormula::Lexer;
using namespace ExcelFormula::Lexer::Tokens;

OpenCurlyParenToken::OpenCurlyParenToken()
{
    _stringViewRepresentation = L"{";
    _regexRepresentation = std::regex("\\{");
    _variableLengthToken = false;
    _outputTokenType = TokenType::OpenCurlyParenToken;
    _tokenPriority = -1; // Just a dummy value for now
}

bool OpenCurlyParenToken::IsVariableLengthToken() const noexcept
{
    return _variableLengthToken;
}

std::wstring_view OpenCurlyParenToken::GetTerminalRepresentation() const noexcept
{
    return _stringViewRepresentation;
}

std::regex OpenCurlyParenToken::GetRegexRepresentation() const noexcept
{
    return _regexRepresentation;
}

size_t OpenCurlyParenToken::GetTokenMaxLength() const noexcept
{
    return _stringViewRepresentation.size();
}

int OpenCurlyParenToken::GetTokenPriority() const noexcept
{
    return _tokenPriority;
}

bool OpenCurlyParenToken::MatchToken(const std::wstring_view inputString) noexcept
{
    if (inputString.substr(0, _stringViewRepresentation.size()) == _stringViewRepresentation)
    {
        _extractedTokenDataString = std::wstring(_stringViewRepresentation);
        return true;
    }
    else
    {
        return false;
    }
}

TokenType OpenCurlyParenToken::GetTokenType() const noexcept
{
    return _outputTokenType;
}

std::wstring_view OpenCurlyParenToken::GetTokenData() const noexcept
{
    return _extractedTokenData;
}

std::wstring OpenCurlyParenToken::GetTokenDataString() const noexcept
{
    return _extractedTokenDataString;
}

size_t OpenCurlyParenToken::GetTokenMatchStartingPosition() const noexcept
{
    if (!_extractedTokenDataString.empty())
    {
        return 0;
    }
    else
    {
        return std::numeric_limits<size_t>::max();
    }
}

void OpenCurlyParenToken::SetTokenData(const std::wstring_view inputStringView) noexcept
{
    _extractedTokenData = inputStringView;
}

void OpenCurlyParenToken::SetTokenMatchStartingPosition(const size_t inputTokenMatchStartingPosition) noexcept 
{
    _startingPosOfMatchedStringView = inputTokenMatchStartingPosition;
}

std::unique_ptr<IExcelFormulaToken> ExcelFormula::Lexer::Tokens::CreateOpenCurlyParenTokenInstance()
{
    return std::make_unique<OpenCurlyParenToken>();
}