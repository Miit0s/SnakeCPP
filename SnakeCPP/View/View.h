#pragma once
#include "raylib.h"

class View {
public:
    virtual ~View() = default;
    virtual void Update(int* currentScreen) = 0;
    virtual void Draw(const int* screenWidth, const int* screenHeight) = 0;
};