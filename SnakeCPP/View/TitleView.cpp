#include "TitleView.h"

void TitleView::init(const int* screenWidth, const int* screenHeight)
{
    
}

void TitleView::update(int* currentScreen)
{
    if (IsKeyPressed(KEY_ENTER))
    {
        *currentScreen = 1;
    }
}

void TitleView::draw(const int* screenWidth, const int* screenHeight)
{
    ClearBackground(RAYWHITE);
    DrawRectangle(0, 0, *screenWidth, *screenHeight, WHITE);
    DrawText("Sake Game", 20, 20, 40, GRAY);
    DrawText("Press ENTER to START", 120, 220, 20, GRAY);
}
