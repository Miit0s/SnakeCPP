#pragma once
#include "Scene.h"
#include "../Game/Fruit.h"
#include "../Game/Snake.h"

class GameScene: public Scene
{
public:
    void init(const int* screen_width, const int* screen_height) override;
    void update(int* current_screen) override;
    void draw(const int* screen_width, const int* screen_height) override;

private:
    const int CELLSIZE{25};

    int number_of_horizontal_lines_{};
    int number_of_vertical_lines_{};

    Snake snake_{};
    Fruit fruit_{};

    void drawHorizontalLine(const int* screen_width, const int* screen_height);
    void drawVerticalLine(const int* screen_width, const int* screen_height);
    void drawRectangleAtPos(Vector2* pos, Color* color);

    void checkIfSnakeHasEatFruit();
    
    bool checkIfSquareIsFree(Vector2 squarePos);
    void changeFruitPos();
};
