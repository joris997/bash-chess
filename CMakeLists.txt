cmake_minimum_required(VERSION 3.10)

# set project name and version
project(bash-chess VERSION 1.0)

add_executable(bashChess
    src/main.cpp
    src/Piece.cpp
    src/Board.cpp
    src/colTrans.cpp)

TARGET_LINK_LIBRARIES(bashChess stdc++)
