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
CMAKE_COMMAND = "C:\Users\Gavin McRoy\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-1\201.6668.126\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\Gavin McRoy\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-1\201.6668.126\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Assignment_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Assignment_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment_1.dir/flags.make

CMakeFiles/Assignment_1.dir/main.cpp.obj: CMakeFiles/Assignment_1.dir/flags.make
CMakeFiles/Assignment_1.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Assignment_1.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Assignment_1.dir\main.cpp.obj -c "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\main.cpp"

CMakeFiles/Assignment_1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_1.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\main.cpp" > CMakeFiles\Assignment_1.dir\main.cpp.i

CMakeFiles/Assignment_1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_1.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\main.cpp" -o CMakeFiles\Assignment_1.dir\main.cpp.s

CMakeFiles/Assignment_1.dir/ColorPixel.cpp.obj: CMakeFiles/Assignment_1.dir/flags.make
CMakeFiles/Assignment_1.dir/ColorPixel.cpp.obj: ../ColorPixel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Assignment_1.dir/ColorPixel.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Assignment_1.dir\ColorPixel.cpp.obj -c "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\ColorPixel.cpp"

CMakeFiles/Assignment_1.dir/ColorPixel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_1.dir/ColorPixel.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\ColorPixel.cpp" > CMakeFiles\Assignment_1.dir\ColorPixel.cpp.i

CMakeFiles/Assignment_1.dir/ColorPixel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_1.dir/ColorPixel.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\ColorPixel.cpp" -o CMakeFiles\Assignment_1.dir\ColorPixel.cpp.s

CMakeFiles/Assignment_1.dir/GrayPixel.cpp.obj: CMakeFiles/Assignment_1.dir/flags.make
CMakeFiles/Assignment_1.dir/GrayPixel.cpp.obj: ../GrayPixel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Assignment_1.dir/GrayPixel.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Assignment_1.dir\GrayPixel.cpp.obj -c "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\GrayPixel.cpp"

CMakeFiles/Assignment_1.dir/GrayPixel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_1.dir/GrayPixel.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\GrayPixel.cpp" > CMakeFiles\Assignment_1.dir\GrayPixel.cpp.i

CMakeFiles/Assignment_1.dir/GrayPixel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_1.dir/GrayPixel.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\GrayPixel.cpp" -o CMakeFiles\Assignment_1.dir\GrayPixel.cpp.s

CMakeFiles/Assignment_1.dir/Ppm.cpp.obj: CMakeFiles/Assignment_1.dir/flags.make
CMakeFiles/Assignment_1.dir/Ppm.cpp.obj: ../Ppm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Assignment_1.dir/Ppm.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Assignment_1.dir\Ppm.cpp.obj -c "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\Ppm.cpp"

CMakeFiles/Assignment_1.dir/Ppm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_1.dir/Ppm.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\Ppm.cpp" > CMakeFiles\Assignment_1.dir\Ppm.cpp.i

CMakeFiles/Assignment_1.dir/Ppm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_1.dir/Ppm.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\Ppm.cpp" -o CMakeFiles\Assignment_1.dir\Ppm.cpp.s

CMakeFiles/Assignment_1.dir/Pgm.cpp.obj: CMakeFiles/Assignment_1.dir/flags.make
CMakeFiles/Assignment_1.dir/Pgm.cpp.obj: ../Pgm.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Assignment_1.dir/Pgm.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Assignment_1.dir\Pgm.cpp.obj -c "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\Pgm.cpp"

CMakeFiles/Assignment_1.dir/Pgm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_1.dir/Pgm.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\Pgm.cpp" > CMakeFiles\Assignment_1.dir\Pgm.cpp.i

CMakeFiles/Assignment_1.dir/Pgm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_1.dir/Pgm.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\Pgm.cpp" -o CMakeFiles\Assignment_1.dir\Pgm.cpp.s

CMakeFiles/Assignment_1.dir/Refactor.cpp.obj: CMakeFiles/Assignment_1.dir/flags.make
CMakeFiles/Assignment_1.dir/Refactor.cpp.obj: ../Refactor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Assignment_1.dir/Refactor.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Assignment_1.dir\Refactor.cpp.obj -c "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\Refactor.cpp"

CMakeFiles/Assignment_1.dir/Refactor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment_1.dir/Refactor.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\Refactor.cpp" > CMakeFiles\Assignment_1.dir\Refactor.cpp.i

CMakeFiles/Assignment_1.dir/Refactor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment_1.dir/Refactor.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\Refactor.cpp" -o CMakeFiles\Assignment_1.dir\Refactor.cpp.s

# Object files for target Assignment_1
Assignment_1_OBJECTS = \
"CMakeFiles/Assignment_1.dir/main.cpp.obj" \
"CMakeFiles/Assignment_1.dir/ColorPixel.cpp.obj" \
"CMakeFiles/Assignment_1.dir/GrayPixel.cpp.obj" \
"CMakeFiles/Assignment_1.dir/Ppm.cpp.obj" \
"CMakeFiles/Assignment_1.dir/Pgm.cpp.obj" \
"CMakeFiles/Assignment_1.dir/Refactor.cpp.obj"

# External object files for target Assignment_1
Assignment_1_EXTERNAL_OBJECTS =

Assignment_1.exe: CMakeFiles/Assignment_1.dir/main.cpp.obj
Assignment_1.exe: CMakeFiles/Assignment_1.dir/ColorPixel.cpp.obj
Assignment_1.exe: CMakeFiles/Assignment_1.dir/GrayPixel.cpp.obj
Assignment_1.exe: CMakeFiles/Assignment_1.dir/Ppm.cpp.obj
Assignment_1.exe: CMakeFiles/Assignment_1.dir/Pgm.cpp.obj
Assignment_1.exe: CMakeFiles/Assignment_1.dir/Refactor.cpp.obj
Assignment_1.exe: CMakeFiles/Assignment_1.dir/build.make
Assignment_1.exe: CMakeFiles/Assignment_1.dir/linklibs.rsp
Assignment_1.exe: CMakeFiles/Assignment_1.dir/objects1.rsp
Assignment_1.exe: CMakeFiles/Assignment_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable Assignment_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Assignment_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment_1.dir/build: Assignment_1.exe

.PHONY : CMakeFiles/Assignment_1.dir/build

CMakeFiles/Assignment_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Assignment_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Assignment_1.dir/clean

CMakeFiles/Assignment_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2" "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2" "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\cmake-build-debug" "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\cmake-build-debug" "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Assignment 2\cmake-build-debug\CMakeFiles\Assignment_1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Assignment_1.dir/depend

