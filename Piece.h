#ifndef PIECE_H
#define PIECE_H

#include <colTrans.h>

using namespace std;

class Piece{
 private:
  int row;
  int col;
  int moveCnt;
  int color;
  char type;
  vector<pair<char,int>> permMoves;
  vector<pair<char,int>> allowedMoves;

 public:
  int getRow(){return row};
  int getCol(){return col};
  int getMoveCnt(){return moveCnt};
  char getColor(){return color};
  char getType(){return type};
  vector<pair<char,int>> getPermMoves(){return permMoves};
  vector<pair<char,int>> getAllowedMoves(){return allowedMoves};

  explicit Piece(const int row, const int col, const int color, const char type)
    : row(row), col(col), moveCnt(0), color(color), type(type)
    {
      cout << "Created a " << color<< " "  << type << " at " << row << colTrans(col) << endl;
    }
}

#endif
