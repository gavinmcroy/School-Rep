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
CMAKE_SOURCE_DIR = /Users/gavintaylormcroy/Desktop/Format

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gavintaylormcroy/Desktop/Format/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Format.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Format.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Format.dir/flags.make

CMakeFiles/Format.dir/main.cpp.o: CMakeFiles/Format.dir/flags.make
CMakeFiles/Format.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gavintaylormcroy/Desktop/Format/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Format.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Format.dir/main.cpp.o -c /Users/gavintaylormcroy/Desktop/Format/main.cpp

CMakeFiles/Format.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Format.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gavintaylormcroy/Desktop/Format/main.cpp > CMakeFiles/Format.dir/main.cpp.i

CMakeFiles/Format.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Format.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gavintaylormcroy/Desktop/Format/main.cpp -o CMakeFiles/Format.dir/main.cpp.s

# Object files for target Format
Format_OBJECTS = \
"CMakeFiles/Format.dir/main.cpp.o"

# External object files for target Format
Format_EXTERNAL_OBJECTS =

Format: CMakeFiles/Format.dir/main.cpp.o
Format: CMakeFiles/Format.dir/build.make
Format: CMakeFiles/Format.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gavintaylormcroy/Desktop/Format/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Format"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Format.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Format.dir/build: Format

.PHONY : CMakeFiles/Format.dir/build

CMakeFiles/Format.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Format.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Format.dir/clean

CMakeFiles/Format.dir/depend:
	cd /Users/gavintaylormcroy/Desktop/Format/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gavintaylormcroy/Desktop/Format /Users/gavintaylormcroy/Desktop/Format /Users/gavintaylormcroy/Desktop/Format/cmake-build-debug /Users/gavintaylormcroy/Desktop/Format/cmake-build-debug /Users/gavintaylormcroy/Desktop/Format/cmake-build-debug/CMakeFiles/Format.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Format.dir/depend

