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
CMAKE_SOURCE_DIR = /home/none/Documents/cpp/bash-chess

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/none/Documents/cpp/bash-chess/build

# Include any dependencies generated for this target.
include CMakeFiles/bash-chess.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bash-chess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bash-chess.dir/flags.make

CMakeFiles/bash-chess.dir/src/main.cpp.o: CMakeFiles/bash-chess.dir/flags.make
CMakeFiles/bash-chess.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/none/Documents/cpp/bash-chess/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bash-chess.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bash-chess.dir/src/main.cpp.o -c /home/none/Documents/cpp/bash-chess/src/main.cpp

CMakeFiles/bash-chess.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bash-chess.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/none/Documents/cpp/bash-chess/src/main.cpp > CMakeFiles/bash-chess.dir/src/main.cpp.i

CMakeFiles/bash-chess.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bash-chess.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/none/Documents/cpp/bash-chess/src/main.cpp -o CMakeFiles/bash-chess.dir/src/main.cpp.s

CMakeFiles/bash-chess.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/bash-chess.dir/src/main.cpp.o.requires

CMakeFiles/bash-chess.dir/src/main.cpp.o.provides: CMakeFiles/bash-chess.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/bash-chess.dir/build.make CMakeFiles/bash-chess.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/bash-chess.dir/src/main.cpp.o.provides

CMakeFiles/bash-chess.dir/src/main.cpp.o.provides.build: CMakeFiles/bash-chess.dir/src/main.cpp.o


CMakeFiles/bash-chess.dir/src/Piece.cpp.o: CMakeFiles/bash-chess.dir/flags.make
CMakeFiles/bash-chess.dir/src/Piece.cpp.o: ../src/Piece.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/none/Documents/cpp/bash-chess/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/bash-chess.dir/src/Piece.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bash-chess.dir/src/Piece.cpp.o -c /home/none/Documents/cpp/bash-chess/src/Piece.cpp

CMakeFiles/bash-chess.dir/src/Piece.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bash-chess.dir/src/Piece.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/none/Documents/cpp/bash-chess/src/Piece.cpp > CMakeFiles/bash-chess.dir/src/Piece.cpp.i

CMakeFiles/bash-chess.dir/src/Piece.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bash-chess.dir/src/Piece.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/none/Documents/cpp/bash-chess/src/Piece.cpp -o CMakeFiles/bash-chess.dir/src/Piece.cpp.s

CMakeFiles/bash-chess.dir/src/Piece.cpp.o.requires:

.PHONY : CMakeFiles/bash-chess.dir/src/Piece.cpp.o.requires

CMakeFiles/bash-chess.dir/src/Piece.cpp.o.provides: CMakeFiles/bash-chess.dir/src/Piece.cpp.o.requires
	$(MAKE) -f CMakeFiles/bash-chess.dir/build.make CMakeFiles/bash-chess.dir/src/Piece.cpp.o.provides.build
.PHONY : CMakeFiles/bash-chess.dir/src/Piece.cpp.o.provides

CMakeFiles/bash-chess.dir/src/Piece.cpp.o.provides.build: CMakeFiles/bash-chess.dir/src/Piece.cpp.o


CMakeFiles/bash-chess.dir/src/Board.cpp.o: CMakeFiles/bash-chess.dir/flags.make
CMakeFiles/bash-chess.dir/src/Board.cpp.o: ../src/Board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/none/Documents/cpp/bash-chess/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/bash-chess.dir/src/Board.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bash-chess.dir/src/Board.cpp.o -c /home/none/Documents/cpp/bash-chess/src/Board.cpp

CMakeFiles/bash-chess.dir/src/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bash-chess.dir/src/Board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/none/Documents/cpp/bash-chess/src/Board.cpp > CMakeFiles/bash-chess.dir/src/Board.cpp.i

CMakeFiles/bash-chess.dir/src/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bash-chess.dir/src/Board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/none/Documents/cpp/bash-chess/src/Board.cpp -o CMakeFiles/bash-chess.dir/src/Board.cpp.s

CMakeFiles/bash-chess.dir/src/Board.cpp.o.requires:

.PHONY : CMakeFiles/bash-chess.dir/src/Board.cpp.o.requires

CMakeFiles/bash-chess.dir/src/Board.cpp.o.provides: CMakeFiles/bash-chess.dir/src/Board.cpp.o.requires
	$(MAKE) -f CMakeFiles/bash-chess.dir/build.make CMakeFiles/bash-chess.dir/src/Board.cpp.o.provides.build
.PHONY : CMakeFiles/bash-chess.dir/src/Board.cpp.o.provides

CMakeFiles/bash-chess.dir/src/Board.cpp.o.provides.build: CMakeFiles/bash-chess.dir/src/Board.cpp.o


CMakeFiles/bash-chess.dir/src/colTrans.cpp.o: CMakeFiles/bash-chess.dir/flags.make
CMakeFiles/bash-chess.dir/src/colTrans.cpp.o: ../src/colTrans.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/none/Documents/cpp/bash-chess/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/bash-chess.dir/src/colTrans.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bash-chess.dir/src/colTrans.cpp.o -c /home/none/Documents/cpp/bash-chess/src/colTrans.cpp

CMakeFiles/bash-chess.dir/src/colTrans.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bash-chess.dir/src/colTrans.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/none/Documents/cpp/bash-chess/src/colTrans.cpp > CMakeFiles/bash-chess.dir/src/colTrans.cpp.i

CMakeFiles/bash-chess.dir/src/colTrans.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bash-chess.dir/src/colTrans.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/none/Documents/cpp/bash-chess/src/colTrans.cpp -o CMakeFiles/bash-chess.dir/src/colTrans.cpp.s

CMakeFiles/bash-chess.dir/src/colTrans.cpp.o.requires:

.PHONY : CMakeFiles/bash-chess.dir/src/colTrans.cpp.o.requires

CMakeFiles/bash-chess.dir/src/colTrans.cpp.o.provides: CMakeFiles/bash-chess.dir/src/colTrans.cpp.o.requires
	$(MAKE) -f CMakeFiles/bash-chess.dir/build.make CMakeFiles/bash-chess.dir/src/colTrans.cpp.o.provides.build
.PHONY : CMakeFiles/bash-chess.dir/src/colTrans.cpp.o.provides

CMakeFiles/bash-chess.dir/src/colTrans.cpp.o.provides.build: CMakeFiles/bash-chess.dir/src/colTrans.cpp.o


# Object files for target bash-chess
bash__chess_OBJECTS = \
"CMakeFiles/bash-chess.dir/src/main.cpp.o" \
"CMakeFiles/bash-chess.dir/src/Piece.cpp.o" \
"CMakeFiles/bash-chess.dir/src/Board.cpp.o" \
"CMakeFiles/bash-chess.dir/src/colTrans.cpp.o"

# External object files for target bash-chess
bash__chess_EXTERNAL_OBJECTS =

bash-chess: CMakeFiles/bash-chess.dir/src/main.cpp.o
bash-chess: CMakeFiles/bash-chess.dir/src/Piece.cpp.o
bash-chess: CMakeFiles/bash-chess.dir/src/Board.cpp.o
bash-chess: CMakeFiles/bash-chess.dir/src/colTrans.cpp.o
bash-chess: CMakeFiles/bash-chess.dir/build.make
bash-chess: CMakeFiles/bash-chess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/none/Documents/cpp/bash-chess/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable bash-chess"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bash-chess.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bash-chess.dir/build: bash-chess

.PHONY : CMakeFiles/bash-chess.dir/build

CMakeFiles/bash-chess.dir/requires: CMakeFiles/bash-chess.dir/src/main.cpp.o.requires
CMakeFiles/bash-chess.dir/requires: CMakeFiles/bash-chess.dir/src/Piece.cpp.o.requires
CMakeFiles/bash-chess.dir/requires: CMakeFiles/bash-chess.dir/src/Board.cpp.o.requires
CMakeFiles/bash-chess.dir/requires: CMakeFiles/bash-chess.dir/src/colTrans.cpp.o.requires

.PHONY : CMakeFiles/bash-chess.dir/requires

CMakeFiles/bash-chess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bash-chess.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bash-chess.dir/clean

CMakeFiles/bash-chess.dir/depend:
	cd /home/none/Documents/cpp/bash-chess/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/none/Documents/cpp/bash-chess /home/none/Documents/cpp/bash-chess /home/none/Documents/cpp/bash-chess/build /home/none/Documents/cpp/bash-chess/build /home/none/Documents/cpp/bash-chess/build/CMakeFiles/bash-chess.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bash-chess.dir/depend
