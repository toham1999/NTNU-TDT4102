/**
 * @file Weapon.cpp
 * @author Tor Gunnar Ravatn Hammer (tor.ravatn@gmail.com)
 * @brief The cpp file for the Weapon class
 * @version 1.0
 * @date 2025-04-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "Weapon.h"
#include "SpaceDefender.h" 
#include "SpaceShip.h"


/**
 * @brief Fire the weapon. 
 * 
 * Sets the position of the projectile to the position of the player. 
 * The movement of the projectile is handled in Bullet::move().
 * @param window SpaceDefender object
 * @param xProjectile Position of the projectile in the x-axis
 * @param yProjectile Position of the projectile in the y-axis
 */
void Bullet::fireWeapon(SpaceShip& shooter) {
    xProjectile = shooter.getPositionX();
    yProjectile = shooter.getPositionY();
    if (dynamic_cast<const SpaceShipEnemy*>(&shooter)) {
        setWeaponSpeed(-2);
    }
}

/**
 * @brief Draw the bullet on the screen.
 * @param window SpaceDefender object
 * @param radius Radius of the bullet
 * @param location Location of the bullet. Updated in Bullet::fireWeapon(SpaceDefender& window)
 */
void Bullet::draw(SpaceDefender& window) {
    TDT4102::Point location {xProjectile + window.playerShip.getShipWidth()/2,yProjectile};
    window.draw_circle(location,radius,TDT4102::Color::antique_white);
}


/**
 * @brief 
 * @todo Add this function
 * @param shooter 
 */
void Bomb::fireWeapon(SpaceShip& shooter) {
    (void)shooter;
}


/**
 * @brief 
 * @todo Add this function
 * @param shooter 
 */
void Laser::fireWeapon(SpaceShip& shooter) {
    (void)shooter;
}