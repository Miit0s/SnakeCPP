#include "Fruit.h"
#include "../Tools/Random.h"

void Fruit::moveFruit(int* number_of_vertical_lines_, int* number_of_horizontal_lines_)
{
    const float fruit_pos_x{Random::RandomFloat(1, *number_of_vertical_lines_)};
    const float fruit_pos_y{Random::RandomFloat(1, *number_of_horizontal_lines_)};
    
    fruit_position_ = Vector2{fruit_pos_x, fruit_pos_y};
}