#pragma once

#ifndef EXCEL_FORMULA_LEXER_H
#define EXCEL_FORMULA_LEXER_H

#include "i_excel_formula_lexer.h"

namespace ExcelFormula
{
    namespace Lexer
    {
        class ExcelFormulaLexer : public IExcelFormulaLexer
        {
            public:
                std::pair<LexerError, std::vector<IExcelFormulaToken>> LexFormulaIntoTokens(const std::wstring_view inputFormulaString) const noexcept;
        };
    };
};

#endif