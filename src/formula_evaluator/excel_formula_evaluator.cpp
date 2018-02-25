#include <functional>

#include "excel_formula_evaluator.h"
#include "../formula_lexer/i_excel_formula_lexer.h"
#include "../formula_parser/i_excel_formula_parser.h"
#include "../formula_callback_manager/i_excel_formula_callback_manager.h"
#include "../parse_tree_executor/i_excel_formula_parse_tree_executor.h"

using namespace ExcelFormula;
using namespace ExcelFormula::Lexer;
using namespace ExcelFormula::Parser;
using namespace ExcelFormula::Runtime;

EvaluatedFormulaOutput ExcelFormulaEvaluator::EvaluateFormula(std::wstring_view inputFormulaString, const std::function<void(const std::wstring_view, std::wstring&, LibExcelFormulaError&)>& inputCallbackFunction) const noexcept
{
    EvaluatedFormulaOutput output;
    // Formula evaluation is four step process

    // 1. You need to lex the input string into tokens. Let's go do that
    const std::unique_ptr<IExcelFormulaLexer> excelFormulaLexerInstance = CreateExcelFormulaLexerInstance();
    const auto [lexerError, lexedTokens] = excelFormulaLexerInstance->LexFormulaIntoTokens(inputFormulaString);
    if (lexerError != LexerError::None)
    {
        output.outputFormulaError = LibExcelFormulaError::LexerError;
        return output;
    }

    // 2. Once you have the tokens, you need to parse them into a parse tree. Let's go do that now.
    const std::unique_ptr<IExcelFormulaParser> excelFormulaParserInstance = CreateExcelFormulaParserInstance();
    auto [parserError, parsedFormulaTree] = excelFormulaParserInstance->BuildParseTreeFromTokens(lexedTokens);
    if (parserError != ParserError::None)
    {
        output.outputFormulaError = LibExcelFormulaError::ParserError;
        return output;
    }

    // 3. Analyze the parse tree and make callbacks to the caller to retrieve data for references and other things
    //    that we don't have data for. Since we have the parse tree, let's analyze and perform callbacks to retrieve the data that we  
    //    don't have yet.
    const std::unique_ptr<IExcelFormulaCallbackManager> excelFormulaCallbackManagerInstance = CreateExcelFormulaCallbackManagerInstance();
    const LibExcelFormulaError outputDataReferenceError = excelFormulaCallbackManagerInstance->ResolveReferences(parsedFormulaTree, inputCallbackFunction);
    if (outputDataReferenceError != LibExcelFormulaError::None)
    {
        output.outputFormulaError = outputDataReferenceError;
        return output;
    }

    // 4. Evaluate the formula
    const std::unique_ptr<IExcelFormulaParseTreeExecutor> excelFormulaParseTreeExecutorInstance = CreateExcelFormulaParseTreeExecutorInstance();
    const auto [runtimeError, outputEvaluatedResult] = excelFormulaParseTreeExecutorInstance->ExecuteParseTree(parsedFormulaTree);
    if (runtimeError != RuntimeError::None)
    {
        output.outputFormulaError = LibExcelFormulaError::RuntimeError;
        return output;
    }

    output.outputFormulaError = LibExcelFormulaError::None;
    output.outputEvaluatedResult = outputEvaluatedResult;
    return output;
}

std::unique_ptr<IExcelFormulaEvaluator> ExcelFormula::CreateExcelFormulaEvaluatorInstance()
{
    return std::make_unique<ExcelFormulaEvaluator>();
}
