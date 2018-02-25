#pragma once

#ifndef I_EXCEL_FORMULA_PARSE_TREE_EXECUTOR_H
#define I_EXCEL_FORMULA_PARSE_TREE_EXECUTOR_H

#include <memory>
#include <string>
#include <utility>

#include "../shared/i_excel_formula_parse_tree.h"
#include "../shared/runtime_error.h"

namespace ExcelFormula
{
    namespace Runtime
    {
        class IExcelFormulaParseTreeExecutor
        {
            public:
                virtual std::pair<RuntimeError, std::wstring> ExecuteParseTree(ExcelFormula::Parser::IExcelFormulaParseTree& inputParseTreeToExecute) const noexcept = 0;
        };

        std::unique_ptr<IExcelFormulaParseTreeExecutor> CreateExcelFormulaParseTreeExecutorInstance();
    };
};

#endif