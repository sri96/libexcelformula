#pragma once

#ifndef FORMULA_LEXER_UTS_HPP
#define FORMULA_LEXER_UTS_HPP

#include "../../../src/formula_lexer/i_excel_formula_lexer.h"
#include "../../../src/shared/i_excel_formula_token.h"
#include "../../../src/shared/lexer_error.h"
#include "../../../src/shared/token_types.h"

TEST_CASE( "Lexing `=` should return a EqualOperationToken", "[FormulaLexing]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring_view inputFormula(L"=");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);

    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);
    REQUIRE(lexedTokens.size() == 1);
    REQUIRE(lexedTokens.at(0)->GetTokenType() == ExcelFormula::TokenType::EqualOperationToken);
}

TEST_CASE( "Lexing `{` should return a OpenCurlyParenToken", "[FormulaLexing]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring inputFormula(L"{");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);

    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);
    REQUIRE(lexedTokens.size() == 1);
    REQUIRE(lexedTokens.at(0)->GetTokenType() == ExcelFormula::TokenType::OpenCurlyParenToken);
}

TEST_CASE( "Lexing `{=` should return a OpenCurlyParenToken and EqualOperationToken", "[FormulaLexing]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring_view inputFormula(L"{=");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);

    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);
    REQUIRE(lexedTokens.size() == 2);
    REQUIRE(lexedTokens.at(0)->GetTokenType() == ExcelFormula::TokenType::OpenCurlyParenToken);
    REQUIRE(lexedTokens.at(1)->GetTokenType() == ExcelFormula::TokenType::EqualOperationToken);
}

TEST_CASE( "Lexing `={` should return a EqualOperationToken and OpenCurlyParenToken", "[FormulaLexing]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring_view inputFormula(L"={");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);

    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);
    REQUIRE(lexedTokens.size() == 2);
    REQUIRE(lexedTokens.at(0)->GetTokenType() == ExcelFormula::TokenType::EqualOperationToken);
    REQUIRE(lexedTokens.at(1)->GetTokenType() == ExcelFormula::TokenType::OpenCurlyParenToken);
}

TEST_CASE( "Lexing `===` should return two EqualOperationToken", "[FormulaLexing]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring_view inputFormula(L"===");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);

    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);
    REQUIRE(lexedTokens.size() == 3);
    REQUIRE(lexedTokens.at(0)->GetTokenType() == ExcelFormula::TokenType::EqualOperationToken);
    REQUIRE(lexedTokens.at(1)->GetTokenType() == ExcelFormula::TokenType::EqualOperationToken);
}

TEST_CASE( "Lexing `}={` should return one CloseCurlyParenToken, EqualOperationToken and OpenCurlyParenToken", "[FormulaLexing]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring_view inputFormula(L"}={");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);

    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);
    REQUIRE(lexedTokens.size() == 3);
    REQUIRE(lexedTokens.at(0)->GetTokenType() == ExcelFormula::TokenType::CloseCurlyParenToken);
    REQUIRE(lexedTokens.at(1)->GetTokenType() == ExcelFormula::TokenType::EqualOperationToken);
    REQUIRE(lexedTokens.at(2)->GetTokenType() == ExcelFormula::TokenType::OpenCurlyParenToken);
}

TEST_CASE( "Lexing `}=(` should return one CloseCurlyParenToken, EqualOperationToken and OpenParenToken", "[FormulaLexing]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring_view inputFormula(L"}=(");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);

    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);
    REQUIRE(lexedTokens.size() == 3);
    REQUIRE(lexedTokens.at(0)->GetTokenType() == ExcelFormula::TokenType::CloseCurlyParenToken);
    REQUIRE(lexedTokens.at(1)->GetTokenType() == ExcelFormula::TokenType::EqualOperationToken);
    REQUIRE(lexedTokens.at(2)->GetTokenType() == ExcelFormula::TokenType::OpenParenToken);
}

TEST_CASE( "Lexing `{=()}` should return OpenCurlyParenToken, EqualOperationToken, OpenParenToken, CloseParenToken and CloseCurlyParenToken", "[FormulaLexing]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring_view inputFormula(L"{=()}");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);

    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);
    REQUIRE(lexedTokens.size() == 5);
    REQUIRE(lexedTokens.at(0)->GetTokenType() == ExcelFormula::TokenType::OpenCurlyParenToken);
    REQUIRE(lexedTokens.at(1)->GetTokenType() == ExcelFormula::TokenType::EqualOperationToken);
    REQUIRE(lexedTokens.at(2)->GetTokenType() == ExcelFormula::TokenType::OpenParenToken);
    REQUIRE(lexedTokens.at(3)->GetTokenType() == ExcelFormula::TokenType::CloseParenToken);
    REQUIRE(lexedTokens.at(4)->GetTokenType() == ExcelFormula::TokenType::CloseCurlyParenToken);
}

TEST_CASE( "Lexing `{=SUM()}` should return OpenCurlyParenToken, EqualOperationToken, ExcelFunctionToken, CloseParenToken and CloseCurlyParenToken", "[FormulaLexing]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring_view inputFormula(L"{=SUM()}");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);

    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);
    REQUIRE(lexedTokens.size() == 5);
    REQUIRE(lexedTokens.at(0)->GetTokenType() == ExcelFormula::TokenType::OpenCurlyParenToken);
    REQUIRE(lexedTokens.at(1)->GetTokenType() == ExcelFormula::TokenType::EqualOperationToken);
    REQUIRE(lexedTokens.at(2)->GetTokenType() == ExcelFormula::TokenType::ExcelFunctionToken);
    REQUIRE(lexedTokens.at(3)->GetTokenType() == ExcelFormula::TokenType::CloseParenToken);
    REQUIRE(lexedTokens.at(4)->GetTokenType() == ExcelFormula::TokenType::CloseCurlyParenToken);
}

TEST_CASE( "Lexing `{=SUM(,)}` should return OpenCurlyParenToken, EqualOperationToken, ExcelFunctionToken, CommaToken, CloseParenToken and CloseCurlyParenToken", "[FormulaLexing]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring_view inputFormula(L"{=SUM(,)}");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);

    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);
    REQUIRE(lexedTokens.size() == 6);
    REQUIRE(lexedTokens.at(0)->GetTokenType() == ExcelFormula::TokenType::OpenCurlyParenToken);
    REQUIRE(lexedTokens.at(1)->GetTokenType() == ExcelFormula::TokenType::EqualOperationToken);
    REQUIRE(lexedTokens.at(2)->GetTokenType() == ExcelFormula::TokenType::ExcelFunctionToken);
    REQUIRE(lexedTokens.at(3)->GetTokenType() == ExcelFormula::TokenType::CommaToken);
    REQUIRE(lexedTokens.at(4)->GetTokenType() == ExcelFormula::TokenType::CloseParenToken);
    REQUIRE(lexedTokens.at(5)->GetTokenType() == ExcelFormula::TokenType::CloseCurlyParenToken);
}

TEST_CASE( "Lexing `1500{` should return a IntegerToken and OpenCurlyParenToken", "[FormulaLexing]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring_view inputFormula(L"1500{");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);

    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);
    REQUIRE(lexedTokens.size() == 2);
    REQUIRE(lexedTokens.at(0)->GetTokenType() == ExcelFormula::TokenType::IntegerToken);
    REQUIRE(lexedTokens.at(1)->GetTokenType() == ExcelFormula::TokenType::OpenCurlyParenToken);
}

TEST_CASE( "Lexing `{=SUM(1500,1600)}` should be eight tokens", "[FormulaLexing]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring_view inputFormula(L"{=SUM(1500,1600)}");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);

    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);
    REQUIRE(lexedTokens.size() == 8);
    REQUIRE(lexedTokens.at(0)->GetTokenType() == ExcelFormula::TokenType::OpenCurlyParenToken);
    REQUIRE(lexedTokens.at(1)->GetTokenType() == ExcelFormula::TokenType::EqualOperationToken);
    REQUIRE(lexedTokens.at(2)->GetTokenType() == ExcelFormula::TokenType::ExcelFunctionToken);
    REQUIRE(lexedTokens.at(3)->GetTokenType() == ExcelFormula::TokenType::IntegerToken);
    REQUIRE(lexedTokens.at(4)->GetTokenType() == ExcelFormula::TokenType::CommaToken);
    REQUIRE(lexedTokens.at(5)->GetTokenType() == ExcelFormula::TokenType::IntegerToken);
    REQUIRE(lexedTokens.at(6)->GetTokenType() == ExcelFormula::TokenType::CloseParenToken);
    REQUIRE(lexedTokens.at(7)->GetTokenType() == ExcelFormula::TokenType::CloseCurlyParenToken);
}

TEST_CASE( "Lexing `{=SUM(1500,A4)}` should be eight tokens", "[FormulaLexing]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring_view inputFormula(L"{=SUM(1500,A4)}");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);

    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);
    REQUIRE(lexedTokens.size() == 8);
    REQUIRE(lexedTokens.at(0)->GetTokenType() == ExcelFormula::TokenType::OpenCurlyParenToken);
    REQUIRE(lexedTokens.at(1)->GetTokenType() == ExcelFormula::TokenType::EqualOperationToken);
    REQUIRE(lexedTokens.at(2)->GetTokenType() == ExcelFormula::TokenType::ExcelFunctionToken);
    REQUIRE(lexedTokens.at(3)->GetTokenType() == ExcelFormula::TokenType::IntegerToken);
    REQUIRE(lexedTokens.at(4)->GetTokenType() == ExcelFormula::TokenType::CommaToken);
    REQUIRE(lexedTokens.at(5)->GetTokenType() == ExcelFormula::TokenType::CellToken);
    REQUIRE(lexedTokens.at(6)->GetTokenType() == ExcelFormula::TokenType::CloseParenToken);
    REQUIRE(lexedTokens.at(7)->GetTokenType() == ExcelFormula::TokenType::CloseCurlyParenToken);
}

TEST_CASE( "Formula lexing should be successful", "[FormulaLexing]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring_view inputFormula(L"=SUM(5,6)");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);
    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);
}

#endif