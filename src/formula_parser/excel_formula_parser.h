#pragma once

#ifndef EXCEL_FORMULA_PARSER_H
#define EXCEL_FORMULA_PARSER_H

#include "i_excel_formula_parser.h"
#include "../shared/parser_error.h"

namespace ExcelFormula
{
    namespace Parser
    {
        class ExcelFormulaParser : public IExcelFormulaParser
        {
            public:
                std::pair<ParserError, IExcelFormulaParseTree> BuildParseTreeFromTokens(const std::vector<std::unique_ptr<ExcelFormula::IExcelFormulaToken>>& inputLexedTokens) const noexcept;
        };
    };
};

#endif