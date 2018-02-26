#include "excel_formula_callback_manager.h"
#include <queue>

using namespace ExcelFormula;
using namespace ExcelFormula::Parser;

LibExcelFormulaError ExcelFormulaCallbackManager::ResolveReferences(ExcelFormulaParseTree& inputFormulaParseTree, const std::function<void(const std::wstring_view, std::wstring&, LibExcelFormulaError&)>& inputCallbackFunction, std::unordered_map<std::wstring_view, std::wstring>& outputReferenceCache) const noexcept
{
    // Go through the Parse tree and for all reference nodes make a callback to the callee to get the referential data. This referential data will stored in a 
    // cache and exported back to the calling function.

    ExcelFormulaParseTreeNode& rootNode = inputFormulaParseTree.GetRootNode();
    std::queue<ExcelFormulaParseTreeNode> childNodesToTraverse{};

    for (ExcelFormulaParseTreeNode childNode: rootNode.GetChildNodes())
    {
        childNodesToTraverse.emplace(childNode);
    }

    while(!childNodesToTraverse.empty())
    {
        auto childNode = childNodesToTraverse.front();
        TokenInformationForParseTree tokenInfo = childNode.GetTokenInformationForNode();
        if (tokenInfo._tokenType == TokenType::CellToken)
        {
            std::wstring outputValueForReference;
            LibExcelFormulaError outputError = LibExcelFormulaError::None;
            const std::wstring_view referenceInformation = tokenInfo._tokenData;
            inputCallbackFunction(referenceInformation, outputValueForReference, outputError);
            if (outputError == LibExcelFormulaError::DataReferenceError)
            {
                return outputError;
            }
            outputReferenceCache.emplace(std::make_pair(referenceInformation, outputValueForReference));
        }
        for (ExcelFormulaParseTreeNode node: childNode.GetChildNodes())
        {
            childNodesToTraverse.emplace(node);
        }
        childNodesToTraverse.pop();
    }

    return LibExcelFormulaError::None;
}

std::unique_ptr<IExcelFormulaCallbackManager> ExcelFormula::CreateExcelFormulaCallbackManagerInstance()
{
    return std::make_unique<ExcelFormulaCallbackManager>();
}