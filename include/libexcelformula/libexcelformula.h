#pragma once

#ifndef LIBEXCELFORMULA_H
#define LIBEXCELFORMULA_H

#include <memory>
#include <utility>
#include <string_view>

#include "libexcelformulaerror.h"

namespace ExcelFormula
{
    struct EvaluatedFormulaOutput
    {
        LibExcelFormulaError outputFormulaError;
        std::wstring outputEvaluatedResult;
    };

    class IExcelFormulaEvaluator
    {
        public:
            virtual EvaluatedFormulaOutput EvaluateFormula(const std::wstring_view inputFormulaString) const noexcept = 0;
    };

    std::unique_ptr<IExcelFormulaEvaluator> CreateExcelFormulaEvaluatorInstance();
}

#endif
