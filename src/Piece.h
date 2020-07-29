#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <iostream>
#include "colTrans.h"

using namespace std;

class Piece{
 private:
  int row;
  int col;
  // number of moves made by the piece
  int moveCnt;
  // white = 1, black = -1
  int color;
  // 'p', 'n', 'b', 'r', 'q', 'k' for pawn, knight, bishop, rook, queen, king
  char type;
  // permissable moves for the piece
  vector<pair<int,int>> permMoves;
  // allowable moves for the piece, taking the entire board into account (1. Ke2 is not allowed but permissable)
  vector<pair<int,int>> allowedMoves;

 public:
  // getting
  int getRow(){return row;};
  int getCol(){return col;};
  int getMoveCnt(){return moveCnt;};
  int getColor(){return color;};
  char getType(){return type;};
  vector<pair<int,int>> getPermMoves(){return permMoves;};
  vector<pair<int,int>> getAllowedMoves(){return allowedMoves;};
  // setting
  void changeRow(int newRow){row = newRow;};
  void changeCol(int newCol){col = newCol;};
  void changeType(char newType){type = newType;};
  // template member functions
  void computePermMovesBishop();
  void computePermMovesRook();
  void computePermMoves();
  void computeAllowedMoves();
  void movePiece();

  // constructor
  explicit Piece(const int row, const int col, const int color, const char type)
    : row(row), col(col), moveCnt(0), color(color), type(type)
    {
      cout << "Created a " << color << " "  << (char)type << " at " << num2char(col) << row << endl;
    }
};

#endif
