#include "Connect4Board.h"
#include <iostream>

using namespace std;

// constructor to initialize the board
Connect4Board::Connect4Board(): Board(6, 7) {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            board[i][j] = '0';
        }
    }
    status = '0';
}
bool Connect4Board::dropDisc(int column, char player) {
    int playerWhowonThetie ;
    if (column < 0 || column >= 7) {
        return false; // Invalid column
    }
    if (status != '0') {
        throw "This board is already finished!";
    }
    for (int i = 5; i >= 0; --i) {
        if (board[i][column] == '0') {
            board[i][column] = player;
            checkWin(player); // Check if the move wins the game

            if (isTie()){
                playerWhowonThetie = tieBreaker(); // If it's a tie, determine the winner using the tiebreaker
            }
            return true; // Disc dropped successfully
        }
    }
    return false; // Column is full
}

bool Connect4Board::checkWin(char player) {
    // Check for horizontal wins
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] == player && board[i][j + 1] == player && board[i][j + 2] == player && board[i][j + 3] == player) {
                status = player;
                return true;
            }
        }
    }

    // Check for vertical wins
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (board[i][j] == player && board[i + 1][j] == player && board[i + 2][j] == player && board[i + 3][j] == player) {
                status = player;
                return true;
            }
        }
    }

    // Check for diagonal wins (top-left to bottom-right)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player) {
                status = player;
                return true;
            }
        }
    }

    // Check for diagonal wins (top-right to bottom-left)
    for (int i = 0; i < 3; ++i) {
        for (int j = 3; j < 7; ++j) {
            if (board[i][j] == player && board[i + 1][j - 1] == player && board[i + 2][j - 2] == player && board[i + 3][j - 3] == player) {
                status = player;
                return true;
            }
        }
    }

    return false;
}
void Connect4Board::displayBoard() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool Connect4Board::isFull() {
    for (int j = 0; j < 7; ++j) {
        if (board[0][j] == '0') {
            return false; // At least one column is not full
        }
    }
    return true; // All columns are full
}

int Connect4Board::tieBreaker(){
    int player1Count = 0; 
    int player2Count = 0;
    int Rowvalue  =  7;

    for (int i = 0; i < 6; ++i) { 
        Rowvalue --;
        for (int j = 0; j < 7; ++j) {
            if (board[i][j] == player1) {
                player1Count++;
            } else if (board[i][j] == player2) {
                player2Count++;
            }
        }
    }
    if (player1Count >player2Count) {
        status = player1;
        return 1; // Player 1 wins the tiebreaker
    } else if (player2Count > player1Count) {
        status = player2;
        return 0; // Player 2 wins the tiebreaker
    } else {
        status = player1;
        return 1; // Player 1 wins by default if the count is the same.
    }
}

bool Connect4Board::isTie() {
    return isFull() && !checkWin(player1) && !checkWin(player2);
}

char Connect4Board::getCell(int row, int column) const {
    if (row < 0 || row >= 6 || column < 0 || column >= 7) {
        throw "Invalid cell position!";
    }

    return board[row][column];
}

char Connect4Board::getStatus() const {
    return status;
}