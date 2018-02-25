#pragma once

#ifndef MOCK_EXCEL_FORMULA_LEXER_H
#define MOCK_EXCEL_FORMULA_LEXER_H

#include "i_excel_formula_lexer.h"

namespace ExcelFormula
{
    namespace Lexer
    {
        class MockExcelFormulaLexer : public IExcelFormulaLexer
        {
            LexerError _outputLexerError;
            std::vector<std::unique_ptr<IExcelFormulaToken>> _outputLexerTokens;
            
            public:
                std::pair<LexerError, std::vector<std::unique_ptr<IExcelFormulaToken>>> LexFormulaIntoTokens(const std::wstring_view inputFormulaString) const noexcept;
                void PopulateData();
        };
    };
};

#endif