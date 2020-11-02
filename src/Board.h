#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "Piece.h"

using namespace std;

class Board{
    public:
        vector<Piece> pieces;

    public:
        // Copy constructor
        Board(const Board &b){pieces = b.pieces;}

        // template class functions
        bool checkWin(int color);
        void move(int color);

        void playGame();
        void dispBoard();
        void computeAllowedMoves();

        Piece getPiece(pair<int,int> square);
        int getColor(pair<int,int> square);
        char getType(pair<int,int> square);
        bool isOccupied(pair<int,int> square);
        bool checkSelfCheck(Piece &pice, pair<int,int> square);

        void computeAllowedMovesKingKnight(Piece &piece);
        void computeAllowedMovesPawn(Piece &piece);
        void computeAllowedMovesBishop(Piece &piece);
        void computeAllowedMovesRook(Piece &piece);

    // constructor
    explicit Board()
    : pieces()
    {
        // TODO: allow manually adding pieces
        // order: row col color type
        char piece_order[] = {'r','n','b','q','k','b','n','r'};
        for (int i=0; i<8; i++){
            // white pieces
            cout << piece_order[i] << endl;
            pieces.emplace_back(Piece (1,i+1,1,piece_order[i]));
            pieces.emplace_back(Piece (2,i+1,1,'p'));
            // black pieces
            pieces.emplace_back(Piece (8,i+1,-1,piece_order[i]));
            pieces.emplace_back(Piece (7,i+1,-1,'p'));
        }
    }
};
#endif
