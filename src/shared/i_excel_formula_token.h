#pragma once

#ifndef I_EXCEL_FORMULA_TOKEN_H
#define I_EXCEL_FORMULA_TOKEN_H

#include <regex>
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
            virtual bool MatchToken(const std::wstring_view inputString) const noexcept = 0;
            virtual TokenType GetTokenType() const noexcept;
    };
};

#endif