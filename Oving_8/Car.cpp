#include "Car.h"

#include <cassert>

// BEGIN 1b
Car::Car(int nrOfFreeSeats) : freeSeats(nrOfFreeSeats) {}
// END 1b

// BEGIN 1c
bool Car::hasFreeSeats() const {
    return (freeSeats > 0);
}

void Car::reserveFreeSeat() {
    assert(freeSeats > 0 && "Free seats need to be greater than zero");
    --freeSeats;
}
// END 1c