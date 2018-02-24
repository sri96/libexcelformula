cmake_minimum_required(VERSION 3.10.1)

project(ut)

message("Building ut with high levels of optimization, address and leak sanitization and high levels of warnings")
find_library(EXCEL_FORMULA_LIB excelformula)
if(NOT EXCEL_FORMULA_LIB)
    message(FATAL_ERROR "Excel Formula lib is not found")
endif()
set(CMAKE_CXX_FLAGS "-std=c++1z -o3 -fsanitize=address -Wall -Wextra")
add_executable(ut ../unit_test/unit_test_driver.cpp)
target_link_libraries(ut libexcelformula.a)

set(CMAKE_EXE_LINKER_FLAGS "-lbenchmark")
add_executable(benchmark ../perf_test/perf_test_driver.cpp)