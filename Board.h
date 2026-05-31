// this is an abstract class 
#ifndef BOARD_H
#define BOARD_H


class Board { 
    protected:
        char player1;
        char player2;
    public:
        Board(char p1, char p2);
        virtual void displayBoard() ; // Pure virtual method to display the current state of the board
};

#endif // BOARD_H