#include "excel_formula_parse_tree_executor.h"
#include <queue>

using namespace ExcelFormula::Runtime;
using namespace ExcelFormula::Parser;

std::pair<RuntimeError, std::wstring> ExcelFormulaParseTreeExecutor::ExecuteParseTree(ExcelFormula::Parser::ExcelFormulaParseTree& /*inputParseTreeToExecute*/) const noexcept
{
    return std::make_pair(RuntimeError::NotImplemented, L"Formula Not Implemented");
}

std::unique_ptr<IExcelFormulaParseTreeExecutor> ExcelFormula::Runtime::CreateExcelFormulaParseTreeExecutorInstance()
{
    return std::make_unique<ExcelFormulaParseTreeExecutor>();
}