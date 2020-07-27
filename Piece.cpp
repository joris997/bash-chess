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
  else if(this.getType() == "n"){
    // TODO: function from column 'a' to 1
  }
}

// compute the allowed moves (regarding other pieces)
void Piece::computeAllowedMoves(){
  this.allowedMoves = this.permMoves;
}

// move a piece
void Piece::movePiece(){
  int newRow;
  char ansCol;
  int newCol;
  
  bool validMoveMade;
  while(validMoveMade == false){
    // TODO: streamline this input
    cout << "Give a move for " << (char)this.getType() << " " << num2char(this.getCol) << this.getRow << ": " << endl;
    cout << "Column: " << endl;
    cin >> ansCol;
    newCol = char2num(ansCol);
    cout << "Row: " << endl;
    cin >> newRow;
    pair<int,int> newMove = <newCol,newRow>;

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
      validMoveMade = true;
    }
    else{
      cout << "Not an allowed move" << endl;
    }
  }
}
