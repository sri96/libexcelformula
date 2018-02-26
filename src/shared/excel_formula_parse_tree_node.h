#pragma once

#ifndef EXCEL_FORMULA_PARSE_TREE_NODE_H
#define EXCEL_FORMULA_PARSE_TREE_NODE_H


#include <string>
#include <vector>
#include "token_types.h"

namespace ExcelFormula
{
    namespace Parser
    {
        struct TokenInformationForParseTree
        {
            TokenType _tokenType;
            std::wstring _tokenData;
        };

        // Parse Trees are not binary trees. They can have n children.
        class ExcelFormulaParseTreeNode
        {
            std::vector<ExcelFormulaParseTreeNode> _childNodes;
            std::wstring_view _nodeTag; // Human readable name for this node
            TokenInformationForParseTree _tokenInformtionForNode;

        public:
            void AddChildNode(const ExcelFormulaParseTreeNode& inputNode) noexcept;
            void AddNodeTag(const std::wstring_view inputNodeTag) noexcept;
            void AddTokenInformation(const TokenInformationForParseTree& inputTokenInformation) noexcept;
            std::vector<ExcelFormulaParseTreeNode> GetChildNodes() const noexcept;
            std::wstring_view GetNodeTag() const noexcept;
            TokenInformationForParseTree GetTokenInformationForNode() const noexcept;
        };
    };
};

#endif