#include "Meeting.h"

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <cstdlib>

// BEGIN 3b
std::ostream& operator<<(std::ostream& os, const Campus& campus) {
    os << campusToString.at(campus) << std::endl;
    return os;
}
// END 3b

// BEGIN 3e
void Meeting::addParticipant(std::shared_ptr<Person> person) {
    participants.push_back(person);
}
// END 3e

// BEGIN 3f
Meeting::Meeting(int day, int startTime, int endTime, Campus location, 
    const std::string& subject, const std::shared_ptr<Person> leader) 
    : day(day),startTime(startTime),endTime(endTime), location(location),
    subject(subject),leader(leader),participants{leader} {}
// END 3f

// BEGIN 3h
std::vector<std::string> Meeting::getParticipantList() const {
    std::vector<std::string> names;
    for (const auto& participant : participants) {
        names.push_back(participant->getName());
    }
    return names;
}
// END 3h

// BEGIN 3i
std::vector<std::shared_ptr<Person>> Meeting::findPotentialCoDriving(const Meeting& otherMeeting) const {
    std::vector<std::shared_ptr<Person>> potentialDrivers;

    if (location == otherMeeting.getLocation() && 
        day == otherMeeting.getDay() &&
        std::abs(startTime - otherMeeting.getStartTime()) <= 1 && 
        std::abs(endTime - otherMeeting.getEndTime()) <= 1) {

            for (const auto& participant : otherMeeting.participants) {
                if (participant->hasAvailableSeats()) {potentialDrivers.push_back(participant);}
            }
        }
    return potentialDrivers;
}
// END 3i

// BEGIN 3j
std::ostream& operator<<(std::ostream& os, const Meeting& meeting) {
    os << "Meeting" << std::endl;
    os << "Subject: " << meeting.getSubject() << std::endl;
    os << "Location: " << meeting.getLocation();
    os << "Start time: " << meeting.getStartTime() << std::endl;
    os << "End time: " << meeting.getEndTime() << std::endl;
    os << "Meeting leader: " << meeting.getLeader()->getName() << std::endl;
    os << "Participants: ";
    for (const std::string participant : meeting.getParticipantList()) {
        os << participant;
    }
    os << std::endl;
    return os;
}
// END 3j
