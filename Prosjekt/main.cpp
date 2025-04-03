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
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

/**
 * @fn int main()
 * @brief Starts the game 
 * @param game SpaceDefender object
 * @return Returns 0 on success 
 */
int main() {    
    // Create SpaceDefender window and initialize with MenuScreen
    SpaceDefender game{};
    game.setScreen(std::make_unique<ScreenHighscore>());
    game.run();
    return 0;
}