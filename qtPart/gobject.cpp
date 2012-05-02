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

Gobject::Gobject()
{
	liveGobjects.push_back(this);
	referenceCount = 0;
}

Gobject::~Gobject() {}

void Gobject::addReference()
{
   referenceCount++;
}

void Gobject::releaseReference()
{
	referenceCount--;
	if(referenceCount <= 0)
	{
		liveGobjects.remove(this);
		deadGobjects.push_back(this);
	}
}

void Gobject::collectGarbage()
{
	for(list<Gobject*>::iterator it = deadGobjects.begin(); it != deadGobjects.end(); it++)
	{
		delete *it;
	}
	deadGobjects.clear();
}

void Gobject::collectRemainingGobjects(bool warnings)
{
	collectGarbage();
	for(list<Gobject*>::iterator it = liveGobjects.begin(); it != liveGobjects.end(); it++)
	{
		Gobject* curObj = (*it);
		if(warnings)
		{
			// Log error message
		}
		delete curObj;
	}
	liveGobjects.clear();
}
