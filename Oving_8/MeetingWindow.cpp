#include "MeetingWindow.h"
#include <iostream>
#include <cassert>

MeetingWindow::MeetingWindow(TDT4102::Point position, int width, int height, const std::string& title):
	// BEGIN 4a
    AnimationWindow{position.x,position.y, width, height, title},
	// END 4a

	// BEGIN 4e
	quitBtn({width-pad-btnW, pad}, btnW, btnH,"Quit"),
	// END 4e

	// BEGIN 5a
	personName({pad,pad},fieldW,fieldH,"Name"),
	personEmail({pad,2*pad+fieldH},fieldW,fieldH,"Email"),
	//#define FOUR_A
	// END 5a

	// BEGIN 5b
	personSeats({pad,3*pad+2*fieldH},fieldW,fieldH,"Car seats"),
	personNewBtn({pad,4*pad+3*fieldH},fieldW,fieldH,"Add person"),
	//#define FOUR_B
	// END 5b

	dummyArgument{0}
{
	// Felles
	// BEGIN 4f
	add(quitBtn);
	// END 4f
	
	// BEGIN 4g
	quitBtn.setCallback(std::bind(&MeetingWindow::cb_quit, this));
	// END 4g

	// BEGIN 5d
	personNewBtn.setCallback(std::bind(&MeetingWindow::newPerson, this));
	// END 5d

	// Ny person
	#ifndef FOUR_A
	attachPersonWidget(personName);
	attachPersonWidget(personEmail);
	#endif

	#ifndef FOUR_B
	attachPersonWidget(personSeats);
	attachPersonWidget(personNewBtn);
	#endif
}

// Callbackfunksjoner
// BEGIN 4d
void MeetingWindow::cb_quit() {close();}
// END 4d

// BEGIN 5c
void MeetingWindow::newPerson() {
	std::string name = personName.getText();
    std::string email = personEmail.getText();
    std::string seats_str = personSeats.getText();
	
	assert(!(name.empty() || email.empty() || seats_str.empty()));
	int seats_int = std::stoi(seats_str);

	Car c(seats_int);
	people.emplace_back(std::shared_ptr<Person>(new Person(name, email, std::make_unique<Car>(c))));
	
	personName.setText("Namee");
	personEmail.setText("Email");
	personSeats.setText("Car seats");
}
// END 5c

void MeetingWindow::attachPersonWidget(TDT4102::Widget& pw)
{
	add(pw);
	personWidgets.emplace_back(std::ref(pw));
}