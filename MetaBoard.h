#include "Connect4Board.h"
#include "Board.h"

class MetaBoard: public Board {
    private:
        Connect4Board board[3][3]; // 3x3 grid of Connect4Boards
        public:
        MetaBoard(); // Constructor to initialize the meta board
        char checkMetaWin(char player1 , char player2);
        void displayBoard(); 
        
}