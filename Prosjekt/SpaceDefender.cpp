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
#include <fstream>
#include "nlohmann/json.hpp" 
using json = nlohmann::json;

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
            enemyShips.emplace_back(std::make_unique<SpaceShipEnemy>(SpaceShipEnemy(spacing * (i + 1), spacing * (j + 1))));
        }
    }
}

/**
 * @brief Set the current screen. 
 * 
 * Replaces the current screen with std::move(newScreen) of the unique_ptr<Screen>
 * @param newScreen The new screen that we want to point to
 * @param currentScreen The current screen that the pointer points to
 * @todo Add reset function
 */
void SpaceDefender::setScreen(std::unique_ptr<Screen> newScreen) {
    //currentScreen->reset();
    currentScreen = std::move(newScreen);
}

/**
 * @brief takes in a pointer to an enemy ship and a pointer to a weapon and checks if they have collided
 * 
 * the unique pointer should be deleated if they have collided
 * @param itEnemy the pointer to the enemy ship
 * @param it the pointer to the weapon class often a bullet
 * @return true if they have collided, false if not
 * @todo make the fuction general and happen, ok with takeing in unique pointer adresses
 */
bool SpaceDefender::checkCollision(std::unique_ptr<SpaceShipEnemy>& itEnemy, std::unique_ptr<Weapon>& it) {
    (void)itEnemy;
    (void)it;
    return false;
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
 * This function determines which enemy ship should fire a shot in the game. 
 * It ensures that only the front-line ships (i.e., the lowest ships in each column) are eligible to shoot. 
 * It then selects one of them at random to perform the shooting action, based on a timing condition.
 * @param now The current time
 * @param lowestShipsMap The map of the lowest ships in each column
 */
void SpaceDefender::findShipToKill() {
    auto now = std::chrono::steady_clock::now();
    if (enemyShips.empty()) return; // Safety check
    std::unordered_map<int, SpaceShipEnemy*> lowestShipsMap;
    for (auto & enemyShip : enemyShips) {
        const int posX = enemyShip->getPositionX();

        if (lowestShipsMap.find(posX) == lowestShipsMap.end() || enemyShip->getPositionY() > lowestShipsMap[posX]->getPositionY()) {
            lowestShipsMap[posX] = &*enemyShip;
        }
    }
    std::vector<SpaceShipEnemy*> lowestShips;
    for (auto& pair : lowestShipsMap) {
        lowestShips.push_back(pair.second);
    }
    // Select a random ship
    std::random_device rd;
    std::default_random_engine gen(rd());
    std::uniform_int_distribution<std::size_t> distribution(0, lowestShips.size() - 1);
    SpaceShipEnemy* chosenShip = lowestShips[distribution(gen)];

    if (std::chrono::duration_cast<std::chrono::milliseconds>(now - lastShotTimeAlien) >= fireRate) {
        chosenShip->shooting(*this);
        lastShotTimeAlien = now;
    }

}

/**
 * @brief Moves the enemy ships swarm as a whole
 * 
 * Updates the position of each enemy ship in the swarm. If any enemy reaches the screen edge, the swarm reverses direction. 
 * Every 4th edge hit causes the swarm to drop down vertically. 
 * The swarm speed increases as the number of remaining enemies decreases.
 * @param enemiesShouldDrop Bool that determines if the swarm should drop when reaching the edge 4 times.
 * @param deltaX Precompute horizontal movement to avoid repeated computation
 */
void SpaceDefender::enemySwarmMovement() {
    bool enemiesShouldDrop = false;
    for (auto & enemyShipPtr : enemyShips) {
        int posX = enemyShipPtr->getPositionX();
        int rightEdge = this->width() - enemyShipPtr->getShipWidth() - 10;

        if (posX >= rightEdge || posX <= 10) {
            enemyDirection *= -1;
            ++enemiesDropCounter;
            enemiesShouldDrop = (enemiesDropCounter % 4 == 0);
            break;  // Only need to change once per frame
        }
    }
    int deltaX = static_cast<int>(enemySpeed) * enemyDirection;
    for (auto & enemyShipPtr : enemyShips) {
        if (enemiesShouldDrop) {
            enemyShipPtr->updatePosition(deltaX,enemyDropDistance);
        }
        else {
            enemyShipPtr->updatePosition(deltaX);
        }
    }
    /** @todo Make the speed better in regards to double vs int, since most functions use int for the positions */
    enemySpeed = enemyShipCount/static_cast<double>(enemyShips.size());  // Swarm moves faster after each enemy is killed 
}


void SpaceDefender::writeScores(const std::string& filename) {
    (void)filename;
    /*
    std::vector<Player> players;
    std::ifstream file(filename);

    if (!file) {std::cout << "Error opening file: " << filename << std::endl;}
    // Step 1: Read existing scores
    json jsonData;
    file >> jsonData;
    for (const auto& entry : jsonData.at("highscores")) {
        players.push_back({entry.at("rank"), entry.at("player"), entry.at("score"), entry.at("round")});
    }

    // Step 2: Insert the new player in the right position

    // Step 3: Update ranks

    // Step 4: Write back to the file

    */
}
