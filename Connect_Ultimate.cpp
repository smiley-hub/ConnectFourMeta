#include "Connect_Ultimate.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Connect_Ultimate::Connect_Ultimate() {
    player1 = 'X';
    player2 = 'O';

    srand(time(0));
}

void Connect_Ultimate::playGame() {
    MetaBoard metaBoard1;
    MetaBoard metaBoard2;

    char round1Winner;
    char round2Winner;
    char finalWinner;

    cout << "Welcome to Ultimate Connect 4!" << endl;

    round1Winner = playNormalRound(metaBoard1, 1);
    round2Winner = playNormalRound(metaBoard2, 2);

    if (round1Winner == round2Winner) {
        finalWinner = round1Winner;

        cout << endl;
        cout << "Player " << finalWinner << " wins the whole game!" << endl;
    }
    else {
        cout << endl;
        cout << "Each player won one round." << endl;
        cout << "Starting special third round..." << endl;

        finalWinner = playThirdRound(metaBoard1, metaBoard2);

        cout << endl;
        cout << "Player " << finalWinner << " wins the whole game!" << endl;
    }
}

char Connect_Ultimate::playNormalRound(MetaBoard& metaBoard, int roundNumber) {
    char winner;

    do {
        cout << endl;
        cout << "Starting Round... " << roundNumber << endl;
      

        winner = playMetaBoard(metaBoard);

        if (winner == 'D') {
            cout << "The meta-board ended in a draw." << endl;
            cout << "This round does not count. Restarting round..." << endl;

            metaBoard = MetaBoard();
        }

    } while (winner == 'D');

    cout << "Round " << roundNumber << " winner: Player " << winner << endl;

    return winner;
}

char Connect_Ultimate::playMetaBoard(MetaBoard& metaBoard) {
    char currentPlayer = player1;
    char winner = '0';

    while (winner == '0') {
        int boardRow;
        int boardCol;
        int column;

        metaBoard.displayBoard();

        cout << "Player " << currentPlayer << ", enter board row (0-2): ";
        cin >> boardRow;

        cout << "Player " << currentPlayer << ", enter board column (0-2): ";
        cin >> boardCol;

        cout << "Player " << currentPlayer << ", enter column to drop disc (0-6): ";
        cin >> column;

        try {
            if (!metaBoard.dropDisc(boardRow, boardCol, column, currentPlayer)) {
                cout << "Invalid move! Please try again." << endl;
                continue;
            }
        }
        catch (const char* message) {
            cout << "Error: " << message << endl;
            continue;
        }

        winner = metaBoard.checkMetaWin(player1, player2);

        if (winner == 'D') {
            metaBoard.displayBoard();
            return 'D';
        }

        if (winner == player1 || winner == player2) {
            metaBoard.displayBoard();
            return winner;
        }

        if (currentPlayer == player1) {
            currentPlayer = player2;
        }
        else {
            currentPlayer = player1;
        }
    }

    return winner;
}

char Connect_Ultimate::additionResult(char first, char second) {
    if (first == player1 || second == player1) {
        return player1;
    }

    if (first == player2 || second == player2) {
        return player2;
    }

    return '0';
}

char Connect_Ultimate::subtractionResult(char first, char second) {
    if (first == '0' && second == '0') {
        return '0';
    }

    if (first == '0') {
        return second;
    }

    if (second == '0') {
        return first;
    }

    if (first == second) {
        return first;
    }

    return player2;
}

char Connect_Ultimate::probabilityWinnerAddition(MetaBoard& metaBoard1, MetaBoard& metaBoard2) {
    char resultBoard[3][3];
    char winner;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultBoard[i][j] = additionResult(
                metaBoard1.getSmallBoardStatus(i, j),
                metaBoard2.getSmallBoardStatus(i, j)
            );
        }
    }

    cout << endl;
    cout << "Round 3 operation selected: Addition (+)" << endl;

    printResultBoard(resultBoard);

    winner = checkResultBoardWinner(resultBoard);

    if (winner == '0') {
        cout << "No 3-in-a-row winner from addition result." << endl;
        cout << "Choosing random winner..." << endl;

        winner = randomWinner();
    }

    cout << "Round 3 winner: Player " << winner << endl;

    return winner;
}

char Connect_Ultimate::probabilityWinnerSubtraction(MetaBoard& metaBoard1, MetaBoard& metaBoard2) {
    char resultBoard[3][3];
    char winner;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            resultBoard[i][j] = subtractionResult(
                metaBoard1.getSmallBoardStatus(i, j),
                metaBoard2.getSmallBoardStatus(i, j)
            );
        }
    }

    cout << endl;
    cout << "Round 3 operation selected: Subtraction (-)" << endl;

    printResultBoard(resultBoard);

    winner = checkResultBoardWinner(resultBoard);

    if (winner == '0') {
        cout << "No 3-in-a-row winner from subtraction result." << endl;
        cout << "Choosing random winner..." << endl;

        winner = randomWinner();
    }

    cout << "Round 3 winner: Player " << winner << endl;

    return winner;
}

char Connect_Ultimate::playThirdRound(MetaBoard& metaBoard1, MetaBoard& metaBoard2) {
    int randomChoice;

    randomChoice = rand() % 2;

    if (randomChoice == 0) {
        return probabilityWinnerAddition(metaBoard1, metaBoard2);
    }

    return probabilityWinnerSubtraction(metaBoard1, metaBoard2);
}

char Connect_Ultimate::checkResultBoardWinner(char resultBoard[3][3]) {
    int winningLines[8][3][2] = {
        {{0, 0}, {0, 1}, {0, 2}},
        {{1, 0}, {1, 1}, {1, 2}},
        {{2, 0}, {2, 1}, {2, 2}},

        {{0, 0}, {1, 0}, {2, 0}},
        {{0, 1}, {1, 1}, {2, 1}},
        {{0, 2}, {1, 2}, {2, 2}},

        {{0, 0}, {1, 1}, {2, 2}},
        {{0, 2}, {1, 1}, {2, 0}}
    };

    for (int i = 0; i < 8; i++) {
        int row1 = winningLines[i][0][0];
        int col1 = winningLines[i][0][1];

        int row2 = winningLines[i][1][0];
        int col2 = winningLines[i][1][1];

        int row3 = winningLines[i][2][0];
        int col3 = winningLines[i][2][1];

        if (resultBoard[row1][col1] != '0' &&
            resultBoard[row1][col1] == resultBoard[row2][col2] &&
            resultBoard[row2][col2] == resultBoard[row3][col3]) {
            return resultBoard[row1][col1];
        }
    }

    return '0';
}

char Connect_Ultimate::randomWinner() {
    int randomNumber;

    randomNumber = rand() % 2;

    if (randomNumber == 0) {
        return player1;
    }

    return player2;
}

void Connect_Ultimate::printResultBoard(char resultBoard[3][3]) {
    cout << endl;
    cout << "Round 3 Result Board:" << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << resultBoard[i][j] << " ";
        }

        cout << endl;
    }

    cout << endl;
}