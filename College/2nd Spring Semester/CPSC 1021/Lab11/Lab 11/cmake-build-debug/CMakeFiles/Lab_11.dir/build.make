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
CMAKE_SOURCE_DIR = "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Lab_11.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab_11.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab_11.dir/flags.make

CMakeFiles/Lab_11.dir/main.cpp.obj: CMakeFiles/Lab_11.dir/flags.make
CMakeFiles/Lab_11.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab_11.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab_11.dir\main.cpp.obj -c "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11\main.cpp"

CMakeFiles/Lab_11.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_11.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11\main.cpp" > CMakeFiles\Lab_11.dir\main.cpp.i

CMakeFiles/Lab_11.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_11.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11\main.cpp" -o CMakeFiles\Lab_11.dir\main.cpp.s

CMakeFiles/Lab_11.dir/Animal.cpp.obj: CMakeFiles/Lab_11.dir/flags.make
CMakeFiles/Lab_11.dir/Animal.cpp.obj: ../Animal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lab_11.dir/Animal.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab_11.dir\Animal.cpp.obj -c "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11\Animal.cpp"

CMakeFiles/Lab_11.dir/Animal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_11.dir/Animal.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11\Animal.cpp" > CMakeFiles\Lab_11.dir\Animal.cpp.i

CMakeFiles/Lab_11.dir/Animal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_11.dir/Animal.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11\Animal.cpp" -o CMakeFiles\Lab_11.dir\Animal.cpp.s

CMakeFiles/Lab_11.dir/Monkey.cpp.obj: CMakeFiles/Lab_11.dir/flags.make
CMakeFiles/Lab_11.dir/Monkey.cpp.obj: ../Monkey.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Lab_11.dir/Monkey.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab_11.dir\Monkey.cpp.obj -c "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11\Monkey.cpp"

CMakeFiles/Lab_11.dir/Monkey.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_11.dir/Monkey.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11\Monkey.cpp" > CMakeFiles\Lab_11.dir\Monkey.cpp.i

CMakeFiles/Lab_11.dir/Monkey.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_11.dir/Monkey.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11\Monkey.cpp" -o CMakeFiles\Lab_11.dir\Monkey.cpp.s

CMakeFiles/Lab_11.dir/Tiger.cpp.obj: CMakeFiles/Lab_11.dir/flags.make
CMakeFiles/Lab_11.dir/Tiger.cpp.obj: ../Tiger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Lab_11.dir/Tiger.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab_11.dir\Tiger.cpp.obj -c "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11\Tiger.cpp"

CMakeFiles/Lab_11.dir/Tiger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab_11.dir/Tiger.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11\Tiger.cpp" > CMakeFiles\Lab_11.dir\Tiger.cpp.i

CMakeFiles/Lab_11.dir/Tiger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab_11.dir/Tiger.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11\Tiger.cpp" -o CMakeFiles\Lab_11.dir\Tiger.cpp.s

# Object files for target Lab_11
Lab_11_OBJECTS = \
"CMakeFiles/Lab_11.dir/main.cpp.obj" \
"CMakeFiles/Lab_11.dir/Animal.cpp.obj" \
"CMakeFiles/Lab_11.dir/Monkey.cpp.obj" \
"CMakeFiles/Lab_11.dir/Tiger.cpp.obj"

# External object files for target Lab_11
Lab_11_EXTERNAL_OBJECTS =

Lab_11.exe: CMakeFiles/Lab_11.dir/main.cpp.obj
Lab_11.exe: CMakeFiles/Lab_11.dir/Animal.cpp.obj
Lab_11.exe: CMakeFiles/Lab_11.dir/Monkey.cpp.obj
Lab_11.exe: CMakeFiles/Lab_11.dir/Tiger.cpp.obj
Lab_11.exe: CMakeFiles/Lab_11.dir/build.make
Lab_11.exe: CMakeFiles/Lab_11.dir/linklibs.rsp
Lab_11.exe: CMakeFiles/Lab_11.dir/objects1.rsp
Lab_11.exe: CMakeFiles/Lab_11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Lab_11.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lab_11.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab_11.dir/build: Lab_11.exe

.PHONY : CMakeFiles/Lab_11.dir/build

CMakeFiles/Lab_11.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab_11.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lab_11.dir/clean

CMakeFiles/Lab_11.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11" "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11" "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11\cmake-build-debug" "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11\cmake-build-debug" "C:\Users\Gavin McRoy\Desktop\GitHubProjects\Lab 11\cmake-build-debug\CMakeFiles\Lab_11.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Lab_11.dir/depend

