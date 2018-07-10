/// 
//Written by Jesse Domingo 
// Teacher Pete Tucker 
// CS273 (Summer) 
// 7/9/2018
///
#ifndef _FOOTBALL_EVENT_H_
#define _FOOTBALL_EVENT_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Event.h"
#include "FootballTicket.h"

/**
* FootballEvent is derived from Event
*/
class FootballEvent : public Event
{
	//  Data structure for containing the event goers in this Baseball Game
	std::list<std::string> fevent;
	std::string hometeam;
	std::string visitingteam;


	// Constructor for creating a Baseball Game
	FootballEvent(std::string home, std::string visiting) {
		hometeam = home;
		visitingteam = visiting;
	}

	friend class EventFactory;
public:

	/**
	* Add a person to the event
	* @param name the name of the event goer
	*/
	EventTicket * add(std::string name)
	{
		//creates event ticket 
		EventTicket *eventticket = NULL;

		//add name to the front of stadium
		fevent.push_front(name);

		//get iterator to the front of the stadium (this points to the recently added event goer)
		std::list<std::string> ::iterator IT = fevent.begin();

		//create a new Football ticket with its constructor
		eventticket = new FootballTicket(this, IT);

		//return this new event ticket 
		return eventticket;
	}

	// List all the goers to the event 
	void list()
	{
		std::cout << "Football Game: " << hometeam << " V.S " << visitingteam << std::endl;
		// iterate through all the persons here.
		for (std::list<std::string> ::iterator i = fevent.begin(); i != fevent.end(); i++)
		{
			//Output each name 
			std::cout << *i << std::endl;
		}
	}

	// Remove the person identified by the iterator from the event
	void remove(std::list<std::string>::iterator it)
	{
		// someone's getting out of hand they leave 
		fevent.erase(it);
	}
	// special event get snacks 
	// iterates through each goer and they go get snacks 
	void get_snacks() {
		for (std::list<std::string>::iterator i = fevent.begin(); i != fevent.end(); i++) {
			std::cout << '\t' << *i << " goes to get delicious snack" << std::endl;

		}
		std::cout << std::endl;
	}
};

#endif
