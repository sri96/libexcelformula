#pragma once

#ifndef FORMULA_PARSER_UTS_HPP
#define FORMULA_PARSER_UTS_HPP

#include <vector>

#include "../../../src/formula_parser/i_excel_formula_parser.h"
#include "../../../src/shared/excel_formula_parse_tree.h"
#include "../../../src/shared/i_excel_formula_token.h"
#include "../../../src/shared/parser_error.h"

TEST_CASE( "Formula parsing should be successful", "[FormulaParsing]" ) {
    const std::unique_ptr<ExcelFormula::Parser::IExcelFormulaParser> excelFormulaParserInstance = ExcelFormula::Parser::CreateExcelFormulaParserInstance();
    const auto [parseError, parsedFormulaTree] = excelFormulaParserInstance->BuildParseTreeFromTokens(std::vector<std::unique_ptr<ExcelFormula::IExcelFormulaToken>>{});
    REQUIRE(parseError == ExcelFormula::Parser::ParserError::None);
}

#endif