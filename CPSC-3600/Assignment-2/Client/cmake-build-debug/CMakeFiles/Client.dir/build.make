# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/Users/gavintaylormcroy/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/203.5981.166/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/gavintaylormcroy/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/203.5981.166/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-3600/Assignment-2/Client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-3600/Assignment-2/Client/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Client.dir/flags.make

CMakeFiles/Client.dir/DieWithMessage.c.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/DieWithMessage.c.o: ../DieWithMessage.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gavintaylormcroy/Desktop/School-Rep/CPSC-3600/Assignment-2/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Client.dir/DieWithMessage.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Client.dir/DieWithMessage.c.o   -c /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-3600/Assignment-2/Client/DieWithMessage.c

CMakeFiles/Client.dir/DieWithMessage.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Client.dir/DieWithMessage.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-3600/Assignment-2/Client/DieWithMessage.c > CMakeFiles/Client.dir/DieWithMessage.c.i

CMakeFiles/Client.dir/DieWithMessage.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Client.dir/DieWithMessage.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-3600/Assignment-2/Client/DieWithMessage.c -o CMakeFiles/Client.dir/DieWithMessage.c.s

CMakeFiles/Client.dir/TCPClientUtility.c.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/TCPClientUtility.c.o: ../TCPClientUtility.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gavintaylormcroy/Desktop/School-Rep/CPSC-3600/Assignment-2/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Client.dir/TCPClientUtility.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Client.dir/TCPClientUtility.c.o   -c /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-3600/Assignment-2/Client/TCPClientUtility.c

CMakeFiles/Client.dir/TCPClientUtility.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Client.dir/TCPClientUtility.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-3600/Assignment-2/Client/TCPClientUtility.c > CMakeFiles/Client.dir/TCPClientUtility.c.i

CMakeFiles/Client.dir/TCPClientUtility.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Client.dir/TCPClientUtility.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-3600/Assignment-2/Client/TCPClientUtility.c -o CMakeFiles/Client.dir/TCPClientUtility.c.s

CMakeFiles/Client.dir/TCPEchoClient.c.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/TCPEchoClient.c.o: ../TCPEchoClient.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gavintaylormcroy/Desktop/School-Rep/CPSC-3600/Assignment-2/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Client.dir/TCPEchoClient.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Client.dir/TCPEchoClient.c.o   -c /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-3600/Assignment-2/Client/TCPEchoClient.c

CMakeFiles/Client.dir/TCPEchoClient.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Client.dir/TCPEchoClient.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-3600/Assignment-2/Client/TCPEchoClient.c > CMakeFiles/Client.dir/TCPEchoClient.c.i

CMakeFiles/Client.dir/TCPEchoClient.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Client.dir/TCPEchoClient.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-3600/Assignment-2/Client/TCPEchoClient.c -o CMakeFiles/Client.dir/TCPEchoClient.c.s

# Object files for target Client
Client_OBJECTS = \
"CMakeFiles/Client.dir/DieWithMessage.c.o" \
"CMakeFiles/Client.dir/TCPClientUtility.c.o" \
"CMakeFiles/Client.dir/TCPEchoClient.c.o"

# External object files for target Client
Client_EXTERNAL_OBJECTS =

Client: CMakeFiles/Client.dir/DieWithMessage.c.o
Client: CMakeFiles/Client.dir/TCPClientUtility.c.o
Client: CMakeFiles/Client.dir/TCPEchoClient.c.o
Client: CMakeFiles/Client.dir/build.make
Client: CMakeFiles/Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gavintaylormcroy/Desktop/School-Rep/CPSC-3600/Assignment-2/Client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable Client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Client.dir/build: Client

.PHONY : CMakeFiles/Client.dir/build

CMakeFiles/Client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Client.dir/clean

CMakeFiles/Client.dir/depend:
	cd /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-3600/Assignment-2/Client/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-3600/Assignment-2/Client /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-3600/Assignment-2/Client /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-3600/Assignment-2/Client/cmake-build-debug /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-3600/Assignment-2/Client/cmake-build-debug /Users/gavintaylormcroy/Desktop/School-Rep/CPSC-3600/Assignment-2/Client/cmake-build-debug/CMakeFiles/Client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Client.dir/depend

