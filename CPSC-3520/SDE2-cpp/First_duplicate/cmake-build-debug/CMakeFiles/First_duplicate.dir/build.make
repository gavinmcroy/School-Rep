# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Users/gavintaylormcroy/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/211.7442.42/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/gavintaylormcroy/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/211.7442.42/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gavintaylormcroy/Desktop/SDE2/First_duplicate

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gavintaylormcroy/Desktop/SDE2/First_duplicate/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/First_duplicate.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/First_duplicate.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/First_duplicate.dir/flags.make

CMakeFiles/First_duplicate.dir/main.cpp.o: CMakeFiles/First_duplicate.dir/flags.make
CMakeFiles/First_duplicate.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gavintaylormcroy/Desktop/SDE2/First_duplicate/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/First_duplicate.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/First_duplicate.dir/main.cpp.o -c /Users/gavintaylormcroy/Desktop/SDE2/First_duplicate/main.cpp

CMakeFiles/First_duplicate.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/First_duplicate.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gavintaylormcroy/Desktop/SDE2/First_duplicate/main.cpp > CMakeFiles/First_duplicate.dir/main.cpp.i

CMakeFiles/First_duplicate.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/First_duplicate.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gavintaylormcroy/Desktop/SDE2/First_duplicate/main.cpp -o CMakeFiles/First_duplicate.dir/main.cpp.s

# Object files for target First_duplicate
First_duplicate_OBJECTS = \
"CMakeFiles/First_duplicate.dir/main.cpp.o"

# External object files for target First_duplicate
First_duplicate_EXTERNAL_OBJECTS =

First_duplicate: CMakeFiles/First_duplicate.dir/main.cpp.o
First_duplicate: CMakeFiles/First_duplicate.dir/build.make
First_duplicate: CMakeFiles/First_duplicate.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gavintaylormcroy/Desktop/SDE2/First_duplicate/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable First_duplicate"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/First_duplicate.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/First_duplicate.dir/build: First_duplicate

.PHONY : CMakeFiles/First_duplicate.dir/build

CMakeFiles/First_duplicate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/First_duplicate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/First_duplicate.dir/clean

CMakeFiles/First_duplicate.dir/depend:
	cd /Users/gavintaylormcroy/Desktop/SDE2/First_duplicate/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gavintaylormcroy/Desktop/SDE2/First_duplicate /Users/gavintaylormcroy/Desktop/SDE2/First_duplicate /Users/gavintaylormcroy/Desktop/SDE2/First_duplicate/cmake-build-debug /Users/gavintaylormcroy/Desktop/SDE2/First_duplicate/cmake-build-debug /Users/gavintaylormcroy/Desktop/SDE2/First_duplicate/cmake-build-debug/CMakeFiles/First_duplicate.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/First_duplicate.dir/depend

