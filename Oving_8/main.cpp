#include "Person.h"
#include "Meeting.h"
#include "MeetingWindow.h"
#include <iostream>

int main()
{
	/*
	Car c(0);
	Person personTor("Tor Hammer", "tghammer@stud.ntnu.no",std::make_unique<Car>(c));
	
	std::shared_ptr<Person> leader = std::make_shared<Person>("Gunnar Ravatn", "tor.ravatn@gmail.com");  
	Meeting meet(11, 11, 12, Campus::trh, "X-TEAM", leader);
	meet.addParticipant(std::make_shared<Person> (personTor));
	std::cout << meet << std::endl;
	*/
	// Opprett en Point med posisjon x=100, y=100
    TDT4102::Point position(100, 100);

    // Definer størrelse og tittel på MeetingWindow
    int width = 800;
    int height = 600;
    std::string title = "Møte Vindu";

    // Lag et MeetingWindow-objekt
    MeetingWindow meetingWindow(position, width, height, title);

    // Bruk wait_for_close() for å holde vinduet åpent til brukeren lukker det
    meetingWindow.wait_for_close();
	return 0;
}