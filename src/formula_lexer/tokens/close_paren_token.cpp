#include "close_paren_token.h"
#include <limits>

using namespace ExcelFormula;
using namespace ExcelFormula::Lexer;
using namespace ExcelFormula::Lexer::Tokens;

CloseParenToken::CloseParenToken()
{
    _stringViewRepresentation = L")";
    _regexRepresentation = std::regex("\\)");
    _variableLengthToken = false;
    _outputTokenType = TokenType::CloseParenToken;
    _tokenPriority = -1; // Just a dummy value for now
}

bool CloseParenToken::IsVariableLengthToken() const noexcept
{
    return _variableLengthToken;
}

std::wstring_view CloseParenToken::GetTerminalRepresentation() const noexcept
{
    return _stringViewRepresentation;
}

std::regex CloseParenToken::GetRegexRepresentation() const noexcept
{
    return _regexRepresentation;
}

size_t CloseParenToken::GetTokenMaxLength() const noexcept
{
    return _stringViewRepresentation.size();
}

int CloseParenToken::GetTokenPriority() const noexcept
{
    return _tokenPriority;
}

bool CloseParenToken::MatchToken(const std::wstring_view inputString) noexcept
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

TokenType CloseParenToken::GetTokenType() const noexcept
{
    return _outputTokenType;
}

std::wstring_view CloseParenToken::GetTokenData() const noexcept
{
    return _extractedTokenData;
}

size_t CloseParenToken::GetTokenMatchStartingPosition() const noexcept
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

void CloseParenToken::SetTokenData(const std::wstring_view inputStringView) noexcept
{
    _extractedTokenData = inputStringView;
}

void CloseParenToken::SetTokenMatchStartingPosition(const size_t inputTokenMatchStartingPosition) noexcept 
{
    _startingPosOfMatchedStringView = inputTokenMatchStartingPosition;
}

std::unique_ptr<IExcelFormulaToken> ExcelFormula::Lexer::Tokens::CreateCloseParenTokenInstance()
{
    return std::make_unique<CloseParenToken>();
}