#include "Piece.h"
#include <iostream>
#include <utility>
#include "colTrans.h"

// compute the permissible moves for a pawn
void Piece::computePermMovesPawn(){
    // add move to one row ahead
    permMoves.emplace_back(getCol(),getRow()+1*getColor());
    if (getMoveCnt() == 0){
        // add move to two rows ahead
        permMoves.emplace_back(getCol(),getRow()+2*getColor());
    }
    /*
    std::cout << "pawn at " << getCol() << ", " << getRow() << std::endl;
    for (int i=0; i<permMoves.size(); i++){
    std::cout << permMoves[i].first << ", " << permMoves[i].second << std::endl;
    }
    */
}

// compute the permissible moves for a knight
void Piece::computePermMovesKnight(){
    int X[8] = {-2,-2,-1,-1,1,1,2,2};
    int Y[8] = {-1,1,-2,2,-2,2,-1,1};
    for (int i=0; i<8; i++){
        int newCol = getCol() + X[i];
        int newRow = getRow() + Y[i];
        if (newCol>=1 && newCol<=8 && newRow>=1 && newRow<=8){
            permMoves.emplace_back(newCol,newRow);
        }
    }
}

// compute the permissible moves for a bishop piece (and partly the queen)
void Piece::computePermMovesBishop(){
    for (int i=1; i<=8; i++){
        if (getCol()+i >= 1 && getCol()+i <= 8 && getRow()+i >= 1 && getRow()+i <= 8){
            permMoves.emplace_back(getCol()+i,getRow()+i);
        }
        if (getCol()-i >= 1 && getCol()-i <= 8 && getRow()+i >= 1 && getRow()+i <= 8){
            permMoves.emplace_back(getCol()-i,getRow()+i);
        }
        if (getCol()-i >= 1 && getCol()-i <= 8 && getRow()-i >= 1 && getRow()-i <= 8){
            permMoves.emplace_back(getCol()-i,getRow()-i);
        }
        if (getCol()+i >= 1 && getCol()+i <= 8 && getRow()-i >= 1 && getRow()-i <= 8){
            permMoves.emplace_back(getCol()+i,getRow()-i);
        }
    }
}

// compute the permissible moves for a rook piece (and queen)
void Piece::computePermMovesRook(){
    int top = 8 - getRow();
    int left = getCol() - 1;
    int right = 8 - getCol();
    int bottom = getRow() - 1;
    for (int i=0; i<top; i++){
        permMoves.emplace_back(getCol(),getRow()+(i+1));
    }
    for (int i=0; i<left; i++){
        permMoves.emplace_back(getCol()-(i+1),getRow());
    }
    for (int i=0; i<right; i++){
        permMoves.emplace_back(getCol()+(i+1),getRow());
    }
    for (int i=0; i<bottom; i++){
        permMoves.emplace_back(getCol(),getRow()-(i+1));
    }
    /*
    std::cout << "rook at " << getCol() << ", " << getRow() << std::endl;
    std::cout << top << ", " << left << ", " << right << ", " << bottom << std::endl;
    for (int i=0; i<permMoves.size(); i++){
    std::cout << permMoves[i].first << ", " << permMoves[i].second << std::endl;
    }
    */
}

void Piece::computePermMovesKing(){
    int X[8] = {-1,-1,-1,0,0,1,1,1};
    int Y[8] = {-1,0,1,-1,-1,-1,0,1};
    for (int i=0; i<8; i++){
        int newCol = getCol() + X[i];
        int newRow = getRow() + Y[i];
        if (newCol>=1 && newCol<=8 && newRow>=1 && newRow<=8){
            permMoves.emplace_back(pair<int,int>(newCol,newRow));
        }
    }
}

// compute the permissible moves (that are of the nature of the piece)
void Piece::computePermMoves(){
    // Clear the old permissible moves
    permMoves.clear();
    // PAWN
    if (getType() == 'p'){
        computePermMovesPawn();
    }
    // KNIGHT
    else if(getType() == 'n'){
        computePermMovesKnight();
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
        computePermMovesKing();
    }
}

// move a piece
void Piece::movePiece(){
    char newMove[2];
    int newRow;
    char ansCol;
    int newCol;

    bool validMoveMade = false;
    while(!validMoveMade){
//        std::cout << "Give a move for " << (char)type << " " << num2char(col) << row << ": (e.g. e2)" << std::endl;
        std::cout << "Give a move: (e.g. e2)" << std::endl;
        cin >> newMove;
        newCol = char2num(newMove[0]);
        newRow =  newMove[1] - '0';

        pair<int,int> newMove (newCol,newRow);

        // check if the newMove is an allowed move
        bool allowed = false;
        for (auto & allowedMove : allowedMoves){
            std::cout << allowedMove.first << ", " << allowedMove.second << std::endl;
            if (newMove == allowedMove){
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
            // Determine whether this piece is eligible for an en passe capture
            if (abs(newRow - getRow()) == 2 && getType() == 'p'){
                enPasse = true;
            }
            else if (getType() == 'p'){
                enPasse = false;
            }
        }
        else{
            std::cout << "Not an allowed move" << std::endl;
        }
    }
}
