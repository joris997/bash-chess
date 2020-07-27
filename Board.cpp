#include "Board.h"
#include "colTrans.h"
#include <iostream>

using namespace std;

// moving pieces, color = 1 for white, color = -1 for black
void Board::move(int color){
  for (int i=0; i<sizeof(this.pieces)/sizeof(this.pieces[0]); i++){
    this.pieces[i].computePermMoves();
    this.pieces[i].computeAllowedMoves();
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
  while (valideMoveMade == false){
    // get the piece that needs to be moved
    char pieceType;
    char charTemp;
    int pieceCol;
    int pieceRow;
    cout << "Type which piece you want to move: " << endl;
    cout << "Type: " << endl;
    cin >> pieceType;
    cout << "Column: " << endl;
    cin >> charTemp;
    pieceCol = char2num(charTemp);
    cout << "Row: " << endl;
    cin >> pieceRow;

    bool exists;
    int pieceLoc;
    for (int i=0; i<sizeof(this.pieces)/sizeof(this.pieces[0]); i++){
      if (this.pieces[i].getColor == color && this.pieces[i].getType == pieceType && this.pieces[i].getCol == pieceCol && this.pieces[i].getRow == pieceRow){
	exists = true;
	pieceLoc = i;
	break;
      }
    }
    if (exists){
      this.pieces[i].movePiece();
      validMoveMade = true;
    }
    else{
      cout << "Not a valid piece" << endl;
    }
  }
}

// check win-condition, checkmate
void Board::checkWin(){

}

void Board::playGame(){
  while(true){
    this.move(1);
    this.move(-1);
    this.checkWin();
  }
}
