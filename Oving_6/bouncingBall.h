#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

struct Config{ 
    // BEGIN: 4a
    int colour_up;
    int colour_down;
    int velocity;
    // END: 4a
};

extern map<int, Color> ball_colour;

istream& operator>>(istream& is, Config& cfg);

void bouncingBall();
