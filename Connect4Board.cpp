#include "Connect4Board.h"
#include <iostream>

using namespace std;

// constructor to initialize the board
Connect4Board::Connect4Board()
    : Board(6, 7) {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            board[i][j] = '0';
        }
    }
}
bool Connect4Board::dropDisc(int column, char player) {
    if (column < 0 || column >= 7) {
        return false; // Invalid column
    }
    for (int i = 5; i >= 0; --i) {
        if (board[i][column] == '0') {
            board[i][column] = player;
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
                return true;
            }
        }
    }

    // Check for vertical wins
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (board[i][j] == player && board[i + 1][j] == player && board[i + 2][j] == player && board[i + 3][j] == player) {
                return true;
            }
        }
    }

    // Check for diagonal wins (top-left to bottom-right)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player) {
                return true;
            }
        }
    }

    // Check for diagonal wins (top-right to bottom-left)
    for (int i = 0; i < 3; ++i) {
        for (int j = 3; j < 7; ++j) {
            if (board[i][j] == player && board[i + 1][j - 1] == player && board[i + 2][j - 2] == player && board[i + 3][j - 3] == player) {
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