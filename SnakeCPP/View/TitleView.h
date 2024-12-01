#pragma once
#include "View.h"

class TitleView: public View
{
public:
    void Update(int* currentScreen) override;
    void Draw(const int* screenWidth, const int* screenHeight) override;
};
