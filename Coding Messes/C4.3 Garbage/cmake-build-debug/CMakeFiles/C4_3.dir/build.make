# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "/Users/gavintaylormcroy/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/192.6817.18/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/gavintaylormcroy/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/192.6817.18/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/gavintaylormcroy/Documents/College/CPSC 1010/Chapter 4/C4.3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/gavintaylormcroy/Documents/College/CPSC 1010/Chapter 4/C4.3/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/C4_3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/C4_3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/C4_3.dir/flags.make

CMakeFiles/C4_3.dir/main.c.o: CMakeFiles/C4_3.dir/flags.make
CMakeFiles/C4_3.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/gavintaylormcroy/Documents/College/CPSC 1010/Chapter 4/C4.3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/C4_3.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/C4_3.dir/main.c.o   -c "/Users/gavintaylormcroy/Documents/College/CPSC 1010/Chapter 4/C4.3/main.c"

CMakeFiles/C4_3.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/C4_3.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/gavintaylormcroy/Documents/College/CPSC 1010/Chapter 4/C4.3/main.c" > CMakeFiles/C4_3.dir/main.c.i

CMakeFiles/C4_3.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/C4_3.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/gavintaylormcroy/Documents/College/CPSC 1010/Chapter 4/C4.3/main.c" -o CMakeFiles/C4_3.dir/main.c.s

# Object files for target C4_3
C4_3_OBJECTS = \
"CMakeFiles/C4_3.dir/main.c.o"

# External object files for target C4_3
C4_3_EXTERNAL_OBJECTS =

C4_3: CMakeFiles/C4_3.dir/main.c.o
C4_3: CMakeFiles/C4_3.dir/build.make
C4_3: CMakeFiles/C4_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/gavintaylormcroy/Documents/College/CPSC 1010/Chapter 4/C4.3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable C4_3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/C4_3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/C4_3.dir/build: C4_3

.PHONY : CMakeFiles/C4_3.dir/build

CMakeFiles/C4_3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/C4_3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/C4_3.dir/clean

CMakeFiles/C4_3.dir/depend:
	cd "/Users/gavintaylormcroy/Documents/College/CPSC 1010/Chapter 4/C4.3/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/gavintaylormcroy/Documents/College/CPSC 1010/Chapter 4/C4.3" "/Users/gavintaylormcroy/Documents/College/CPSC 1010/Chapter 4/C4.3" "/Users/gavintaylormcroy/Documents/College/CPSC 1010/Chapter 4/C4.3/cmake-build-debug" "/Users/gavintaylormcroy/Documents/College/CPSC 1010/Chapter 4/C4.3/cmake-build-debug" "/Users/gavintaylormcroy/Documents/College/CPSC 1010/Chapter 4/C4.3/cmake-build-debug/CMakeFiles/C4_3.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/C4_3.dir/depend

