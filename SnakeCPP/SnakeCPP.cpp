#include "raylib.h"
#include "cstdint"
#include "View/EndingView.h"
#include "View/GameView.h"
#include "View/TitleView.h"

constexpr int screenWidth{800};
constexpr int screenHeight{450};

TitleView title_view{};
GameView game_view{};
EndingView ending_view{};

void reinitView()
{
    title_view.init(&screenWidth, &screenHeight);
    game_view.init(&screenWidth, &screenHeight);
    ending_view.init(&screenWidth, &screenHeight);
}

int main() {
    int current_scene{0};
    int previous_scene{0};
    
    View* current_view = &title_view;
    
    InitWindow(screenWidth, screenHeight, "SnakeCPP");
    SetTargetFPS(60);

    reinitView();

    while (!WindowShouldClose()) {
        switch (current_scene)
        {
            case 0:
                {
                    current_view = &title_view;
                }
                break;
            case 1:
                {
                    current_view = &game_view;
                }
                break;
            case 2:
                {
                    current_view = &ending_view;
                }
            break;
        }

        if (current_scene != previous_scene) {
            reinitView();
            previous_scene = current_scene;
        }

        current_view->update(&current_scene);
        BeginDrawing();
        current_view->draw(&screenWidth, &screenHeight);
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}