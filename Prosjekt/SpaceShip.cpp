/**
 * @file SpaceShip.cpp
 * @author Tor Gunnar Ravatn Hammer (tor.ravatn@gmail.com)
 * @author Gabriel Anton Norheim (gabriel.norheim@gmail.com)
 * @brief The cpp file for the SpaceShip class
 * @version 1.0
 * @date 2025-04-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "SpaceShip.h"
#include "SpaceDefender.h"
#include <iostream>


/**
 * @brief Move the spaceship in x-axis using the arrow keys
 * 
 * @param window SpaceDefender object
 * @param x Position of the spaceship in the x-axis
 */
void SpaceShipPlayer::movements(SpaceDefender& window) {
    if (window.is_key_down(KeyboardKey::RIGHT) && x < window.width()) {
        x+=shipSpeed;
    }
    else if (window.is_key_down(KeyboardKey::LEFT) && x > 0) {
        x-=shipSpeed;
    }
}

/**
 * @brief Fires the weapon if the space key is pressed
 * 
 * Fires a bullet, fire the  and stores it in a vector
 * @param window SpaceDefender object
 * @param newBullet Creates a new Bullet
 * @param new The time at the point when the function is called
 * @todo Only bullets are fired, consider making it more general. For example having a set weapon type
 */
void SpaceShipPlayer::shooting(SpaceDefender& window) {
    auto now = std::chrono::steady_clock::now();
    if (window.is_key_down(KeyboardKey::SPACE) && std::chrono::duration_cast<std::chrono::milliseconds>(now - lastShotTime) >= fireRate) {
        std::unique_ptr<Bullet> newBullet = std::make_unique<Bullet>(5, 1);  // Create the bullet
        newBullet->fireWeapon(*this);  // Call the fireWeapon method to set the position
        window.firedWeapons.emplace_back(std::move(newBullet));  // Store the bullet
        lastShotTime = now;
    }
}
// hei tor

/**
 * @brief Moves the spaceship of the enemy
 * 
 * Make a bullet, fire the and stores it in a vector
 * @param window SpaceDefender object
 * @todo Fix the movement of the enemy
 */
void SpaceShipEnemy::movements(SpaceDefender& window) {
    (void)window;
}

/**
 * @brief Fires the weapon at some interval
 * 
 * A random enenmy fires a bullet and stores it in a vector
 * @param window SpaceDefender object
 * @todo Fix shooting of the enemy
 * @todo Method to find lowest ship in each column
 * @todo One of said ships fire randomly
 * @todo Firerate approximatly same as playership
 */
void SpaceShipEnemy::shooting(SpaceDefender& window) {
    std::unique_ptr<Bullet> newBullet = std::make_unique<Bullet>(5, 1); 
    newBullet->fireWeapon(*this);
    window.firedWeapons.emplace_back(std::move(newBullet));
}
