# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/elman1901/Studies/C++/distributedWC

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/elman1901/Studies/C++/distributedWC/build

# Include any dependencies generated for this target.
include CMakeFiles/distributor.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/distributor.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/distributor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/distributor.dir/flags.make

CMakeFiles/distributor.dir/src/distributor.cpp.o: CMakeFiles/distributor.dir/flags.make
CMakeFiles/distributor.dir/src/distributor.cpp.o: /home/elman1901/Studies/C++/distributedWC/src/distributor.cpp
CMakeFiles/distributor.dir/src/distributor.cpp.o: CMakeFiles/distributor.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/elman1901/Studies/C++/distributedWC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/distributor.dir/src/distributor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/distributor.dir/src/distributor.cpp.o -MF CMakeFiles/distributor.dir/src/distributor.cpp.o.d -o CMakeFiles/distributor.dir/src/distributor.cpp.o -c /home/elman1901/Studies/C++/distributedWC/src/distributor.cpp

CMakeFiles/distributor.dir/src/distributor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/distributor.dir/src/distributor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/elman1901/Studies/C++/distributedWC/src/distributor.cpp > CMakeFiles/distributor.dir/src/distributor.cpp.i

CMakeFiles/distributor.dir/src/distributor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/distributor.dir/src/distributor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/elman1901/Studies/C++/distributedWC/src/distributor.cpp -o CMakeFiles/distributor.dir/src/distributor.cpp.s

# Object files for target distributor
distributor_OBJECTS = \
"CMakeFiles/distributor.dir/src/distributor.cpp.o"

# External object files for target distributor
distributor_EXTERNAL_OBJECTS =

distributor: CMakeFiles/distributor.dir/src/distributor.cpp.o
distributor: CMakeFiles/distributor.dir/build.make
distributor: liblib.a
distributor: CMakeFiles/distributor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/elman1901/Studies/C++/distributedWC/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable distributor"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/distributor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/distributor.dir/build: distributor
.PHONY : CMakeFiles/distributor.dir/build

CMakeFiles/distributor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/distributor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/distributor.dir/clean

CMakeFiles/distributor.dir/depend:
	cd /home/elman1901/Studies/C++/distributedWC/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/elman1901/Studies/C++/distributedWC /home/elman1901/Studies/C++/distributedWC /home/elman1901/Studies/C++/distributedWC/build /home/elman1901/Studies/C++/distributedWC/build /home/elman1901/Studies/C++/distributedWC/build/CMakeFiles/distributor.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/distributor.dir/depend

