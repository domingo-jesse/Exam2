/// 
//Written by Jesse Domingo 
// Teacher Pete Tucker 
// CS273 (Summer) 
// 7/9/2018
///
/**
* CS-273 Exam 2 Summer 2018
* Who doesn't like sports ?!
*
* @authors Everyone!
*/
#include <iostream>
#include <string>
#include <typeinfo>
#include "Event.h"
#include "EventTicket.h"
#include "EventFactory.h"


using std::cout;
using std::endl;

const int EVENT_COUNT = 4;

int main()
{
	//Create a third kind of event, and test it 

	Event* events[EVENT_COUNT]; //Create a worldcup match and a baseball game
	events[0] = EventFactory::factory("worldcup", "Germany", "Mexico"); // Create a worldcup match with the event factory
	events[1] = EventFactory::factory("baseball", "Everett", "Spokane");
	//generate an event object for your new kind of event
	events[2] = EventFactory::factory("football", "Seahawks", "49ers");

	//Let's go through and test each one
	for (int i = 0; i<EVENT_COUNT - 1; i++) {
		// Let's add a couple of people to the match, and store their tickets in variables
		EventTicket *ticket1 = events[i]->add("Mike");
		EventTicket *ticket2 = events[i]->add("Jane");
		EventTicket *ticket3 = events[i]->add("Antonio");
		EventTicket *ticket4 = events[i]->add("Sue");

		cout << "Event before Jane leaves\n";
		events[i]->list(); // List the people currently at the event

						   // Jane decides to leave the event. Darn! She was really fun to have around!
		ticket2->leave();

		//  tests if Worldcup Event 
		if (typeid(WorldcupEvent) == typeid(*events[i]))
			// if a world cup game goers will chant
			dynamic_cast<WorldcupEvent*>(events[i])->chant();
		// tests if Baseball Event  
		else if (typeid(BaseballEvent) == typeid(*events[i]))
			// if this is a baseball game, include a call to have attendees at the baseball game stretch
			dynamic_cast<BaseballEvent*>(events[i])->stretch();
		//  tests if Football event 
		else if (typeid(FootballEvent) == typeid(*events[i]))
			//if this is your event, include a call to your event's special behavior
			dynamic_cast<FootballEvent*>(events[i])->get_snacks();



		cout << "Event after Jane leaves:\n";
		events[i]->list(); // List the people remaining

						   // I like this so I can seperate the events when it is displayed eaier to see
		cout << endl;
		cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
		cout << endl;
	}
}