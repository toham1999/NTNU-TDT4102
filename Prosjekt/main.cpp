/**
 * @file main.cpp
 * @author Tor Gunnar Ravatn Hammer (tor.ravatn@gmail.com)
 * @author Gabriel Anton Norheim ()
 * @brief Main file
 * @version 1.0
 * @date 2025-04-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "std_lib_facilities.h"
#include "SpaceDefender.h"

/**
 * @fn int main()
 * @brief Starts the game 
 * @param game SpaceDefender object
 * @return Returns 0 on success 
 */
int main() {
    // Create SpaceDefender window and initialize with MenuScreen
    SpaceDefender game{};
    game.setScreen(std::make_unique<ScreenMenu>());
    game.run();
    return 0;
}