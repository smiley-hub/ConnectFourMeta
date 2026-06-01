#ifndef BOARD_H
#define BOARD_H

class Board { 
    protected:
        char player1;
        char player2;
    public:
        Board(char p1, char p2) : player1(p1), player2(p2) {}
        virtual ~Board() = default;
        virtual void displayBoard() = 0; // Pure virtual method to display the current state of the board
       
};

#endif // BOARD_H
