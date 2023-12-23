#include "Game.h"

using namespace std;

void Game::Draw()
{

     system("cls");
        for (int i = 0; i < width + 2; i++)
            cout << "#";
        cout << endl;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j == 0)
                    cout << "#";
                if (i == snake.getY() && j == snake.getX())
                    cout << "O";
                else if (i == fruit.getY() && j == fruit.getX())
                    cout << "F";
                else {
                    bool printTail = false;
                    for (int k = 0; k < nTail; k++) {
                        if (tailX[k] == j && tailY[k] == i) {
                            cout << "o";
                            printTail = true;
                        }
                    }
                    if (!printTail)
                        cout << " ";
                }

                if (j == width - 1)
                    cout << "#";
            }
            cout << endl;
        }

        for (int i = 0; i < width + 2; i++)
            cout << "#";
        cout << endl;
        cout << "Score:" << score << endl;


}

void Game::Input()
{

    if (_kbhit()) {
            switch (_getch()) {
                case 'a':
                    dir = LEFT;
                    break;
                case 'd':
                    dir = RIGHT;
                    break;
                case 'w':
                    dir = UP;
                    break;
                case 's':
                    dir = DOWN;
                    break;
                case 'x':
                    gameOver = true;
                    break;
            }
        }

}

void Game::Logic()
{

    int prevX = tailX[0];
        int prevY = tailY[0];
        int prev2X, prev2Y;
        tailX[0] = snake.getX();
        tailY[0] = snake.getY();
        for (int i = 1; i < nTail; i++) {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }
        switch (dir) {
            case LEFT:
                snake.move(snake.getX() - 1, snake.getY());
                break;
            case RIGHT:
                snake.move(snake.getX() + 1, snake.getY());
                break;
            case UP:
                snake.move(snake.getX(), snake.getY() - 1);
                break;
            case DOWN:
                snake.move(snake.getX(), snake.getY() + 1);
                break;
            default:
                break;
        }
        if (snake.getX() >= width) snake.move(0, snake.getY());
        else if (snake.getX() < 0) snake.move(width - 1, snake.getY());
        if (snake.getY() >= height) snake.move(snake.getX(), 0);
        else if (snake.getY() < 0) snake.move(snake.getX(), height - 1);

        for (int i = 0; i < nTail; i++)
            if (tailX[i] == snake.getX() && tailY[i] == snake.getY())
                gameOver = true;

        if (snake.getX() == fruit.getX() && snake.getY() == fruit.getY()) {
            score += 10;
            fruit.setPosition(rand() % width, rand() % height);
            nTail++;
        }

}

void Game::RunGame()
{

    while (!gameOver) {
            Draw();
            Input();
            Logic();
            Sleep(100);
        }

}
