#include "EndingView.h"

void EndingView::init(const int* screenWidth, const int* screenHeight)
{
    
}

void EndingView::update(int* currentScreen)
{
    if (IsKeyPressed(KEY_ENTER))
    {
        *currentScreen = 0;
    }
}

void EndingView::draw(const int* screenWidth, const int* screenHeight)
{
    ClearBackground(RAYWHITE);
    DrawRectangle(0, 0, *screenWidth, *screenHeight, RED);
    DrawText("ENDING SCREEN", 20, 20, 40, DARKBROWN);
    DrawText("PRESS ENTER to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKBROWN);
}
