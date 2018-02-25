#pragma once

#ifndef EXCEL_FORMULA_PARSE_TREE_EXECUTOR_H
#define EXCEL_FORMULA_PARSE_TREE_EXECUTOR_H

#include "i_excel_formula_parse_tree_executor.h"

namespace ExcelFormula
{
    namespace Runtime
    {
        class ExcelFormulaParseTreeExecutor : public IExcelFormulaParseTreeExecutor
        {
            public:
                std::pair<RuntimeError, std::wstring> ExecuteParseTree(ExcelFormula::Parser::IExcelFormulaParseTree& inputParseTreeToExecute) const noexcept;
        };
    };
};

#endif