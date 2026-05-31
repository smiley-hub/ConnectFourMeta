#ifndef CONNECT4BOARD_H
#define CONNECT4BOARD_H

#include "Board.h"

class Connect4Board: public Board {
    private:
        char board[6][7]; 
        char status ; // '0' for ongoing, 'X' for player 1 win, 'O' for player 2 win, 'T' for tie
    public:
        Connect4Board(); 
        bool dropDisc(int column, char player); 
        bool checkWin(char player); 
        bool isFull();  
        bool isTie();
        void displayBoard() override;
        int tieBreaker();
        
        char  getCell(int row, int col) const; // Method to get the value of a specific cell on the board
        char getStatus() const; // Method to get the current status of the board
};

#endif // CONNECT4BOARD_H
