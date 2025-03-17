#include "SpaceDefender.h"

#include <iostream>

SpaceDefender::SpaceDefender(TDT4102::Point position, int width, int height, const std::string& title): 
    AnimationWindow(position.x, position.y, width, height, title),
    StartGameBtn({200, 200}, 150, 50, "Start Game"),
    HighscoresBtn({200, 270}, 150, 50, "Highscores"),
    SettingsBtn({200, 300}, 150, 50, "Settings"),
    EndGameBtn({200, 340}, 150, 50, "End Game"),
    GoToMenuBtn({250, 340}, 150, 50, "Back to menu"),

    playerShip(width/2,height*4/5),
    enemyShips(),
    currentScreen(nullptr)
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
    unsigned int numEnemiesHeight = 5;
    unsigned int numEnemiesWidth = 10;
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
        playerShip.movements(*this);
        if (currentScreen) {
            currentScreen->draw(*this);         // Draw the current screen
        }
    }
}