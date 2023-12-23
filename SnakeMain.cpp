#include "Game.h"

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    Game game(20, 20);
    game.RunGame();
    return 0;
}