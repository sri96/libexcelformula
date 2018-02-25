#pragma once

#ifndef TOKEN_TYPES_H
#define TOKEN_TYPES_H

namespace ExcelFormula
{
    enum class TokenType
    {
        EqualOperationToken,
        OpenCurlyParenToken,
        CloseCurlyParenToken,
    };
};

#endif