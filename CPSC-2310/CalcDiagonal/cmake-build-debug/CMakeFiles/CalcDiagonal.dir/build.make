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
CMAKE_SOURCE_DIR = /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-2310/CalcDiagonal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-2310/CalcDiagonal/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CalcDiagonal.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CalcDiagonal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CalcDiagonal.dir/flags.make

CMakeFiles/CalcDiagonal.dir/driver.c.o: CMakeFiles/CalcDiagonal.dir/flags.make
CMakeFiles/CalcDiagonal.dir/driver.c.o: ../driver.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gavintaylormcroy/Desktop/School-Rep/CPSC-2310/CalcDiagonal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/CalcDiagonal.dir/driver.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CalcDiagonal.dir/driver.c.o -c /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-2310/CalcDiagonal/driver.c

CMakeFiles/CalcDiagonal.dir/driver.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CalcDiagonal.dir/driver.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-2310/CalcDiagonal/driver.c > CMakeFiles/CalcDiagonal.dir/driver.c.i

CMakeFiles/CalcDiagonal.dir/driver.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CalcDiagonal.dir/driver.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-2310/CalcDiagonal/driver.c -o CMakeFiles/CalcDiagonal.dir/driver.c.s

CMakeFiles/CalcDiagonal.dir/diagonal.c.o: CMakeFiles/CalcDiagonal.dir/flags.make
CMakeFiles/CalcDiagonal.dir/diagonal.c.o: ../diagonal.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gavintaylormcroy/Desktop/School-Rep/CPSC-2310/CalcDiagonal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/CalcDiagonal.dir/diagonal.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/CalcDiagonal.dir/diagonal.c.o -c /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-2310/CalcDiagonal/diagonal.c

CMakeFiles/CalcDiagonal.dir/diagonal.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/CalcDiagonal.dir/diagonal.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-2310/CalcDiagonal/diagonal.c > CMakeFiles/CalcDiagonal.dir/diagonal.c.i

CMakeFiles/CalcDiagonal.dir/diagonal.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/CalcDiagonal.dir/diagonal.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-2310/CalcDiagonal/diagonal.c -o CMakeFiles/CalcDiagonal.dir/diagonal.c.s

# Object files for target CalcDiagonal
CalcDiagonal_OBJECTS = \
"CMakeFiles/CalcDiagonal.dir/driver.c.o" \
"CMakeFiles/CalcDiagonal.dir/diagonal.c.o"

# External object files for target CalcDiagonal
CalcDiagonal_EXTERNAL_OBJECTS =

CalcDiagonal: CMakeFiles/CalcDiagonal.dir/driver.c.o
CalcDiagonal: CMakeFiles/CalcDiagonal.dir/diagonal.c.o
CalcDiagonal: CMakeFiles/CalcDiagonal.dir/build.make
CalcDiagonal: CMakeFiles/CalcDiagonal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gavintaylormcroy/Desktop/School-Rep/CPSC-2310/CalcDiagonal/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable CalcDiagonal"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CalcDiagonal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CalcDiagonal.dir/build: CalcDiagonal

.PHONY : CMakeFiles/CalcDiagonal.dir/build

CMakeFiles/CalcDiagonal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CalcDiagonal.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CalcDiagonal.dir/clean

CMakeFiles/CalcDiagonal.dir/depend:
	cd /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-2310/CalcDiagonal/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-2310/CalcDiagonal /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-2310/CalcDiagonal /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-2310/CalcDiagonal/cmake-build-debug /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-2310/CalcDiagonal/cmake-build-debug /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-2310/CalcDiagonal/cmake-build-debug/CMakeFiles/CalcDiagonal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CalcDiagonal.dir/depend

