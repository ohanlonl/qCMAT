# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chrome/work/CloudCompare/qCMAT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chrome/work/CloudCompare/qCMAT/build

# Utility rule file for QPHOTOSCAN_IO_PLUGIN_autogen.

# Include the progress variables for this target.
include plugins/core/qPhotoscanIO/CMakeFiles/QPHOTOSCAN_IO_PLUGIN_autogen.dir/progress.make

plugins/core/qPhotoscanIO/CMakeFiles/QPHOTOSCAN_IO_PLUGIN_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/chrome/work/CloudCompare/qCMAT/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC for target QPHOTOSCAN_IO_PLUGIN"
	cd /home/chrome/work/CloudCompare/qCMAT/build/plugins/core/qPhotoscanIO && /usr/bin/cmake -E cmake_autogen /home/chrome/work/CloudCompare/qCMAT/build/plugins/core/qPhotoscanIO/CMakeFiles/QPHOTOSCAN_IO_PLUGIN_autogen.dir/AutogenInfo.cmake ""

QPHOTOSCAN_IO_PLUGIN_autogen: plugins/core/qPhotoscanIO/CMakeFiles/QPHOTOSCAN_IO_PLUGIN_autogen
QPHOTOSCAN_IO_PLUGIN_autogen: plugins/core/qPhotoscanIO/CMakeFiles/QPHOTOSCAN_IO_PLUGIN_autogen.dir/build.make

.PHONY : QPHOTOSCAN_IO_PLUGIN_autogen

# Rule to build all files generated by this target.
plugins/core/qPhotoscanIO/CMakeFiles/QPHOTOSCAN_IO_PLUGIN_autogen.dir/build: QPHOTOSCAN_IO_PLUGIN_autogen

.PHONY : plugins/core/qPhotoscanIO/CMakeFiles/QPHOTOSCAN_IO_PLUGIN_autogen.dir/build

plugins/core/qPhotoscanIO/CMakeFiles/QPHOTOSCAN_IO_PLUGIN_autogen.dir/clean:
	cd /home/chrome/work/CloudCompare/qCMAT/build/plugins/core/qPhotoscanIO && $(CMAKE_COMMAND) -P CMakeFiles/QPHOTOSCAN_IO_PLUGIN_autogen.dir/cmake_clean.cmake
.PHONY : plugins/core/qPhotoscanIO/CMakeFiles/QPHOTOSCAN_IO_PLUGIN_autogen.dir/clean

plugins/core/qPhotoscanIO/CMakeFiles/QPHOTOSCAN_IO_PLUGIN_autogen.dir/depend:
	cd /home/chrome/work/CloudCompare/qCMAT/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chrome/work/CloudCompare/qCMAT /home/chrome/work/CloudCompare/qCMAT/plugins/core/qPhotoscanIO /home/chrome/work/CloudCompare/qCMAT/build /home/chrome/work/CloudCompare/qCMAT/build/plugins/core/qPhotoscanIO /home/chrome/work/CloudCompare/qCMAT/build/plugins/core/qPhotoscanIO/CMakeFiles/QPHOTOSCAN_IO_PLUGIN_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : plugins/core/qPhotoscanIO/CMakeFiles/QPHOTOSCAN_IO_PLUGIN_autogen.dir/depend
