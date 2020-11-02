#include "Board.h"
#include "colTrans.h"
#include <iostream>

using namespace std;

// General check functions
Piece Board::getPiece(pair<int,int> square){
    for (auto & piece : pieces){
        if (piece.getCol() == square.first && piece.getRow() == square.second){
            return piece;
        }
    }
}

char Board::getType(pair<int, int> square) {
    for (auto & piece : pieces){
        if (piece.getCol() == square.first && piece.getRow() == square.second){
            return piece.getType();
        }
    }
    return '0';
}

int Board::getColor(pair<int,int> square){
    for (auto & piece : pieces){
        if (piece.getCol() == square.first && piece.getRow() == square.second){
            return piece.getColor();
        }
    }
    return 0;
}

bool Board::isOccupied(pair<int,int> square){
    for (auto & piece : pieces){
        if (piece.getCol() == square.first && piece.getRow() == square.second){
            return true;
        }
    }
    return false;
}

bool Board::checkSelfCheck(Piece &piece, pair<int,int> move){
    Board copyBoard = *this;
    return true;
}



// Allowed moves functions
void Board::computeAllowedMovesKingKnight(Piece &piece){
    for (auto & permMove : piece.getPermMoves()){
        if (getColor(pair <int,int> (permMove.first,permMove.second)) != piece.getColor()){
            piece.allowedMoves.push_back(permMove);
        }
    }
}

void Board::computeAllowedMovesPawn(Piece &piece){
    for (auto & permMove : piece.getPermMoves()){
        if (getColor(pair <int,int> (permMove.first,permMove.second)) != piece.getColor()){
            piece.allowedMoves.push_back(permMove);
        }
    }
    // Can you capture a piece front left from you?
    if (getColor(pair<int,int> (piece.getCol()-1,piece.getRow()+piece.getColor())) != piece.getColor()){
        piece.allowedMoves.emplace_back(pair<int,int>(piece.getCol()-1,piece.getRow()+piece.getColor()));
    }
    // Can you capture a piece front right from you?
    if (getColor(pair<int,int> (piece.getCol()+1,piece.getRow()+piece.getColor())) != piece.getColor()){
        piece.allowedMoves.emplace_back(pair<int,int>(piece.getCol()+1,piece.getRow()+piece.getColor()));
    }
    // Can you capture a piece en passe left?
    pair<int,int> potentialPair(piece.getCol()-1,piece.getRow());
    // check if there even is a piece
    if (getColor(potentialPair) != 0){
        // check if opposite color and if en passe is possible
        if (getColor(potentialPair) != piece.getColor() && getPiece(potentialPair).getEnPasse()){
            piece.allowedMoves.emplace_back(potentialPair);
        }
    }
    // Can you capture a piece en pass right?
    potentialPair.first = piece.getCol()+1; potentialPair.second = piece.getRow();
    if (getColor(potentialPair) != 0){
        if (getColor(potentialPair) != piece.getColor() && getPiece(potentialPair).getEnPasse()){
            piece.allowedMoves.emplace_back(potentialPair);
        }
    }

}

void Board::computeAllowedMovesBishop(Piece &piece){
    for (int i=1; i<=8; i++){
        // Only permit moves that are within the board
        if (piece.getCol()+i >= 1 && piece.getCol()+i <= 8 && piece.getRow()+i >= 1 && piece.getRow()+i <= 8){
            pair<int,int> potentialPair(piece.getCol()+i,piece.getRow()+i);
            // If the next square is not occupied at all
            if (!isOccupied(potentialPair)){
                piece.allowedMoves.emplace_back(potentialPair);
            // If the next square is occupied by a different colored piece, break after
            } else if (getColor(potentialPair) != piece.getColor()){
                piece.allowedMoves.emplace_back(potentialPair);
                break;
            // Next square occupied by same colored piece
            } else {
                break;
            }
        }
    }
    for (int i=1; i<=8; i++){
        if (piece.getCol()-i >= 1 && piece.getCol()-i <= 8 && piece.getRow()+i >= 1 && piece.getRow()+i <= 8){
            pair<int,int> potentialPair(piece.getCol()-i,piece.getRow()+i);
            if (!isOccupied(potentialPair)){
                piece.allowedMoves.emplace_back(potentialPair);
            } else if (getColor(potentialPair) != piece.getColor()){
                piece.allowedMoves.emplace_back(potentialPair);
                break;
            } else {
                break;
            }
        }
    }
    for (int i=1; i<=8; i++){
        if (piece.getCol()-i >= 1 && piece.getCol()-i <= 8 && piece.getRow()-i >= 1 && piece.getRow()-i <= 8){
            pair<int,int> potentialPair(piece.getCol()-i,piece.getRow()-i);
            if (!isOccupied(potentialPair)){
                piece.allowedMoves.emplace_back(potentialPair);
            } else if (getColor(potentialPair) != piece.getColor()){
                piece.allowedMoves.emplace_back(potentialPair);
                break;
            } else {
                break;
            }
        }
    }
    for (int i=1; i<=8; i++){
        if (piece.getCol()+i >= 1 && piece.getCol()+i <= 8 && piece.getRow()-i >= 1 && piece.getRow()-i <= 8){
            pair<int,int> potentialPair(piece.getCol()+i,piece.getRow()-1);
            if (!isOccupied(potentialPair)){
                piece.allowedMoves.emplace_back(potentialPair);
            } else if (getColor(potentialPair) != piece.getColor()){
                piece.allowedMoves.emplace_back(potentialPair);
                break;
            } else {
                break;
            }
        }
    }
}

void Board::computeAllowedMovesRook(Piece &piece){
    int top = 8 - piece.getRow();
    int left = piece.getCol() - 1;
    int right = 8 - piece.getCol();
    int bottom = piece.getRow() - 1;
    for (int i=0; i<top; i++){
        pair<int,int> potentialPair(piece.getCol(),piece.getRow()+(i+1));
        // If the next square is not occupied at all
        if (!isOccupied(potentialPair)){
            piece.allowedMoves.emplace_back(potentialPair);
        // If the next square is occupied by a different colored piece, break after
        } else if (getColor(potentialPair) != piece.getColor()){
            piece.allowedMoves.emplace_back(potentialPair);
            break;
        // Next square occupied by same colored piece
        } else {
            break;
        }
    }
    for (int i=0; i<left; i++){
        pair<int,int> potentialPair(piece.getCol()-(i+1),piece.getRow());
        if (!isOccupied(potentialPair)){
            piece.allowedMoves.emplace_back(potentialPair);
        } else if (getColor(potentialPair) != piece.getColor()){
            piece.allowedMoves.emplace_back(potentialPair);
            break;
        } else {
            break;
        }
    }
    for (int i=0; i<right; i++){
        pair<int,int> potentialPair(piece.getCol()+(i+1),piece.getRow());
        if (!isOccupied(potentialPair)){
            piece.allowedMoves.emplace_back(potentialPair);
        } else if (getColor(potentialPair) != piece.getColor()){
            piece.allowedMoves.emplace_back(potentialPair);
            break;
        } else {
            break;
        }
    }
    for (int i=0; i<bottom; i++){
        pair<int,int> potentialPair(piece.getCol(),piece.getRow()-(i+1));
        if (!isOccupied(potentialPair)){
            piece.allowedMoves.emplace_back(potentialPair);
        } else if (getColor(potentialPair) != piece.getColor()){
            piece.allowedMoves.emplace_back(potentialPair);
            break;
        } else {
            break;
        }
    }
}

void Board::computeAllowedMoves() {
    for (auto & piece : pieces){
        piece.computePermMoves();
        piece.allowedMoves.clear();
        // the knight and king 'jump' so here we only check if the color does not correspond
        if (piece.getType() == 'k' || piece.getType() == 'n'){
            computeAllowedMovesKingKnight(piece);
        }

        if (piece.getType() == 'p'){
            computeAllowedMovesPawn(piece);
        }

        if (piece.getType() == 'b' || piece.getType() == 'q'){
            computeAllowedMovesBishop(piece);
        }

        if (piece.getType() == 'r' || piece.getType() == 'q'){
            computeAllowedMovesRook(piece);
        }
    }
}



// check win-condition, checkmate, stalemate
bool Board::checkWin(int color){
    // if other king's allowed moves is empty and other king in check return true
    cout << "checking win" << endl;
}

// moving pieces, color = 1 for white, color = -1 for black
void Board::move(int color){
    computeAllowedMoves();

    // announce which color is to move
    if (color == 1){
        cout << "White to move!" << endl;
    }
    else {
        cout << "Black to move!" << endl;
    }

    // while loop until a valid move has been made (selecting the wrong move or wrong piece)
    bool validMoveMade = false;
    while (!validMoveMade){
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

        // find the piece in the pieces vector that needs to be moved
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
    // TODO: ensure printing distinct pieces instead of "p" etc.
    system("clear");
    cout << "   -----------------" << endl;
    for (int i=8; i>=1; i--){
        cout << i << " | ";
        for (int ii=1; ii<=8; ii++){
            bool pieceOnSquare = false;
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
    cout << "    a b c d e f g h " << endl;
}

void Board::playGame(){
    bool win = false;
    while(!win){
        dispBoard();
        // white to move
        move(1);
        win = checkWin(1);
        dispBoard();
        // black to move
        move(-1);
        win = checkWin(-1);
    }
}
