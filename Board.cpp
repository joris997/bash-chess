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
  for (int i=0; i<sizeof(pieces)/sizeof(pieces[0]); i++){
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
  bool validMoveMade;
  while (validMoveMade == false){
    // get the piece that needs to be moved
    char pieceType;
    char charTemp;
    int pieceCol;
    int pieceRow;
    cout << "Which piece you want to move?" << endl;
    cout << "Type: " << endl;
    cin >> pieceType;
    cout << "Column: " << endl;
    cin >> charTemp;
    pieceCol = char2num(charTemp);
    cout << "Row: " << endl;
    cin >> pieceRow;

    bool exists;
    int pieceLoc;
    for (int p=0; p<sizeof(pieces)/sizeof(pieces[0]); p++){
      if (pieces[p].getColor() == color && pieces[p].getType() == pieceType && pieces[p].getCol() == pieceCol && pieces[p].getRow() == pieceRow){
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
  //system("clear");
  // TODO: ensure printing distinct pieces instead of "p"
  for (int i=8; i>=1; i--){
    cout << "| ";
    for (int ii=1; ii<=8; ii++){
      bool pieceOnSquare;
      for (int p=0; p<sizeof(pieces)/sizeof(pieces[0]); p++){
	if (pieces[p].getRow() == i && pieces[p].getCol() == ii){
	  pieceOnSquare = true;
	  break;
	}
      }
      
      if (pieceOnSquare){
	cout << "p ";
      }
      else{
	cout << ". ";
      }
    }
    cout << "|" << endl;
  }
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
