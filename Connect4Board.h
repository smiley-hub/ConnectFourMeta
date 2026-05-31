
#include "Board.h"
class Connect4Board: public Board {
    private:
        char board[6][7]; // 6 rows and 7 columns for Connect 4
    public:
        Connect4Board(); // Constructor to initialize the board     
        bool dropDisc(int column, char player); // Method to drop a disc in the specified column for the given player
        bool checkWin(char player); // Method to check if the given player has won   
        void displayBoard(); // Method to display the current state of the board
};