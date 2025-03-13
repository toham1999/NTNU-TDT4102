#pragma once

#include "AnimationWindow.h"
#include "Meeting.h"
#include "Person.h"
#include "widgets/Button.h"
#include "widgets/TextInput.h"
#include "widgets/DropdownList.h"

#include <string>
#include <vector>
#include <functional>


// Meeting GUI
class MeetingWindow : public TDT4102::AnimationWindow
{
	public:
	// BEGIN 4c
	static constexpr int pad = 50;
	static constexpr int btnW = 150;
	static constexpr int btnH = 50;
	static constexpr int fieldW = 300;
	static constexpr int fieldH = 50;
	// END 4c

	MeetingWindow(TDT4102::Point position, int width, int height, const std::string& title);

	// Avslutt knapp
	// BEGIN 4e
	TDT4102::Button quitBtn;
	// END 4e

	// Callback-funksjoner
	// BEGIN 4d
	void cb_quit();
	// END 4d

	// Person
	// BEGIN 5a
	TDT4102::TextInput personName;
	TDT4102::TextInput personEmail;
	// END 5a

	// BEGIN 5b
	TDT4102::TextInput personSeats;
	TDT4102::Button personNewBtn;
	// END 5b

	// Personer
	// BEGIN 5c
	void newPerson();
	std::vector<std::shared_ptr<Person>> people;
	// END 5c

	int dummyArgument;

	// Hjelpefunksjoner og variabler
	void attachPersonWidget(TDT4102::Widget& pw);
	std::vector<std::reference_wrapper<TDT4102::Widget>> personWidgets;
};
