#include "excel_formula_callback_manager.h"

using namespace ExcelFormula;
using namespace ExcelFormula::Parser;

LibExcelFormulaError ExcelFormulaCallbackManager::ResolveReferences(ExcelFormulaParseTree& /*inputFormulaParseTree*/, const std::function<void(const std::wstring_view, std::wstring&, LibExcelFormulaError&)>& /*inputCallbackFunction*/) const noexcept
{
    return LibExcelFormulaError::DataReferenceError;
}

std::unique_ptr<IExcelFormulaCallbackManager> ExcelFormula::CreateExcelFormulaCallbackManagerInstance()
{
    return std::make_unique<ExcelFormulaCallbackManager>();
}