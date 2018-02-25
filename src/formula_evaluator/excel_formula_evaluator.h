#pragma once

#ifndef FORMULA_EVALUATOR_H
#define FORMULA_EVALUATOR_H

#include "../../include/libexcelformula/libexcelformula.h"

namespace ExcelFormula
{
    class ExcelFormulaEvaluator : public IExcelFormulaEvaluator
    {
        public:
            EvaluatedFormulaOutput EvaluateFormula(const std::wstring_view inputFormulaString, const std::function<void(const std::wstring_view, std::wstring&)>& inputCallbackFunction) const noexcept;
    };
}

#endif
