#include "excel_formula_parse_tree_executor.h"

using namespace ExcelFormula::Runtime;

std::pair<RuntimeError, std::wstring> ExcelFormulaParseTreeExecutor::ExecuteParseTree(ExcelFormula::Parser::ExcelFormulaParseTree& /*inputParseTreeToExecute*/) const noexcept
{
    return std::make_pair(RuntimeError::Error, L"");
}

std::unique_ptr<IExcelFormulaParseTreeExecutor> ExcelFormula::Runtime::CreateExcelFormulaParseTreeExecutorInstance()
{
    return std::make_unique<ExcelFormulaParseTreeExecutor>();
}