#include "TitleView.h"

void TitleView::Update(int* currentScreen)
{
    if (IsKeyPressed(KEY_ENTER))
    {
        *currentScreen = 1;
    }
}

void TitleView::Draw(const int* screenWidth, const int* screenHeight)
{
    DrawRectangle(0, 0, *screenWidth, *screenHeight, GREEN);
    DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
    DrawText("PRESS ENTER to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);
}
