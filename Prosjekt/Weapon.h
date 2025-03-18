#pragma once
#include <cstddef>  // For size_t

class SpaceDefender;  // Forward declaration of SpaceDefender to avoid circular dependency

class Weapon {
public:
    Weapon(unsigned int speed,unsigned int damage) : speed(speed), damage(damage) {}
    virtual ~Weapon() = default;  // Virtual destructor to ensure proper cleanup
    virtual void noe_ting() = 0;
    void setPossision(unsigned int inx, unsigned int iny){x = inx; y = iny;} // setter posisjon
    unsigned int getDamage() const {return damage;}
    unsigned int x; // possisjon for skudd
    unsigned int y;

protected:
    unsigned int speed; // det  du inkrimenterer possisjonen til
    unsigned int damage;
};


// ---- Bullet ----
class Bullet : public Weapon {
    public:
        void noe_ting() override;
    };


// ---- Bomb ----
class Bomb : public Weapon {
    public:
        void noe_ting() override;
    };


// ---- Laser ----
class Laser : public Weapon {
    public:
        void noe_ting() override;
    };