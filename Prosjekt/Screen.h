/**
 * @file Screen.h
 * @author Tor Gunnar Ravatn Hammer (tor.ravatn@gmail.com)
 * @brief The header file for the Screen class
 * @version 1.0
 * @date 2025-04-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once
#include <string>


/**
 * @brief An object representing a player in regards to highscores
 * @struct Player
 * @param rank The rank of the player
 * @param name The name of the player
 * @param score The score of the player
 * @param round The round of the player
 * 
 */
struct Player {
    std::string rank;
    std::string name;
    int score;
    int round;
};

std::vector<Player> readScores(const std::string& filename = "highscores.json");

class SpaceDefender;  // Forward declaration of SpaceDefender to avoid circular dependency

/** 
 * @class Screen
 * @brief Abstract base class for different screens
 * @param window SpaceDefender object
 */
class Screen {
public:
    virtual ~Screen() = default;  /**< Virtual destructor to ensure proper cleanup */
    virtual void draw(SpaceDefender& window) = 0; /**< Pure virtual function. Is supposed to draw the screen */
};


/** 
 * @class ScreenMenu
 * @brief The menu screen
 */
class ScreenMenu : public Screen {
public:
    void draw(SpaceDefender& window) override;
};


/** 
 * @class ScreenGame
 * @brief The game screen
 */
class ScreenGame : public Screen {
public:
    void draw(SpaceDefender& window) override; 
};


/** 
 * @class ScreenHighscore
 * @brief The highscore screen
 */
class ScreenHighscore : public Screen {
public:
    void draw(SpaceDefender& window) override;
};
        

/** 
 * @class ScreenSettings
 * @brief The settings screen
 */
class ScreenSettings : public Screen {
public:
    void draw(SpaceDefender& window) override;
};