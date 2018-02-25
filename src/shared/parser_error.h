#pragma once

#ifndef PARSER_ERROR_H
#define PARSER_ERROR_H

namespace ExcelFormula
{
    namespace Parser
    {
        enum class ParserError
        {
            Error, // A generic error. This will be replaced with more specific error messages as I write the parser
            None
        };
    };
};

#endif