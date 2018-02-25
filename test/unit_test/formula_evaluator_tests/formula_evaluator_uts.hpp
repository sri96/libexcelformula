#pragma once

#ifndef FORMULA_EVALUATOR_UTS_HPP
#define FORMULA_EVALUATOR_UTS_HPP

#include <libexcelformula.h>
#include <libexcelformulaerror.h>

TEST_CASE( "Formula evaluations should be successful", "[FormulaEvaluation]" ) {
    std::unique_ptr<ExcelFormula::IExcelFormulaEvaluator> excelFormulaEvaluatorInstance = ExcelFormula::CreateExcelFormulaEvaluatorInstance();
    const std::wstring_view inputFormula(L"=SUM(5,6)");
    auto callbackFunctionForReferenceValues = [=](const std::wstring_view /*inputReferenceName*/, std::wstring& /*outputValueForReference*/, ExcelFormula::LibExcelFormulaError& /*oututError*/){};
    const ExcelFormula::EvaluatedFormulaOutput output = excelFormulaEvaluatorInstance->EvaluateFormula(inputFormula, callbackFunctionForReferenceValues);
    REQUIRE(output.outputFormulaError == ExcelFormula::LibExcelFormulaError::LexerError);
    REQUIRE(output.outputFormulaError == ExcelFormula::LibExcelFormulaError::None);
}

#endif