#include "GameView.h"
#include "../Enum/SnakeDirectionEnum.h"
#include <cmath>
#include <iostream>
#include <ostream>
#include "../Tools/Random.h"

void GameView::init(const int* screen_width, const int* screen_height)
{
    number_of_horizontal_lines = *screen_height/CELLSIZE;
    number_of_vertical_lines = *screen_width/CELLSIZE;

    const float snake_head_x = std::round(static_cast<float>(number_of_vertical_lines)/3);
    const float snake_head_y = std::round(static_cast<float>(number_of_horizontal_lines)/2);
    
    snake_body_pos_[0] = Vector2{snake_head_x, snake_head_y};
    
    moveFruit();
}

void GameView::update(int* current_screen)
{
    if (snakeIsDead()) {
        *current_screen = 2;
    }

    if (!snake_has_choose_next_move_)
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

void GameView::draw(const int* screen_width, const int* screen_height)
{
    ClearBackground(RAYWHITE);
    
    number_of_horizontal_lines = *screen_height/CELLSIZE;
    number_of_vertical_lines = *screen_width/CELLSIZE;

    drawHorizontalLine(screen_width, screen_height);
    drawVerticalLine(screen_width, screen_height);

    drawRectangleAtPos(&fruit_position_, &fruit_color_);
    drawRectangleAtPos(&snake_body_pos_[0], &snake_head_color_);

    for (int i = 1; i < snake_current_length_; i++)
    {
        drawRectangleAtPos(&snake_body_pos_[i], &snake_body_color_);
    }
}

void GameView::drawHorizontalLine(const int* screen_width, const int* screen_height)
{
    for (int i = 0; i < number_of_horizontal_lines; i++)
    {
        const Vector2 start_pos{0, static_cast<float>(CELLSIZE) * static_cast<float>(i)};
        const Vector2 end_pos{static_cast<float>(*screen_width), static_cast<float>(CELLSIZE) * static_cast<float>(i)};
        DrawLineV(start_pos, end_pos, GRAY);
    }
}

void GameView::drawVerticalLine(const int* screen_width, const int* screen_height)
{
    for (int j = 0; j < number_of_vertical_lines; j++)
    {
        const Vector2 start_pos{static_cast<float>(CELLSIZE) * static_cast<float>(j), 0};
        const Vector2 end_pos{static_cast<float>(CELLSIZE) * static_cast<float>(j), static_cast<float>(*screen_height)};
        DrawLineV(start_pos, end_pos, GRAY);
    }
}

void GameView::drawRectangleAtPos(Vector2* pos, Color* color)
{
    const int x_pos{CELLSIZE * (static_cast<int>(pos->x)-1)}, y_pos{CELLSIZE * (static_cast<int>(pos->y)-1)};
    DrawRectangle(x_pos, y_pos, CELLSIZE, CELLSIZE, *color);
}

void GameView::chooseNextDirection()
{
    if (IsKeyPressed(KEY_W) && snake_direction_ != Down)
    {
        snake_direction_ = Up;
        snake_has_choose_next_move_ = true;
    }
    else if (IsKeyPressed(KEY_S) && snake_direction_ != Up)
    {
        snake_direction_ = Down;
        snake_has_choose_next_move_ = true;
    }
    else if (IsKeyPressed(KEY_A) && snake_direction_ != Right)
    {
        snake_direction_ = Left;
        snake_has_choose_next_move_ = true;
    }
    else if (IsKeyPressed(KEY_D) && snake_direction_ != Left)
    {
        snake_direction_ = Right;
        snake_has_choose_next_move_ = true;
    }
}

void GameView::moveSnake()
{
    moveSnakeTail();
    moveSnakeHead();

    if (snake_body_pos_[0].x == fruit_position_.x && snake_body_pos_[0].y == fruit_position_.y)
    {
        snake_current_length_++;
        moveFruit();
    }
}

void GameView::moveSnakeHead()
{
    switch (snake_direction_)
    {
    case Up: snake_body_pos_[0].y -= 1; break;
    case Down: snake_body_pos_[0].y += 1; break;
    case Left: snake_body_pos_[0].x -= 1; break;
    case Right: snake_body_pos_[0].x += 1; break;
    }
    snake_can_move_ = false;
    snake_has_choose_next_move_ = false;
}

void GameView::moveSnakeTail()
{
    for (int i = snake_current_length_; i > 0; i--)
    {
        snake_body_pos_[i] = snake_body_pos_[i-1];
    }
}

void GameView::moveFruit()
{
    const float fruit_pos_x{Random::RandomFloat(1, number_of_vertical_lines)};
    const float fruit_pos_y{Random::RandomFloat(1, number_of_horizontal_lines)};

    std::cout << "fruit_position_.x: " << fruit_pos_x << '\n';
    std::cout << "fruit_position_.y: " << fruit_pos_y << '\n';
    
    fruit_position_ = Vector2{fruit_pos_x, fruit_pos_y};
}

bool GameView::snakeIsDead()
{
    return checkIfSnakeIsOutOfBound() || checkIfSnakeIsCollideWithHisTales();
}

bool GameView::checkIfSnakeIsOutOfBound()
{
    const bool out_of_bound_x{0 >= snake_body_pos_[0].x || snake_body_pos_[0].x >= static_cast<float>(number_of_vertical_lines)};
    const bool out_of_bound_y{0 >= snake_body_pos_[0].y || snake_body_pos_[0].y >= static_cast<float>(number_of_horizontal_lines)};

    return out_of_bound_x || out_of_bound_y;
}

bool GameView::checkIfSnakeIsCollideWithHisTales()
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