#include "GameScene.h"
#include <cmath>

void GameScene::init(const int* screen_width, const int* screen_height)
{
    number_of_horizontal_lines_ = *screen_height/CELLSIZE;
    number_of_vertical_lines_ = *screen_width/CELLSIZE;

    const float snake_head_x = std::round(static_cast<float>(number_of_vertical_lines_)/3);
    const float snake_head_y = std::round(static_cast<float>(number_of_horizontal_lines_)/2);

    snake_.init(Vector2{snake_head_x, snake_head_y});
    
    fruit_.moveFruit(&number_of_vertical_lines_, &number_of_horizontal_lines_);
}

void GameScene::update(int* current_screen)
{
    if (snake_.snakeIsDead(&number_of_vertical_lines_, &number_of_horizontal_lines_)) {
        *current_screen = 2;
    }

    snake_.update();
    checkIfSnakeHasEatFruit();
}

void GameScene::draw(const int* screen_width, const int* screen_height)
{
    ClearBackground(RAYWHITE);
    
    number_of_horizontal_lines_ = *screen_height/CELLSIZE;
    number_of_vertical_lines_ = *screen_width/CELLSIZE;

    drawHorizontalLine(screen_width, screen_height);
    drawVerticalLine(screen_width, screen_height);

    drawRectangleAtPos(&fruit_.fruit_position_, &fruit_.fruit_color_);
    drawRectangleAtPos(&snake_.snake_body_pos_[0], &snake_.snake_head_color_);

    for (int i = 1; i < snake_.getSnakeLength(); i++)
    {
        drawRectangleAtPos(&snake_.snake_body_pos_[i], &snake_.snake_body_color_);
    }
}

void GameScene::drawHorizontalLine(const int* screen_width, const int* screen_height)
{
    for (int i = 0; i < number_of_horizontal_lines_; i++)
    {
        const Vector2 start_pos{0, static_cast<float>(CELLSIZE) * static_cast<float>(i)};
        const Vector2 end_pos{static_cast<float>(*screen_width), static_cast<float>(CELLSIZE) * static_cast<float>(i)};
        DrawLineV(start_pos, end_pos, GRAY);
    }
}

void GameScene::drawVerticalLine(const int* screen_width, const int* screen_height)
{
    for (int j = 0; j < number_of_vertical_lines_; j++)
    {
        const Vector2 start_pos{static_cast<float>(CELLSIZE) * static_cast<float>(j), 0};
        const Vector2 end_pos{static_cast<float>(CELLSIZE) * static_cast<float>(j), static_cast<float>(*screen_height)};
        DrawLineV(start_pos, end_pos, GRAY);
    }
}

void GameScene::drawRectangleAtPos(Vector2* pos, Color* color)
{
    const int x_pos{CELLSIZE * (static_cast<int>(pos->x)-1)}, y_pos{CELLSIZE * (static_cast<int>(pos->y)-1)};
    DrawRectangle(x_pos, y_pos, CELLSIZE, CELLSIZE, *color);
}

bool GameScene::checkIfSquareIsFree(Vector2 squarePos)
{
    for (int i = 0; i < snake_.getSnakeLength(); i++)
    {
        if (snake_.snake_body_pos_[i].x == squarePos.x && snake_.snake_body_pos_[i].y == squarePos.y)
        {
            return false;
        }
    }
    return true;
}

void GameScene::checkIfSnakeHasEatFruit()
{
    const Vector2 snake_head_pos{snake_.getSnakeHeadPos()};
    if (snake_head_pos.x == fruit_.fruit_position_.x && snake_head_pos.y == fruit_.fruit_position_.y)
    {
        changeFruitPos();
        snake_.growSnake();
    }
}

//Yeah, this is a horrible solution to the issue, but for the moment It will be like that until I have the strength to change it
void GameScene::changeFruitPos()
{
    fruit_.moveFruit(&number_of_vertical_lines_, &number_of_horizontal_lines_);
    
    if (!checkIfSquareIsFree(fruit_.fruit_position_))
    {
        changeFruitPos();
    }
}
