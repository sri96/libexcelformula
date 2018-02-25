#pragma once

#ifndef MOCK_FORMULA_EVALUATOR_H
#define MOCK_FORMULA_EVALUATOR_H

#include "../../include/libexcelformula/libexcelformula.h"

namespace ExcelFormula
{
    class MockExcelFormulaEvaluator : public IExcelFormulaEvaluator
    {
        EvaluatedFormulaOutput _mockOutput;

        public:
            EvaluatedFormulaOutput EvaluateFormula(const std::wstring_view inputFormulaString, const std::function<void(const std::wstring_view, std::wstring&, LibExcelFormulaError&)>& inputCallbackFunction) const noexcept;
            void PopulateMockData();
    };
}

#endif
