/// 
//Written by Jesse Domingo 
// Teacher Pete Tucker 
// CS273 (Summer) 
// 7/9/2018
///
#include "BaseballTicket.h"
#include "BaseballEvent.h"

/**
* Implements the leave method
*/
void BaseballTicket::leave() {
	// down-cast base class to derived class
	BaseballEvent * actual_event = dynamic_cast<BaseballEvent *>(the_event);

	// call Baseball Event remove method to erase event goer identified by "me"

	actual_event->remove(me);

}