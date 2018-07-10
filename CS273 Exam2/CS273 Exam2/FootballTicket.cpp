/// 
//
//Written by Jesse Domingo 
// Teacher Pete Tucker 
// CS273 (Summer) 
// 7/9/2018
///
#include "FootballTicket.h"
#include "FootballEvent.h"

/**
* Implements the leave method
*/
void FootballTicket::leave() {
	// down-cast base class to derived class
	FootballEvent * actual_event = dynamic_cast<FootballEvent *>(the_event);

	// call Football Event remove method to erase event goer identified by "me"
	actual_event->remove(me);

}
