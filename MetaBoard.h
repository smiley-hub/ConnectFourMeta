#ifndef METABOARD_H
#define METABOARD_H

#include "Connect4Board.h"

class MetaBoard: public Board {
    private:
        Connect4Board board[3][3]; // 3x3 grid of Connect4Boards
        int checkboardNumber(int row, int col);

        public:
        MetaBoard(); // Constructor to initialize the meta board
        char checkMetaWin(char player1 , char player2);
        bool dropDisc(int boardRow, int boardCol, int column, char player) ; // Method to drop a disc into a specific sub-board
        void displayBoard() override; 
        bool isFull();
        char getSmallBoardStatus(int row, int col) const; // Method to get the status of a specific small board
        
};

#endif // METABOARD_H
