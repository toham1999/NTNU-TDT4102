#pragma once

#include "subprojects/animationwindow/include/Image.h" //for image type

class SpaceDefender;  // Forward declaration of SpaceDefender to avoid circular dependency

class SpaceShip {
public:
    SpaceShip(int startX, int startY, int startHealth) : x(startX), y(startY), health(startHealth) {}
    virtual ~SpaceShip() = default;  // Virtual destructor to ensure proper cleanup

    virtual void movements(SpaceDefender& window) = 0;
    virtual void shooting(SpaceDefender& window) = 0;
    void healthReduction(int damage) { health -= damage; }
    int getHealth() const {return health;}
    int getPositionX() const {return x;}
    int getPositionY() const {return y;}
    int getShipHeight() const {return shipHeight;}
    int getShipWidth() const {return shipWidth;}
    void setShipSpeed(const int &newSpeed) {this->shipSpeed = newSpeed;}

protected:
    int x; // Positions
    int y;
    int health; // Life points
    const int shipHeight = 20;
    const int shipWidth = 20;
    int shipSpeed;
};

// ---- SpaceShipPlayer ----
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
}; 


// ---- SpaceShipEnemy ----
class SpaceShipEnemy : public SpaceShip {
    public:
        SpaceShipEnemy(int startX, int startY) : 
            SpaceShip(startX, startY, 1),
            alienImage("bilder/ailienHead.png") {}
        void movements(SpaceDefender& window) override;
        void shooting(SpaceDefender& window) override;
        TDT4102::Image alienImage;
        ~SpaceShipEnemy() = default;
};