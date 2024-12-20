#pragma once
#include "raylib.h"

class View {
public:
    virtual ~View() = default;

    virtual void init(const int* screenWidth, const int* screenHeight) = 0;
    virtual void update(int* currentScreen) = 0;
    virtual void draw(const int* screenWidth, const int* screenHeight) = 0;
};