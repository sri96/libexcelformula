#include "excel_function_token.h"
#include <limits>

using namespace ExcelFormula;
using namespace ExcelFormula::Lexer;
using namespace ExcelFormula::Lexer::Tokens;

ExcelFunctionToken::ExcelFunctionToken()
{
    _stringViewRepresentation = L"";
    _regexRepresentation = std::regex("");
    _variableLengthToken = true;
    _outputTokenType = TokenType::ExcelFunctionToken;
    _tokenPriority = -1; // Just a dummy value for now

    // The token for the function names actually include the open paran as 
    // well. 
    _supportedExcelFunctionNames.push_back(L"SUM(");

    for (const std::wstring_view& excelFunctionName : _supportedExcelFunctionNames)
    {
        if (_maxLengthOfToken < excelFunctionName.size())
        {
            _maxLengthOfToken = excelFunctionName.size();
        }
    }
}

bool ExcelFunctionToken::IsVariableLengthToken() const noexcept
{
    return _variableLengthToken;
}

std::wstring_view ExcelFunctionToken::GetTerminalRepresentation() const noexcept
{
    return _stringViewRepresentation;
}

std::regex ExcelFunctionToken::GetRegexRepresentation() const noexcept
{
    return _regexRepresentation;
}

size_t ExcelFunctionToken::GetTokenMaxLength() const noexcept
{
    return _maxLengthOfToken;
}

int ExcelFunctionToken::GetTokenPriority() const noexcept
{
    return _tokenPriority;
}

bool ExcelFunctionToken::MatchToken(const std::wstring_view inputString) noexcept
{
    for (const std::wstring_view& excelFunctionName : _supportedExcelFunctionNames)
    {
        if (inputString.substr(0, excelFunctionName.size()) == excelFunctionName)
        {
            _extractedTokenData = excelFunctionName;
            return true;
        }
    }

    return false;
}

TokenType ExcelFunctionToken::GetTokenType() const noexcept
{
    return _outputTokenType;
}

std::wstring_view ExcelFunctionToken::GetTokenData() const noexcept
{
    return _extractedTokenData;
}

size_t ExcelFunctionToken::GetTokenMatchStartingPosition() const noexcept
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

void ExcelFunctionToken::SetTokenData(const std::wstring_view inputStringView) noexcept
{
    _extractedTokenData = inputStringView;
}

void ExcelFunctionToken::SetTokenMatchStartingPosition(const size_t inputTokenMatchStartingPosition) noexcept 
{
    _startingPosOfMatchedStringView = inputTokenMatchStartingPosition;
}

std::unique_ptr<IExcelFormulaToken> ExcelFormula::Lexer::Tokens::CreateExcelFunctionTokenInstance()
{
    return std::make_unique<ExcelFunctionToken>();
}