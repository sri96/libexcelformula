#pragma once

#ifndef I_EXCEL_FORMULA_LEXER_H
#define I_EXCEL_FORMULA_LEXER_H

#include <memory>
#include <string_view>
#include <utility>
#include <vector>
#include "../shared/i_excel_formula_token.h"
#include "../shared/lexer_error.h"

namespace ExcelFormula
{
    namespace Lexer
    {
        class IExcelFormulaLexer
        {
            public:
                virtual std::pair<LexerError, std::vector<std::unique_ptr<IExcelFormulaToken>>> LexFormulaIntoTokens(const std::wstring_view inputFormulaString) const noexcept = 0;
        };

        std::unique_ptr<IExcelFormulaLexer> CreateExcelFormulaLexerInstance();
    };
};

#endif