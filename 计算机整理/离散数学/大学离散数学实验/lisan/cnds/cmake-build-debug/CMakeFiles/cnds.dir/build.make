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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/iruihang/Desktop/Clion homework/lisan/cnds"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/iruihang/Desktop/Clion homework/lisan/cnds/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/cnds.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cnds.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cnds.dir/flags.make

CMakeFiles/cnds.dir/main.cpp.o: CMakeFiles/cnds.dir/flags.make
CMakeFiles/cnds.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/iruihang/Desktop/Clion homework/lisan/cnds/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cnds.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/cnds.dir/main.cpp.o -c "/Users/iruihang/Desktop/Clion homework/lisan/cnds/main.cpp"

CMakeFiles/cnds.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/cnds.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/iruihang/Desktop/Clion homework/lisan/cnds/main.cpp" > CMakeFiles/cnds.dir/main.cpp.i

CMakeFiles/cnds.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/cnds.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/iruihang/Desktop/Clion homework/lisan/cnds/main.cpp" -o CMakeFiles/cnds.dir/main.cpp.s

# Object files for target cnds
cnds_OBJECTS = \
"CMakeFiles/cnds.dir/main.cpp.o"

# External object files for target cnds
cnds_EXTERNAL_OBJECTS =

cnds: CMakeFiles/cnds.dir/main.cpp.o
cnds: CMakeFiles/cnds.dir/build.make
cnds: CMakeFiles/cnds.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/iruihang/Desktop/Clion homework/lisan/cnds/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cnds"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cnds.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cnds.dir/build: cnds

.PHONY : CMakeFiles/cnds.dir/build

CMakeFiles/cnds.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cnds.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cnds.dir/clean

CMakeFiles/cnds.dir/depend:
	cd "/Users/iruihang/Desktop/Clion homework/lisan/cnds/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/iruihang/Desktop/Clion homework/lisan/cnds" "/Users/iruihang/Desktop/Clion homework/lisan/cnds" "/Users/iruihang/Desktop/Clion homework/lisan/cnds/cmake-build-debug" "/Users/iruihang/Desktop/Clion homework/lisan/cnds/cmake-build-debug" "/Users/iruihang/Desktop/Clion homework/lisan/cnds/cmake-build-debug/CMakeFiles/cnds.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/cnds.dir/depend

