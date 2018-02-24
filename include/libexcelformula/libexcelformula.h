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
            EvaluatedFormulaOutput EvaluateFormula(std::wstring_view inputFormulaString);
    };

    std::unique_ptr<IExcelFormulaEvaluator> CreateExcelFormulaEvaluatorInstance(std::wstring_view inputFormulaString);
}

#endif