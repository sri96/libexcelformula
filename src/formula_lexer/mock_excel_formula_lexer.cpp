#include "mock_excel_formula_lexer.h"

using namespace ExcelFormula;
using namespace ExcelFormula::Lexer;

std::pair<LexerError, std::vector<std::unique_ptr<IExcelFormulaToken>>> MockExcelFormulaLexer::LexFormulaIntoTokens(const std::wstring_view inputFormulaString) const noexcept
{
    return std::make_pair(_outputLexerError, _outputLexerTokens);
}

void MockExcelFormulaLexer::PopulateData()
{
    // Use this function to populate data for your mock.
}

std::unique_ptr<IExcelFormulaLexer> CreateExcelFormulaLexerInstance()
{
    auto mockLexerInstance = std::make_unique<MockExcelFormulaLexer>();
    mockLexerInstance->PopulateData();
    return mockLexerInstance;
}