#pragma once

#ifndef EXCEL_FORMULA_PARSER_H
#define EXCEL_FORMULA_PARSER_H

#include "i_excel_formula_parser.h"
#include "../shared/parser_error.h"
#include "../shared/token_types.h"

#include <string_view>
#include <experimental/optional>

namespace ExcelFormula
{
    namespace Parser
    {
        class ExcelFormulaParser : public IExcelFormulaParser
        {
            public:
                std::pair<ParserError, ExcelFormulaParseTree> BuildParseTreeFromTokens(const std::vector<std::unique_ptr<ExcelFormula::IExcelFormulaToken>>& inputLexedTokens) const noexcept;
        };

        std::experimental::optional<ExcelFormulaParseTree> TryConvertingTokensToFormulaParseTree(const std::vector<TokenInformationForParseTree>& inputLexedTokens);
        std::experimental::optional<ExcelFormulaParseTree> TryConvertingTokensToFormulaWithEquivalentSignParseTree(const std::vector<TokenInformationForParseTree>& inputLexedTokens);
        std::experimental::optional<ExcelFormulaParseTree> TryConvertingTokensToArrayFormulaParseTree(const std::vector<TokenInformationForParseTree>& inputLexedTokens);
    };
};

#endif