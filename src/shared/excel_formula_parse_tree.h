#pragma once

#ifndef EXCEL_FORMULA_PARSE_TREE_H
#define EXCEL_FORMULA_PARSE_TREE_H

#include "excel_formula_parse_tree_node.h"
#include "token_types.h"

namespace ExcelFormula
{
    namespace Parser
    {
        class ExcelFormulaParseTree
        {
            ExcelFormulaParseTreeNode _rootNode;

            public:
                ExcelFormulaParseTreeNode& GetRootNode();
        };
    };
};

#endif