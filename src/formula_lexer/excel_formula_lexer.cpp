#include "excel_formula_lexer.h"

using namespace ExcelFormula;
using namespace ExcelFormula::Lexer;

std::pair<LexerError, std::vector<IExcelFormulaToken>> ExcelFormulaLexer::LexFormulaIntoTokens(const std::wstring_view /*inputFormulaString*/) const noexcept
{
    return std::make_pair(LexerError::Error, std::vector<IExcelFormulaToken>{});
}

std::unique_ptr<IExcelFormulaLexer> ExcelFormula::Lexer::CreateExcelFormulaLexerInstance()
{
    return std::make_unique<ExcelFormulaLexer>();
}