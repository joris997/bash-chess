#include "Board.h"
#include "colTrans.h"
#include <iostream>

using namespace std;

// check win-condition, checkmate, stalemate
void Board::checkWin(){
  cout << "checking win" << endl;
}

// moving pieces, color = 1 for white, color = -1 for black
void Board::move(int color){
  for (int i=0; i<pieces.size(); i++){
    pieces[i].computePermMoves();
    pieces[i].computeAllowedMoves();
  }

  // announce which color is to move
  if (color == 1){
    cout << "White to move!" << endl;
  }
  else {
    cout << "Black to move!" << endl;
  }

  // while loop until a valid move has been made (selecting the wrong move or wrong piece)
  bool validMoveMade = false;
  while (validMoveMade == false){
    // get the piece that needs to be moved
    char movePiece[3];
    char moveType;
    int moveCol;
    int moveRow;
    
    cout << "Piece you want to move: (e.g. ke1)" << endl;
    cin >> movePiece;

    moveType = movePiece[0];
    moveCol = char2num(movePiece[1]);
    moveRow =  movePiece[2] - '0';
    
    bool exists = false;
    int pieceLoc;
    for (int p=0; p<pieces.size(); p++){
      if (pieces[p].getColor() == color && pieces[p].getType() == moveType && pieces[p].getCol() == moveCol && pieces[p].getRow() == moveRow){
	exists = true;
	pieceLoc = p;
	break;
      }
    }
    if (exists){
      pieces[pieceLoc].movePiece();
      validMoveMade = true;
    }
    else{
      cout << "Not a valid piece" << endl;
    }
  }
}

void Board::dispBoard(){
  // TODO: ensure printing distinct pieces instead of "p"
  system("clear");
  cout << "   -----------------" << endl;
  for (int i=8; i>=1; i--){
    cout << i << " | ";
    for (int ii=1; ii<=8; ii++){
      bool pieceOnSquare;
      int pieceCnt;
      for (int p=0; p<pieces.size(); p++){
	if (pieces[p].getRow() == i && pieces[p].getCol() == ii){
	  pieceOnSquare = true;
	  pieceCnt = p;
	  break;
	}
      }
      
      if (pieceOnSquare){
	cout << pieces[pieceCnt].getType() << " ";
	pieceOnSquare = false;
      }
      else{
	cout << ". ";
      }
    }
    cout << "|" << endl;
  }
  cout << "   -----------------" << endl;
  cout << "    a b c d e f g h" << endl;
}

void Board::playGame(){
  while(true){
    dispBoard();
    move(1);
    dispBoard();
    move(-1);
    checkWin();
  }
}
