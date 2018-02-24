#pragma once

#ifndef LIBEXCELFORMULAERROR_H
#define LIBEXCELFORMULAERROR_H

#include <string>
#include <unordered_map>

namespace ExcelFormula
{
    enum class LibExcelFormulaError
    {
        None
    };

    static const std::unordered_map<LibExcelFormulaError, std::wstring> errorToStringMapping = {
        { LibExcelFormulaError::None, L"None"},
    }; 
}

#endif