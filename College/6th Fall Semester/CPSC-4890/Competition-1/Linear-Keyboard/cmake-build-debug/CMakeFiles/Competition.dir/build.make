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
CMAKE_COMMAND = "/Users/gavintaylormcroy/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-1/211.7628.27/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/gavintaylormcroy/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-1/211.7628.27/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gavintaylormcroy/Desktop/Competition

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gavintaylormcroy/Desktop/Competition/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Competition.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Competition.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Competition.dir/flags.make

CMakeFiles/Competition.dir/main.cpp.o: CMakeFiles/Competition.dir/flags.make
CMakeFiles/Competition.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gavintaylormcroy/Desktop/Competition/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Competition.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Competition.dir/main.cpp.o -c /Users/gavintaylormcroy/Desktop/Competition/main.cpp

CMakeFiles/Competition.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Competition.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gavintaylormcroy/Desktop/Competition/main.cpp > CMakeFiles/Competition.dir/main.cpp.i

CMakeFiles/Competition.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Competition.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gavintaylormcroy/Desktop/Competition/main.cpp -o CMakeFiles/Competition.dir/main.cpp.s

# Object files for target Competition
Competition_OBJECTS = \
"CMakeFiles/Competition.dir/main.cpp.o"

# External object files for target Competition
Competition_EXTERNAL_OBJECTS =

Competition: CMakeFiles/Competition.dir/main.cpp.o
Competition: CMakeFiles/Competition.dir/build.make
Competition: CMakeFiles/Competition.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gavintaylormcroy/Desktop/Competition/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Competition"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Competition.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Competition.dir/build: Competition

.PHONY : CMakeFiles/Competition.dir/build

CMakeFiles/Competition.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Competition.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Competition.dir/clean

CMakeFiles/Competition.dir/depend:
	cd /Users/gavintaylormcroy/Desktop/Competition/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gavintaylormcroy/Desktop/Competition /Users/gavintaylormcroy/Desktop/Competition /Users/gavintaylormcroy/Desktop/Competition/cmake-build-debug /Users/gavintaylormcroy/Desktop/Competition/cmake-build-debug /Users/gavintaylormcroy/Desktop/Competition/cmake-build-debug/CMakeFiles/Competition.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Competition.dir/depend

