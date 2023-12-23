#ifndef GAME_H
#define GAME_H

#include "Snake.h"
#include "Food.h"

#include <iostream>
#include <conio.h>
#include <windows.h>

class Game {
private:
    bool gameOver;
    const int width;
    const int height;
    Snake snake;
    Food fruit;
    int score;
    int *tailX;
    int *tailY;
    int nTail;
    enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    eDirection dir;

public:
    Game(int w, int h) : width(w), height(h), snake(w / 2, h / 2), fruit(rand() % w, rand() % h) {
        gameOver = false;
        dir = STOP;
        score = 0;
        tailX = new int[width * height];
        tailY = new int[width * height];
        nTail = 0;
    }

    ~Game() {
        delete[] tailX;
        delete[] tailY;
    }

    void Draw();

    void Input();

    void Logic();

    void RunGame();
};

#endif