#include "excel_formula_parse_tree.h"

using namespace ExcelFormula::Parser;

ExcelFormulaParseTreeNode& ExcelFormulaParseTree::GetRootNode()
{
    return _rootNode;
}