#include "mock_excel_formula_parse_tree_executor.h"

using namespace ExcelFormula::Runtime;

std::pair<RuntimeError, std::wstring> MockExcelFormulaParseTreeExecutor::ExecuteParseTree(ExcelFormula::Parser::ExcelFormulaParseTree& /*inputParseTreeToExecute*/) const noexcept
{
    return std::make_pair(_outputRuntimeError, _outputString);
}

void MockExcelFormulaParseTreeExecutor::PopulateData()
{
    // Use this function to populate data for your mock
}

std::unique_ptr<IExcelFormulaParseTreeExecutor> ExcelFormula::Runtime::CreateExcelFormulaParseTreeExecutorInstance()
{
    auto outputInstance = std::make_unique<MockExcelFormulaParseTreeExecutor>();
    outputInstance->PopulateData();
    return outputInstance;
}