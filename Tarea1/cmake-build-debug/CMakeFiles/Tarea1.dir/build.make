# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /opt/clion-2017.1/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2017.1/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/wororo/CLionProjects/TareasGeometria/Tarea1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wororo/CLionProjects/TareasGeometria/Tarea1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Tarea1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tarea1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tarea1.dir/flags.make

CMakeFiles/Tarea1.dir/main.cpp.o: CMakeFiles/Tarea1.dir/flags.make
CMakeFiles/Tarea1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wororo/CLionProjects/TareasGeometria/Tarea1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tarea1.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tarea1.dir/main.cpp.o -c /home/wororo/CLionProjects/TareasGeometria/Tarea1/main.cpp

CMakeFiles/Tarea1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tarea1.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wororo/CLionProjects/TareasGeometria/Tarea1/main.cpp > CMakeFiles/Tarea1.dir/main.cpp.i

CMakeFiles/Tarea1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tarea1.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wororo/CLionProjects/TareasGeometria/Tarea1/main.cpp -o CMakeFiles/Tarea1.dir/main.cpp.s

CMakeFiles/Tarea1.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Tarea1.dir/main.cpp.o.requires

CMakeFiles/Tarea1.dir/main.cpp.o.provides: CMakeFiles/Tarea1.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tarea1.dir/build.make CMakeFiles/Tarea1.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Tarea1.dir/main.cpp.o.provides

CMakeFiles/Tarea1.dir/main.cpp.o.provides.build: CMakeFiles/Tarea1.dir/main.cpp.o


CMakeFiles/Tarea1.dir/Point.cpp.o: CMakeFiles/Tarea1.dir/flags.make
CMakeFiles/Tarea1.dir/Point.cpp.o: ../Point.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wororo/CLionProjects/TareasGeometria/Tarea1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Tarea1.dir/Point.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tarea1.dir/Point.cpp.o -c /home/wororo/CLionProjects/TareasGeometria/Tarea1/Point.cpp

CMakeFiles/Tarea1.dir/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tarea1.dir/Point.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wororo/CLionProjects/TareasGeometria/Tarea1/Point.cpp > CMakeFiles/Tarea1.dir/Point.cpp.i

CMakeFiles/Tarea1.dir/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tarea1.dir/Point.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wororo/CLionProjects/TareasGeometria/Tarea1/Point.cpp -o CMakeFiles/Tarea1.dir/Point.cpp.s

CMakeFiles/Tarea1.dir/Point.cpp.o.requires:

.PHONY : CMakeFiles/Tarea1.dir/Point.cpp.o.requires

CMakeFiles/Tarea1.dir/Point.cpp.o.provides: CMakeFiles/Tarea1.dir/Point.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tarea1.dir/build.make CMakeFiles/Tarea1.dir/Point.cpp.o.provides.build
.PHONY : CMakeFiles/Tarea1.dir/Point.cpp.o.provides

CMakeFiles/Tarea1.dir/Point.cpp.o.provides.build: CMakeFiles/Tarea1.dir/Point.cpp.o


# Object files for target Tarea1
Tarea1_OBJECTS = \
"CMakeFiles/Tarea1.dir/main.cpp.o" \
"CMakeFiles/Tarea1.dir/Point.cpp.o"

# External object files for target Tarea1
Tarea1_EXTERNAL_OBJECTS =

Tarea1: CMakeFiles/Tarea1.dir/main.cpp.o
Tarea1: CMakeFiles/Tarea1.dir/Point.cpp.o
Tarea1: CMakeFiles/Tarea1.dir/build.make
Tarea1: CMakeFiles/Tarea1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wororo/CLionProjects/TareasGeometria/Tarea1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Tarea1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tarea1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tarea1.dir/build: Tarea1

.PHONY : CMakeFiles/Tarea1.dir/build

CMakeFiles/Tarea1.dir/requires: CMakeFiles/Tarea1.dir/main.cpp.o.requires
CMakeFiles/Tarea1.dir/requires: CMakeFiles/Tarea1.dir/Point.cpp.o.requires

.PHONY : CMakeFiles/Tarea1.dir/requires

CMakeFiles/Tarea1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tarea1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tarea1.dir/clean

CMakeFiles/Tarea1.dir/depend:
	cd /home/wororo/CLionProjects/TareasGeometria/Tarea1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wororo/CLionProjects/TareasGeometria/Tarea1 /home/wororo/CLionProjects/TareasGeometria/Tarea1 /home/wororo/CLionProjects/TareasGeometria/Tarea1/cmake-build-debug /home/wororo/CLionProjects/TareasGeometria/Tarea1/cmake-build-debug /home/wororo/CLionProjects/TareasGeometria/Tarea1/cmake-build-debug/CMakeFiles/Tarea1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tarea1.dir/depend

