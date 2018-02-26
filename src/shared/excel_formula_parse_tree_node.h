#pragma once

#ifndef EXCEL_FORMULA_PARSE_TREE_NODE_H
#define EXCEL_FORMULA_PARSE_TREE_NODE_H

#include <vector>

namespace ExcelFormula
{
    namespace Parser
    {
        class ExcelFormulaParseTreeNode
        {
            std::vector<ExcelFormulaParseTreeNode> _childNodes;

        public:
            void AddChildNode();
            std::vector<ExcelFormulaParseTreeNode> GetChildNodes(const ExcelFormulaParseTreeNode& inputNode);
        };
    };
};

#endif