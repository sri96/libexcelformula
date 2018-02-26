#pragma once

#ifndef FORMULA_PARSER_UTS_HPP
#define FORMULA_PARSER_UTS_HPP

#include <vector>

#include "../../../src/formula_lexer/i_excel_formula_lexer.h"
#include "../../../src/formula_parser/i_excel_formula_parser.h"
#include "../../../src/shared/excel_formula_parse_tree.h"
#include "../../../src/shared/i_excel_formula_token.h"
#include "../../../src/shared/parser_error.h"

TEST_CASE( "Formula parsing should be successful", "[FormulaParsing]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring_view inputFormula(L"=SUM(5,6)");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);
    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);

    const std::unique_ptr<ExcelFormula::Parser::IExcelFormulaParser> excelFormulaParserInstance = ExcelFormula::Parser::CreateExcelFormulaParserInstance();
    const auto [parseError, parsedFormulaTree] = excelFormulaParserInstance->BuildParseTreeFromTokens(lexedTokens);
    REQUIRE(parseError == ExcelFormula::Parser::ParserError::None);
}

#endif