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
CMAKE_SOURCE_DIR = /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-3/Masking

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-3/Masking/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Masking.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Masking.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Masking.dir/flags.make

CMakeFiles/Masking.dir/main.cpp.o: CMakeFiles/Masking.dir/flags.make
CMakeFiles/Masking.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-3/Masking/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Masking.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Masking.dir/main.cpp.o -c /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-3/Masking/main.cpp

CMakeFiles/Masking.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Masking.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-3/Masking/main.cpp > CMakeFiles/Masking.dir/main.cpp.i

CMakeFiles/Masking.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Masking.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-3/Masking/main.cpp -o CMakeFiles/Masking.dir/main.cpp.s

CMakeFiles/Masking.dir/Masking.cpp.o: CMakeFiles/Masking.dir/flags.make
CMakeFiles/Masking.dir/Masking.cpp.o: ../Masking.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-3/Masking/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Masking.dir/Masking.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Masking.dir/Masking.cpp.o -c /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-3/Masking/Masking.cpp

CMakeFiles/Masking.dir/Masking.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Masking.dir/Masking.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-3/Masking/Masking.cpp > CMakeFiles/Masking.dir/Masking.cpp.i

CMakeFiles/Masking.dir/Masking.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Masking.dir/Masking.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-3/Masking/Masking.cpp -o CMakeFiles/Masking.dir/Masking.cpp.s

# Object files for target Masking
Masking_OBJECTS = \
"CMakeFiles/Masking.dir/main.cpp.o" \
"CMakeFiles/Masking.dir/Masking.cpp.o"

# External object files for target Masking
Masking_EXTERNAL_OBJECTS =

Masking: CMakeFiles/Masking.dir/main.cpp.o
Masking: CMakeFiles/Masking.dir/Masking.cpp.o
Masking: CMakeFiles/Masking.dir/build.make
Masking: /usr/local/Cellar/openimageio/2.2.17.0/lib/libOpenImageIO.2.2.17.dylib
Masking: /usr/local/lib/libboost_filesystem-mt.dylib
Masking: /usr/local/lib/libboost_system-mt.dylib
Masking: CMakeFiles/Masking.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-3/Masking/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Masking"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Masking.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Masking.dir/build: Masking

.PHONY : CMakeFiles/Masking.dir/build

CMakeFiles/Masking.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Masking.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Masking.dir/clean

CMakeFiles/Masking.dir/depend:
	cd /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-3/Masking/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-3/Masking /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-3/Masking /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-3/Masking/cmake-build-debug /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-3/Masking/cmake-build-debug /Users/gavintaylormcroy/Documents/GitHub/School-Rep/CPSC-4040/Project-3/Masking/cmake-build-debug/CMakeFiles/Masking.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Masking.dir/depend

