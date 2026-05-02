#pragma once
#include "raylib.h"

class Scene {
public:
    virtual ~Scene() = default;

    virtual void init(const int* screenWidth, const int* screenHeight) = 0;
    virtual void update(int* currentScreen) = 0;
    virtual void draw(const int* screenWidth, const int* screenHeight) = 0;
};