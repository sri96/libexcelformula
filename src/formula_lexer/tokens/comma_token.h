#pragma once

#ifndef COMMA_TOKEN_H
#define COMMA_TOKEN_H

#include <memory>

#include "../../shared/i_excel_formula_token.h"
#include "../../shared/token_types.h"

namespace ExcelFormula
{
    namespace Lexer
    {
        namespace Tokens
        {
            class CommaToken : public IExcelFormulaToken
            { 
                std::wstring_view _stringViewRepresentation;
                std::regex _regexRepresentation;
                bool _variableLengthToken;
                std::wstring_view _extractedTokenData;
                size_t _startingPosOfMatchedStringView;
                TokenType _outputTokenType;
                int _tokenPriority;

            public:
                CommaToken();
                bool IsVariableLengthToken() const noexcept;
                std::wstring_view GetTerminalRepresentation() const noexcept;
                std::regex GetRegexRepresentation() const noexcept;
                size_t GetTokenMaxLength() const noexcept;
                int GetTokenPriority() const noexcept;
                bool MatchToken(const std::wstring_view inputString) noexcept;
                TokenType GetTokenType() const noexcept;
                std::wstring_view GetTokenData() const noexcept;
                size_t GetTokenMatchStartingPosition() const noexcept;
                void SetTokenData(const std::wstring_view inputStringView) noexcept;
                void SetTokenMatchStartingPosition(const size_t inputTokenMatchStartingPosition) noexcept;
            };

            std::unique_ptr<IExcelFormulaToken> CreateCommaTokenInstance();
        };
    };
};

#endif
