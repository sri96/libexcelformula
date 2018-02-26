#pragma once

#ifndef PARSE_TREE_EXECUTOR_UTS_HPP
#define PARSE_TREE_EXECUTOR_UTS_HPP

#include <libexcelformulaerror.h>
#include <vector>
#include <unordered_map>

#include "../../../src/formula_lexer/i_excel_formula_lexer.h"
#include "../../../src/formula_parser/i_excel_formula_parser.h"
#include "../../../src/shared/excel_formula_parse_tree.h"
#include "../../../src/shared/i_excel_formula_token.h"
#include "../../../src/shared/parser_error.h"
#include "../../../src/formula_callback_manager/i_excel_formula_callback_manager.h"
#include "../../../src/parse_tree_executor/i_excel_formula_parse_tree_executor.h"
#include "../../../src/shared/runtime_error.h"

TEST_CASE( "Parsed tree should execute successfully", "[Callbacks]" ) {
    std::unique_ptr<ExcelFormula::Lexer::IExcelFormulaLexer> excelFormulaLexerInstance = ExcelFormula::Lexer::CreateExcelFormulaLexerInstance();
    const std::wstring_view inputFormula(L"=SUM(5,B5)");
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormula);
    REQUIRE(lexerError == ExcelFormula::Lexer::LexerError::None);

    const std::unique_ptr<ExcelFormula::Parser::IExcelFormulaParser> excelFormulaParserInstance = ExcelFormula::Parser::CreateExcelFormulaParserInstance();
    auto [parseError, parsedFormulaTree] = excelFormulaParserInstance->BuildParseTreeFromTokens(lexedTokens);
    REQUIRE(parseError == ExcelFormula::Parser::ParserError::None);

    const std::unique_ptr<ExcelFormula::IExcelFormulaCallbackManager> excelFormulaCallbackManager = ExcelFormula::CreateExcelFormulaCallbackManagerInstance();
    auto callbackFunctionForReferenceValues = [=](const std::wstring_view /*inputReferenceName*/, std::wstring& outputValueForReference, ExcelFormula::LibExcelFormulaError& /*oututError*/){ outputValueForReference = std::to_wstring(5);};
    std::unordered_map<std::wstring_view, std::wstring> referenceDataCache;
    const ExcelFormula::LibExcelFormulaError formulaCallbackManagerError = excelFormulaCallbackManager->ResolveReferences(parsedFormulaTree, callbackFunctionForReferenceValues, referenceDataCache);
    REQUIRE(formulaCallbackManagerError == ExcelFormula::LibExcelFormulaError::None);

    const std::unique_ptr<ExcelFormula::Runtime::IExcelFormulaParseTreeExecutor> excelFormulaParseTreeExecutorInstance = ExcelFormula::Runtime::CreateExcelFormulaParseTreeExecutorInstance();
    const auto [runtimeError, outputValue] = excelFormulaParseTreeExecutorInstance->ExecuteParseTree(parsedFormulaTree);
    REQUIRE(runtimeError == ExcelFormula::Runtime::RuntimeError::NotImplemented);
}

#endif