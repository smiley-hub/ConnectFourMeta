#include "MetaBoard.h"
#include <iostream>
using namespace std;


MetaBoard::MetaBoard()
    : Board('X', 'O'), board{} {
}

char MetaBoard::checkMetaWin(char player1, char player2) {
    char winnerboard[9];
    char winner;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int index = checkboardNumber(i, j);
            winnerboard[index] = board[i][j].getStatus();
        }
    }

    int winningLines[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    for (int i = 0; i < 8; i++) {
        int first = winningLines[i][0];
        int second = winningLines[i][1];
        int third = winningLines[i][2];

        if (winnerboard[first] != '0' && winnerboard[first] == winnerboard[second] && winnerboard[second] == winnerboard[third]) {
            winner = winnerboard[first];
            if (winner == player1) {
                return player1; // Player 1 wins
            } else if (winner == player2) {
                return player2; // Player 2 wins
            }
            else {
                throw "Invalid winner status!";
            }
        }
    }
    if (isFull()){
         return 'D'; // Tie
        }

    return '0'; 
}



int MetaBoard::checkboardNumber(int row, int col){
    if (row == 0 && col == 0) return 0;
    if (row == 0 && col == 1) return 1;
    if (row == 0 && col == 2) return 2;
    if (row == 1 && col == 0) return 3;     
    if (row == 1 && col == 1) return 4;
    if (row == 1 && col == 2) return 5;
    if (row == 2 && col == 0) return 6;
    if (row == 2 && col == 1) return 7;
    if (row == 2 && col == 2) return 8;
    return -1; // Invalid row or column

}


void MetaBoard::displayBoard() {
    int metaRow;
    int metaCol;
    int smallRow;
    int smallCol;

    for (metaRow = 0; metaRow < 3; metaRow++) {

        for (smallRow = 0; smallRow < 6; smallRow++) {

            for (metaCol = 0; metaCol < 3; metaCol++) {

                for (smallCol = 0; smallCol < 7; smallCol++) {
                    cout << board[metaRow][metaCol].getCell(smallRow, smallCol) << " ";
                }

                cout << "     "; // space between small boards
            }

            cout << endl;
        }

        cout << endl; // space between meta-board rows
    }
}

bool MetaBoard::isFull() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (!board[i][j].isFull()) {
                return false; // At least one small board is not full
            }
        }
    }
    return true; // All small boards are full
}

bool MetaBoard::dropDisc(int boardRow, int boardCol, int column, char player) {
    if (boardRow < 0 || boardRow > 2 || boardCol < 0 || boardCol > 2) {
        throw "Invalid board position! Row and column must be between 0 and 2.";
        
    }
    return board[boardRow][boardCol].dropDisc(column, player);
}

char MetaBoard::getSmallBoardStatus(int row, int col) const {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        throw "Invalid board position! Row and column must be between 0 and 2.";
    }
    return board[row][col].getStatus();