# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\Program File\JetBrains\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\Program File\JetBrains\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Auto-Control-Cplus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Auto-Control-Cplus\cmake-build-debug-mingw

# Include any dependencies generated for this target.
include CMakeFiles/PID.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/PID.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/PID.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PID.dir/flags.make

CMakeFiles/PID.dir/PID/pid.cpp.obj: CMakeFiles/PID.dir/flags.make
CMakeFiles/PID.dir/PID/pid.cpp.obj: CMakeFiles/PID.dir/includes_CXX.rsp
CMakeFiles/PID.dir/PID/pid.cpp.obj: D:/Auto-Control-Cplus/PID/pid.cpp
CMakeFiles/PID.dir/PID/pid.cpp.obj: CMakeFiles/PID.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Auto-Control-Cplus\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PID.dir/PID/pid.cpp.obj"
	"E:\Program File\JetBrains\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/PID.dir/PID/pid.cpp.obj -MF CMakeFiles\PID.dir\PID\pid.cpp.obj.d -o CMakeFiles\PID.dir\PID\pid.cpp.obj -c D:\Auto-Control-Cplus\PID\pid.cpp

CMakeFiles/PID.dir/PID/pid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PID.dir/PID/pid.cpp.i"
	"E:\Program File\JetBrains\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Auto-Control-Cplus\PID\pid.cpp > CMakeFiles\PID.dir\PID\pid.cpp.i

CMakeFiles/PID.dir/PID/pid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PID.dir/PID/pid.cpp.s"
	"E:\Program File\JetBrains\CLion 2022.2.4\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Auto-Control-Cplus\PID\pid.cpp -o CMakeFiles\PID.dir\PID\pid.cpp.s

# Object files for target PID
PID_OBJECTS = \
"CMakeFiles/PID.dir/PID/pid.cpp.obj"

# External object files for target PID
PID_EXTERNAL_OBJECTS =

PID.exe: CMakeFiles/PID.dir/PID/pid.cpp.obj
PID.exe: CMakeFiles/PID.dir/build.make
PID.exe: CMakeFiles/PID.dir/linklibs.rsp
PID.exe: CMakeFiles/PID.dir/objects1.rsp
PID.exe: CMakeFiles/PID.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Auto-Control-Cplus\cmake-build-debug-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PID.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PID.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PID.dir/build: PID.exe
.PHONY : CMakeFiles/PID.dir/build

CMakeFiles/PID.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PID.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PID.dir/clean

CMakeFiles/PID.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Auto-Control-Cplus D:\Auto-Control-Cplus D:\Auto-Control-Cplus\cmake-build-debug-mingw D:\Auto-Control-Cplus\cmake-build-debug-mingw D:\Auto-Control-Cplus\cmake-build-debug-mingw\CMakeFiles\PID.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PID.dir/depend

