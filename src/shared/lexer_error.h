#pragma once

#ifndef LEXER_ERROR_H
#define LEXER_ERROR_H

namespace ExcelFormula
{
    namespace Lexer
    {
        enum class LexerError
        {
            Error, // Adding a generic error object. This will be removed as we add more specific errors in the future
            None
        };
    };
};

#endif