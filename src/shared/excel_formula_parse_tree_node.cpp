#include "excel_formula_parse_tree_node.h"

using namespace ExcelFormula::Parser;

void ExcelFormulaParseTreeNode::AddChildNode(const ExcelFormulaParseTreeNode& inputNode) noexcept
{
    _childNodes.push_back(inputNode);
}

void ExcelFormulaParseTreeNode::AddNodeTag(const std::wstring_view inputNodeTag) noexcept
{
    _nodeTag = inputNodeTag;
}

void ExcelFormulaParseTreeNode::AddTokenInformation(const TokenInformationForParseTree& inputTokenInformation) noexcept
{
    // Not all nodes need this information. Only user data containing nodes need this information.
    _tokenInformtionForNode = inputTokenInformation;
}

std::vector<ExcelFormulaParseTreeNode> ExcelFormulaParseTreeNode::GetChildNodes() const noexcept
{
    return _childNodes;
}

std::wstring_view ExcelFormulaParseTreeNode::GetNodeTag() const noexcept
{
    return _nodeTag;
}

TokenInformationForParseTree ExcelFormulaParseTreeNode::GetTokenInformationForNode() const noexcept
{
    return _tokenInformtionForNode;
}