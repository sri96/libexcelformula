#include "excel_formula_evaluator.h"

using namespace ExcelFormula;

EvaluatedFormulaOutput ExcelFormulaEvaluator::EvaluateFormula(std::wstring_view /*inputFormulaString*/) const noexcept
{
    EvaluatedFormulaOutput output;
    output.outputFormulaError = LibExcelFormulaError::Error;
    return output;
}

std::unique_ptr<IExcelFormulaEvaluator> ExcelFormula::CreateExcelFormulaEvaluatorInstance()
{
    return std::make_unique<ExcelFormulaEvaluator>();
}
