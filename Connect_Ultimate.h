#ifndef CONNECT_ULTIMATE_H
#define CONNECT_ULTIMATE_H

#include "MetaBoard.h"

class Connect_Ultimate {
private:
    char player1;
    char player2;

    char playMetaBoard(MetaBoard& metaBoard);
    char playNormalRound(MetaBoard& metaBoard, int roundNumber);

    char additionResult(char first, char second);
    char subtractionResult(char first, char second);

    char probabilityWinnerAddition(MetaBoard& metaBoard1, MetaBoard& metaBoard2);
    char probabilityWinnerSubtraction(MetaBoard& metaBoard1, MetaBoard& metaBoard2);

    char playThirdRound(MetaBoard& metaBoard1, MetaBoard& metaBoard2);

    char checkResultBoardWinner(char resultBoard[3][3]);
    char randomWinner();

    void printResultBoard(char resultBoard[3][3]);

public:
    Connect_Ultimate();

    void playGame();
};

#endif