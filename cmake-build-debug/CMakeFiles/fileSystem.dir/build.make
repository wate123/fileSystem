# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/jun/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.4343.16/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/jun/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/172.4343.16/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jun/CLionProjects/fileSystem

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jun/CLionProjects/fileSystem/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/fileSystem.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fileSystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fileSystem.dir/flags.make

CMakeFiles/fileSystem.dir/softwaredisk.c.o: CMakeFiles/fileSystem.dir/flags.make
CMakeFiles/fileSystem.dir/softwaredisk.c.o: ../softwaredisk.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jun/CLionProjects/fileSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/fileSystem.dir/softwaredisk.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fileSystem.dir/softwaredisk.c.o   -c /home/jun/CLionProjects/fileSystem/softwaredisk.c

CMakeFiles/fileSystem.dir/softwaredisk.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fileSystem.dir/softwaredisk.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jun/CLionProjects/fileSystem/softwaredisk.c > CMakeFiles/fileSystem.dir/softwaredisk.c.i

CMakeFiles/fileSystem.dir/softwaredisk.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fileSystem.dir/softwaredisk.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jun/CLionProjects/fileSystem/softwaredisk.c -o CMakeFiles/fileSystem.dir/softwaredisk.c.s

CMakeFiles/fileSystem.dir/softwaredisk.c.o.requires:

.PHONY : CMakeFiles/fileSystem.dir/softwaredisk.c.o.requires

CMakeFiles/fileSystem.dir/softwaredisk.c.o.provides: CMakeFiles/fileSystem.dir/softwaredisk.c.o.requires
	$(MAKE) -f CMakeFiles/fileSystem.dir/build.make CMakeFiles/fileSystem.dir/softwaredisk.c.o.provides.build
.PHONY : CMakeFiles/fileSystem.dir/softwaredisk.c.o.provides

CMakeFiles/fileSystem.dir/softwaredisk.c.o.provides.build: CMakeFiles/fileSystem.dir/softwaredisk.c.o


CMakeFiles/fileSystem.dir/filesystem.c.o: CMakeFiles/fileSystem.dir/flags.make
CMakeFiles/fileSystem.dir/filesystem.c.o: ../filesystem.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jun/CLionProjects/fileSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/fileSystem.dir/filesystem.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fileSystem.dir/filesystem.c.o   -c /home/jun/CLionProjects/fileSystem/filesystem.c

CMakeFiles/fileSystem.dir/filesystem.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fileSystem.dir/filesystem.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jun/CLionProjects/fileSystem/filesystem.c > CMakeFiles/fileSystem.dir/filesystem.c.i

CMakeFiles/fileSystem.dir/filesystem.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fileSystem.dir/filesystem.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jun/CLionProjects/fileSystem/filesystem.c -o CMakeFiles/fileSystem.dir/filesystem.c.s

CMakeFiles/fileSystem.dir/filesystem.c.o.requires:

.PHONY : CMakeFiles/fileSystem.dir/filesystem.c.o.requires

CMakeFiles/fileSystem.dir/filesystem.c.o.provides: CMakeFiles/fileSystem.dir/filesystem.c.o.requires
	$(MAKE) -f CMakeFiles/fileSystem.dir/build.make CMakeFiles/fileSystem.dir/filesystem.c.o.provides.build
.PHONY : CMakeFiles/fileSystem.dir/filesystem.c.o.provides

CMakeFiles/fileSystem.dir/filesystem.c.o.provides.build: CMakeFiles/fileSystem.dir/filesystem.c.o


CMakeFiles/fileSystem.dir/formatfs.c.o: CMakeFiles/fileSystem.dir/flags.make
CMakeFiles/fileSystem.dir/formatfs.c.o: ../formatfs.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jun/CLionProjects/fileSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/fileSystem.dir/formatfs.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/fileSystem.dir/formatfs.c.o   -c /home/jun/CLionProjects/fileSystem/formatfs.c

CMakeFiles/fileSystem.dir/formatfs.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/fileSystem.dir/formatfs.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jun/CLionProjects/fileSystem/formatfs.c > CMakeFiles/fileSystem.dir/formatfs.c.i

CMakeFiles/fileSystem.dir/formatfs.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/fileSystem.dir/formatfs.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jun/CLionProjects/fileSystem/formatfs.c -o CMakeFiles/fileSystem.dir/formatfs.c.s

CMakeFiles/fileSystem.dir/formatfs.c.o.requires:

.PHONY : CMakeFiles/fileSystem.dir/formatfs.c.o.requires

CMakeFiles/fileSystem.dir/formatfs.c.o.provides: CMakeFiles/fileSystem.dir/formatfs.c.o.requires
	$(MAKE) -f CMakeFiles/fileSystem.dir/build.make CMakeFiles/fileSystem.dir/formatfs.c.o.provides.build
.PHONY : CMakeFiles/fileSystem.dir/formatfs.c.o.provides

CMakeFiles/fileSystem.dir/formatfs.c.o.provides.build: CMakeFiles/fileSystem.dir/formatfs.c.o


# Object files for target fileSystem
fileSystem_OBJECTS = \
"CMakeFiles/fileSystem.dir/softwaredisk.c.o" \
"CMakeFiles/fileSystem.dir/filesystem.c.o" \
"CMakeFiles/fileSystem.dir/formatfs.c.o"

# External object files for target fileSystem
fileSystem_EXTERNAL_OBJECTS =

fileSystem: CMakeFiles/fileSystem.dir/softwaredisk.c.o
fileSystem: CMakeFiles/fileSystem.dir/filesystem.c.o
fileSystem: CMakeFiles/fileSystem.dir/formatfs.c.o
fileSystem: CMakeFiles/fileSystem.dir/build.make
fileSystem: CMakeFiles/fileSystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jun/CLionProjects/fileSystem/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable fileSystem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fileSystem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fileSystem.dir/build: fileSystem

.PHONY : CMakeFiles/fileSystem.dir/build

CMakeFiles/fileSystem.dir/requires: CMakeFiles/fileSystem.dir/softwaredisk.c.o.requires
CMakeFiles/fileSystem.dir/requires: CMakeFiles/fileSystem.dir/filesystem.c.o.requires
CMakeFiles/fileSystem.dir/requires: CMakeFiles/fileSystem.dir/formatfs.c.o.requires

.PHONY : CMakeFiles/fileSystem.dir/requires

CMakeFiles/fileSystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fileSystem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fileSystem.dir/clean

CMakeFiles/fileSystem.dir/depend:
	cd /home/jun/CLionProjects/fileSystem/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jun/CLionProjects/fileSystem /home/jun/CLionProjects/fileSystem /home/jun/CLionProjects/fileSystem/cmake-build-debug /home/jun/CLionProjects/fileSystem/cmake-build-debug /home/jun/CLionProjects/fileSystem/cmake-build-debug/CMakeFiles/fileSystem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fileSystem.dir/depend

