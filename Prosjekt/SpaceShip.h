/**
 * @file SpaceShip.h
 * @author Tor Gunnar Ravatn Hammer (tor.ravatn@gmail.com)
 * @brief The header file for the SpaceShip class
 * @version 1.0
 * @date 2025-04-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once
#include <chrono>
#include "subprojects/animationwindow/include/Image.h" //for image type

class SpaceDefender;  // Forward declaration of SpaceDefender to avoid circular dependency

/**
 * @brief Abstract base class for different spaceships
 * @class SpaceShip
 * @param window SpaceDefender object
 * @param x Position in the x-axis
 * @param y Position in the y-axis
 * @param health Health of the ship
 * @param shipHeight Height of the ship
 * @param shipWidth Width of the ship
 * @param shipSpeed Speed of the ship
 * 
 */
class SpaceShip {
public:
    /**
     * @brief Constructor that initializes x, y and health 
     * @param startX 
     * @param startY 
     * @param startHealth 
     */
    SpaceShip(int startX, int startY, int startHealth) : x(startX), y(startY), health(startHealth) {} 
    virtual ~SpaceShip() = default;  /**< Virtual destructor to ensure proper cleanup*/
    virtual void movements(SpaceDefender& window) = 0; /**< Pure virtual function. Is supposed to move the spaceship */
    virtual void shooting(SpaceDefender& window) = 0; /**< Pure virtual function. Is supposed do shooting */
    /**
     * @brief Reduces the Health of the ship by amount standard 1
     * 
     * @param a How much health is reduced
     */
    void healthReduction(const int& a = 1) { health -= a; } 
    int getHealth() const {return health;} /**< Getter for health */
    int getPositionX() const {return x;} /**< Getter for position in x-axis */
    int getPositionY() const {return y;} /**< Getter for position in y-axis */
    int getShipHeight() const {return shipHeight;} /**< Getter for ship height */
    int getShipWidth() const {return shipWidth;} /**< Getter for ship width */
    void setShipSpeed(const int &newSpeed) {this->shipSpeed = newSpeed;} /**< Setter for ship speed */

protected:
    int x;
    int y;
    int health;
    const int shipHeight = 20;
    const int shipWidth = 20;
    int shipSpeed;
};

/**
 * @brief Class for player ship
 * @class SpaceShipPlayer
 * @param playerImage Image of the playership
 * @param lastShotTime The time of the last 
 * @param fireRate How often the weapon can be fired
 * @todo firerate in regards to different weapomn types
 */
class SpaceShipPlayer : public SpaceShip {
    public:
        SpaceShipPlayer(int startX, int startY) : 
            SpaceShip(startX, startY, 3), 
            playerImage("bilder/ShipSprite.png") {
            setShipSpeed(10);
        }
        void movements(SpaceDefender& window) override;
        void shooting(SpaceDefender& window) override;
        TDT4102::Image playerImage;
    private:
        std::chrono::steady_clock::time_point lastShotTime;
        const std::chrono::milliseconds fireRate = std::chrono::milliseconds(500);
}; 


/**
 * @brief Class for enemy ship
 * @class SpaceShipEnemy
 * @param alienImage Image of the alienship
 */
class SpaceShipEnemy : public SpaceShip {
    public:
        SpaceShipEnemy(int startX, int startY) : 
            SpaceShip(startX, startY, 1),
            alienImage("bilder/ailienHead.png") {}
        void movements(SpaceDefender& window) override;
        void shooting(SpaceDefender& window) override;
        TDT4102::Image alienImage;
        bool operator==(const SpaceShipEnemy& other) const { return x == other.x && y == other.y; }
};

