# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.15.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.15.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wyr/Desktop/TRender

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wyr/Desktop/TRender

# Utility rule file for uninstall.

# Include the progress variables for this target.
include lib/glfw/CMakeFiles/uninstall.dir/progress.make

lib/glfw/CMakeFiles/uninstall:
	cd /Users/wyr/Desktop/TRender/lib/glfw && /usr/local/Cellar/cmake/3.15.5/bin/cmake -P /Users/wyr/Desktop/TRender/lib/glfw/cmake_uninstall.cmake

uninstall: lib/glfw/CMakeFiles/uninstall
uninstall: lib/glfw/CMakeFiles/uninstall.dir/build.make

.PHONY : uninstall

# Rule to build all files generated by this target.
lib/glfw/CMakeFiles/uninstall.dir/build: uninstall

.PHONY : lib/glfw/CMakeFiles/uninstall.dir/build

lib/glfw/CMakeFiles/uninstall.dir/clean:
	cd /Users/wyr/Desktop/TRender/lib/glfw && $(CMAKE_COMMAND) -P CMakeFiles/uninstall.dir/cmake_clean.cmake
.PHONY : lib/glfw/CMakeFiles/uninstall.dir/clean

lib/glfw/CMakeFiles/uninstall.dir/depend:
	cd /Users/wyr/Desktop/TRender && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wyr/Desktop/TRender /Users/wyr/Desktop/TRender/lib/glfw /Users/wyr/Desktop/TRender /Users/wyr/Desktop/TRender/lib/glfw /Users/wyr/Desktop/TRender/lib/glfw/CMakeFiles/uninstall.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/glfw/CMakeFiles/uninstall.dir/depend

