#pragma once

#ifndef FORMULA_LEXER_UTS_HPP
#define FORMULA_LEXER_UTS_HPP

#include "../../../src/formula_lexer/i_excel_formula_lexer.h"
#include "../../../src/shared/i_excel_formula_token.h"
#include "../../../src/shared/lexer_error.h"
#include "../../../src/shared/token_types.h"
#include <iostream>

TEST_CASE( "Lexing `=` should return a EqualOperationToken", "[FormulaLexing]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring_view inputFormula(L"=");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);

    // We shouldn't run into any lexing errors. We should have exactly one token. EqualOperationToken is what we are expecting.
    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);
    REQUIRE(lexedTokens.size() == 1);
    REQUIRE(lexedTokens.at(0)->GetTokenType() == ExcelFormula::TokenType::EqualOperationToken);
}

TEST_CASE( "Lexing `{` should return a OpenCurlyParenToken", "[FormulaLexing]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring inputFormula(L"{");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);

    // We shouldn't run into any lexing errors. We should have exactly one token. EqualOperationToken is what we are expecting.
    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);
    REQUIRE(lexedTokens.size() == 1);
    REQUIRE(lexedTokens.at(0)->GetTokenType() == ExcelFormula::TokenType::OpenCurlyParenToken);
}

TEST_CASE( "Lexing `{=` should return a OpenCurlyParenToken and EqualOperationToken", "[FormulaLexing]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring_view inputFormula(L"{=");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);

    // We shouldn't run into any lexing errors. We should have exactly one token. EqualOperationToken is what we are expecting.
    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);
    REQUIRE(lexedTokens.size() == 2);
    REQUIRE(lexedTokens.at(0)->GetTokenType() == ExcelFormula::TokenType::OpenCurlyParenToken);
    REQUIRE(lexedTokens.at(1)->GetTokenType() == ExcelFormula::TokenType::EqualOperationToken);
}

TEST_CASE( "Lexing `={` should return a EqualOperationToken and OpenCurlyParenToken", "[FormulaLexing]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring_view inputFormula(L"={");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);

    // We shouldn't run into any lexing errors. We should have exactly one token. EqualOperationToken is what we are expecting.
    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);
    REQUIRE(lexedTokens.size() == 2);
    REQUIRE(lexedTokens.at(0)->GetTokenType() == ExcelFormula::TokenType::EqualOperationToken);
    REQUIRE(lexedTokens.at(1)->GetTokenType() == ExcelFormula::TokenType::OpenCurlyParenToken);
}

TEST_CASE( "Lexing `===` should return two EqualOperationToken", "[FormulaLexing]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring_view inputFormula(L"===");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);

    // We shouldn't run into any lexing errors. We should have exactly one token. EqualOperationToken is what we are expecting.
    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);
    REQUIRE(lexedTokens.size() == 3);
    REQUIRE(lexedTokens.at(0)->GetTokenType() == ExcelFormula::TokenType::EqualOperationToken);
    REQUIRE(lexedTokens.at(1)->GetTokenType() == ExcelFormula::TokenType::EqualOperationToken);
}

TEST_CASE( "Lexing `}={` should return one CloseCurlyParenToken, EqualOperationToken and OpenCurlyParenToken", "[FormulaLexing]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring_view inputFormula(L"}={");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);

    // We shouldn't run into any lexing errors. We should have exactly one token. EqualOperationToken is what we are expecting.
    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);
    REQUIRE(lexedTokens.size() == 3);
    REQUIRE(lexedTokens.at(0)->GetTokenType() == ExcelFormula::TokenType::CloseCurlyParenToken);
    REQUIRE(lexedTokens.at(1)->GetTokenType() == ExcelFormula::TokenType::EqualOperationToken);
    REQUIRE(lexedTokens.at(2)->GetTokenType() == ExcelFormula::TokenType::OpenCurlyParenToken);
}

TEST_CASE( "Formula lexing should be successful", "[FormulaLexing]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring_view inputFormula(L"=SUM(5,6)");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);
    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);
}

#endif