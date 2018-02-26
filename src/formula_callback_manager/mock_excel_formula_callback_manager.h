#pragma once

#ifndef EXCEL_FORMULA_CALLBACK_MANAGER_H
#define EXCEL_FORMULA_CALLBACK_MANAGER_H

#include "i_excel_formula_callback_manager.h"

namespace ExcelFormula
{
    class MockExcelFormulaCallbackManager : public IExcelFormulaCallbackManager
    {
        LibExcelFormulaError _outputError;

        public:
            LibExcelFormulaError ResolveReferences(Parser::ExcelFormulaParseTree& inputFormulaParseTree, const std::function<void(const std::wstring_view, std::wstring&, LibExcelFormulaError&)>& inputCallbackFunction) const noexcept;
            void PopulateData();
    };
};

#endif