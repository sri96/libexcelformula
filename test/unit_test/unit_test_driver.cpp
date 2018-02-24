#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "../../thirdparty/catch/catch.hpp" // TODO - Add include paths to CMake to avoid using relative paths
#include "list_of_ut_folders.hpp" // Contains a list of .hpp files that hold the actual UTs from each folder


// This is an empty file by design. This cpp file only provides the driver for running UTs. Actual UTs
// are found inside folders.