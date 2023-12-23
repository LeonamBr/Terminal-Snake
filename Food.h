#ifndef FOOD_H
#define FOOD_H

class Food {
private:
    int x, y;
public:
    Food(int startX, int startY) : x(startX), y(startY) {}
    int getX() const { return x; }
    int getY() const { return y; }
    void setPosition(int newX, int newY) { x = newX; y = newY; }
};

#endif