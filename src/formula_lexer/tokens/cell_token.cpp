#include "cell_token.h"
#include <limits>

using namespace ExcelFormula;
using namespace ExcelFormula::Lexer;
using namespace ExcelFormula::Lexer::Tokens;

CellToken::CellToken()
{
    _stringViewRepresentation = L"";
    _regexRepresentation = std::wregex(L"[$]?[A-Z]{1,4}[$]?[1-9][0-9]*");
    _variableLengthToken = true;
    _outputTokenType = TokenType::CellToken;
    _tokenPriority = -1; // Just a dummy value for now
}

bool CellToken::IsVariableLengthToken() const noexcept
{
    return _variableLengthToken;
}

std::wstring_view CellToken::GetTerminalRepresentation() const noexcept
{
    return _stringViewRepresentation;
}

std::regex CellToken::GetRegexRepresentation() const noexcept
{
    // Dummy return. 
    return std::regex{};
}

size_t CellToken::GetTokenMaxLength() const noexcept
{
    return _stringViewRepresentation.size();
}

int CellToken::GetTokenPriority() const noexcept
{
    return _tokenPriority;
}

bool CellToken::MatchToken(const std::wstring_view inputString) noexcept
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
                _extractedTokenDataString = std::wstring(matcher[index].str());
                return true;
            }
        }
    }
    
    return false;
}

TokenType CellToken::GetTokenType() const noexcept
{
    return _outputTokenType;
}

std::wstring_view CellToken::GetTokenData() const noexcept
{
    return _extractedTokenData;
}

std::wstring CellToken::GetTokenDataString() const noexcept
{
    return _extractedTokenDataString;
}

size_t CellToken::GetTokenMatchStartingPosition() const noexcept
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

void CellToken::SetTokenData(const std::wstring_view inputStringView) noexcept
{
    _extractedTokenData = inputStringView;
}

void CellToken::SetTokenMatchStartingPosition(const size_t inputTokenMatchStartingPosition) noexcept 
{
    _startingPosOfMatchedStringView = inputTokenMatchStartingPosition;
}

std::unique_ptr<IExcelFormulaToken> ExcelFormula::Lexer::Tokens::CreateCellTokenInstance()
{
    return std::make_unique<CellToken>();
}