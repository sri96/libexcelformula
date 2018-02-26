#pragma once

#ifndef FORMULA_CALLBACK_MANAGER_UTS_HPP
#define FORMULA_CALLBACK_MANAGER_UTS_HPP

#include <libexcelformulaerror.h>
#include "../../../src/formula_callback_manager/i_excel_formula_callback_manager.h"
#include "../../../src/shared/excel_formula_parse_tree.h"

TEST_CASE( "Callback for references should be successful", "[Callbacks]" ) {
    const std::unique_ptr<ExcelFormula::IExcelFormulaCallbackManager> excelFormulaCallbackManager = ExcelFormula::CreateExcelFormulaCallbackManagerInstance();
    auto callbackFunctionForReferenceValues = [=](const std::wstring_view /*inputReferenceName*/, std::wstring& /*outputValueForReference*/, ExcelFormula::LibExcelFormulaError& /*oututError*/){};
    ExcelFormula::Parser::ExcelFormulaParseTree dummyParseTree{};
    const ExcelFormula::LibExcelFormulaError formulaCallbackManagerError = excelFormulaCallbackManager->ResolveReferences(dummyParseTree, callbackFunctionForReferenceValues);
    REQUIRE(formulaCallbackManagerError == ExcelFormula::LibExcelFormulaError::None);
}

#endif