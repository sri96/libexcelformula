#include "mock_excel_formula_parser.h"

using namespace ExcelFormula;
using namespace ExcelFormula::Parser;

std::pair<ParserError, IExcelFormulaParseTree> MockExcelFormulaParser::BuildParseTreeFromTokens(const std::vector<ExcelFormula::IExcelFormulaToken>& /*inputLexedTokens*/) const noexcept
{
    return std::make_pair(_outputParseError, _outputParseTree);
}

void MockExcelFormulaParser::PopulateData()
{
    // Please use this function to populate your mock data for the Parser
}

std::unique_ptr<IExcelFormulaParser> CreateExcelFormulaParserInstance()
{
    auto outputInstance = std::make_unique<MockExcelFormulaParser>();
    outputInstance->PopulateData();
    return outputInstance;
}