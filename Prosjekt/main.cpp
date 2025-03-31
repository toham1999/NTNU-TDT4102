#include "std_lib_facilities.h"
#include "SpaceDefender.h"


int main() {
    // Create SpaceDefender window and initialize with MenuScreen
    SpaceDefender game{};
    game.setScreen(std::make_unique<ScreenMenu>());
    game.run();
    return 0;
}