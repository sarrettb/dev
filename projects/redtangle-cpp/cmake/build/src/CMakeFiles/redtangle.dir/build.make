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
include src/CMakeFiles/redtangle.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/redtangle.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/redtangle.dir/flags.make

src/CMakeFiles/redtangle.dir/app/redtangle_app.cpp.o: src/CMakeFiles/redtangle.dir/flags.make
src/CMakeFiles/redtangle.dir/app/redtangle_app.cpp.o: ../../src/app/redtangle_app.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bsarrett/dev/projects/redtangle-cpp/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/redtangle.dir/app/redtangle_app.cpp.o"
	cd /home/bsarrett/dev/projects/redtangle-cpp/cmake/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/redtangle.dir/app/redtangle_app.cpp.o -c /home/bsarrett/dev/projects/redtangle-cpp/src/app/redtangle_app.cpp

src/CMakeFiles/redtangle.dir/app/redtangle_app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/redtangle.dir/app/redtangle_app.cpp.i"
	cd /home/bsarrett/dev/projects/redtangle-cpp/cmake/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bsarrett/dev/projects/redtangle-cpp/src/app/redtangle_app.cpp > CMakeFiles/redtangle.dir/app/redtangle_app.cpp.i

src/CMakeFiles/redtangle.dir/app/redtangle_app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/redtangle.dir/app/redtangle_app.cpp.s"
	cd /home/bsarrett/dev/projects/redtangle-cpp/cmake/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bsarrett/dev/projects/redtangle-cpp/src/app/redtangle_app.cpp -o CMakeFiles/redtangle.dir/app/redtangle_app.cpp.s

src/CMakeFiles/redtangle.dir/game/redtangle_local.cpp.o: src/CMakeFiles/redtangle.dir/flags.make
src/CMakeFiles/redtangle.dir/game/redtangle_local.cpp.o: ../../src/game/redtangle_local.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bsarrett/dev/projects/redtangle-cpp/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/redtangle.dir/game/redtangle_local.cpp.o"
	cd /home/bsarrett/dev/projects/redtangle-cpp/cmake/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/redtangle.dir/game/redtangle_local.cpp.o -c /home/bsarrett/dev/projects/redtangle-cpp/src/game/redtangle_local.cpp

src/CMakeFiles/redtangle.dir/game/redtangle_local.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/redtangle.dir/game/redtangle_local.cpp.i"
	cd /home/bsarrett/dev/projects/redtangle-cpp/cmake/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bsarrett/dev/projects/redtangle-cpp/src/game/redtangle_local.cpp > CMakeFiles/redtangle.dir/game/redtangle_local.cpp.i

src/CMakeFiles/redtangle.dir/game/redtangle_local.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/redtangle.dir/game/redtangle_local.cpp.s"
	cd /home/bsarrett/dev/projects/redtangle-cpp/cmake/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bsarrett/dev/projects/redtangle-cpp/src/game/redtangle_local.cpp -o CMakeFiles/redtangle.dir/game/redtangle_local.cpp.s

src/CMakeFiles/redtangle.dir/piece/empty_piece.cpp.o: src/CMakeFiles/redtangle.dir/flags.make
src/CMakeFiles/redtangle.dir/piece/empty_piece.cpp.o: ../../src/piece/empty_piece.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bsarrett/dev/projects/redtangle-cpp/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/redtangle.dir/piece/empty_piece.cpp.o"
	cd /home/bsarrett/dev/projects/redtangle-cpp/cmake/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/redtangle.dir/piece/empty_piece.cpp.o -c /home/bsarrett/dev/projects/redtangle-cpp/src/piece/empty_piece.cpp

src/CMakeFiles/redtangle.dir/piece/empty_piece.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/redtangle.dir/piece/empty_piece.cpp.i"
	cd /home/bsarrett/dev/projects/redtangle-cpp/cmake/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bsarrett/dev/projects/redtangle-cpp/src/piece/empty_piece.cpp > CMakeFiles/redtangle.dir/piece/empty_piece.cpp.i

src/CMakeFiles/redtangle.dir/piece/empty_piece.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/redtangle.dir/piece/empty_piece.cpp.s"
	cd /home/bsarrett/dev/projects/redtangle-cpp/cmake/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bsarrett/dev/projects/redtangle-cpp/src/piece/empty_piece.cpp -o CMakeFiles/redtangle.dir/piece/empty_piece.cpp.s

src/CMakeFiles/redtangle.dir/piece/redtangle_piece.cpp.o: src/CMakeFiles/redtangle.dir/flags.make
src/CMakeFiles/redtangle.dir/piece/redtangle_piece.cpp.o: ../../src/piece/redtangle_piece.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bsarrett/dev/projects/redtangle-cpp/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/redtangle.dir/piece/redtangle_piece.cpp.o"
	cd /home/bsarrett/dev/projects/redtangle-cpp/cmake/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/redtangle.dir/piece/redtangle_piece.cpp.o -c /home/bsarrett/dev/projects/redtangle-cpp/src/piece/redtangle_piece.cpp

src/CMakeFiles/redtangle.dir/piece/redtangle_piece.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/redtangle.dir/piece/redtangle_piece.cpp.i"
	cd /home/bsarrett/dev/projects/redtangle-cpp/cmake/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bsarrett/dev/projects/redtangle-cpp/src/piece/redtangle_piece.cpp > CMakeFiles/redtangle.dir/piece/redtangle_piece.cpp.i

src/CMakeFiles/redtangle.dir/piece/redtangle_piece.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/redtangle.dir/piece/redtangle_piece.cpp.s"
	cd /home/bsarrett/dev/projects/redtangle-cpp/cmake/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bsarrett/dev/projects/redtangle-cpp/src/piece/redtangle_piece.cpp -o CMakeFiles/redtangle.dir/piece/redtangle_piece.cpp.s

src/CMakeFiles/redtangle.dir/redtangle.cpp.o: src/CMakeFiles/redtangle.dir/flags.make
src/CMakeFiles/redtangle.dir/redtangle.cpp.o: ../../src/redtangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bsarrett/dev/projects/redtangle-cpp/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/redtangle.dir/redtangle.cpp.o"
	cd /home/bsarrett/dev/projects/redtangle-cpp/cmake/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/redtangle.dir/redtangle.cpp.o -c /home/bsarrett/dev/projects/redtangle-cpp/src/redtangle.cpp

src/CMakeFiles/redtangle.dir/redtangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/redtangle.dir/redtangle.cpp.i"
	cd /home/bsarrett/dev/projects/redtangle-cpp/cmake/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bsarrett/dev/projects/redtangle-cpp/src/redtangle.cpp > CMakeFiles/redtangle.dir/redtangle.cpp.i

src/CMakeFiles/redtangle.dir/redtangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/redtangle.dir/redtangle.cpp.s"
	cd /home/bsarrett/dev/projects/redtangle-cpp/cmake/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bsarrett/dev/projects/redtangle-cpp/src/redtangle.cpp -o CMakeFiles/redtangle.dir/redtangle.cpp.s

src/CMakeFiles/redtangle.dir/ui/redtangle_ui_sdl.cpp.o: src/CMakeFiles/redtangle.dir/flags.make
src/CMakeFiles/redtangle.dir/ui/redtangle_ui_sdl.cpp.o: ../../src/ui/redtangle_ui_sdl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bsarrett/dev/projects/redtangle-cpp/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/redtangle.dir/ui/redtangle_ui_sdl.cpp.o"
	cd /home/bsarrett/dev/projects/redtangle-cpp/cmake/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/redtangle.dir/ui/redtangle_ui_sdl.cpp.o -c /home/bsarrett/dev/projects/redtangle-cpp/src/ui/redtangle_ui_sdl.cpp

src/CMakeFiles/redtangle.dir/ui/redtangle_ui_sdl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/redtangle.dir/ui/redtangle_ui_sdl.cpp.i"
	cd /home/bsarrett/dev/projects/redtangle-cpp/cmake/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bsarrett/dev/projects/redtangle-cpp/src/ui/redtangle_ui_sdl.cpp > CMakeFiles/redtangle.dir/ui/redtangle_ui_sdl.cpp.i

src/CMakeFiles/redtangle.dir/ui/redtangle_ui_sdl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/redtangle.dir/ui/redtangle_ui_sdl.cpp.s"
	cd /home/bsarrett/dev/projects/redtangle-cpp/cmake/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bsarrett/dev/projects/redtangle-cpp/src/ui/redtangle_ui_sdl.cpp -o CMakeFiles/redtangle.dir/ui/redtangle_ui_sdl.cpp.s

# Object files for target redtangle
redtangle_OBJECTS = \
"CMakeFiles/redtangle.dir/app/redtangle_app.cpp.o" \
"CMakeFiles/redtangle.dir/game/redtangle_local.cpp.o" \
"CMakeFiles/redtangle.dir/piece/empty_piece.cpp.o" \
"CMakeFiles/redtangle.dir/piece/redtangle_piece.cpp.o" \
"CMakeFiles/redtangle.dir/redtangle.cpp.o" \
"CMakeFiles/redtangle.dir/ui/redtangle_ui_sdl.cpp.o"

# External object files for target redtangle
redtangle_EXTERNAL_OBJECTS =

src/redtangle: src/CMakeFiles/redtangle.dir/app/redtangle_app.cpp.o
src/redtangle: src/CMakeFiles/redtangle.dir/game/redtangle_local.cpp.o
src/redtangle: src/CMakeFiles/redtangle.dir/piece/empty_piece.cpp.o
src/redtangle: src/CMakeFiles/redtangle.dir/piece/redtangle_piece.cpp.o
src/redtangle: src/CMakeFiles/redtangle.dir/redtangle.cpp.o
src/redtangle: src/CMakeFiles/redtangle.dir/ui/redtangle_ui_sdl.cpp.o
src/redtangle: src/CMakeFiles/redtangle.dir/build.make
src/redtangle: /home/bsarrett/.local/lib/libSDL2maind.a
src/redtangle: /home/bsarrett/.local/lib/libSDL2-2.0d.so.0.2800.2
src/redtangle: libs/libimgui.a
src/redtangle: src/CMakeFiles/redtangle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bsarrett/dev/projects/redtangle-cpp/cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable redtangle"
	cd /home/bsarrett/dev/projects/redtangle-cpp/cmake/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/redtangle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/redtangle.dir/build: src/redtangle

.PHONY : src/CMakeFiles/redtangle.dir/build

src/CMakeFiles/redtangle.dir/clean:
	cd /home/bsarrett/dev/projects/redtangle-cpp/cmake/build/src && $(CMAKE_COMMAND) -P CMakeFiles/redtangle.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/redtangle.dir/clean

src/CMakeFiles/redtangle.dir/depend:
	cd /home/bsarrett/dev/projects/redtangle-cpp/cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bsarrett/dev/projects/redtangle-cpp /home/bsarrett/dev/projects/redtangle-cpp/src /home/bsarrett/dev/projects/redtangle-cpp/cmake/build /home/bsarrett/dev/projects/redtangle-cpp/cmake/build/src /home/bsarrett/dev/projects/redtangle-cpp/cmake/build/src/CMakeFiles/redtangle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/redtangle.dir/depend

