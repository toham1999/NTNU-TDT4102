#include "SpaceShip.h"
#include "SpaceDefender.h"
#include <iostream>


// ---- SpaceShipPlayer ----
void SpaceShipPlayer::movements(SpaceDefender& window) {
    if (window.is_key_down(KeyboardKey::RIGHT) && x < window.width()) {
        x+=shipSpeed;
    }
    else if (window.is_key_down(KeyboardKey::LEFT) && x > 0) {
        x-=shipSpeed;
    }
}
void SpaceShipPlayer::shooting(SpaceDefender& window) {
    if (window.is_key_down(KeyboardKey::SPACE)) {
        std::unique_ptr<Bullet> newBullet = std::make_unique<Bullet>(5, 1);  // Create the bullet
        newBullet->fireWeapon(window);  // Call the fireWeapon method to set the position
        window.firedWeapons.emplace_back(std::move(newBullet));  // Store the bullet
    }
}


// ---- SpaceShipEnemy ----
void SpaceShipEnemy::movements(SpaceDefender& window) {
    (void)window;
}
void SpaceShipEnemy::shooting(SpaceDefender& window) {
    (void)window;
}