#include "mock_excel_formula_callback_manager.h"

using namespace ExcelFormula;
using namespace ExcelFormula::Parser;

ExcelFormula::LibExcelFormulaError MockExcelFormulaCallbackManager::ResolveReferences(ExcelFormulaParseTree& /*inputFormulaParseTree*/, const std::function<void(const std::wstring_view, std::wstring&, LibExcelFormulaError&)>& /*inputCallbackFunction*/) const noexcept
{
    return _outputError;
}

void MockExcelFormulaCallbackManager::PopulateData()
{
    // Use this function to populate the mock data for the callback manager
}

std::unique_ptr<IExcelFormulaCallbackManager> ExcelFormula::CreateExcelFormulaCallbackManagerInstance()
{
    auto formulaCallbackManagerInstance = std::make_unique<MockExcelFormulaCallbackManager>();
    formulaCallbackManagerInstance->PopulateData();
    return formulaCallbackManagerInstance;
}