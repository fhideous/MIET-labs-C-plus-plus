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
CMAKE_COMMAND = /snap/clion/151/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/151/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fhideous/CLionProjects/lab5/lab0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fhideous/CLionProjects/lab5/lab0/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cpp_lab0.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cpp_lab0.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpp_lab0.dir/flags.make

CMakeFiles/cpp_lab0.dir/src/main.cpp.o: CMakeFiles/cpp_lab0.dir/flags.make
CMakeFiles/cpp_lab0.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fhideous/CLionProjects/lab5/lab0/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cpp_lab0.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp_lab0.dir/src/main.cpp.o -c /home/fhideous/CLionProjects/lab5/lab0/src/main.cpp

CMakeFiles/cpp_lab0.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp_lab0.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fhideous/CLionProjects/lab5/lab0/src/main.cpp > CMakeFiles/cpp_lab0.dir/src/main.cpp.i

CMakeFiles/cpp_lab0.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp_lab0.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fhideous/CLionProjects/lab5/lab0/src/main.cpp -o CMakeFiles/cpp_lab0.dir/src/main.cpp.s

CMakeFiles/cpp_lab0.dir/src/lab0_support.cpp.o: CMakeFiles/cpp_lab0.dir/flags.make
CMakeFiles/cpp_lab0.dir/src/lab0_support.cpp.o: ../src/lab0_support.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fhideous/CLionProjects/lab5/lab0/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cpp_lab0.dir/src/lab0_support.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cpp_lab0.dir/src/lab0_support.cpp.o -c /home/fhideous/CLionProjects/lab5/lab0/src/lab0_support.cpp

CMakeFiles/cpp_lab0.dir/src/lab0_support.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cpp_lab0.dir/src/lab0_support.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fhideous/CLionProjects/lab5/lab0/src/lab0_support.cpp > CMakeFiles/cpp_lab0.dir/src/lab0_support.cpp.i

CMakeFiles/cpp_lab0.dir/src/lab0_support.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cpp_lab0.dir/src/lab0_support.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fhideous/CLionProjects/lab5/lab0/src/lab0_support.cpp -o CMakeFiles/cpp_lab0.dir/src/lab0_support.cpp.s

# Object files for target cpp_lab0
cpp_lab0_OBJECTS = \
"CMakeFiles/cpp_lab0.dir/src/main.cpp.o" \
"CMakeFiles/cpp_lab0.dir/src/lab0_support.cpp.o"

# External object files for target cpp_lab0
cpp_lab0_EXTERNAL_OBJECTS =

cpp_lab0: CMakeFiles/cpp_lab0.dir/src/main.cpp.o
cpp_lab0: CMakeFiles/cpp_lab0.dir/src/lab0_support.cpp.o
cpp_lab0: CMakeFiles/cpp_lab0.dir/build.make
cpp_lab0: CMakeFiles/cpp_lab0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fhideous/CLionProjects/lab5/lab0/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable cpp_lab0"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpp_lab0.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cpp_lab0.dir/build: cpp_lab0

.PHONY : CMakeFiles/cpp_lab0.dir/build

CMakeFiles/cpp_lab0.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cpp_lab0.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cpp_lab0.dir/clean

CMakeFiles/cpp_lab0.dir/depend:
	cd /home/fhideous/CLionProjects/lab5/lab0/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fhideous/CLionProjects/lab5/lab0 /home/fhideous/CLionProjects/lab5/lab0 /home/fhideous/CLionProjects/lab5/lab0/cmake-build-debug /home/fhideous/CLionProjects/lab5/lab0/cmake-build-debug /home/fhideous/CLionProjects/lab5/lab0/cmake-build-debug/CMakeFiles/cpp_lab0.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cpp_lab0.dir/depend

