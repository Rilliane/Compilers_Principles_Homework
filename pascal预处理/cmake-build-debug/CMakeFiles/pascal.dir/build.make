# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/christine/Desktop/线上学习汇总/编译原理/pascal预处理

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/christine/Desktop/线上学习汇总/编译原理/pascal预处理/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/pascal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pascal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pascal.dir/flags.make

CMakeFiles/pascal.dir/main.cpp.o: CMakeFiles/pascal.dir/flags.make
CMakeFiles/pascal.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/christine/Desktop/线上学习汇总/编译原理/pascal预处理/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pascal.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pascal.dir/main.cpp.o -c /Users/christine/Desktop/线上学习汇总/编译原理/pascal预处理/main.cpp

CMakeFiles/pascal.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pascal.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/christine/Desktop/线上学习汇总/编译原理/pascal预处理/main.cpp > CMakeFiles/pascal.dir/main.cpp.i

CMakeFiles/pascal.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pascal.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/christine/Desktop/线上学习汇总/编译原理/pascal预处理/main.cpp -o CMakeFiles/pascal.dir/main.cpp.s

# Object files for target pascal
pascal_OBJECTS = \
"CMakeFiles/pascal.dir/main.cpp.o"

# External object files for target pascal
pascal_EXTERNAL_OBJECTS =

pascal: CMakeFiles/pascal.dir/main.cpp.o
pascal: CMakeFiles/pascal.dir/build.make
pascal: CMakeFiles/pascal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/christine/Desktop/线上学习汇总/编译原理/pascal预处理/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable pascal"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pascal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pascal.dir/build: pascal

.PHONY : CMakeFiles/pascal.dir/build

CMakeFiles/pascal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pascal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pascal.dir/clean

CMakeFiles/pascal.dir/depend:
	cd /Users/christine/Desktop/线上学习汇总/编译原理/pascal预处理/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/christine/Desktop/线上学习汇总/编译原理/pascal预处理 /Users/christine/Desktop/线上学习汇总/编译原理/pascal预处理 /Users/christine/Desktop/线上学习汇总/编译原理/pascal预处理/cmake-build-debug /Users/christine/Desktop/线上学习汇总/编译原理/pascal预处理/cmake-build-debug /Users/christine/Desktop/线上学习汇总/编译原理/pascal预处理/cmake-build-debug/CMakeFiles/pascal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pascal.dir/depend

