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
CMAKE_SOURCE_DIR = /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-4/convolve

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-4/convolve/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Open_Test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Open_Test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Open_Test.dir/flags.make

CMakeFiles/Open_Test.dir/main.cpp.o: CMakeFiles/Open_Test.dir/flags.make
CMakeFiles/Open_Test.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-4/convolve/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Open_Test.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Open_Test.dir/main.cpp.o -c /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-4/convolve/main.cpp

CMakeFiles/Open_Test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Open_Test.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-4/convolve/main.cpp > CMakeFiles/Open_Test.dir/main.cpp.i

CMakeFiles/Open_Test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Open_Test.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-4/convolve/main.cpp -o CMakeFiles/Open_Test.dir/main.cpp.s

# Object files for target Open_Test
Open_Test_OBJECTS = \
"CMakeFiles/Open_Test.dir/main.cpp.o"

# External object files for target Open_Test
Open_Test_EXTERNAL_OBJECTS =

Open_Test: CMakeFiles/Open_Test.dir/main.cpp.o
Open_Test: CMakeFiles/Open_Test.dir/build.make
Open_Test: /usr/local/lib/libboost_filesystem-mt.dylib
Open_Test: /usr/local/lib/libboost_system-mt.dylib
Open_Test: /usr/local/Cellar/openimageio/2.2.18.0/lib/libOpenImageIO.2.2.18.dylib
Open_Test: CMakeFiles/Open_Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-4/convolve/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Open_Test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Open_Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Open_Test.dir/build: Open_Test

.PHONY : CMakeFiles/Open_Test.dir/build

CMakeFiles/Open_Test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Open_Test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Open_Test.dir/clean

CMakeFiles/Open_Test.dir/depend:
	cd /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-4/convolve/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-4/convolve /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-4/convolve /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-4/convolve/cmake-build-debug /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-4/convolve/cmake-build-debug /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-4/convolve/cmake-build-debug/CMakeFiles/Open_Test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Open_Test.dir/depend

