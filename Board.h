#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "Piece.h"

using namespace std;

class Board{
 public:
  vector<Piece> pieces;

 public:
  // template class functions
  void checkWin();
  void move(int color);
  void playGame();
  void dispBoard();
  
  // constructor
  explicit Board()
    : pieces()
    {
      // TODO: add all pieces and allow manually adding pieces
      // order: row col color type
      Piece new_piece{1,1,1,'p'};
      pieces.push_back(new_piece);
      cout << sizeof(pieces)/sizeof(pieces[0]) << endl;
    }
};

#endif
