#pragma once

#ifndef I_EXCEL_FORMULA_TOKEN_H
#define I_EXCEL_FORMULA_TOKEN_H

#include <regex>
#include <string>
#include <string_view>

#include "token_types.h"

namespace ExcelFormula
{
    // Both the Lexer and Parser needs to be aware of tokens
    class IExcelFormulaToken
    {
        public:
            virtual bool IsVariableLengthToken() const noexcept = 0;
            virtual std::wstring_view GetTerminalRepresentation() const noexcept = 0;
            virtual std::regex GetRegexRepresentation() const noexcept = 0;
            virtual size_t GetTokenMaxLength() const noexcept = 0;
            virtual int GetTokenPriority() const noexcept = 0;
            virtual bool MatchToken(const std::wstring_view inputString) noexcept = 0;
            virtual TokenType GetTokenType() const noexcept = 0;
            virtual std::wstring_view GetTokenData() const noexcept = 0;
            virtual std::wstring GetTokenDataString() const noexcept = 0;
            virtual size_t GetTokenMatchStartingPosition() const noexcept = 0;
            virtual void SetTokenData(const std::wstring_view inputStringView) noexcept = 0;
            virtual void SetTokenMatchStartingPosition(const size_t inputTokenMatchStartingPosition) noexcept = 0;
    };
};

#endif