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
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

/**
 * @brief Reads the highscores from a json file
 * 
 * @param filename The name of the json file to be read
 * @return std::vector<Player> 
 */
std::vector<Player> readScores(const std::string& filename) {
    std::vector<Player> players;
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Error opening file: " << filename << std::endl;
        return players;
    }
    json jsonData;
    file >> jsonData;

    for (const auto& entry : jsonData.at("highscores")) {
        players.push_back({entry.at("rank"), entry.at("player"), entry.at("score"), entry.at("round")});
    }
    return players;
}

/**
 * @brief Function to format the text that is drawn for each highscore
 * 
 * @param player A single input of the Player struct
 * @return std::string of the formatted player info
 * @todo Make better, width depends on characters
 */
std::string formatPlayerInfo(const Player& player) {
    std::stringstream ss;
    ss << std::left << std::setw(10)  << player.rank  
       << std::setw(15) << player.name  
       << std::setw(10) << player.score  
       << std::setw(10)  << player.round;
    return ss.str();
}


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
        window.draw_image({enemyShip.getPositionX(),enemyShip.getPositionY()}, enemyShip.alienImage, enemyShip.getShipWidth(),enemyShip.getShipHeight());
    }
    window.draw_image({window.playerShip.getPositionX(),window.playerShip.getPositionY()}, window.playerShip.playerImage, window.playerShip.getShipWidth(), window.playerShip.getShipHeight());

    // Hide unnecessary buttons for this screen
    window.StartGameBtn.setVisible(false);
    window.HighscoresBtn.setVisible(false);
    window.SettingsBtn.setVisible(false);
    window.EndGameBtn.setVisible(false);
    window.GoToMenuBtn.setVisible(true);

    // Update and draw fired weapons
/*
    for (auto& weaponPtr : window.firedWeapons) {
        // Check if the weapon is out of the screen, stops memory leakage
        if (weaponPtr->getPositionY() < 0) {
            window.firedWeapons.pop_back();
        }
        if (weaponPtr->getPositionY() > window.height()) {
            weaponPtr -> ~Weapon();
            weaponPtr = nullptr;
            break;
        }
    
        weaponPtr->move();
        weaponPtr->draw(window);
        
        // Check if the weapon hit the enemy ship
        
        for (SpaceShipEnemy& enemyShip : window.enemyShips) {
            if (weaponPtr->getPositionX() >= enemyShip.getPositionX() ||
                weaponPtr->getPositionX() <= enemyShip.getPositionX() + enemyShip.getShipWidth() ||
                weaponPtr->getPositionY() >= enemyShip.getPositionY() ||
                weaponPtr->getPositionY() <= enemyShip.getPositionY() + enemyShip.getShipHeight()) {
                //window.firedWeapons.erase(window.firedWeapons.begin());

                enemyShip.healthReduction(weaponPtr->getDamage());
                window.firedWeapons.erase(std::remove(window.firedWeapons.begin(), window.firedWeapons.end(), weaponPtr), window.firedWeapons.end());
                if (enemyShip.getHealth() <= 0) {
                    //window.enemyShips.erase(std::remove(window.enemyShips.begin(), window.enemyShips.end(), enemyShip), window.enemyShips.end());
                    //enemyShip.~aceShipEnemy();
                    window.enemyShips.pop_back();
                }
            } 
        }
    }
    */
    // itereator versionSp
    if(!window.firedWeapons.empty()){
        std::vector<std::unique_ptr<Weapon>> firedWeaponsCopy;
        
        for(auto it = window.firedWeapons.begin(); it != window.firedWeapons.end();)
        {  
            for(int i = 0; i < window.enemyShips.size(); i++)
            {
                auto itEnemy = window.enemyShips.at(i);
                if((itEnemy.getPositionX()<=(*it)->getPositionX() && (*it)->getPositionX()<= itEnemy.getPositionX() + itEnemy.getShipWidth()) &&
                ((*it)->getPositionY() <= (itEnemy).getPositionY() + (itEnemy).getShipHeight()))
                {
                    
                    //window.enemyShips.erase(window.enemyShips.at(i));

                    /*window.enemyShips.erase(std::remove_if(window.enemyShips.begin(), window.enemyShips.end(), [](SpaceShipEnemy& enemyShip) 
                    {
                        return ((itEnemy->getPositionX()<=(*it)->getPositionX() && (*it)->getPositionX()<= (itEnemy)->getPositionX() + (itEnemy)->getShipWidth()) &&
                        ((*it)->getPositionY() <= (itEnemy)->getPositionY() + (itEnemy)->getShipHeight()));}
                    ))
                    */
                    /*
                    (itEnemy)->healthReduction((*it)->getDamage());
                    it = window.firedWeapons.erase(it);
                    if ((itEnemy)->getHealth() <= 0) {
                        window.enemyShips.erase(itEnemy);
                        
                        } */
                }
                else{
                    //itEnemy++;
                    //break;
                }
            } 
            //window.firedWeapons.erase();
            
            // Check if the weapon is out of the screen, stops memory leakage WORKS!!!
        
            if ((*it)->getPositionY() < 100)
            {
                it = window.firedWeapons.erase(it);
            }
            else{
                (*it)->move();
                (*it)->draw(window);
                it++;
            }
        }
    }
    
    
    // Update spaceship movements and shooting
    window.playerShip.movements(window);
    window.playerShip.shooting(window);
    window.findShipToKill();
}

/**
 * @fn void ScreenHighscore::draw(SpaceDefender& window)
 * @brief Draws the screencontent of the Highscore
 * 
 * Draws the highscore screen, and show the back button.
 * @todo Add highscores to the screen that is read from a json file
 * @param window SpaceDefender object
 * @param file The json file variable which contains the highscores
 */
void ScreenHighscore::draw(SpaceDefender& window) {
    window.draw_text({window.width()/2 - window.width()/4, window.height()/20}, "TOP 10 SCORES", TDT4102::Color::aqua,  35);
    // Headline row
    window.draw_text({150, 120}, "Rank  Name - Score  Round", TDT4102::Color::dark_red, 30);

    std::vector<Player> players = readScores("highscores.json");

    int yOffset = 150;
    for (const auto& player : players) {
        std::string text = formatPlayerInfo(player);
        window.draw_text({150, yOffset}, text, TDT4102::Color::white, 25);
        yOffset += 30;
    }

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
    window.draw_text({window.width()*2/5, 100}, "Settings", TDT4102::Color::cyan, static_cast<unsigned int>(window.height()/20)); 

    window.StartGameBtn.setVisible(false);
    window.HighscoresBtn.setVisible(false);
    window.SettingsBtn.setVisible(false);
    window.EndGameBtn.setVisible(false);
    window.GoToMenuBtn.setVisible(true);
}