cmake_minimum_required(VERSION 3.10.1)

project(libexcelformula)

message("Building a static library with high levels of optimization, address and leak sanitization and high levels of warnings")
set(CMAKE_CXX_FLAGS "-std=c++1z -o3 -fsanitize=address -Weverything -Wno-non-virtual-dtor -Wno-missing-prototypes -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-weak-vtables -Wno-padded -Wno-exit-time-destructors -Wno-global-constructors")

add_library(excelformula ../src/formula_evaluator/excel_formula_evaluator.cpp)

install(TARGETS excelformula DESTINATION lib)
install(FILES ../include/libexcelformula/libexcelformula.h ../include/libexcelformula/libexcelformulaerror.h DESTINATION include)