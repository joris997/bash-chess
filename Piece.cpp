#include "Piece.h"
#include <iostream>

using namespace std;

// compute the permissable moves (that are of the nature of the piece)
void Piece::computePermMoves(){
  if (this.getType() == "p"){
    // add move to one row ahead
    this.permMoves.push_back((this.getCol(),this.getRow()+1*this.getColor()));
    if (this.getMoveCnt() == 0){
      // add move to two rows ahead
      this.permMoves.push_back((this.getCol(),this.getRow()+2*this.getColor()));
    }
  }
}

// compute the allowed moves (regarding other pieces)
void Piece::computeAllowedMoves(){
  this.allowedMoves = this.permMoves;
}

// move a piece
void Piece::movePiece(){
  int newRow;
  char newCol;
  cout << "Give a move for " << (char)this.getType() << " " << colTrans(this.getCol) << this.getRow << ": " << endl;
  cout << "Column: " << endl;
  cin >> newCol;
  cout << "Row: " << endl;
  cin >> newRow;
  pair<char,int> newMove = <newCol,newRow>;

  // check if hte newMove is an allowed move
  bool allowed;
  for (int i=0; i<sizeof(this.allowedMoves)/sizeof(this.allowedMoves[0]); i++){
    if (newMove == this.allowedMoves[i]){
      allowed = true;
      break;
    }    
  }

  // conduct the new move
  if (allowed){
    this.changeRow = newRow;
    this.changeCol = newCol;
  }
  else{
    cout << "Not an allowed move" << endl;
  }  
}
