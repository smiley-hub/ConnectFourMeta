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
        void displayBoard() override; 
        bool isFull();
        
};

#endif // METABOARD_H
