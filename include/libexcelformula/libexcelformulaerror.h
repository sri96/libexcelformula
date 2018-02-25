#pragma once

#ifndef LIBEXCELFORMULAERROR_H
#define LIBEXCELFORMULAERROR_H

#include <string>
#include <unordered_map>

namespace ExcelFormula
{
    enum class LibExcelFormulaError
    {
        LexerError, // Indicates a lexing error. Read the string output for a detailed message
        ParserError, // Indicates a parsing error. Read the string output for a detailed message
        DataReferenceError, // Indicates that the referenced data is not available
        Error, // Adding a generic error. This will be removed in the future as we add more specific errors such as parsing error or lexing error
        None
    };

    static const std::unordered_map<LibExcelFormulaError, std::wstring> errorToStringMapping = {
        { LibExcelFormulaError::LexerError, L"LexerError"},
        { LibExcelFormulaError::ParserError, L"ParseError"},
        { LibExcelFormulaError::DataReferenceError, L"DataReferenceError"},
        { LibExcelFormulaError::Error, L"Error"},
        { LibExcelFormulaError::None, L"None"},
    }; 
}

#endif
