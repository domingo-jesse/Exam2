/// 
//Written by Jesse Domingo 
// Teacher Pete Tucker 
// CS273 (Summer) 
// 7/9/2018
///
#ifndef _BASEBALL_EVENT_H_
#define _BASEBALL_EVENT_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Event.h"
#include "BaseballTicket.h"

//  Create BaseballEvent and BaseballTicket to for good baseball games!
//  Create a function stretch so that the attendees can stand up an stretch for the 7th inning
//  Update EventFactory::factory() to allow it to be the ONLY method for creating a BaseballEvent
/**
* BaseballEvent is derived from Event
*/
class BaseballEvent : public Event
{
	//// Data structure for containing the event goers in this Baseball Game
	std::list<std::string> bevent;
	std::string hometeam;
	std::string visitingteam;


	// Constructor for creating a Baseball Game
	BaseballEvent(std::string home, std::string visiting) {
		hometeam = home;
		visitingteam = visiting;
	}

	friend class EventFactory;
public:

	EventTicket * add(std::string name)
	{
		//creates event ticket 
		EventTicket *eventticket = NULL;

		//add name to the front of stadium
		bevent.push_front(name);

		//get iterator to the front of the stadium (this points to the recently added event goer)
		std::list<std::string> ::iterator IT = bevent.begin();

		////creates event ticket 
		eventticket = new BaseballTicket(this, IT);

		return eventticket;
	}

	// List all the goers to the event 
	void list()
	{
		std::cout << "Baseball Game: " << hometeam << " V.S " << visitingteam << std::endl;
		// iterate through all the persons here.
		for (std::list<std::string> ::iterator i = bevent.begin(); i != bevent.end(); i++)
		{
			//Output each name 
			std::cout << *i << std::endl;
		}
	}

	// Remove the person identified by the iterator from the event
	void remove(std::list<std::string>::iterator it)
	{
		// someone's getting out of hand they leave 
		bevent.erase(it);
	}
	// the action which each goer does and they stretch iteraters through them al 
	void stretch() {
		for (std::list<std::string>::iterator i = bevent.begin(); i != bevent.end(); i++) {
			std::cout << '\t' << *i << " does the 7th inning Stretch" << std::endl;
		}
		std::cout << std::endl;
	}
};

#endif