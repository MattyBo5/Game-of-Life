/***************************************************************************************************
 File Name:
	gobject.cpp

 Purpose:
	Implementation file for an abstract, memory managed object base class. Defines a class called
	Gobject (game object) that will serve as the base class for all future objects that need to be
	memory managed.

 Authors:
	Igor Janjic

 Version:
	0.9 (4/17/12)
	Not done: Log error messages for collectRemainingObjects().
***************************************************************************************************/

#include "gobject.h"

// Static initializer to give the list of live gobjects a definitive presence
list<Gobject*> Gobject::liveGobjects;

// Static initializer to give the list of dead gobjects a definitive presence
list<Gobject*> Gobject::deadGobjects;

// Default constructor
Gobject::Gobject()
{
	liveGobjects.push_back(this);
	referenceCount = 0;
}

// Destructor
Gobject::~Gobject() {}

// Adds reference to gobject
void Gobject::addReference()
{
   referenceCount++;
}

// Removes reference to gobject
void Gobject::releaseReference()
{
	referenceCount--;
	if(referenceCount <= 0)
	{
		liveGobjects.remove(this);
		deadGobjects.push_back(this);
	}
}

// Deletes dead gobjects and flushes dead gobjects list
void Gobject::collectGarbage()
{
	for(list<Gobject*>::iterator it = deadGobjects.begin(); it != deadGobjects.end(); it++)
	{
		delete *it;
	}
	deadGobjects.clear();
}

// Deletes live gobjects and flushes live gobjects list
void Gobject::collectRemainingGobjects(bool emitWarnings)
{
	collectGarbage();
	for(list<Gobject*>::iterator it = liveGobjects.begin(); it != liveGobjects.end(); it++)
	{
		Gobject* curObj = (*it);
		if(emitWarnings)
		{
			// Log error message
		}
		delete curObj;
	}
	liveGobjects.clear();
}