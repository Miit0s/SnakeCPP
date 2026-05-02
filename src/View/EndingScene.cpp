#include "EndingScene.h"

void EndingScene::init(const int* screenWidth, const int* screenHeight)
{
    
}

void EndingScene::update(int* currentScreen)
{
    if (IsKeyPressed(KEY_ENTER))
    {
        *currentScreen = 1;
    }
}

void EndingScene::draw(const int* screenWidth, const int* screenHeight)
{
    ClearBackground(RAYWHITE);
    DrawRectangle(0, 0, *screenWidth, *screenHeight, RAYWHITE);
    DrawText("Game Over", 20, 20, 40, GRAY);
    DrawText("Press ENTER to REPLAY", 120, 220, 20, GRAY);
}
