#include "EndingView.h"

void EndingView::init(const int* screenWidth, const int* screenHeight)
{
    
}

void EndingView::update(int* currentScreen)
{
    if (IsKeyPressed(KEY_ENTER))
    {
        *currentScreen = 1;
    }
}

void EndingView::draw(const int* screenWidth, const int* screenHeight)
{
    ClearBackground(RAYWHITE);
    DrawRectangle(0, 0, *screenWidth, *screenHeight, RED);
    DrawText("Game Over", 20, 20, 40, DARKBROWN);
    DrawText("Press ENTER to REPLAY", 120, 220, 20, DARKBROWN);
}
