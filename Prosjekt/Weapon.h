/**
 * @file Weapon.h
 * @author Tor Gunnar Ravatn Hammer (tor.ravatn@gmail.com)
 * @brief The header file for the Weapon class
 * @version 1.0
 * @date 2025-04-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once
class SpaceShip;
class SpaceDefender;  // Forward declaration of SpaceDefender to avoid circular dependency

/**
 * @brief Abstract base class for different weapons
 * @class Weapon
 * @param speed Speed of the projectile
 * @param damage Damage the projectile does
 * @param xProjectile Position of the projectile in the x-axis
 * @param yProjectile Position of the projectile in the y-axis
 * @param window SpaceDefender object
 */
class Weapon {
public:
    Weapon(int speed, int damage) : speed(speed), damage(damage) {} /**< Constructor that initializes speed and damage */
    virtual ~Weapon() = default; /**< Virtual destructor to ensure proper cleanup*/ 
    virtual void fireWeapon(SpaceShip& shooter) = 0; /**< Pure virtual function. Is supposed to fire the projectile, aka get the postion when fired. */
    int getSpeed() {return speed;} /**< Getter for speed */
    int getDamage() {return damage;} /**< Getter for damage */
    virtual void move() {yProjectile -=speed;} /**< Move the projectile in y-axis */
    virtual void draw(SpaceDefender& window) = 0; /**< Pure virtual function. Is supposed to draw the projectile */
    int getPositionX() const {return xProjectile;};
    int getPositionY() const {return yProjectile;};
    void setWeaponSpeed(int newSpeed) {speed = newSpeed;}; /**< Setter for speed */
    virtual int getRadius() = 0; //**< Pure virtual function. Is supposed to get the radius of the projectile */
protected:
    int speed;
    int damage;
    int xProjectile;
    int yProjectile;
};

/**
 * @brief Class for Bullet. Inherits from Weapon
 * @class Bullet
 * @param radius Radius of the bullet
 */
class Bullet : public Weapon {
public:
    Bullet(int speed, int damage) : Weapon(speed, damage) {}
    void fireWeapon(SpaceShip& shooter) override;
    void draw(SpaceDefender& window) override;
    int getRadius() {return radius;} //**< Getter for radius */
private:
    int radius = 5;
};

/**
 * @brief Class for Bomb. Inherits from Weapon
 * @class Bomb
 * @todo Add Bomb to the game
 */
class Bomb : public Weapon {
public:
    Bomb(int speed, int damage) : Weapon(speed, damage) {}
    void fireWeapon(SpaceShip& shooter) override;
};

/**
 * @brief Class for Laser. Inherits from Weapon
 * @class Laser
 * @todo Add Laser to the game
 */
class Laser : public Weapon {
public:
    Laser(int speed, int damage) : Weapon(speed, damage) {}
    void fireWeapon(SpaceShip& shooter) override;
};