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
CMAKE_SOURCE_DIR = /Users/gavintaylormcroy/Desktop/School-Rep/Leet-Code/Array-101/Introduction/Max-Consecutive-Ones

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gavintaylormcroy/Desktop/School-Rep/Leet-Code/Array-101/Introduction/Max-Consecutive-Ones/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Max_Consecutive_Ones.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Max_Consecutive_Ones.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Max_Consecutive_Ones.dir/flags.make

CMakeFiles/Max_Consecutive_Ones.dir/main.cpp.o: CMakeFiles/Max_Consecutive_Ones.dir/flags.make
CMakeFiles/Max_Consecutive_Ones.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gavintaylormcroy/Desktop/School-Rep/Leet-Code/Array-101/Introduction/Max-Consecutive-Ones/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Max_Consecutive_Ones.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Max_Consecutive_Ones.dir/main.cpp.o -c /Users/gavintaylormcroy/Desktop/School-Rep/Leet-Code/Array-101/Introduction/Max-Consecutive-Ones/main.cpp

CMakeFiles/Max_Consecutive_Ones.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Max_Consecutive_Ones.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gavintaylormcroy/Desktop/School-Rep/Leet-Code/Array-101/Introduction/Max-Consecutive-Ones/main.cpp > CMakeFiles/Max_Consecutive_Ones.dir/main.cpp.i

CMakeFiles/Max_Consecutive_Ones.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Max_Consecutive_Ones.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gavintaylormcroy/Desktop/School-Rep/Leet-Code/Array-101/Introduction/Max-Consecutive-Ones/main.cpp -o CMakeFiles/Max_Consecutive_Ones.dir/main.cpp.s

# Object files for target Max_Consecutive_Ones
Max_Consecutive_Ones_OBJECTS = \
"CMakeFiles/Max_Consecutive_Ones.dir/main.cpp.o"

# External object files for target Max_Consecutive_Ones
Max_Consecutive_Ones_EXTERNAL_OBJECTS =

Max_Consecutive_Ones: CMakeFiles/Max_Consecutive_Ones.dir/main.cpp.o
Max_Consecutive_Ones: CMakeFiles/Max_Consecutive_Ones.dir/build.make
Max_Consecutive_Ones: CMakeFiles/Max_Consecutive_Ones.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gavintaylormcroy/Desktop/School-Rep/Leet-Code/Array-101/Introduction/Max-Consecutive-Ones/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Max_Consecutive_Ones"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Max_Consecutive_Ones.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Max_Consecutive_Ones.dir/build: Max_Consecutive_Ones

.PHONY : CMakeFiles/Max_Consecutive_Ones.dir/build

CMakeFiles/Max_Consecutive_Ones.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Max_Consecutive_Ones.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Max_Consecutive_Ones.dir/clean

CMakeFiles/Max_Consecutive_Ones.dir/depend:
	cd /Users/gavintaylormcroy/Desktop/School-Rep/Leet-Code/Array-101/Introduction/Max-Consecutive-Ones/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gavintaylormcroy/Desktop/School-Rep/Leet-Code/Array-101/Introduction/Max-Consecutive-Ones /Users/gavintaylormcroy/Desktop/School-Rep/Leet-Code/Array-101/Introduction/Max-Consecutive-Ones /Users/gavintaylormcroy/Desktop/School-Rep/Leet-Code/Array-101/Introduction/Max-Consecutive-Ones/cmake-build-debug /Users/gavintaylormcroy/Desktop/School-Rep/Leet-Code/Array-101/Introduction/Max-Consecutive-Ones/cmake-build-debug /Users/gavintaylormcroy/Desktop/School-Rep/Leet-Code/Array-101/Introduction/Max-Consecutive-Ones/cmake-build-debug/CMakeFiles/Max_Consecutive_Ones.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Max_Consecutive_Ones.dir/depend

