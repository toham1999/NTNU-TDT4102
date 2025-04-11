/**
 * @file SpaceDefender.h
 * @author Tor Gunnar Ravatn Hammer (tor.ravatn@gmail.com)
 * @author Gabriel Anton Norheim (gabriel.norheim@gmail.com)
 * @brief The header file for the SpaceDefender class
 * @version 1.0
 * @date 2025-04-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once

#include "AnimationWindow.h"
#include "widgets/Button.h"

#include "Screen.h"
#include "SpaceShip.h"
#include "Weapon.h"

/**
 * @class SpaceDefender
 * @brief The main game class which runs the game. Uses AnimationWindow as base class
 * @param currentScreen Pointer to the current screen
 * @param btnWidth Width of the buttons. Relative to window width
 * @param btnHeight Height of the buttons. Relative to window height
 * @param playerShip PlayerShip object
 * @param enemyShips Vector of EnemyShip objects
 * @param firedWeapons Vector of Weapon objects
 * @param enemySpeed Speed of the enemy ships swarm
 * @param enemyDirection Direction of the enemy ships swarm, 1 = right, -1 = left
 * 
 */
class SpaceDefender : public TDT4102::AnimationWindow {
private:
	std::unique_ptr<Screen> currentScreen;
    unsigned int btnWidth;
    unsigned int btnHeight;

    // Callback functions for buttons
    void cb_endGame()        {close();} /**< Close the game callback function */
    void cb_startGame()      {setScreen(std::make_unique<ScreenGame>());} /**< Start the game callback function */
    void cb_showHighscores() {setScreen(std::make_unique<ScreenHighscore>());} /**< Show the highscores callback function */
    void cb_settings()       {setScreen(std::make_unique<ScreenSettings>());} /**< Show the settings callback function */
    void cb_menu()           {setScreen(std::make_unique<ScreenMenu>()); } /**< Show the menu callback function */

public:
    SpaceDefender(TDT4102::Point position = {100, 50}, int width = 600, int height = 650, const std::string& title = "Space Defender");
    void setScreen(std::unique_ptr<Screen> newScreen);
    void run();
    // Helper functions
    void findShipToKill();
    void enemySwarmMovement();
    void writeScores(const std::string& filename);
    void addHearts();
    TDT4102::Image heart = TDT4102::Image("bilder/pixel-heart.png");
    double enemySpeed = 1.0;                  // Pixels per movement step
    int enemyDirection = 1;              // 1 for right, -1 for left
    int enemyDropDistance = 7;           // Drop when hitting screen edge
    int enemiesDropCounter = 0;
    int enemyShipCount = 50;
    int score = 0;

    std::chrono::steady_clock::time_point lastShotTimeAlien;
    const std::chrono::milliseconds fireRate = std::chrono::milliseconds(1000);

    // Buttons
    TDT4102::Button StartGameBtn;
    TDT4102::Button HighscoresBtn;
	TDT4102::Button SettingsBtn;
    TDT4102::Button EndGameBtn;
	TDT4102::Button GoToMenuBtn;

	// Spaceships 
	SpaceShipPlayer playerShip;
    std::vector<std::unique_ptr<SpaceShipEnemy>> enemyShips; //canged to unique

    // Weapons
    std::vector<std::unique_ptr<Weapon>> firedWeapons; /** @todo Will the weapons be deleted? Since we are putting bullet in there?*/

    //Check collision
    bool checkCollision(std::unique_ptr<SpaceShipEnemy>& ship, std::unique_ptr<Weapon>& bullet);
};
