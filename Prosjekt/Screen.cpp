/**
 * @file Screen.cpp
 * @author Tor Gunnar Ravatn Hammer (tor.ravatn@gmail.com)
 * @brief The cpp file for the Screen class
 * @version 1.0
 * @date 2025-04-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Screen.h"
#include "SpaceDefender.h"



/**
 * @fn void ScreenMenu::draw(SpaceDefender& window)
 * @brief Draws the screencontent of the Menu
 * 
 * Draws the menu screen where it shows all the buttons exept the back button.
 * @param window SpaceDefender object
 */
void ScreenMenu::draw(SpaceDefender& window) {
    window.StartGameBtn.setVisible(true);
    window.HighscoresBtn.setVisible(true);
    window.SettingsBtn.setVisible(true);
    window.EndGameBtn.setVisible(true);
    window.GoToMenuBtn.setVisible(false);
}


/**
 * @fn void ScreenGame::draw(SpaceDefender& window)
 * @brief Draws the screencontent of the Game
 * 
 * Draws and updates, enemie ships, the player ship and fired weapons. 
 * @param window SpaceDefender object
 */
void ScreenGame::draw(SpaceDefender& window) {
    for (SpaceShipEnemy enemyShip : window.enemyShips) {
        //window.draw_circle({enemyShip.getPositionX(),enemyShip.getPositionY()},10,TDT4102::Color::antique_white);
        window.draw_image({enemyShip.getPositionX(),enemyShip.getPositionY()},
                enemyShip.alienImage, enemyShip.getShipWidth(),enemyShip.getShipHeight());
    }
    window.draw_image({window.playerShip.getPositionX(),window.playerShip.getPositionY()}, 
                       window.playerShip.playerImage, window.playerShip.getShipWidth(), window.playerShip.getShipHeight());

    // Hide unnecessary buttons for this screen
    window.StartGameBtn.setVisible(false);
    window.HighscoresBtn.setVisible(false);
    window.SettingsBtn.setVisible(false);
    window.EndGameBtn.setVisible(false);
    window.GoToMenuBtn.setVisible(true);

    // Update and draw fired weapons
    for (auto& weaponPtr : window.firedWeapons) {
        weaponPtr->move();
        weaponPtr->draw(window);
    }

    // Update spaceship movements and shooting
    window.playerShip.movements(window);
    window.playerShip.shooting(window);
}


/**
 * @fn void ScreenHighscore::draw(SpaceDefender& window)
 * @brief Draws the screencontent of the Highscore
 * 
 * Draws the highscore screen, and show the back button.
 * @todo Add highscores to the screen that is read from a json file
 * @param window SpaceDefender object
 */
void ScreenHighscore::draw(SpaceDefender& window) {
    window.draw_text({window.width()/2 - window.width()/4, window.height()/20}, "TOP 10 SCORES", TDT4102::Color::aqua,  35);
    // Headline row
    window.draw_text({150, 120}, "Rank  Player - Score  Round", TDT4102::Color::white, 20);

    // Player rows (you can add round number here as well)
    window.draw_text({150, 150}, "1. Player1 - 100  Round 1", TDT4102::Color::white, 20);
    window.draw_text({150, 180}, "2. Player2 - 80  Round 1", TDT4102::Color::white, 20);
    window.draw_text({150, 210}, "3. Player3 - 60  Round 1", TDT4102::Color::white, 20);
    window.draw_text({150, 240}, "4. Player4 - 40  Round 1", TDT4102::Color::white, 20);


    window.StartGameBtn.setVisible(false);
    window.HighscoresBtn.setVisible(false);
    window.SettingsBtn.setVisible(false);
    window.EndGameBtn.setVisible(false);
    window.GoToMenuBtn.setVisible(true);
}


/**
 * @fn void ScreenSettings::draw(SpaceDefender& window)
 * @brief Draws the screencontent of the Settings
 * 
 * Draws the settings screen, where you can change the game settings
 * @todo Add settings to the screen
 * @param window SpaceDefender object
 */
void ScreenSettings::draw(SpaceDefender& window) {
    window.draw_text({window.width()*2/5, 100}, "Settings", TDT4102::Color::cyan, window.height()/20); 

    window.StartGameBtn.setVisible(false);
    window.HighscoresBtn.setVisible(false);
    window.SettingsBtn.setVisible(false);
    window.EndGameBtn.setVisible(false);
    window.GoToMenuBtn.setVisible(true);
}