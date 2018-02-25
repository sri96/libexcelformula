#include "excel_formula_parser.h"

using namespace ExcelFormula;
using namespace ExcelFormula::Parser;

std::pair<ParserError, IExcelFormulaParseTree> ExcelFormulaParser::BuildParseTreeFromTokens(const std::vector<std::unique_ptr<ExcelFormula::IExcelFormulaToken>>& /*inputLexedTokens*/) const noexcept
{
    ParserError outputError = ParserError::Error;
    IExcelFormulaParseTree outputTree{};
    return std::make_pair(outputError, outputTree);
}

std::unique_ptr<IExcelFormulaParser> ExcelFormula::Parser::CreateExcelFormulaParserInstance()
{
    return std::make_unique<ExcelFormulaParser>();
}