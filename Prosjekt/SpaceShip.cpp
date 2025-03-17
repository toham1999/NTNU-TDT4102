#include "SpaceShip.h"
#include "SpaceDefender.h"
#include <iostream>


// ---- SpaceShipPlayer ----
void SpaceShipPlayer::movements(SpaceDefender& window) {
    if (window.is_key_down(KeyboardKey::RIGHT) && x < window.width()) {
        x+=5;
    }
    else if (window.is_key_down(KeyboardKey::LEFT) && x > 0) {
        x-=5;
    }
}
void SpaceShipPlayer::shooting(SpaceDefender& window) {
    (void)window;
}


// ---- SpaceShipEnemy ----
void SpaceShipEnemy::movements(SpaceDefender& window) {
    (void)window;
}
void SpaceShipEnemy::shooting(SpaceDefender& window) {
    (void)window;
}