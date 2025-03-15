#pragma once

#include "SpaceDefender.h"
#include "Screen.h"  // Include the base Screen class

class ScreenGame : public Screen {
public:
    void draw(SpaceDefender& window) override;
    void handleInput(SpaceDefender& window) override;
};
