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
#include <std_lib_facilities.h>
#include "Screen.h"
#include "SpaceDefender.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "nlohmann/json.hpp" 
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
 * Itrerates through all the fired weapons and checks for collisions when iterating through all the enemy ships
 * It is an iterator for the fired weapons and itEnemy is an iterator for the enemy ships that is an unique pointer to the enemy ship object
 * if they collide the iterator unique pointer is deleated and the object is then deleated automatically from the vector
 * to move along in the loop we must update the iterator either by deleating it or incrementing it
 * draws every object in window, player ship, enemie ships and fired weapons are deleated from window if hit and helth <= 0
 * @param window SpaceDefender object
 */
void ScreenGame::draw(SpaceDefender& window)
{
    for (auto ptr = window.enemyShips.begin(); ptr != window.enemyShips.end(); ++ptr) {
        //window.draw_circle({enemyShip.getPositionX(),enemyShip.getPositionY()},10,TDT4102::Color::antique_white);
        window.draw_image({(*ptr)->getPositionX(),(*ptr)->getPositionY()}, (*ptr)->alienImage, (*ptr)->getShipWidth(),(*ptr)->getShipHeight());
    }
    window.draw_image({window.playerShip.getPositionX(),window.playerShip.getPositionY()}, window.playerShip.playerImage, window.playerShip.getShipWidth(), window.playerShip.getShipHeight());

    // Hide unnecessary buttons for this screen
    window.StartGameBtn.setVisible(false);
    window.HighscoresBtn.setVisible(false);
    window.SettingsBtn.setVisible(false);
    window.EndGameBtn.setVisible(false);
    window.GoToMenuBtn.setVisible(true);
    //std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();
    // Update and draw fired weapons
    for(auto it = window.firedWeapons.begin(); it != window.firedWeapons.end();)
    {  
        bool killShip = false;
        bool bullethit = false;
        std::vector<std::unique_ptr<Weapon>>::iterator itHit;        
        for (auto it2 = window.firedWeapons.begin(); it2 != window.firedWeapons.end(); ++it2) 
        {
            if(it != it2)
            {   
                if(((*it)->getPositionX() <= (*it2)->getPositionX()+4 && (*it)->getPositionX() + (*it)->getRadius()+4 >= (*it2)->getPositionX())
                && (abs((*it)->getPositionY() - (*it2)->getPositionY()) <= (*it)->getRadius() + 4 )){
                    itHit = it2;
                    bullethit = true;
                    break;
                }
            }
        }
        for(auto itEnemy = window.enemyShips.begin(); itEnemy != window.enemyShips.end();)
        {   
            bool checksXPossision = ((*itEnemy)->getPositionX()-(*itEnemy)->getShipWidth() <=(*it)->getPositionX() + (*it)->getRadius() && (*it)->getPositionX() - (*it)->getRadius() <= (*itEnemy)->getPositionX() + (*itEnemy)->getShipWidth());
            bool checksYPossision = ((*it)->getPositionY() <= (*itEnemy)->getPositionY() + (*itEnemy)->getShipHeight());
            if(checksXPossision&&checksYPossision)
            {
                (*itEnemy)->healthReduction((*it)->getDamage());
                if ((*itEnemy)->getHealth() <= 0) {
                    itEnemy = window.enemyShips.erase(itEnemy); //* @todo update Gamescore*/
                }
                killShip = true;
            }
            else{
                itEnemy++;
            }
        }

        
        SpaceShipPlayer& player = window.playerShip;
        bool checksXPossision = (player.getPositionX()-player.getShipWidth() <=(*it)->getPositionX() + (*it)->getRadius() && (*it)->getPositionX() - (*it)->getRadius() <= player.getPositionX() + player.getShipWidth());
        bool checksYPossision = (player.getPositionY() < (*it)->getPositionY() && (*it)->getPositionY() < player.getPositionY() + player.getShipHeight());
        if (checksXPossision&&checksYPossision)
        {
            player.healthReduction((*it)->getDamage());
            player.setShipSpeed(3);
            killShip = true;
            if (player.getHealth() <= 0) {
                 // fixes to Game over 
                window.setScreen(std::move(std::make_unique<ScreenHighscore>()));
                std::cout << "Game Over" << std::endl;
                break;
            }
        }
        
        //* @todo update hitconditions and make GameOver screen with score*/
        // Check if the weapon is out of the screen, stops memory leakage WORKS!!!
        
        if ((*it)->getPositionY() < 10 || killShip || (*it)->getPositionY() > window.height())
        {
            it = window.firedWeapons.erase(it);
        }
        else if (bullethit){
            it = window.firedWeapons.erase(it);
            it = window.firedWeapons.erase(itHit);
            break;
        }
        else if(!killShip){
            (*it)->move();
            (*it)->draw(window);
            it++;
        }
    }

    /*
    std::chrono::time_point endTime = std::chrono::steady_clock::now();
    long durationInMicroseconds = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count();
    double durationInSeconds = double(durationInMicroseconds)/1000000.0;
    std::cout << durationInSeconds << std::endl;
    */

    // Update spaceship movements and shooting
    window.playerShip.movements(window);
    window.playerShip.shooting(window);
    window.findShipToKill();
    window.enemySwarmMovement();
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