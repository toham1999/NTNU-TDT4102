#include "std_lib_facilities.h"
#include "SpaceDefender.h"
#include "ScreenMenu.h"
#include "ScreenHighscore.h"

int main() {
    // Create SpaceDefender window and initialize with MenuScreen
    SpaceDefender game({100, 100}, 600, 400, "Space Defender");
    game.setScreen(std::make_unique<ScreenMenu>());
    game.run();
    return 0;
}