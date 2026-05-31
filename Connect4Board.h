#ifndef CONNECT4BOARD_H
#define CONNECT4BOARD_H

#include "Board.h"

class Connect4Board: public Board {
    private:
        char board[6][7]; // 6 rows and 7 columns for Connect 4
    public:
        Connect4Board(); 
        bool dropDisc(int column, char player); 
        bool checkWin(char player); 
        bool isFull();  
        bool isTie();
        void displayBoard() override;

        char  getCell(int row, int col) const; // Method to get the value of a specific cell on the board
};

#endif // CONNECT4BOARD_H
