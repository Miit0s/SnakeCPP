#include "raylib.h"

typedef enum GameScreen { TITLE, GAMEPLAY, ENDING } GameScreen;

int main() {
    constexpr int screenWidth{800};
    constexpr int screenHeight{450};
    
    InitWindow(screenWidth, screenHeight, "SnakeCPP");
    SetTargetFPS(60);

    GameScreen currentScreen = TITLE;

    while (!WindowShouldClose()) {
        
        switch (currentScreen)
        {
            case TITLE:
                if (IsKeyPressed(KEY_ENTER))
                {
                    currentScreen = GAMEPLAY;
                }
            break;
            case GAMEPLAY:
                if (IsKeyPressed(KEY_ENTER))
                {
                    currentScreen = ENDING;
                }
            break;
            case ENDING:
                if (IsKeyPressed(KEY_ENTER))
                {
                    currentScreen = TITLE;
                }
            break;
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (currentScreen)
        {
            case TITLE:
                DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
                DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
                DrawText("PRESS ENTER to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);
            break;
            case GAMEPLAY:
                DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
                DrawText("GAMEPLAY SCREEN", 20, 20, 40, DARKBLUE);
                DrawText("PRESS ENTER to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKBLUE);
            break;
            case ENDING:
                DrawRectangle(0, 0, screenWidth, screenHeight, RED);
                DrawText("ENDING SCREEN", 20, 20, 40, DARKBROWN);
                DrawText("PRESS ENTER to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKBROWN);
            break;
        }
        
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}

