#pragma once

#ifndef EXCEL_FORMULA_CALLBACK_MANAGER_H
#define EXCEL_FORMULA_CALLBACK_MANAGER_H

#include "i_excel_formula_callback_manager.h"

namespace ExcelFormula
{
    class ExcelFormulaCallbackManager : public IExcelFormulaCallbackManager
    {
        public:
            LibExcelFormulaError ResolveReferences(Parser::ExcelFormulaParseTree& inputFormulaParseTree, 
            const std::function<void(const std::wstring_view, std::wstring&, LibExcelFormulaError&)>& inputCallbackFunction,
            std::unordered_map<std::wstring_view, std::wstring>& outputReferenceCache) const noexcept;
    };
};

#endif