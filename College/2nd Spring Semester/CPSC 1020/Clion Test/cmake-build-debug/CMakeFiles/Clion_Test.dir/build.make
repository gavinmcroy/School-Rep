# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Users\Gavin McRoy\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-1\201.7223.86\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\Gavin McRoy\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-1\201.7223.86\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Gavin McRoy\Desktop\Clion Test"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Gavin McRoy\Desktop\Clion Test\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Clion_Test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Clion_Test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Clion_Test.dir/flags.make

CMakeFiles/Clion_Test.dir/main.cpp.obj: CMakeFiles/Clion_Test.dir/flags.make
CMakeFiles/Clion_Test.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gavin McRoy\Desktop\Clion Test\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Clion_Test.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Clion_Test.dir\main.cpp.obj -c "C:\Users\Gavin McRoy\Desktop\Clion Test\main.cpp"

CMakeFiles/Clion_Test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Clion_Test.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gavin McRoy\Desktop\Clion Test\main.cpp" > CMakeFiles\Clion_Test.dir\main.cpp.i

CMakeFiles/Clion_Test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Clion_Test.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gavin McRoy\Desktop\Clion Test\main.cpp" -o CMakeFiles\Clion_Test.dir\main.cpp.s

# Object files for target Clion_Test
Clion_Test_OBJECTS = \
"CMakeFiles/Clion_Test.dir/main.cpp.obj"

# External object files for target Clion_Test
Clion_Test_EXTERNAL_OBJECTS =

Clion_Test.exe: CMakeFiles/Clion_Test.dir/main.cpp.obj
Clion_Test.exe: CMakeFiles/Clion_Test.dir/build.make
Clion_Test.exe: CMakeFiles/Clion_Test.dir/linklibs.rsp
Clion_Test.exe: CMakeFiles/Clion_Test.dir/objects1.rsp
Clion_Test.exe: CMakeFiles/Clion_Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Gavin McRoy\Desktop\Clion Test\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Clion_Test.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Clion_Test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Clion_Test.dir/build: Clion_Test.exe

.PHONY : CMakeFiles/Clion_Test.dir/build

CMakeFiles/Clion_Test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Clion_Test.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Clion_Test.dir/clean

CMakeFiles/Clion_Test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Gavin McRoy\Desktop\Clion Test" "C:\Users\Gavin McRoy\Desktop\Clion Test" "C:\Users\Gavin McRoy\Desktop\Clion Test\cmake-build-debug" "C:\Users\Gavin McRoy\Desktop\Clion Test\cmake-build-debug" "C:\Users\Gavin McRoy\Desktop\Clion Test\cmake-build-debug\CMakeFiles\Clion_Test.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Clion_Test.dir/depend

