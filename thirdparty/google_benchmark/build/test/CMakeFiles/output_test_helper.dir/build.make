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
include test/CMakeFiles/output_test_helper.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/output_test_helper.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/output_test_helper.dir/flags.make

test/CMakeFiles/output_test_helper.dir/output_test_helper.cc.o: test/CMakeFiles/output_test_helper.dir/flags.make
test/CMakeFiles/output_test_helper.dir/output_test_helper.cc.o: /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/benchmark/test/output_test_helper.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/output_test_helper.dir/output_test_helper.cc.o"
	cd /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/output_test_helper.dir/output_test_helper.cc.o -c /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/benchmark/test/output_test_helper.cc

test/CMakeFiles/output_test_helper.dir/output_test_helper.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/output_test_helper.dir/output_test_helper.cc.i"
	cd /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/benchmark/test/output_test_helper.cc > CMakeFiles/output_test_helper.dir/output_test_helper.cc.i

test/CMakeFiles/output_test_helper.dir/output_test_helper.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/output_test_helper.dir/output_test_helper.cc.s"
	cd /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build/test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/benchmark/test/output_test_helper.cc -o CMakeFiles/output_test_helper.dir/output_test_helper.cc.s

test/CMakeFiles/output_test_helper.dir/output_test_helper.cc.o.requires:

.PHONY : test/CMakeFiles/output_test_helper.dir/output_test_helper.cc.o.requires

test/CMakeFiles/output_test_helper.dir/output_test_helper.cc.o.provides: test/CMakeFiles/output_test_helper.dir/output_test_helper.cc.o.requires
	$(MAKE) -f test/CMakeFiles/output_test_helper.dir/build.make test/CMakeFiles/output_test_helper.dir/output_test_helper.cc.o.provides.build
.PHONY : test/CMakeFiles/output_test_helper.dir/output_test_helper.cc.o.provides

test/CMakeFiles/output_test_helper.dir/output_test_helper.cc.o.provides.build: test/CMakeFiles/output_test_helper.dir/output_test_helper.cc.o


# Object files for target output_test_helper
output_test_helper_OBJECTS = \
"CMakeFiles/output_test_helper.dir/output_test_helper.cc.o"

# External object files for target output_test_helper
output_test_helper_EXTERNAL_OBJECTS =

test/liboutput_test_helper.a: test/CMakeFiles/output_test_helper.dir/output_test_helper.cc.o
test/liboutput_test_helper.a: test/CMakeFiles/output_test_helper.dir/build.make
test/liboutput_test_helper.a: test/CMakeFiles/output_test_helper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liboutput_test_helper.a"
	cd /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build/test && $(CMAKE_COMMAND) -P CMakeFiles/output_test_helper.dir/cmake_clean_target.cmake
	cd /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/output_test_helper.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/output_test_helper.dir/build: test/liboutput_test_helper.a

.PHONY : test/CMakeFiles/output_test_helper.dir/build

test/CMakeFiles/output_test_helper.dir/requires: test/CMakeFiles/output_test_helper.dir/output_test_helper.cc.o.requires

.PHONY : test/CMakeFiles/output_test_helper.dir/requires

test/CMakeFiles/output_test_helper.dir/clean:
	cd /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build/test && $(CMAKE_COMMAND) -P CMakeFiles/output_test_helper.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/output_test_helper.dir/clean

test/CMakeFiles/output_test_helper.dir/depend:
	cd /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/benchmark /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/benchmark/test /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build/test /Users/adhithya/Documents/libexcelformula/thirdparty/google_benchmark/build/test/CMakeFiles/output_test_helper.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/output_test_helper.dir/depend

