# include "MetaBoard.h"
#include <iostream>
using namespace std;


MetaBoard::MetaBoard() {
    // The Connect4Board constructor will automatically initialize each board
}

char MetaBoard::checkMetaWin(char player1, char player2){
    char winnerboard [9];
    int index = 0 ;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j].checkWin(player1)) {
                winnerboard[checkboardNumber(i, j)] = player1;
            }
            if (board[i][j].checkWin(player2)) {
                winnerboard[checkboardNumber(i, j)] = player2;
            }
            else {
                winnerboard[checkboardNumber(i, j)] = '0'; // No winner for this board
            }

        }
    }
   
//check for a winner who has won 3 in a row in the meta board. that the winner of the metboard

    for (int i = 0; i < 6; ++i) {
        if (winnerboard[i]==winnerboard[i+1] && winnerboard[i+1]==winnerboard[i+2]) {
            if (winnerboard[i] == player1) {
                return player1;
            }
            if (winnerboard[i] == player2) {
                return player2;
            }
        }
    }
    return '0'; // No winner in the meta board
   

}

int checkboardNumber(int row, int col){
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