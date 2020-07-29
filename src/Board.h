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
      // TODO: allow manually adding pieces
      // order: row col color type
      char piece_order[] = {'r','n','b','q','k','b','n','r'};
      for (int ii=0; ii<8; ii++){
	// white pieces
	cout << piece_order[ii] << endl;
	pieces.push_back(Piece {1,ii+1,1,piece_order[ii]});
	pieces.push_back(Piece {2,ii+1,1,'p'});
	// black pieces
	pieces.push_back(Piece {8,ii+1,-1,piece_order[ii]});
	pieces.push_back(Piece {7,ii+1,-1,'p'});
      }
    }
};

#endif
