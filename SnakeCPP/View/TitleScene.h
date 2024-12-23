#pragma once
#include "Scene.h"

class TitleScene: public Scene
{
public:
    void init(const int* screenWidth, const int* screenHeight) override;
    void update(int* currentScreen) override;
    void draw(const int* screenWidth, const int* screenHeight) override;
};
