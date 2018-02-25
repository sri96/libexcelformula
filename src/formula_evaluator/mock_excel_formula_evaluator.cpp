#include "mock_excel_formula_evaluator.h"

using namespace ExcelFormula;

EvaluatedFormulaOutput MockExcelFormulaEvaluator::EvaluateFormula(const std::wstring_view inputFormulaString, const std::function<void(const std::wstring_view, std::wstring&)>& /*inputCallbackFunction*/) const noexcept
{
    return _mockOutput;
}

void MockExcelFormulaEvaluator::PopulateMockData()
{
    // Please use this function to populate your mock data for testing purposes.
}

std::unique_ptr<IExcelFormulaEvaluator> ExcelFormula::CreateExcelFormulaEvaluatorInstance()
{
    auto outputMockEvaluatorInstance = std::make_unique<MockExcelFormulaEvaluator>();
    outputMockEvaluatorInstance->PopulateMockData();
    return outputMockEvaluatorInstance;
}
