#include "Weapon.h"
#include "SpaceDefender.h"
#include <iostream>

// ---- Bullet ----
void Bullet::fireWeapon(SpaceDefender& window) {
    xProjectile = window.playerShip.getPositionX();
    yProjectile = window.playerShip.getPositionY();
}
void Bullet::draw(SpaceDefender& window) {
    TDT4102::Point StartPoint{xProjectile,yProjectile};
    window.draw_circle(StartPoint,10,TDT4102::Color::antique_white);
}


// ---- Bomb ----
void Bomb::fireWeapon(SpaceDefender& window) {
    (void)window;
}


// ---- Laser ----
void Laser::fireWeapon(SpaceDefender& window) {
    (void)window;
}