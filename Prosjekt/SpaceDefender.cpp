/**
 * @file SpaceDefender.cpp
 * @author Tor Gunnar Ravatn Hammer (tor.ravatn@gmail.com)
 * @author Gabriel Anton Norheim ()
 * @brief The cpp file for the SpaceDefender class
 * @version 1.0
 * @date 2025-04-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "SpaceDefender.h"
#include <iostream>
#include <random>


/**
 * @brief Construct a new SpaceDefender::SpaceDefender object
 * 
 * @param position Position of where the window starts in upper left corner
 * @param width The width of the window
 * @param height The height of the window
 * @param title The title of the window
 * @param numEnemiesHeight The number of enemies in the height of the window
 * @param numEnemiesWidth The number of enemies in the width of the window
 */
SpaceDefender::SpaceDefender(TDT4102::Point position, int width, int height, const std::string& title): 
    AnimationWindow(position.x, position.y, width, height, title),
    currentScreen(nullptr),
    btnWidth(static_cast<unsigned int>(width * 0.4)),      // 40% of window width
    btnHeight(static_cast<unsigned int>(height * 0.08)),   // 8% of window height 

    // Position buttons relatively
    StartGameBtn( TDT4102::Point(width / 2 - static_cast<int>(btnWidth / 2), static_cast<int>(height * 0.3)),                   btnWidth, btnHeight, "Start Game"),
    HighscoresBtn(TDT4102::Point(width / 2 - static_cast<int>(btnWidth / 2), static_cast<int>(height * 0.3 + btnHeight * 1.2)), btnWidth, btnHeight, "Highscores"),
    SettingsBtn(  TDT4102::Point(width / 2 - static_cast<int>(btnWidth / 2), static_cast<int>(height * 0.3 + btnHeight * 2.4)), btnWidth, btnHeight, "Settings"),
    EndGameBtn(   TDT4102::Point(width / 2 - static_cast<int>(btnWidth / 2), static_cast<int>(height * 0.3 + btnHeight * 3.6)), btnWidth, btnHeight, "End Game"),
    GoToMenuBtn(  TDT4102::Point(0, 0), btnWidth/3, btnHeight, "Back"),

    playerShip(width/2,height*4/5),
    enemyShips(),
    firedWeapons()
{
    setBackgroundColor(TDT4102::Color::black);

    // Add buttons
    add(StartGameBtn);
    add(HighscoresBtn);
    add(SettingsBtn);
    add(EndGameBtn);
    add(GoToMenuBtn);

    // Set button callbacks
    StartGameBtn.setCallback(std::bind(&SpaceDefender::cb_startGame, this));
    HighscoresBtn.setCallback(std::bind(&SpaceDefender::cb_showHighscores, this));
    SettingsBtn.setCallback(std::bind(&SpaceDefender::cb_settings, this));
    EndGameBtn.setCallback(std::bind(&SpaceDefender::cb_endGame, this));
    GoToMenuBtn.setCallback(std::bind(&SpaceDefender::cb_menu, this));

    // Add enemies to enemyShips vector
    int numEnemiesHeight = 5; /** @todo Fix how enemies spawn */
    int numEnemiesWidth = 10; /** @todo Need dynamic */
    int spacing = width / (numEnemiesWidth + 1);
    for (int j = 0;j < numEnemiesHeight;++j) {
        for (int i = 0; i < numEnemiesWidth; ++i) {
            enemyShips.emplace_back(spacing * (i + 1), spacing * (j + 1));
        }
    }
}

/**
 * @brief Set the current screen. 
 * 
 *  Replaces the current screen with std::move(newScreen) of the unique_ptr<Screen>
 * @param newScreen The new screen that we want to point to
 * @param currentScreen The current screen that the pointer points to
 */
void SpaceDefender::setScreen(std::unique_ptr<Screen> newScreen) {
    currentScreen = std::move(newScreen);
}

/**
 * @brief Game loop that runs the game until the window is closed
 * 
 * Updates the game state and draws the current screen
 * @param currentScreen Draws the current screen as long as its not a null pointer
 */
void SpaceDefender::run() {
    while (!should_close()) {
        next_frame();

        if (currentScreen) {
            currentScreen->draw(*this);         // Draw the current screen
        }
    }
}

/**
 * @brief Finds the ship to kill
 * 
 */
void SpaceDefender::findShipToKill() {
    auto now = std::chrono::steady_clock::now();
    if (enemyShips.empty()) return; // Safety check
    std::unordered_map<int, SpaceShipEnemy*> lowestShipsMap;

    for (auto & enemyShip : enemyShips) {
        const int posX = enemyShip.getPositionX();
        const int posY = enemyShip.getPositionY();

        if (lowestShipsMap.find(posX) == lowestShipsMap.end() || enemyShip.getPositionY() > lowestShipsMap[posX]->getPositionY()) {
            lowestShipsMap[posX] = &enemyShip;
        }
    }
    std::vector<SpaceShipEnemy*> lowestShips;
    for (auto& pair : lowestShipsMap) {
        lowestShips.push_back(pair.second);
    }
    // Select a random ship
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, lowestShips.size() - 1);
    SpaceShipEnemy* chosenShip = lowestShips[distr(gen)];

    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - lastShotTimeAlien) >= fireRate) {
        chosenShip->shooting(*this);
        lastShotTimeAlien = now;
    }

}