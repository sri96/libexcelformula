#pragma once

#ifndef LIST_OF_PERF_TEST_FOLDERS_HPP
#define LIST_OF_PERF_TEST_FOLDERS_HPP

#include <benchmark/benchmark.h>

// Just a dummy test to make sure that this code compiles and links successfully
static void BM_StringCreation(benchmark::State& state) {
  for (auto _ : state)
    std::string empty_string;
}
// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

#endif