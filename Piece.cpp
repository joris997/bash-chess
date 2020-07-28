#include "Piece.h"
#include <iostream>
#include <utility>
#include "colTrans.h"

using namespace std;

// compute the permissable moves (that are of the nature of the piece)
void Piece::computePermMoves(){
  if (getType() == 'p'){
    // add move to one row ahead
    pair<int,int> add_pair (getCol(),getRow()+1*getColor());
    permMoves.push_back(add_pair);
    if (getMoveCnt() == 0){
      // add move to two rows ahead
      pair<int,int> add_pair (getCol(),getRow()+2*getColor());
      permMoves.push_back(add_pair);
    }
  }
  else if(getType() == 'n'){
    // TODO: function from column 'a' to 1
  }
}

// compute the allowed moves (regarding other pieces)
void Piece::computeAllowedMoves(){
  allowedMoves = permMoves;
}

// move a piece
void Piece::movePiece(){
  int newRow;
  char ansCol;
  int newCol;
  
  bool validMoveMade;
  while(validMoveMade == false){
    // TODO: streamline this to allow "nh3" as input
    cout << "Give a move for " << (char)type << " " << num2char(col) << row << ": " << endl;
    cout << "Column: " << endl;
    cin >> ansCol;
    newCol = char2num(ansCol);
    cout << "Row: " << endl;
    cin >> newRow;
    pair<int,int> newMove (newCol,newRow);

    // check if the newMove is an allowed move
    bool allowed;
    for (int i=0; i<sizeof(allowedMoves)/sizeof(allowedMoves[0]); i++){
      if (newMove == allowedMoves[i]){
	allowed = true;
	break;
      }    
    }

    // conduct the new move
    if (allowed){
      changeRow(newRow);
      changeCol(newCol);
      validMoveMade = true;
    }
    else{
      cout << "Not an allowed move" << endl;
    }
  }
}
