#pragma once

#ifndef I_EXCEL_FORMULA_PARSER
#define I_EXCEL_FORMULA_PARSER

#include <memory>
#include <utility>
#include <vector>
#include "../shared/i_excel_formula_parse_tree.h"
#include "../shared/i_excel_formula_token.h"
#include "../shared/parser_error.h"

namespace ExcelFormula
{
    namespace Parser
    {
        class IExcelFormulaParser
        {
            public:
                virtual std::pair<ParserError, IExcelFormulaParseTree> BuildParseTreeFromTokens(const std::vector<ExcelFormula::IExcelFormulaToken>& inputLexedTokens) const noexcept = 0;
        };

        std::unique_ptr<IExcelFormulaParser> CreateExcelFormulaParserInstance();
    };
};

#endif