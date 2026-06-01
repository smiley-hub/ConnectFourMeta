#include <iostream>
#include "Connect_Ultimate.h"

using namespace std;

int main() {
    try {
        Connect_Ultimate game;
        game.playGame();
    }
    catch (const char* message) {
        cout << "Program error: " << message << endl;
    }

    return 0;
}