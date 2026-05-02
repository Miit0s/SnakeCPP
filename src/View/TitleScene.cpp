#include "TitleScene.h"

void TitleScene::init(const int* screenWidth, const int* screenHeight)
{
    
}

void TitleScene::update(int* currentScreen)
{
    if (IsKeyPressed(KEY_ENTER))
    {
        *currentScreen = 1;
    }
}

void TitleScene::draw(const int* screenWidth, const int* screenHeight)
{
    ClearBackground(RAYWHITE);
    DrawRectangle(0, 0, *screenWidth, *screenHeight, WHITE);
    DrawText("Sake Game", 20, 20, 40, GRAY);
    DrawText("Press ENTER to START", 120, 220, 20, GRAY);
}
