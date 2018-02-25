#pragma once

#ifndef MOCK_EXCEL_FORMULA_PARSER_H
#define MOCK_EXCEL_FORMULA_PARSER_H

#include "i_excel_formula_parser.h"
#include "../shared/parser_error.h"

namespace ExcelFormula
{
    namespace Parser
    {
        class MockExcelFormulaParser : public IExcelFormulaParser
        {
            ParserError _outputParseError;
            IExcelFormulaParseTree _outputParseTree;

            public:
                std::pair<ParserError, IExcelFormulaParseTree> BuildParseTreeFromTokens(const std::vector<std::unique_ptr<ExcelFormula::IExcelFormulaToken>>& inputLexedTokens) const noexcept;
                void PopulateData();
        };
    };
};

#endif