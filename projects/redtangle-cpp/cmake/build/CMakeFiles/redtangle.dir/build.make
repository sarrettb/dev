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
CMAKE_COMMAND = /home/bsarrett/.local/bin/cmake

# The command to remove a file.
RM = /home/bsarrett/.local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bsarrett/dev/projects/redtangle-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bsarrett/dev/projects/redtangle-cpp/cmake/build

# Include any dependencies generated for this target.
include CMakeFiles/redtangle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/redtangle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/redtangle.dir/flags.make

CMakeFiles/redtangle.dir/src/empty_piece.cpp.o: CMakeFiles/redtangle.dir/flags.make
CMakeFiles/redtangle.dir/src/empty_piece.cpp.o: ../../src/empty_piece.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bsarrett/dev/projects/redtangle-cpp/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/redtangle.dir/src/empty_piece.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/redtangle.dir/src/empty_piece.cpp.o -c /home/bsarrett/dev/projects/redtangle-cpp/src/empty_piece.cpp

CMakeFiles/redtangle.dir/src/empty_piece.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/redtangle.dir/src/empty_piece.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bsarrett/dev/projects/redtangle-cpp/src/empty_piece.cpp > CMakeFiles/redtangle.dir/src/empty_piece.cpp.i

CMakeFiles/redtangle.dir/src/empty_piece.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/redtangle.dir/src/empty_piece.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bsarrett/dev/projects/redtangle-cpp/src/empty_piece.cpp -o CMakeFiles/redtangle.dir/src/empty_piece.cpp.s

CMakeFiles/redtangle.dir/src/redtangle.cpp.o: CMakeFiles/redtangle.dir/flags.make
CMakeFiles/redtangle.dir/src/redtangle.cpp.o: ../../src/redtangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bsarrett/dev/projects/redtangle-cpp/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/redtangle.dir/src/redtangle.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/redtangle.dir/src/redtangle.cpp.o -c /home/bsarrett/dev/projects/redtangle-cpp/src/redtangle.cpp

CMakeFiles/redtangle.dir/src/redtangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/redtangle.dir/src/redtangle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bsarrett/dev/projects/redtangle-cpp/src/redtangle.cpp > CMakeFiles/redtangle.dir/src/redtangle.cpp.i

CMakeFiles/redtangle.dir/src/redtangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/redtangle.dir/src/redtangle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bsarrett/dev/projects/redtangle-cpp/src/redtangle.cpp -o CMakeFiles/redtangle.dir/src/redtangle.cpp.s

CMakeFiles/redtangle.dir/src/redtangle_app.cpp.o: CMakeFiles/redtangle.dir/flags.make
CMakeFiles/redtangle.dir/src/redtangle_app.cpp.o: ../../src/redtangle_app.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bsarrett/dev/projects/redtangle-cpp/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/redtangle.dir/src/redtangle_app.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/redtangle.dir/src/redtangle_app.cpp.o -c /home/bsarrett/dev/projects/redtangle-cpp/src/redtangle_app.cpp

CMakeFiles/redtangle.dir/src/redtangle_app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/redtangle.dir/src/redtangle_app.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bsarrett/dev/projects/redtangle-cpp/src/redtangle_app.cpp > CMakeFiles/redtangle.dir/src/redtangle_app.cpp.i

CMakeFiles/redtangle.dir/src/redtangle_app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/redtangle.dir/src/redtangle_app.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bsarrett/dev/projects/redtangle-cpp/src/redtangle_app.cpp -o CMakeFiles/redtangle.dir/src/redtangle_app.cpp.s

CMakeFiles/redtangle.dir/src/redtangle_local.cpp.o: CMakeFiles/redtangle.dir/flags.make
CMakeFiles/redtangle.dir/src/redtangle_local.cpp.o: ../../src/redtangle_local.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bsarrett/dev/projects/redtangle-cpp/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/redtangle.dir/src/redtangle_local.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/redtangle.dir/src/redtangle_local.cpp.o -c /home/bsarrett/dev/projects/redtangle-cpp/src/redtangle_local.cpp

CMakeFiles/redtangle.dir/src/redtangle_local.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/redtangle.dir/src/redtangle_local.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bsarrett/dev/projects/redtangle-cpp/src/redtangle_local.cpp > CMakeFiles/redtangle.dir/src/redtangle_local.cpp.i

CMakeFiles/redtangle.dir/src/redtangle_local.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/redtangle.dir/src/redtangle_local.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bsarrett/dev/projects/redtangle-cpp/src/redtangle_local.cpp -o CMakeFiles/redtangle.dir/src/redtangle_local.cpp.s

CMakeFiles/redtangle.dir/src/redtangle_piece.cpp.o: CMakeFiles/redtangle.dir/flags.make
CMakeFiles/redtangle.dir/src/redtangle_piece.cpp.o: ../../src/redtangle_piece.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bsarrett/dev/projects/redtangle-cpp/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/redtangle.dir/src/redtangle_piece.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/redtangle.dir/src/redtangle_piece.cpp.o -c /home/bsarrett/dev/projects/redtangle-cpp/src/redtangle_piece.cpp

CMakeFiles/redtangle.dir/src/redtangle_piece.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/redtangle.dir/src/redtangle_piece.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bsarrett/dev/projects/redtangle-cpp/src/redtangle_piece.cpp > CMakeFiles/redtangle.dir/src/redtangle_piece.cpp.i

CMakeFiles/redtangle.dir/src/redtangle_piece.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/redtangle.dir/src/redtangle_piece.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bsarrett/dev/projects/redtangle-cpp/src/redtangle_piece.cpp -o CMakeFiles/redtangle.dir/src/redtangle_piece.cpp.s

CMakeFiles/redtangle.dir/src/redtangle_ui_sdl.cpp.o: CMakeFiles/redtangle.dir/flags.make
CMakeFiles/redtangle.dir/src/redtangle_ui_sdl.cpp.o: ../../src/redtangle_ui_sdl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bsarrett/dev/projects/redtangle-cpp/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/redtangle.dir/src/redtangle_ui_sdl.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/redtangle.dir/src/redtangle_ui_sdl.cpp.o -c /home/bsarrett/dev/projects/redtangle-cpp/src/redtangle_ui_sdl.cpp

CMakeFiles/redtangle.dir/src/redtangle_ui_sdl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/redtangle.dir/src/redtangle_ui_sdl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bsarrett/dev/projects/redtangle-cpp/src/redtangle_ui_sdl.cpp > CMakeFiles/redtangle.dir/src/redtangle_ui_sdl.cpp.i

CMakeFiles/redtangle.dir/src/redtangle_ui_sdl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/redtangle.dir/src/redtangle_ui_sdl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bsarrett/dev/projects/redtangle-cpp/src/redtangle_ui_sdl.cpp -o CMakeFiles/redtangle.dir/src/redtangle_ui_sdl.cpp.s

# Object files for target redtangle
redtangle_OBJECTS = \
"CMakeFiles/redtangle.dir/src/empty_piece.cpp.o" \
"CMakeFiles/redtangle.dir/src/redtangle.cpp.o" \
"CMakeFiles/redtangle.dir/src/redtangle_app.cpp.o" \
"CMakeFiles/redtangle.dir/src/redtangle_local.cpp.o" \
"CMakeFiles/redtangle.dir/src/redtangle_piece.cpp.o" \
"CMakeFiles/redtangle.dir/src/redtangle_ui_sdl.cpp.o"

# External object files for target redtangle
redtangle_EXTERNAL_OBJECTS =

redtangle: CMakeFiles/redtangle.dir/src/empty_piece.cpp.o
redtangle: CMakeFiles/redtangle.dir/src/redtangle.cpp.o
redtangle: CMakeFiles/redtangle.dir/src/redtangle_app.cpp.o
redtangle: CMakeFiles/redtangle.dir/src/redtangle_local.cpp.o
redtangle: CMakeFiles/redtangle.dir/src/redtangle_piece.cpp.o
redtangle: CMakeFiles/redtangle.dir/src/redtangle_ui_sdl.cpp.o
redtangle: CMakeFiles/redtangle.dir/build.make
redtangle: CMakeFiles/redtangle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bsarrett/dev/projects/redtangle-cpp/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable redtangle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/redtangle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/redtangle.dir/build: redtangle

.PHONY : CMakeFiles/redtangle.dir/build

CMakeFiles/redtangle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/redtangle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/redtangle.dir/clean

CMakeFiles/redtangle.dir/depend:
	cd /home/bsarrett/dev/projects/redtangle-cpp/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bsarrett/dev/projects/redtangle-cpp /home/bsarrett/dev/projects/redtangle-cpp /home/bsarrett/dev/projects/redtangle-cpp/cmake/build /home/bsarrett/dev/projects/redtangle-cpp/cmake/build /home/bsarrett/dev/projects/redtangle-cpp/cmake/build/CMakeFiles/redtangle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/redtangle.dir/depend

