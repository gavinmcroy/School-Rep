# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Users\Gavin McRoy\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-1\202.7660.37\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\Gavin McRoy\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-1\202.7660.37\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Gavin McRoy\Desktop\School-Rep\CPSC-2121\Lab09"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Gavin McRoy\Desktop\School-Rep\CPSC-2121\Lab09\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Lab09.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab09.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab09.dir/flags.make

CMakeFiles/Lab09.dir/main.cpp.obj: CMakeFiles/Lab09.dir/flags.make
CMakeFiles/Lab09.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gavin McRoy\Desktop\School-Rep\CPSC-2121\Lab09\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab09.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab09.dir\main.cpp.obj -c "C:\Users\Gavin McRoy\Desktop\School-Rep\CPSC-2121\Lab09\main.cpp"

CMakeFiles/Lab09.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab09.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gavin McRoy\Desktop\School-Rep\CPSC-2121\Lab09\main.cpp" > CMakeFiles\Lab09.dir\main.cpp.i

CMakeFiles/Lab09.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab09.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gavin McRoy\Desktop\School-Rep\CPSC-2121\Lab09\main.cpp" -o CMakeFiles\Lab09.dir\main.cpp.s

CMakeFiles/Lab09.dir/FillingJugs.cpp.obj: CMakeFiles/Lab09.dir/flags.make
CMakeFiles/Lab09.dir/FillingJugs.cpp.obj: ../FillingJugs.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Gavin McRoy\Desktop\School-Rep\CPSC-2121\Lab09\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Lab09.dir/FillingJugs.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab09.dir\FillingJugs.cpp.obj -c "C:\Users\Gavin McRoy\Desktop\School-Rep\CPSC-2121\Lab09\FillingJugs.cpp"

CMakeFiles/Lab09.dir/FillingJugs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab09.dir/FillingJugs.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Gavin McRoy\Desktop\School-Rep\CPSC-2121\Lab09\FillingJugs.cpp" > CMakeFiles\Lab09.dir\FillingJugs.cpp.i

CMakeFiles/Lab09.dir/FillingJugs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab09.dir/FillingJugs.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Gavin McRoy\Desktop\School-Rep\CPSC-2121\Lab09\FillingJugs.cpp" -o CMakeFiles\Lab09.dir\FillingJugs.cpp.s

# Object files for target Lab09
Lab09_OBJECTS = \
"CMakeFiles/Lab09.dir/main.cpp.obj" \
"CMakeFiles/Lab09.dir/FillingJugs.cpp.obj"

# External object files for target Lab09
Lab09_EXTERNAL_OBJECTS =

Lab09.exe: CMakeFiles/Lab09.dir/main.cpp.obj
Lab09.exe: CMakeFiles/Lab09.dir/FillingJugs.cpp.obj
Lab09.exe: CMakeFiles/Lab09.dir/build.make
Lab09.exe: CMakeFiles/Lab09.dir/linklibs.rsp
Lab09.exe: CMakeFiles/Lab09.dir/objects1.rsp
Lab09.exe: CMakeFiles/Lab09.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Gavin McRoy\Desktop\School-Rep\CPSC-2121\Lab09\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Lab09.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lab09.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab09.dir/build: Lab09.exe

.PHONY : CMakeFiles/Lab09.dir/build

CMakeFiles/Lab09.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab09.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lab09.dir/clean

CMakeFiles/Lab09.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Gavin McRoy\Desktop\School-Rep\CPSC-2121\Lab09" "C:\Users\Gavin McRoy\Desktop\School-Rep\CPSC-2121\Lab09" "C:\Users\Gavin McRoy\Desktop\School-Rep\CPSC-2121\Lab09\cmake-build-debug" "C:\Users\Gavin McRoy\Desktop\School-Rep\CPSC-2121\Lab09\cmake-build-debug" "C:\Users\Gavin McRoy\Desktop\School-Rep\CPSC-2121\Lab09\cmake-build-debug\CMakeFiles\Lab09.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Lab09.dir/depend

