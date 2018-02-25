#pragma once

#ifndef I_EXCEL_FORMULA_CALLBACK_MANAGER_H
#define I_EXCEL_FORMULA_CALLBACK_MANAGER_H

#include <functional>
#include <memory>
#include <string>
#include <string_view>

#include "../../include/libexcelformula/libexcelformulaerror.h"
#include "../shared/i_excel_formula_parse_tree.h"

namespace ExcelFormula
{
    class IExcelFormulaCallbackManager
    {
        public:
            virtual LibExcelFormulaError ResolveReferences(Parser::IExcelFormulaParseTree& inputFormulaParseTree, const std::function<void(const std::wstring_view, std::wstring&, LibExcelFormulaError&)>& inputCallbackFunction) const noexcept = 0;
    };

    std::unique_ptr<IExcelFormulaCallbackManager> CreateExcelFormulaCallbackManagerInstance();
};

#endif