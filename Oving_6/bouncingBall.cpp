#include "bouncingBall.h"

// BEGIN: 4b
map<int, Color> ball_colour 
{
    {1,Color::aqua},
    {2,Color::burly_wood},
    {3,Color::tomato},
    {4,Color::rebecca_purple}
};
// END: 4b

// BEGIN: 4c
istream& operator>>(istream& is, Config& cfg)
{
    is >> cfg.colour_up >> cfg.colour_down >> cfg.velocity;
    
    if (!is) 
    {
        std::cout << "Feil ved lesing av konfigurasjonen!" << std::endl;
    }
    return is;
}
// END: 4c

constexpr Point BOUNCE_WINDOW_TOP_LEFT{50, 50};
constexpr int BOUNCE_WINDOW_WIDTH{800}; 
constexpr int BOUNCE_WINDOW_HEIGHT{500};

// FJERN DETTE NAAR DU BEGYNNER PÅ OPPGAVE 4e)
//#define BOUNCING_BALL
//

void bouncingBall(){
    #ifndef BOUNCING_BALL
    AnimationWindow window{BOUNCE_WINDOW_TOP_LEFT.x, BOUNCE_WINDOW_TOP_LEFT.y, 
                           BOUNCE_WINDOW_WIDTH, BOUNCE_WINDOW_HEIGHT, "Bouncing ball"};
    
    const int radius{30};
    int alpha{1};
    int velocity{2};
    Color colour_up{Color::blue};
    Color colour_down{Color::blue};
    int x{0};
    int y{360};
    int increment_x{0};
    int increment_y{0};
    int count_bounce_top{0};
    int count_bounce_bottom{0};
    int count_num_passes{0};

    Config slow = {1, 1, 0};
    Config fast = {1, 1, 0};

    // read in the configurations
    filesystem::path file_name{"konfigurasjon.txt"};
    ifstream is{file_name};
    is >> slow >> fast; 

    // initialise the run
    velocity = slow.velocity;
    colour_up = ball_colour.at(slow.colour_up);
    colour_down = ball_colour.at(slow.colour_down);

    int radiusBall = 50;
    Color movingColor;
    string upDownSwitch = "down";
    while (!window.should_close()) {
        // determine increments based on the velocity
        increment_x = velocity * cos(alpha);
        increment_y = velocity * sin(alpha);

        // movement i x-direction
        if ((increment_x + x) > window.width()) {
            // reached right side - wrap around to the leftmost
            x = 0;
            // increment counter which counts number of full left-to-right passes
            count_num_passes++;
            // alternate between slow and fast configuration every second pass
            if (count_num_passes % 2 == 0) {
                if (velocity == slow.velocity) {
                    velocity = fast.velocity;
                    colour_up = ball_colour.at(fast.colour_up);
                    colour_down = ball_colour.at(fast.colour_down);
                } else {
                    velocity = slow.velocity;
                    colour_up = ball_colour.at(slow.colour_up);
                    colour_down = ball_colour.at(slow.colour_down);
                }
            }
        } 
        else 
        {
            // moving rightwards
            x += increment_x;
        }
        // HINT 1: Ta en titt på koden ovenfor og se hvilke variabler som brukes. 
        // Bruk disse variablene for å implementere bevegelsen til den sprettende ballen. For eksempel:
        // Variablene count_bounce_top og count_bounce_bottom kan brukes
        // for å holde styr på hvilken retning ballen skal gå. 
        // Variabelen increment_y skal brukes for å øke y.

        // HINT 2: window.draw_circle({x, y}, r, c) tegner en sirkel med radius r, 
        // sentrum i (x, y) og fargen c

        // BEGIN: 4d
        // movement in y-direction
        if ((increment_y + y) > (window.height() - radiusBall)) 
        {
            upDownSwitch = "up";
        }
        else if ((increment_y + y) < radiusBall) 
        {
            upDownSwitch = "down";
        } 

        if (upDownSwitch == "down")
        {
            y += increment_y;
            movingColor = colour_down;
        }
        if (upDownSwitch == "up")
        {
            y -= increment_y;
            movingColor = colour_up;
        }


        if (x < 2*radiusBall)
        {
            window.draw_circle({x+window.width(), y}, radiusBall, movingColor);
        }
        if (x > window.width() - 2*radiusBall)
        {
            window.draw_circle({x-window.width(), y}, radiusBall, movingColor);
        }
        window.draw_circle({x, y}, radiusBall, movingColor);
        // END: 4d
    
        window.next_frame();
    }
    #endif
}