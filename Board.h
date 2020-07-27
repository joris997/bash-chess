#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "Piece.h"

using namespace std;

class Board{
 private:
  vector<Piece> pieces;

 public:
  // constructor
  explicit Board()
    : pieces()
    {
      // TODO: add all pieces and allow manually adding pieces
      pieces.push_back(Piece {1,1,1,'1'});
    }
}

#endif
