/// 
//Written by Jesse Domingo 
// Teacher Pete Tucker 
// CS273 (Summer) 
// 7/9/2018
///
#ifndef _TICKET_H_
#define _TICKET_H_

/**
* Abstract Base Class for Ticket
* This class just defines the methods that need to be implemented by its derived classes
*/
class EventTicket
{
public:

	/**
	* Allows an attendee to leave an event
	*/
	virtual void leave() = 0;
};
#endif