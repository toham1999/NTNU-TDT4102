#pragma once
#include <cstddef>  // For size_t
#include <utility> // For std::pair

class SpaceDefender;  // Forward declaration of SpaceDefender to avoid circular dependency

class SpaceShip {
public:
    SpaceShip(size_t startX, size_t startY, size_t startHealth) : x(startX), y(startY), health(startHealth) {}
    virtual ~SpaceShip() = default;  // Virtual destructor to ensure proper cleanup

    virtual void movements(SpaceDefender& window) = 0;
    virtual void shooting(SpaceDefender& window) = 0;
    void healthReduction() { --health; }
    size_t getHealth() const {return health;}
    int getPositionX() const {return x;}
    int getPositionY() const {return y;}

protected:
    size_t x; // Positions
    size_t y;
    size_t health; // Life points
};


class SpaceShipPlayer : public SpaceShip {
    public:
        SpaceShipPlayer(size_t startX, size_t startY) : SpaceShip(startX, startY, 3) {}
        void movements(SpaceDefender& window) override;
        void shooting(SpaceDefender& window) override;
};


class SpaceShipEnemy : public SpaceShip {
    public:
        SpaceShipEnemy(size_t startX, size_t startY) : SpaceShip(startX, startY, 1) {}
        void movements(SpaceDefender& window) override;
        void shooting(SpaceDefender& window) override;
        
};