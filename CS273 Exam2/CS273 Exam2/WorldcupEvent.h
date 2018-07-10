/// 
//Written by Jesse Domingo 
// Teacher Pete Tucker 
// CS273 (Summer) 
// 7/9/2018
///
#ifndef _WORLDCUP_EVENT_H_
#define _WORLDCUP_EVENT_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Event.h"
#include "WorldcupTicket.h"

/**
* WorldcupEvent is derived from Event
*/
class WorldcupEvent : public Event
{
private:
	std::list<std::string> stadium; // Data structure for containing the event goers in this worldcup event
									// intializes the team names 
	std::string hometeam;
	std::string visitingteam;

	/**
	* Constructor for creating a WorldcupEvent
	*/
	WorldcupEvent(std::string home, std::string visiting) {
		// stores name for the event 
		hometeam = home;
		visitingteam = visiting;
	}
	// allows access from Event factory 
	friend class EventFactory;

public:

	/**
	* Add a person to the event
	* @param name the name of the event goer
	*/
	EventTicket * add(std::string name) {

		//creates event ticket 
		EventTicket * eventticket = NULL;

		//add name to the front of stadium
		stadium.push_front(name);

		//get iterator to the front of the stadium (this points to the recently added event goer)
		std::list<std::string> ::iterator IT = stadium.begin();

		//create a new worldcup ticket (WorldcupTicket) with its constructor
		//*Pass to the constructor "this" event, and the iterator from step 2
		eventticket = new WorldcupTicket(this, IT);
		//return this new event ticket 
		return eventticket;
	}

	/**
	* Show the event's home team and visiting team, then list all the persons currently in the event
	*/
	void list() {
		//Show the event's home team and visiting team, then iterate through all the persons here.

		std::cout << "WorldCup: " << hometeam << " V.S " << visitingteam << std::endl;
		// iterate through all the persons here.
		for (std::list<std::string> ::iterator i = stadium.begin(); i != stadium.end(); i++)
		{
			// outputs each name of the event goers
			std::cout << *i << std::endl;
		}
	}

	/**
	* Remove the person identified by the iterator from the event
	*/
	//someone's getting out of hand. Ushers have asked them to leave.
	void remove(std::list<std::string>::iterator it) {
		stadium.erase(it);
	}

	/**
	* Have world cup attendees chant
	*/
	// has them chants and iteraters through all of the goers 
	void chant() {
		for (std::list<std::string>::iterator i = stadium.begin(); i != stadium.end(); i++) {
			std::cout << '\t' << *i << " says 'boom boom clap!'" << std::endl;
		}
		std::cout << std::endl;
	}
};
#endif