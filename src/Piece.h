#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <iostream>
#include "colTrans.h"

using namespace std;

class Piece{
    private:
        int row;
        int col;
        // number of moves made by the piece
        int moveCnt;
        // is the en passe capture available on this piece?
        bool enPasse;
        // white = 1, black = -1
        int color;
        // 'p', 'n', 'b', 'r', 'q', 'k' for pawn, knight, bishop, rook, queen, king
        char type;
        // permissible moves for the piece
        vector<pair<int,int>> permMoves;

    // Reserve maximum size of 21, this is the maximum possible moves for an empty board queen
        Piece(){
        permMoves.reserve(21);
        allowedMoves.reserve(21);
        }

    public:
        vector<pair<int,int>> allowedMoves;

        // getting
        int getRow() const{return row;}
        int getCol() const{return col;}
        bool getEnPasse() const{return enPasse;}
        int getMoveCnt() const{return moveCnt;}
        int getColor() const{return color;}
        char getType() const{return type;}
        vector<pair<int,int>> getPermMoves(){return permMoves;}
        vector<pair<int,int>> getAllowedMoves(){return allowedMoves;}
        // setting
        void changeRow(int newRow){row = newRow;}
        void changeCol(int newCol){col = newCol;}
        void changeMoveCnt(int newMoveCnt){moveCnt = newMoveCnt;}
        void changeType(char newType){type = newType;}
        // template member functions
        void computePermMovesPawn();
        void computePermMovesKnight();
        void computePermMovesBishop();
        void computePermMovesRook();
        void computePermMovesKing();
        void computePermMoves();
        void movePiece();

    // constructor
    explicit Piece(const int row, const int col, const int color, const char type)
    : row(row), col(col), moveCnt(0), color(color), type(type)
    {}
//        cout << "Created a " << color << " " << (char)type << " at " << num2char(col) << row << endl;
//    }
};
#endif
