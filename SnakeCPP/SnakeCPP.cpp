#include "raylib.h"
#include "cstdint"
#include "View/EndingView.h"
#include "View/GameView.h"
#include "View/TitleView.h"

constexpr int screenWidth{800};
constexpr int screenHeight{450};

TitleView titleView{};
GameView gameView{};
EndingView endingView{};

int main() {
    int currentScene{0};
    View* currentView = &titleView;
    
    InitWindow(screenWidth, screenHeight, "SnakeCPP");
    SetTargetFPS(60);

    ClearBackground(RAYWHITE);

    while (!WindowShouldClose()) {
        switch (currentScene)
        {
            case 0:
                {
                    currentView = &titleView;
                }
                break;
            case 1:
                {
                    currentView = &gameView;
                }
                break;
            case 2:
                {
                    currentView = &endingView;
                }
            break;
        }

        currentView->Update(&currentScene);
        BeginDrawing();
        currentView->Draw(&screenWidth, &screenHeight);
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}

