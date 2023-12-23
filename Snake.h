#ifndef SNAKE_H
#define SNAKE_H

class Snake {
private:
    int x, y;
public:
    Snake(int startX, int startY) : x(startX), y(startY) {}
    int getX() const { return x; }
    int getY() const { return y; }
    void move(int newX, int newY) { x = newX; y = newY; }
};

#endif