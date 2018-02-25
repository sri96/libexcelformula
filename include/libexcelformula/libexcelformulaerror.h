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
        RuntimeError, // Indicates a runtime error has happend during function execution
        None
    };

    static const std::unordered_map<LibExcelFormulaError, std::wstring> errorToStringMapping = {
        { LibExcelFormulaError::LexerError, L"LexerError"},
        { LibExcelFormulaError::ParserError, L"ParseError"},
        { LibExcelFormulaError::DataReferenceError, L"DataReferenceError"},
        { LibExcelFormulaError::RuntimeError, L"RuntimeError"},
        { LibExcelFormulaError::None, L"None"},
    }; 
}

#endif
