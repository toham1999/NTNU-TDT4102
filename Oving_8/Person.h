#pragma once
#include "Car.h"
#include <string>
#include <iostream>
#include <memory>

class Person
{
public:
	// BEGIN 2b
	Person(std::string name, std::string email, std::unique_ptr<Car> car = nullptr);
	std::string getEmail() const;
	std::string getName() const;
	void setEmail(const std::string& email);
	// END 2b

	// BEGIN 2c
	bool hasAvailableSeats() const;
	// END 2c

	// BEGIN 2d
	friend std::ostream& operator<<(std::ostream& os,const Person& p);
	// END 2d

	// Vi onsker ikke å tillate kopiering av Person-objekter
	Person(const Person&) = delete;
	Person& operator=(const Person&) = delete;

private:
	// BEGIN 2a
	std::string name;
	std::string email;
	std::unique_ptr<Car> car = nullptr;
	// END 2a
};
