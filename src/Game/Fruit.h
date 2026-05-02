#pragma once
#include <raylib.h>

class Fruit
{
public:
    Color fruit_color_{RED};
    
    Vector2 fruit_position_{};
    
    void moveFruit(int* number_of_vertical_lines_, int* number_of_horizontal_lines_);
};
