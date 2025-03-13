#include "Person.h"

// BEGIN 2b
Person::Person(std::string name, std::string email, 
    std::unique_ptr<Car> car) : name(name), email(email), car(std::move(car)) {}
std::string Person::getEmail() const {return email;}
std::string Person::getName() const {return name;}
void Person::setEmail(const std::string& email) {
    this-> email = email;
}
// END 2b

// BEGIN 2c
bool Person::hasAvailableSeats() const {
    return (this->car != nullptr && this->car->hasFreeSeats());
}
// END 2c

// BEGIN 2d
std::ostream& operator<<(std::ostream& os,const Person& p) {
    os << "Name: " << p.getName() << std::endl;
    os << "Email: " << p.getEmail() << std::endl;
    return os;
}
// END 2d
