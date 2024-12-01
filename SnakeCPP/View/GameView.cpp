#include "GameView.h"

void GameView::Update(int* currentScreen) {
    if (IsKeyPressed(KEY_ENTER)) {
        *currentScreen = 2;
    }
}

void GameView::Draw(const int* screenWidth, const int* screenHeight) {
    DrawRectangle(0, 0, *screenWidth, *screenHeight, BLUE);
    DrawText("GAMEPLAY SCREEN", 20, 20, 40, DARKBLUE);
    DrawText("PRESS ENTER to JUMP to ENDING SCREEN", 120, 220, 20, DARKBLUE);
}
