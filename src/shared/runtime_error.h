#pragma once

#ifndef RUNTIME_ERROR_H
#define RUNTIME_ERROR_H

namespace ExcelFormula
{
    namespace Runtime
    {
        enum class RuntimeError
        {
            NotImplemented,
            Error, // A generic error object. It will be replaced shortly
            None
        };
    }
};

#endif