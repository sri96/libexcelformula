#pragma once

#ifndef MOCK_EXCEL_FORMULA_PARSE_TREE_EXECUTOR_H
#define MOCK_EXCEL_FORMULA_PARSE_TREE_EXECUTOR_H

#include "i_excel_formula_parse_tree_executor.h"

namespace ExcelFormula
{
    namespace Runtime
    {
        class MockExcelFormulaParseTreeExecutor : public IExcelFormulaParseTreeExecutor
        {
            RuntimeError _outputRuntimeError;
            std::wstring _outputString;

            public:
                std::pair<RuntimeError, std::wstring> ExecuteParseTree(ExcelFormula::Parser::IExcelFormulaParseTree& inputParseTreeToExecute) const noexcept;
                void PopulateData();
        };
    };
};

#endif