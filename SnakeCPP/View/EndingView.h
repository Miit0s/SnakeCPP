#pragma once
#include "View.h"

class EndingView: public View
{
public:
    void init(const int* screenWidth, const int* screenHeight) override;
    void update(int* currentScreen) override;
    void draw(const int* screenWidth, const int* screenHeight) override;
};
