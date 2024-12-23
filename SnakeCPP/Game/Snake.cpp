#include "Snake.h"

void Snake::init(Vector2 snake_start_pos)
{
    snake_current_length_ = 1;
    snake_direction_ = Right;
    frame_counter_ = 0;

    snake_body_pos_[0] = snake_start_pos;
}

void Snake::update()
{
    if (!has_choose_next_move_)
    {
        chooseNextDirection();
    }

    if (snake_can_move_)
    {
        moveSnake();
    }

    const float time_elapsed{static_cast<float>(frame_counter_)/60};
    if (time_elapsed >= MOVEMENTDELAY)
    {
        snake_can_move_ = true;
        frame_counter_ = 0;
    }
    
    frame_counter_++;
}

void Snake::chooseNextDirection()
{
    if (IsKeyPressed(KEY_W) && snake_direction_ != Down)
    {
        snake_direction_ = Up;
        has_choose_next_move_ = true;
    }
    else if (IsKeyPressed(KEY_S) && snake_direction_ != Up)
    {
        snake_direction_ = Down;
        has_choose_next_move_ = true;
    }
    else if (IsKeyPressed(KEY_A) && snake_direction_ != Right)
    {
        snake_direction_ = Left;
        has_choose_next_move_ = true;
    }
    else if (IsKeyPressed(KEY_D) && snake_direction_ != Left)
    {
        snake_direction_ = Right;
        has_choose_next_move_ = true;
    }
}


void Snake::moveSnake()
{
    moveSnakeTail();
    moveSnakeHead();
}

void Snake::moveSnakeHead()
{
    switch (snake_direction_)
    {
    case Up: snake_body_pos_[0].y -= 1; break;
    case Down: snake_body_pos_[0].y += 1; break;
    case Left: snake_body_pos_[0].x -= 1; break;
    case Right: snake_body_pos_[0].x += 1; break;
    }
    snake_can_move_ = false;
    has_choose_next_move_ = false;
}

void Snake::moveSnakeTail()
{
    for (int i = snake_current_length_; i > 0; i--)
    {
        snake_body_pos_[i] = snake_body_pos_[i-1];
    }
}

void Snake::growSnake()
{
    snake_current_length_++;
}

Vector2 Snake::getSnakeHeadPos()
{
    return snake_body_pos_[0];
}

int Snake::getSnakeLength()
{
    return snake_current_length_;
}

bool Snake::snakeIsDead(int* number_of_vertical_lines_, int* number_of_horizontal_lines_)
{
    return checkIfSnakeIsOutOfBound(number_of_vertical_lines_, number_of_horizontal_lines_) || checkIfSnakeIsCollideWithHisTales();
}

bool Snake::checkIfSnakeIsOutOfBound(int* number_of_vertical_lines_, int* number_of_horizontal_lines_)
{
    const bool out_of_bound_x{0 >= snake_body_pos_[0].x || snake_body_pos_[0].x > static_cast<float>(*number_of_vertical_lines_)};
    const bool out_of_bound_y{0 >= snake_body_pos_[0].y || snake_body_pos_[0].y > static_cast<float>(*number_of_horizontal_lines_)};

    return out_of_bound_x || out_of_bound_y;
}

bool Snake::checkIfSnakeIsCollideWithHisTales()
{
    const Vector2 snake_head_pos{snake_body_pos_[0]};
    for (int i = 1; i < snake_current_length_; i++)
    {
        if (snake_body_pos_[i].x == snake_head_pos.x && snake_body_pos_[i].y == snake_head_pos.y)
        {
            return true;
        }
    }
    return false;
}
