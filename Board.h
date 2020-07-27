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
  
  // constructor
  explicit Board()
    : pieces()
    {
      // TODO: add all pieces and allow manually adding pieces
      pieces.push_back(Piece {1,1,1,'1'});
    }
};

#endif
