#pragma once

#ifndef EXCEL_FORMULA_LEXER_H
#define EXCEL_FORMULA_LEXER_H

#include "i_excel_formula_lexer.h"
#include "../shared/i_excel_formula_token.h"
#include "../shared/token_types.h"

namespace ExcelFormula
{
    namespace Lexer
    {
        class ExcelFormulaLexer : public IExcelFormulaLexer
        {
            std::vector<std::unique_ptr<IExcelFormulaToken>> _testingTokenInstances;

            public:
                ExcelFormulaLexer();
                std::pair<LexerError, std::vector<std::unique_ptr<IExcelFormulaToken>>> LexFormulaIntoTokens(const std::wstring_view inputFormulaString) const noexcept;
        
            private:
                std::unique_ptr<IExcelFormulaToken> GetNewTokenInstanceForExport(const TokenType& inputTokenType) const noexcept;
        };
    };
};

#endif