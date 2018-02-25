#pragma once

#ifndef PARSE_TREE_EXECUTOR_UTS_HPP
#define PARSE_TREE_EXECUTOR_UTS_HPP

#include <vector>

#include "../../../src/parse_tree_executor/i_excel_formula_parse_tree_executor.h"
#include "../../../src/shared/i_excel_formula_parse_tree.h"
#include "../../../src/shared/runtime_error.h"

TEST_CASE( "Formula execution should be successful", "[FormulaRuntime]" ) {
    const std::unique_ptr<ExcelFormula::Runtime::IExcelFormulaParseTreeExecutor> excelFormulaParseTreeExecutorInstance = ExcelFormula::Runtime::CreateExcelFormulaParseTreeExecutorInstance();
    ExcelFormula::Parser::IExcelFormulaParseTree inputParseTreeToExecute{};
    const auto [runtimeError, outputValue] = excelFormulaParseTreeExecutorInstance->ExecuteParseTree(inputParseTreeToExecute);
    REQUIRE(runtimeError == ExcelFormula::Runtime::RuntimeError::None);
}

#endif