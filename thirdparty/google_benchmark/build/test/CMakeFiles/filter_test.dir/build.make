# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.10.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.10.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/benchmark

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build

# Include any dependencies generated for this target.
include test/CMakeFiles/filter_test.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/filter_test.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/filter_test.dir/flags.make

test/CMakeFiles/filter_test.dir/filter_test.cc.o: test/CMakeFiles/filter_test.dir/flags.make
test/CMakeFiles/filter_test.dir/filter_test.cc.o: /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/benchmark/test/filter_test.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/filter_test.dir/filter_test.cc.o"
	cd /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/filter_test.dir/filter_test.cc.o -c /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/benchmark/test/filter_test.cc

test/CMakeFiles/filter_test.dir/filter_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/filter_test.dir/filter_test.cc.i"
	cd /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/benchmark/test/filter_test.cc > CMakeFiles/filter_test.dir/filter_test.cc.i

test/CMakeFiles/filter_test.dir/filter_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/filter_test.dir/filter_test.cc.s"
	cd /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/benchmark/test/filter_test.cc -o CMakeFiles/filter_test.dir/filter_test.cc.s

test/CMakeFiles/filter_test.dir/filter_test.cc.o.requires:

.PHONY : test/CMakeFiles/filter_test.dir/filter_test.cc.o.requires

test/CMakeFiles/filter_test.dir/filter_test.cc.o.provides: test/CMakeFiles/filter_test.dir/filter_test.cc.o.requires
	$(MAKE) -f test/CMakeFiles/filter_test.dir/build.make test/CMakeFiles/filter_test.dir/filter_test.cc.o.provides.build
.PHONY : test/CMakeFiles/filter_test.dir/filter_test.cc.o.provides

test/CMakeFiles/filter_test.dir/filter_test.cc.o.provides.build: test/CMakeFiles/filter_test.dir/filter_test.cc.o


# Object files for target filter_test
filter_test_OBJECTS = \
"CMakeFiles/filter_test.dir/filter_test.cc.o"

# External object files for target filter_test
filter_test_EXTERNAL_OBJECTS =

test/filter_test: test/CMakeFiles/filter_test.dir/filter_test.cc.o
test/filter_test: test/CMakeFiles/filter_test.dir/build.make
test/filter_test: src/libbenchmark.a
test/filter_test: test/CMakeFiles/filter_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable filter_test"
	cd /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/filter_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/filter_test.dir/build: test/filter_test

.PHONY : test/CMakeFiles/filter_test.dir/build

test/CMakeFiles/filter_test.dir/requires: test/CMakeFiles/filter_test.dir/filter_test.cc.o.requires

.PHONY : test/CMakeFiles/filter_test.dir/requires

test/CMakeFiles/filter_test.dir/clean:
	cd /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build/test && $(CMAKE_COMMAND) -P CMakeFiles/filter_test.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/filter_test.dir/clean

test/CMakeFiles/filter_test.dir/depend:
	cd /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/benchmark /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/benchmark/test /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build/test /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build/test/CMakeFiles/filter_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/filter_test.dir/depend

