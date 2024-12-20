#pragma once
#include "View.h"

class TitleView: public View
{
public:
    void init(const int* screenWidth, const int* screenHeight) override;
    void update(int* currentScreen) override;
    void draw(const int* screenWidth, const int* screenHeight) override;
};
