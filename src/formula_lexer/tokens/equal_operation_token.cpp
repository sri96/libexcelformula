#include "equal_operation_token.h"
#include <limits>

using namespace ExcelFormula;
using namespace ExcelFormula::Lexer;
using namespace ExcelFormula::Lexer::Tokens;

EqualOperationToken::EqualOperationToken()
{
    _stringViewRepresentation = L"=";
    _regexRepresentation = std::regex("=");
    _variableLengthToken = false;
    _outputTokenType = TokenType::EqualOperationToken;
    _tokenPriority = -1; // Just a dummy value for now
}

bool EqualOperationToken::IsVariableLengthToken() const noexcept
{
    return _variableLengthToken;
}

std::wstring_view EqualOperationToken::GetTerminalRepresentation() const noexcept
{
    return _stringViewRepresentation;
}

std::regex EqualOperationToken::GetRegexRepresentation() const noexcept
{
    return _regexRepresentation;
}

size_t EqualOperationToken::GetTokenMaxLength() const noexcept
{
    return _stringViewRepresentation.size();
}

int EqualOperationToken::GetTokenPriority() const noexcept
{
    return _tokenPriority;
}

bool EqualOperationToken::MatchToken(const std::wstring_view inputString) noexcept
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

TokenType EqualOperationToken::GetTokenType() const noexcept
{
    return _outputTokenType;
}

std::wstring_view EqualOperationToken::GetTokenData() const noexcept
{
    return _extractedTokenData;
}

size_t EqualOperationToken::GetTokenMatchStartingPosition() const noexcept
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

void EqualOperationToken::SetTokenData(const std::wstring_view inputStringView) noexcept
{
    _extractedTokenData = inputStringView;
}

void EqualOperationToken::SetTokenMatchStartingPosition(const size_t inputTokenMatchStartingPosition) noexcept 
{
    _startingPosOfMatchedStringView = inputTokenMatchStartingPosition;
}

std::unique_ptr<IExcelFormulaToken> ExcelFormula::Lexer::Tokens::CreateEqualOperationTokenInstance()
{
    return std::make_unique<EqualOperationToken>();
}