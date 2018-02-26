cmake_minimum_required(VERSION 3.10.1)

project(libexcelformula)

message("Building a static library with high levels of optimization, address and leak sanitization and high levels of warnings")
set(CMAKE_CXX_FLAGS "-std=c++1z -o3 -fsanitize=address -Weverything -Wno-unreachable-code-break -Wno-covered-switch-default -Wno-pessimizing-move -Wno-newline-eof -Wno-non-virtual-dtor -Wno-missing-prototypes -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-weak-vtables -Wno-padded -Wno-exit-time-destructors -Wno-global-constructors")

add_library(excelformula 
            ../src/formula_evaluator/excel_formula_evaluator.cpp 
            ../src/formula_lexer/excel_formula_lexer.cpp
            ../src/formula_lexer/tokens/equal_operation_token.cpp
            ../src/formula_lexer/tokens/open_curly_paren_token.cpp
            ../src/formula_lexer/tokens/close_curly_paren_token.cpp
            ../src/formula_lexer/tokens/open_paren_token.cpp
            ../src/formula_lexer/tokens/close_paren_token.cpp
            ../src/formula_lexer/tokens/excel_function_token.cpp
            ../src/formula_lexer/tokens/comma_token.cpp
            ../src/formula_lexer/tokens/integer_token.cpp
            ../src/formula_lexer/tokens/cell_token.cpp
            ../src/formula_parser/excel_formula_parser.cpp
            ../src/shared/excel_formula_parse_tree_node.cpp
            ../src/shared/excel_formula_parse_tree.cpp
            ../src/formula_callback_manager/excel_formula_callback_manager.cpp 
            ../src/parse_tree_executor/excel_formula_parse_tree_executor.cpp)

install(TARGETS excelformula DESTINATION lib)
install(FILES ../include/libexcelformula/libexcelformula.h ../include/libexcelformula/libexcelformulaerror.h DESTINATION include)
