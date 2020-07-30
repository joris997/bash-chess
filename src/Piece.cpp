#include "Piece.h"
#include <iostream>
#include <utility>
#include "colTrans.h"

using namespace std;

// compute the permissible moves for a bishop piece (and queen)
void Piece::computePermMovesBishop(){
  int topLeft = min(getRow(),getCol()) - 1;
  int bottomLeft = 8 - max(getRow(),9-getCol());
  int topRight = min(getRow(),9-getCol());
  int bottomRight = 8 - max(getRow(),getCol());
  for (int i=0; i<topLeft; i++){
    pair<int,int> add_pair (getCol()-(i+1),getRow()+(i+1));
    permMoves.push_back(add_pair);
  }
  for (int i=0; i<bottomLeft; i++){
    pair<int,int> add_pair (getCol()-(i+1),getRow()-(i+1));
    permMoves.push_back(add_pair);
  }
  for (int i=0; i<topRight; i++){
    pair<int,int> add_pair (getCol()+(i+1),getRow()+(i+1));
    permMoves.push_back(add_pair);
  }
  for (int i=0; i<bottomRight; i++){
    pair<int,int> add_pair (getCol()+(i+1),getRow()-(i+1));
    permMoves.push_back(add_pair);
  }
}

// compute the permissible moves for a rook piece (and queen)
void Piece::computePermMovesRook(){
  int top = 8 - getRow();
  int left = getCol() - 1;
  int right = 8 - getCol();
  int bottom = getRow() - 1;
  for (int i=0; i<top; i++){
    pair<int,int> add_pair (getCol(),getRow()+(i+1));
    permMoves.push_back(add_pair);
  }
  for (int i=0; i<left; i++){
    pair<int,int> add_pair (getCol()-(i+1),getRow());
    permMoves.push_back(add_pair);
  }
  for (int i=0; i<right; i++){
    pair<int,int> add_pair (getCol()+(i+1),getRow());
    permMoves.push_back(add_pair);
  }
  for (int i=0; i<bottom; i++){
    pair<int,int> add_pair (getCol(),getRow()-(i+1));
    permMoves.push_back(add_pair);
  }
  cout << "new rook at " << getCol() << ", " << getRow() << endl;
  cout << top << ", " << left << ", " << right << ", " << bottom << endl;
  for (int i=0; i<sizeof(permMoves)/sizeof(permMoves[0]); i++){
    cout << permMoves[i].first << ", " << permMoves[i].second << endl;
  }
}

// compute the permissable moves (that are of the nature of the piece)
void Piece::computePermMoves(){
  // Clear the old permissible moves
  vector<pair<int,int>> emptyPermMoves {{0,0}};
  permMoves.swap(emptyPermMoves);
  // PAWN
  if (getType() == 'p'){
    // add move to one row ahead
    pair<int,int> add_pair (getCol(),getRow()+1*getColor());
    permMoves.push_back(add_pair);
    if (getMoveCnt() == 0){
      // add move to two rows ahead
      pair<int,int> add_pair (getCol(),getRow()+2*getColor());
      permMoves.push_back(add_pair);
    }
    cout << "new pawn at " << getCol() << ", " << getRow() << endl;
    for (int i=0; i<sizeof(permMoves)/sizeof(permMoves[0]); i++){
      cout << permMoves[i].first << ", " << permMoves[i].second << endl;
    }
  }
  // KNIGHT
  else if(getType() == 'n'){
    int X[8] = {-2,-2,-1,-1,1,1,2,2};
    int Y[8] = {-1,1,-2,2,-2,2,-1,1};
    for (int i=0; i<8; i++){
      int newCol = getCol() + X[i];
      int newRow = getRow() + Y[i];
      if (newCol>=1 && newCol<=8 && newRow>=1 && newRow<=8){
	pair<int,int> add_pair (newCol,newRow);
	permMoves.push_back(add_pair);
      }
    }
  }
  // BISHOP
  else if(getType() == 'b'){
    computePermMovesBishop();
  }
  // ROOK
  else if(getType() == 'r'){
    computePermMovesRook();
  }
  // QUEEN
  else if(getType() == 'q'){
    computePermMovesBishop();
    computePermMovesRook();
  }
  // KING
  else if(getType() == 'k'){
    int X[8] = {-1,-1,-1,0,0,1,1,1};
    int Y[8] = {-1,0,1,-1,-1,-1,0,1};
    for (int i=0; i<8; i++){
      int newCol = getCol() + X[i];
      int newRow = getRow() + Y[i];
      if (newCol>=1 && newCol<=8 && newRow>=1 && newRow<=8){
	pair<int,int> add_pair (newCol,newRow);
	permMoves.push_back(add_pair);
      }
    }
  }
}

// compute the allowed moves (regarding other pieces)
void Piece::computeAllowedMoves(){
  allowedMoves = permMoves;
}

// move a piece
void Piece::movePiece(){
  char newMove[2];
  int newRow;
  char ansCol;
  int newCol;
  
  bool validMoveMade = false;
  while(validMoveMade == false){
    cout << "Give a move for " << (char)type << " " << num2char(col) << row << ": (e.g. e2)" << endl;
    cin >> newMove;
    newCol = char2num(newMove[0]);
    newRow =  newMove[1] - '0';
    
    pair<int,int> newMove (newCol,newRow);

    // check if the newMove is an allowed move
    bool allowed = false;
    for (int i=0; i<sizeof(allowedMoves)/sizeof(allowedMoves[0]); i++){
      cout << allowedMoves[i].first << ", " << allowedMoves[i].second << endl;
      if (newMove == allowedMoves[i]){
	allowed = true;
	break;
      }    
    }

    // conduct the new move
    if (allowed){
      changeRow(newRow);
      changeCol(newCol);
      changeMoveCnt(getMoveCnt()+1);
      validMoveMade = true;
    }
    else{
      cout << "Not an allowed move" << endl;
    }
  }
}
