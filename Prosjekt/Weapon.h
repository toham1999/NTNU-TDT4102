#pragma once

class SpaceDefender;  // Forward declaration of SpaceDefender to avoid circular dependency

class Weapon {
public:
    Weapon(int speed, int damage) : speed(speed), damage(damage) {}
    virtual ~Weapon() = default;  // Virtual destructor to ensure proper cleanup
    virtual void fireWeapon(SpaceDefender& window) = 0;
    int getSpeed() {return speed;}
    int getDamage() {return damage;}
    virtual void move() {yProjectile -=speed;}
    virtual void draw(SpaceDefender& window) = 0;

protected:
    int speed;
    int damage;
    int xProjectile;
    int yProjectile;
};

// ---- Bullet ----
class Bullet : public Weapon {
public:
    Bullet(int speed, int damage) : Weapon(speed, damage) {}
    void fireWeapon(SpaceDefender& window) override;
    void draw(SpaceDefender& window) override;
};

// ---- Bomb ----
class Bomb : public Weapon {
public:
    Bomb(int speed, int damage) : Weapon(speed, damage) {}
    void fireWeapon(SpaceDefender& window) override;
};

// ---- Laser ----
class Laser : public Weapon {
public:
    Laser(int speed, int damage) : Weapon(speed, damage) {}
    void fireWeapon(SpaceDefender& window) override;
};