/// 
//Written by Jesse Domingo 
// Teacher Pete Tucker 
// CS273 (Summer) 
// 7/9/2018
///
#ifndef _EVENT_H_
#define _EVENT_H_
#include <string>
#include "EventTicket.h"

/**
* Abstract Base Class for an athletic event.
* This class just defines the methods that need to be implemented in its derived classes.
*/
class Event
{
public:

	/**
	* Adds a person to the party, and returns a party ticket
	*/
	virtual EventTicket * add(std::string name) = 0;

	/**
	* List the people currently in the party
	*/
	virtual void list() = 0;
};

#endif#pragma once
