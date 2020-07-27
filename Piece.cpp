#include "Piece.h"
#include <iostream>

using namespace std;

// compute the permissable moves (that are of the nature of the piece)
void Piece::computePermMoves(){
  if (Piece.getType() == "p"){
    // add move to one row ahead
    permMoves.push_back((Piece.getCol(),Piece.getRow()+1*Piece.getColor()));
    if (Piece.getMoveCnt() == 0){
      // add move to two rows ahead
      permMoves.push_back((Piece.getCol(),Piece.getRow()+2*Piece.getColor()));
    }
  }
}

// compute the allowed moves (regarding other pieces)
void Piece::computeAllowedMoves(){
  allowedMoves = permMoves;
}
