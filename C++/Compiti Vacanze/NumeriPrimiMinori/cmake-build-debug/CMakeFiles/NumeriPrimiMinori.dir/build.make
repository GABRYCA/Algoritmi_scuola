# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = C:\Users\GABRYCA\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\211.7442.42\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\GABRYCA\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\211.7442.42\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\GABRYCA\CLionProjects\NumeriPrimiMinori

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\GABRYCA\CLionProjects\NumeriPrimiMinori\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/NumeriPrimiMinori.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NumeriPrimiMinori.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NumeriPrimiMinori.dir/flags.make

CMakeFiles/NumeriPrimiMinori.dir/main.cpp.obj: CMakeFiles/NumeriPrimiMinori.dir/flags.make
CMakeFiles/NumeriPrimiMinori.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\GABRYCA\CLionProjects\NumeriPrimiMinori\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NumeriPrimiMinori.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\NumeriPrimiMinori.dir\main.cpp.obj -c C:\Users\GABRYCA\CLionProjects\NumeriPrimiMinori\main.cpp

CMakeFiles/NumeriPrimiMinori.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NumeriPrimiMinori.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\GABRYCA\CLionProjects\NumeriPrimiMinori\main.cpp > CMakeFiles\NumeriPrimiMinori.dir\main.cpp.i

CMakeFiles/NumeriPrimiMinori.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NumeriPrimiMinori.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\GABRYCA\CLionProjects\NumeriPrimiMinori\main.cpp -o CMakeFiles\NumeriPrimiMinori.dir\main.cpp.s

# Object files for target NumeriPrimiMinori
NumeriPrimiMinori_OBJECTS = \
"CMakeFiles/NumeriPrimiMinori.dir/main.cpp.obj"

# External object files for target NumeriPrimiMinori
NumeriPrimiMinori_EXTERNAL_OBJECTS =

NumeriPrimiMinori.exe: CMakeFiles/NumeriPrimiMinori.dir/main.cpp.obj
NumeriPrimiMinori.exe: CMakeFiles/NumeriPrimiMinori.dir/build.make
NumeriPrimiMinori.exe: CMakeFiles/NumeriPrimiMinori.dir/linklibs.rsp
NumeriPrimiMinori.exe: CMakeFiles/NumeriPrimiMinori.dir/objects1.rsp
NumeriPrimiMinori.exe: CMakeFiles/NumeriPrimiMinori.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\GABRYCA\CLionProjects\NumeriPrimiMinori\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable NumeriPrimiMinori.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\NumeriPrimiMinori.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NumeriPrimiMinori.dir/build: NumeriPrimiMinori.exe

.PHONY : CMakeFiles/NumeriPrimiMinori.dir/build

CMakeFiles/NumeriPrimiMinori.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\NumeriPrimiMinori.dir\cmake_clean.cmake
.PHONY : CMakeFiles/NumeriPrimiMinori.dir/clean

CMakeFiles/NumeriPrimiMinori.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\GABRYCA\CLionProjects\NumeriPrimiMinori C:\Users\GABRYCA\CLionProjects\NumeriPrimiMinori C:\Users\GABRYCA\CLionProjects\NumeriPrimiMinori\cmake-build-debug C:\Users\GABRYCA\CLionProjects\NumeriPrimiMinori\cmake-build-debug C:\Users\GABRYCA\CLionProjects\NumeriPrimiMinori\cmake-build-debug\CMakeFiles\NumeriPrimiMinori.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NumeriPrimiMinori.dir/depend
