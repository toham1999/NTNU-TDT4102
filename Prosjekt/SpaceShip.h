#pragma once


class SpaceDefender;  // Forward declaration of SpaceDefender to avoid circular dependency

class SpaceShip {
public:
    SpaceShip(unsigned int startX, unsigned int startY, unsigned int startHealth) : x(startX), y(startY), health(startHealth) {}
    virtual ~SpaceShip() = default;  // Virtual destructor to ensure proper cleanup

    virtual void movements(SpaceDefender& window) = 0;
    virtual void shooting(SpaceDefender& window) = 0;
    void healthReduction() { --health; }
    unsigned int getHealth() const {return health;}
    int getPositionX() const {return x;}
    int getPositionY() const {return y;}

protected:
    unsigned int x; // Positions
    unsigned int y;
    unsigned int health; // Life points
};


// ---- SpaceShipPlayer ----
class SpaceShipPlayer : public SpaceShip {
    public:
        SpaceShipPlayer(unsigned int startX, unsigned int startY) : SpaceShip(startX, startY, 3) {}
        void movements(SpaceDefender& window) override;
        void shooting(SpaceDefender& window) override;
}; 


// ---- SpaceShipEnemy ----
class SpaceShipEnemy : public SpaceShip {
    public:
        SpaceShipEnemy(unsigned int startX = 100, unsigned int startY = 100) : SpaceShip(startX, startY, 1) {}
        void movements(SpaceDefender& window) override;
        void shooting(SpaceDefender& window) override;
        
};