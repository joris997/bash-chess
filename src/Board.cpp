#include "Board.h"
#include "colTrans.h"
#include <iostream>

// General check functions
Piece Board::getKing(int color){
    for (auto & piece : pieces){
        if (piece.getType() == 'k' && piece.getCol() == color){
            return piece;
        }
    }
}

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

bool Board::isOnBoard(pair<int,int> potentialPair){
    if (potentialPair.first > 0 && potentialPair.first < 9 &&
            potentialPair.second > 0 && potentialPair.second < 9){
        return true;
    }
    else {
        return false;
    }
}


// Allowed moves functions
void Board::computeAllowedMovesKing(Piece &piece){
    pair<int,int> potentialPair(0,0);

    for (int i=-1; i<2; i+=2){
        for (int ii=-1; ii<2; ii+=2){
            potentialPair.first = piece.getCol()+i;
            potentialPair.second = piece.getRow()+i;
            if (getColor(potentialPair) == 0 ||
                    getColor(potentialPair) == -1*piece.getColor() &&
                    isOnBoard(potentialPair)){
                piece.allowedMoves.push_back(potentialPair);
            }
        }
    }
}

void Board::computeAllowedMovesKnight(Piece &piece){
    int knightMovesColumns[8] = {-2,-2,-1,-1,1,1,2,2};
    int knightMovesRows[8] = {1,-1,2,-2,2,-2,1,-1};
    pair<int,int> potentialPair(0,0);

    for (auto & col : knightMovesColumns){
        for (auto & row : knightMovesRows){
            potentialPair.first = piece.getCol() + col;
            potentialPair.second = piece.getRow() + row;
            if (getColor(potentialPair) != piece.getColor() && isOnBoard(potentialPair)){
                piece.allowedMoves.push_back(potentialPair);
            }
        }
    }

}

void Board::computeAllowedMovesPawn(Piece &piece){
    pair<int,int> potentialPair(piece.getCol(), piece.getRow()+1);
    if (!isOccupied(potentialPair) && isOnBoard(potentialPair)){
        piece.allowedMoves.push_back(potentialPair);
    }
    potentialPair.first = piece.getCol(); potentialPair.second = piece.getRow()+2;
    if (!isOccupied(potentialPair) && piece.getMoveCnt()==0 && isOnBoard(potentialPair)){
        piece.allowedMoves.push_back(potentialPair);
    }
    // Can you capture a piece front left from you?
    potentialPair.first = piece.getCol()-1; potentialPair.second = piece.getRow()+piece.getColor();
    if (getColor(potentialPair) != piece.getColor() && isOnBoard(potentialPair)){
        piece.allowedMoves.emplace_back(potentialPair);
    }
    // Can you capture a piece front right from you?
    potentialPair.first = piece.getCol()+1; potentialPair.second = piece.getRow()+piece.getColor();
    if (getColor(potentialPair) != piece.getColor() && isOnBoard(potentialPair)){
        piece.allowedMoves.emplace_back(potentialPair);
    }
    // Can you capture a piece en passe left?
    potentialPair.first = piece.getCol()-1; potentialPair.second = piece.getRow();
    // check if there even is a piece
    if (getColor(potentialPair) != 0){
        // check if opposite color and if en passe is possible
        if (getColor(potentialPair) != piece.getColor() &&
                getPiece(potentialPair).getEnPasse() &&
                isOnBoard(potentialPair)){
            piece.allowedMoves.emplace_back(potentialPair);
        }
    }
    // Can you capture a piece en pass right?
    potentialPair.first = piece.getCol()+1; potentialPair.second = piece.getRow();
    if (getColor(potentialPair) != 0){
        if (getColor(potentialPair) != piece.getColor() &&
                getPiece(potentialPair).getEnPasse() &&
                isOnBoard(potentialPair)){
            piece.allowedMoves.emplace_back(potentialPair);
        }
    }

}

void Board::computeAllowedMovesBishop(Piece &piece){
    for (int i=1; i<=8; i++){
        // Only permit moves that are within the board
        if (piece.getCol()+i >= 1 && piece.getCol()+i <= 8 &&
                piece.getRow()+i >= 1 && piece.getRow()+i <= 8){
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
        if (piece.getCol()-i >= 1 && piece.getCol()-i <= 8 &&
                piece.getRow()+i >= 1 && piece.getRow()+i <= 8){
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
        if (piece.getCol()-i >= 1 && piece.getCol()-i <= 8 &&
                piece.getRow()-i >= 1 && piece.getRow()-i <= 8){
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
        if (piece.getCol()+i >= 1 && piece.getCol()+i <= 8 &&
                piece.getRow()-i >= 1 && piece.getRow()-i <= 8){
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
        // the knight and king 'jump' so here only check if color does not correspond
        if (piece.getType() == 'k'){
            computeAllowedMovesKing(piece);
        }

        if (piece.getType() == 'n'){
            computeAllowedMovesKnight(piece);
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

bool Board::checkCheckmate(int color){
    int pieceLoopCount = 0;
    int totalUncheckMoves = 0;

    // check if the playing color is even under check
    if (checkCheck(color)){
        for (auto & piece : pieces){
            // for all the pieces of the playing person's color
            if (piece.getColor() == color){
                // outright remove all the moves (they might not solve check)
                if (pieceLoopCount == 0){
                    piece.allowedMoves.clear();
                }
                // loop through all the allowed moves of each piece
                for (auto & move : piece.allowedMoves){
                    Board plusOneMove = *this;
                    plusOneMove.pieces[0].changeCol(move.first);
                    plusOneMove.pieces[0].changeRow(move.second);
                    // if it prevents check
                    if (!plusOneMove.checkCheck(color)){
                        // add it to the cleared allowed moves again
                        piece.allowedMoves.emplace_back(
                                    pair<int,int> (move.first,move.second));
                        pieceLoopCount += 1;
                        totalUncheckMoves += 1;
                    }
                }
            }
        }
    }
    if (totalUncheckMoves > 0){
        return false;
    } else {
        return true;
    }
}
bool Board::checkCheck(int color){
    bool check = false;

    for (auto & piece : pieces){
        if (piece.getColor() == -1*color){
            for (auto & move : piece.allowedMoves){
                if (move.first == getKing(color).getCol()
                        && move.second == getKing(color).getRow()){
                    check = true;
                    std::cout << "CHECK!!!" << std::endl;
                }
            }
        }
    }
    return check;
}

// check win-condition, checkmate, stalemate
bool Board::checkWin(int color){
    // if other king's allowed moves is empty and other king in check return true
    return checkCheckmate(-1*color);
}

// moving pieces, color = 1 for white, color = -1 for black
void Board::move(int color){
    computeAllowedMoves();

    // announce which color is to move
    if (color == 1){
        cout << "White to move!" << std::endl;
    }
    else {
        cout << "Black to move!" << std::endl;
    }

    // while loop until a valid move has been made
    // (selecting the wrong move or wrong piece)
    bool validMoveMade = false;
    while (!validMoveMade){
        // get the piece that needs to be moved
        char movePiece[3];
        int moveCol;
        int moveRow;

        cout << "Piece you want to move: (e.g. e2)" << std::endl;
        cin >> movePiece;

        moveCol = char2num(movePiece[0]);
        moveRow =  movePiece[1] - '0';

        // find the piece in the pieces vector that needs to be moved
        bool exists = false;
        int pieceLoc;
        for (int p=0; p<pieces.size(); p++){
            if (pieces[p].getColor() == color && pieces[p].getCol() == moveCol
                    && pieces[p].getRow() == moveRow){
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
            cout << "Not a valid piece" << std::endl;
        }
    }
}

void Board::dispBoard(){
    // TODO: ensure printing distinct pieces instead of "p" etc.
    system("clear");
    cout << "   -----------------" << std::endl;
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
        cout << "|" << std::endl;
    }
    cout << "   -----------------" << std::endl;
    cout << "    a b c d e f g h " << std::endl;
}

void Board::playGame(){
    while(true){
        dispBoard();
        // white to move
        move(1);
        if (checkWin(1)){
            std::cout << "White won!" << std::endl;
            break;
        }
        dispBoard();
        // black to move
        move(-1);
        if (checkWin(-1)){
            std::cout << "Black won!" << std::endl;
            break;
        }
    }
}
