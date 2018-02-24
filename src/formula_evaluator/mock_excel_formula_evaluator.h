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
            EvaluatedFormulaOutput EvaluateFormula(const std::wstring_view inputFormulaString) const noexcept;
            void PopulateMockData();
    };
}

#endif
