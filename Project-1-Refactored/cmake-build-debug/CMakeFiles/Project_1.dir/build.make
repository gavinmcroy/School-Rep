# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /home/gav/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/222.3739.54/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/gav/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/222.3739.54/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gav/Documents/GitHub/School-Rep/Project-1-Refactored

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gav/Documents/GitHub/School-Rep/Project-1-Refactored/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Project_1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Project_1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Project_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project_1.dir/flags.make

CMakeFiles/Project_1.dir/Utils.cpp.o: CMakeFiles/Project_1.dir/flags.make
CMakeFiles/Project_1.dir/Utils.cpp.o: ../Utils.cpp
CMakeFiles/Project_1.dir/Utils.cpp.o: CMakeFiles/Project_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gav/Documents/GitHub/School-Rep/Project-1-Refactored/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Project_1.dir/Utils.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_1.dir/Utils.cpp.o -MF CMakeFiles/Project_1.dir/Utils.cpp.o.d -o CMakeFiles/Project_1.dir/Utils.cpp.o -c /home/gav/Documents/GitHub/School-Rep/Project-1-Refactored/Utils.cpp

CMakeFiles/Project_1.dir/Utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_1.dir/Utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gav/Documents/GitHub/School-Rep/Project-1-Refactored/Utils.cpp > CMakeFiles/Project_1.dir/Utils.cpp.i

CMakeFiles/Project_1.dir/Utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_1.dir/Utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gav/Documents/GitHub/School-Rep/Project-1-Refactored/Utils.cpp -o CMakeFiles/Project_1.dir/Utils.cpp.s

CMakeFiles/Project_1.dir/StringIntMap.cpp.o: CMakeFiles/Project_1.dir/flags.make
CMakeFiles/Project_1.dir/StringIntMap.cpp.o: ../StringIntMap.cpp
CMakeFiles/Project_1.dir/StringIntMap.cpp.o: CMakeFiles/Project_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gav/Documents/GitHub/School-Rep/Project-1-Refactored/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Project_1.dir/StringIntMap.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_1.dir/StringIntMap.cpp.o -MF CMakeFiles/Project_1.dir/StringIntMap.cpp.o.d -o CMakeFiles/Project_1.dir/StringIntMap.cpp.o -c /home/gav/Documents/GitHub/School-Rep/Project-1-Refactored/StringIntMap.cpp

CMakeFiles/Project_1.dir/StringIntMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_1.dir/StringIntMap.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gav/Documents/GitHub/School-Rep/Project-1-Refactored/StringIntMap.cpp > CMakeFiles/Project_1.dir/StringIntMap.cpp.i

CMakeFiles/Project_1.dir/StringIntMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_1.dir/StringIntMap.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gav/Documents/GitHub/School-Rep/Project-1-Refactored/StringIntMap.cpp -o CMakeFiles/Project_1.dir/StringIntMap.cpp.s

CMakeFiles/Project_1.dir/StoredWebPages.cpp.o: CMakeFiles/Project_1.dir/flags.make
CMakeFiles/Project_1.dir/StoredWebPages.cpp.o: ../StoredWebPages.cpp
CMakeFiles/Project_1.dir/StoredWebPages.cpp.o: CMakeFiles/Project_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gav/Documents/GitHub/School-Rep/Project-1-Refactored/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Project_1.dir/StoredWebPages.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_1.dir/StoredWebPages.cpp.o -MF CMakeFiles/Project_1.dir/StoredWebPages.cpp.o.d -o CMakeFiles/Project_1.dir/StoredWebPages.cpp.o -c /home/gav/Documents/GitHub/School-Rep/Project-1-Refactored/StoredWebPages.cpp

CMakeFiles/Project_1.dir/StoredWebPages.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_1.dir/StoredWebPages.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gav/Documents/GitHub/School-Rep/Project-1-Refactored/StoredWebPages.cpp > CMakeFiles/Project_1.dir/StoredWebPages.cpp.i

CMakeFiles/Project_1.dir/StoredWebPages.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_1.dir/StoredWebPages.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gav/Documents/GitHub/School-Rep/Project-1-Refactored/StoredWebPages.cpp -o CMakeFiles/Project_1.dir/StoredWebPages.cpp.s

CMakeFiles/Project_1.dir/StoredWords.cpp.o: CMakeFiles/Project_1.dir/flags.make
CMakeFiles/Project_1.dir/StoredWords.cpp.o: ../StoredWords.cpp
CMakeFiles/Project_1.dir/StoredWords.cpp.o: CMakeFiles/Project_1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gav/Documents/GitHub/School-Rep/Project-1-Refactored/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Project_1.dir/StoredWords.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project_1.dir/StoredWords.cpp.o -MF CMakeFiles/Project_1.dir/StoredWords.cpp.o.d -o CMakeFiles/Project_1.dir/StoredWords.cpp.o -c /home/gav/Documents/GitHub/School-Rep/Project-1-Refactored/StoredWords.cpp

CMakeFiles/Project_1.dir/StoredWords.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project_1.dir/StoredWords.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gav/Documents/GitHub/School-Rep/Project-1-Refactored/StoredWords.cpp > CMakeFiles/Project_1.dir/StoredWords.cpp.i

CMakeFiles/Project_1.dir/StoredWords.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project_1.dir/StoredWords.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gav/Documents/GitHub/School-Rep/Project-1-Refactored/StoredWords.cpp -o CMakeFiles/Project_1.dir/StoredWords.cpp.s

# Object files for target Project_1
Project_1_OBJECTS = \
"CMakeFiles/Project_1.dir/Utils.cpp.o" \
"CMakeFiles/Project_1.dir/StringIntMap.cpp.o" \
"CMakeFiles/Project_1.dir/StoredWebPages.cpp.o" \
"CMakeFiles/Project_1.dir/StoredWords.cpp.o"

# External object files for target Project_1
Project_1_EXTERNAL_OBJECTS =

Project_1: CMakeFiles/Project_1.dir/Utils.cpp.o
Project_1: CMakeFiles/Project_1.dir/StringIntMap.cpp.o
Project_1: CMakeFiles/Project_1.dir/StoredWebPages.cpp.o
Project_1: CMakeFiles/Project_1.dir/StoredWords.cpp.o
Project_1: CMakeFiles/Project_1.dir/build.make
Project_1: CMakeFiles/Project_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gav/Documents/GitHub/School-Rep/Project-1-Refactored/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Project_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Project_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project_1.dir/build: Project_1
.PHONY : CMakeFiles/Project_1.dir/build

CMakeFiles/Project_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Project_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Project_1.dir/clean

CMakeFiles/Project_1.dir/depend:
	cd /home/gav/Documents/GitHub/School-Rep/Project-1-Refactored/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gav/Documents/GitHub/School-Rep/Project-1-Refactored /home/gav/Documents/GitHub/School-Rep/Project-1-Refactored /home/gav/Documents/GitHub/School-Rep/Project-1-Refactored/cmake-build-debug /home/gav/Documents/GitHub/School-Rep/Project-1-Refactored/cmake-build-debug /home/gav/Documents/GitHub/School-Rep/Project-1-Refactored/cmake-build-debug/CMakeFiles/Project_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Project_1.dir/depend

