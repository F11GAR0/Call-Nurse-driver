# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/f11gar0/projects/orangepidriver/Call-Nurse-driver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/f11gar0/projects/orangepidriver/Call-Nurse-driver

# Utility rule file for orangepidriver_autogen.

# Include the progress variables for this target.
include CMakeFiles/orangepidriver_autogen.dir/progress.make

CMakeFiles/orangepidriver_autogen: main.qml
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/f11gar0/projects/orangepidriver/Call-Nurse-driver/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and RCC for target orangepidriver"
	/usr/bin/cmake -E cmake_autogen /home/f11gar0/projects/orangepidriver/Call-Nurse-driver/CMakeFiles/orangepidriver_autogen.dir ""

orangepidriver_autogen: CMakeFiles/orangepidriver_autogen
orangepidriver_autogen: CMakeFiles/orangepidriver_autogen.dir/build.make

.PHONY : orangepidriver_autogen

# Rule to build all files generated by this target.
CMakeFiles/orangepidriver_autogen.dir/build: orangepidriver_autogen

.PHONY : CMakeFiles/orangepidriver_autogen.dir/build

CMakeFiles/orangepidriver_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/orangepidriver_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/orangepidriver_autogen.dir/clean

CMakeFiles/orangepidriver_autogen.dir/depend:
	cd /home/f11gar0/projects/orangepidriver/Call-Nurse-driver && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/f11gar0/projects/orangepidriver/Call-Nurse-driver /home/f11gar0/projects/orangepidriver/Call-Nurse-driver /home/f11gar0/projects/orangepidriver/Call-Nurse-driver /home/f11gar0/projects/orangepidriver/Call-Nurse-driver /home/f11gar0/projects/orangepidriver/Call-Nurse-driver/CMakeFiles/orangepidriver_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/orangepidriver_autogen.dir/depend
