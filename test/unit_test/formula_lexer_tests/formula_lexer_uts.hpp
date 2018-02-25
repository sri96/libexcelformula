#pragma once

#ifndef FORMULA_LEXER_UTS_HPP
#define FORMULA_LEXER_UTS_HPP

#include "../../../src/formula_lexer/i_excel_formula_lexer.h"
#include "../../../src/shared/lexer_error.h"

TEST_CASE( "Formula lexing should be successful", "[FormulaLexing]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring_view inputFormula(L"=SUM(5,6)");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);
    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);
}

#endif