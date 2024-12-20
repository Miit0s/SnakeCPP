#pragma once
#include "View.h"
#include "../Enum/SnakeDirectionEnum.h"

#define SNAKE_LENGTH 256

class GameView: public View
{
public:
    void init(const int* screen_width, const int* screen_height) override;
    void update(int* current_screen) override;
    void draw(const int* screen_width, const int* screen_height) override;

private:
    const int CELLSIZE{25};

    int number_of_horizontal_lines{};
    int number_of_vertical_lines{};

    bool game_over_{false};
    
    Vector2 snake_body_pos_[SNAKE_LENGTH]{};
    int snake_current_length_{1};

    Vector2 fruit_position_{};

    const float MOVEMENTDELAY{0.2f};
    bool snake_can_move_{false};
    bool snake_has_choose_next_move_{false};
    SnakeDirectionEnum snake_direction_{Right};

    int frame_counter_{0};

    Color snake_head_color_{DARKGREEN};
    Color snake_body_color_{GREEN};
    Color fruit_color_{RED};

    void drawHorizontalLine(const int* screen_width, const int* screen_height);
    void drawVerticalLine(const int* screen_width, const int* screen_height);
    void drawRectangleAtPos(Vector2* pos, Color* color);
    
    void moveSnake();
    void moveSnakeHead();
    void moveSnakeTail();
    void moveFruit();

    void chooseNextDirection();
};
