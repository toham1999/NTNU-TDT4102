/**
 * @file SpaceDefender.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-04-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "SpaceDefender.h"

#include <iostream>


/**
 * @brief Construct a new Space Defender:: Space Defender object
 * 
 * @param position 
 * @param width 
 * @param height 
 * @param title 
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
    int numEnemiesHeight = 5;
    int numEnemiesWidth = 10;
    int spacing = width / (numEnemiesWidth + 1);
    for (int j = 0;j < numEnemiesHeight;++j) {
        for (int i = 0; i < numEnemiesWidth; ++i) {
            enemyShips.emplace_back(spacing * (i + 1), spacing * (j + 1));
        }
    }
}

// Set the current screen
void SpaceDefender::setScreen(std::unique_ptr<Screen> newScreen) {
    currentScreen = std::move(newScreen);
}

// Callbacks
void SpaceDefender::cb_endGame()        {close();}
void SpaceDefender::cb_startGame()      {setScreen(std::make_unique<ScreenGame>());}
void SpaceDefender::cb_showHighscores() {setScreen(std::make_unique<ScreenHighscore>());}
void SpaceDefender::cb_settings()       {setScreen(std::make_unique<ScreenSettings>());}
void SpaceDefender::cb_menu()           {setScreen(std::make_unique<ScreenMenu>()); }


// Game loop
void SpaceDefender::run() {
    while (!should_close()) {
        next_frame();

        if (currentScreen) {
            currentScreen->draw(*this);         // Draw the current screen
        }
    }
}