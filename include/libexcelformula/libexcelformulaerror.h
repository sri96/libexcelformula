#pragma once

#ifndef LIBEXCELFORMULAERROR_H
#define LIBEXCELFORMULAERROR_H

#include <string>
#include <unordered_map>

namespace ExcelFormula
{
    enum class LibExcelFormulaError
    {
        Error, // Adding a generic error. This will be removed in the future as we add more specific errors such as parsing error or lexing error
        None
    };

    static const std::unordered_map<LibExcelFormulaError, std::wstring> errorToStringMapping = {
        { LibExcelFormulaError::Error, L"Error"},
        { LibExcelFormulaError::None, L"None"},
    }; 
}

#endif
