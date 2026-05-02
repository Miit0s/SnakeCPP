#pragma once
#include <raylib.h>
#include "../Enum/SnakeDirectionEnum.h"

#define SNAKE_MAX_LENGTH 576

class Snake
{
public:
    Color snake_head_color_{DARKGREEN};
    Color snake_body_color_{GREEN};
    
    Vector2 snake_body_pos_[SNAKE_MAX_LENGTH]{};

    int frame_counter_{0};

    void init(Vector2 snake_start_pos);

    Vector2 getSnakeHeadPos();
    int getSnakeLength();

    void update();

    bool snakeIsDead(int* number_of_vertical_lines_, int* number_of_horizontal_lines_);
    void growSnake();
private:
    const float MOVEMENTDELAY{0.2f};
    
    int snake_current_length_{1};
    bool snake_can_move_{false};
    bool has_choose_next_move_{false};
    SnakeDirectionEnum snake_direction_{Right};

    void chooseNextDirection();

    void moveSnake();
    void moveSnakeHead();
    void moveSnakeTail();
    
    bool checkIfSnakeIsOutOfBound(int* number_of_vertical_lines_, int* number_of_horizontal_lines_);
    bool checkIfSnakeIsCollideWithHisTales();
};
