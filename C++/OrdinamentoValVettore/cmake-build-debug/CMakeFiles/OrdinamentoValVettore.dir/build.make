# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = C:\Users\AnonymousGCA\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.4746.93\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\AnonymousGCA\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.4746.93\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\AnonymousGCA\CLionProjects\Algoritmi_scuola\C++\OrdinamentoValVettore

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\AnonymousGCA\CLionProjects\Algoritmi_scuola\C++\OrdinamentoValVettore\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OrdinamentoValVettore.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/OrdinamentoValVettore.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OrdinamentoValVettore.dir/flags.make

CMakeFiles/OrdinamentoValVettore.dir/main.cpp.obj: CMakeFiles/OrdinamentoValVettore.dir/flags.make
CMakeFiles/OrdinamentoValVettore.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\AnonymousGCA\CLionProjects\Algoritmi_scuola\C++\OrdinamentoValVettore\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OrdinamentoValVettore.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\OrdinamentoValVettore.dir\main.cpp.obj -c C:\Users\AnonymousGCA\CLionProjects\Algoritmi_scuola\C++\OrdinamentoValVettore\main.cpp

CMakeFiles/OrdinamentoValVettore.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OrdinamentoValVettore.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\AnonymousGCA\CLionProjects\Algoritmi_scuola\C++\OrdinamentoValVettore\main.cpp > CMakeFiles\OrdinamentoValVettore.dir\main.cpp.i

CMakeFiles/OrdinamentoValVettore.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OrdinamentoValVettore.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\AnonymousGCA\CLionProjects\Algoritmi_scuola\C++\OrdinamentoValVettore\main.cpp -o CMakeFiles\OrdinamentoValVettore.dir\main.cpp.s

# Object files for target OrdinamentoValVettore
OrdinamentoValVettore_OBJECTS = \
"CMakeFiles/OrdinamentoValVettore.dir/main.cpp.obj"

# External object files for target OrdinamentoValVettore
OrdinamentoValVettore_EXTERNAL_OBJECTS =

OrdinamentoValVettore.exe: CMakeFiles/OrdinamentoValVettore.dir/main.cpp.obj
OrdinamentoValVettore.exe: CMakeFiles/OrdinamentoValVettore.dir/build.make
OrdinamentoValVettore.exe: CMakeFiles/OrdinamentoValVettore.dir/linklibs.rsp
OrdinamentoValVettore.exe: CMakeFiles/OrdinamentoValVettore.dir/objects1.rsp
OrdinamentoValVettore.exe: CMakeFiles/OrdinamentoValVettore.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\AnonymousGCA\CLionProjects\Algoritmi_scuola\C++\OrdinamentoValVettore\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable OrdinamentoValVettore.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\OrdinamentoValVettore.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OrdinamentoValVettore.dir/build: OrdinamentoValVettore.exe
.PHONY : CMakeFiles/OrdinamentoValVettore.dir/build

CMakeFiles/OrdinamentoValVettore.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\OrdinamentoValVettore.dir\cmake_clean.cmake
.PHONY : CMakeFiles/OrdinamentoValVettore.dir/clean

CMakeFiles/OrdinamentoValVettore.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\AnonymousGCA\CLionProjects\Algoritmi_scuola\C++\OrdinamentoValVettore C:\Users\AnonymousGCA\CLionProjects\Algoritmi_scuola\C++\OrdinamentoValVettore C:\Users\AnonymousGCA\CLionProjects\Algoritmi_scuola\C++\OrdinamentoValVettore\cmake-build-debug C:\Users\AnonymousGCA\CLionProjects\Algoritmi_scuola\C++\OrdinamentoValVettore\cmake-build-debug C:\Users\AnonymousGCA\CLionProjects\Algoritmi_scuola\C++\OrdinamentoValVettore\cmake-build-debug\CMakeFiles\OrdinamentoValVettore.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OrdinamentoValVettore.dir/depend
