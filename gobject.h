/***************************************************************************************************
 File Name:
  gobject.h

 Purpose:
	Specification file for an abstract, memory managed object base class. Defines a class called
	Gobject (game object) that will serve as the base class for all future objects that need to be
	memory managed.

 Authors:
	Igor Janjic

 Version:
	0.9 (4/17/12)
	Not done: Log error messages for collectRemainingObjects().
***************************************************************************************************/

#include <list>
using std::list;

/***************************************************************************************************
 Class:
	Gobject

 Description:
	Serves as a base class for all derived classes that need to be memory managed. All instances of
	such objects share two statically defined lists: a list of currently live objects and dead
	objects as well as two statically defined methods for garbage collection. Each object created
	contains a count of how many things are referencing it. When the object is not needed anymore
	(nothing is referencing it), the object is added to the dead list. The programmer may choose to
	flush the dead list periodically or implement a smart pointer (smointer) system in which this
	list is flushed automatically. Along with flushing the dead list, another method is defined for
	flushing the remaining objects still live. This method should only really be used at the end of
	the programs execution as a deleting live object that still have references to them may cause
	erratic run time errors. This class is part of the memory management system.
***************************************************************************************************/

class Gobject
{
private:

	/* A list of all gobjects currently in memory. */
	static list<Gobject*> liveGobjects;

	/* A list of all gobjects released from memory. */
	static list<Gobject*> deadGobjects;

	/* Counter for how much the gobject is being shared around. */
	long int referenceCount;

protected:

/***************************************************************************************************
 Method:
	Gobject()

 Scope:
	Protected.

 Description:
	The default constructor. Adds the newly created gobject to the list of live Gobjects.
	Initializes the number of references to the object to 0.

 Parameters:
	None.

 Remarks:
	The default constructor is protected to prevent instantiation.
***************************************************************************************************/

	Gobject();

/***************************************************************************************************
 Method:
	virtual ~Gobject()

 Scope:
	Protected.

 Description:
	The default destructor. Left as purely virtual as derived classes are expected to implement
	their own versions.

 Parameters:
	None.
***************************************************************************************************/

	virtual ~Gobject();

public:

/***************************************************************************************************
 Method:
	inline void addReference()

 Scope:
	Public.

 Description:
	Increments the number of references to the gobject.

 Parameters:
	None.

 Returns:
	Nothing.

 Example:
	<code>
	Gobject A;
	A.addReference();
	</code>

 Remarks:
	Method is inlined to decrease function overhead and increase performance.
***************************************************************************************************/
	
	inline void addReference();

/***************************************************************************************************
 Method:
	inline void releaseReference()

 Scope:
	Public.

 Description:
	Decrements the number of references to the gobject. If nothing is referencing it, the gobject
	is removed from the live gobjects list and moved to the dead gobjects list.

 Parameters:
	None.

 Returns:
	Nothing.

 Example:
	<code>
	Gobject A;
	A.releaseObject();
	</code

 Remarks:
	Method is inlined to decrease function overhead and increase performance.
***************************************************************************************************/

	inline void releaseReference();

/***************************************************************************************************
 Method:
	static void collectGarbage()

 Scope:
	Public.

 Description:
	Deletes all dead gobjects and flushes the dead gobjects list.

 Parameters:
	None.

 Returns:
	Nothing.

 Example:
	<code>
	Gobject A;
	A.collectGarbage();
	</code>
***************************************************************************************************/

	static void collectGarbage();

/***************************************************************************************************
 Method:
	static void collectRemainingGobjects(bool emitWarnings = false)

 Scope:
	Public.

 Description:
	First collects the garbage (deletes all dead gobjects) and then deletes all live gobjects.

 Parameters:
	1.	bool emitWarnings = false - Warning flag that triggers an error message to be logged if
		true.

 Returns:
	Nothing.

 Example:
	<code>
	Gobject A;
	A.collectRemainingObjects(false);
	</code>
***************************************************************************************************/

	static void collectRemainingGobjects(bool emitWarnings = false);

/***************************************************************************************************
 Method:
	virtual unsigned long int size() = 0

 Scope:
	Public

 Description:
	Pure virtual function for derived classes to implement.

 Parameters:
	None.

 Returns:
	This method returns 0 but derived classes should modify the function to return the size of the
	gobject.

 Example:
	<code>
	Gobject A;
	unsigned long int curSize = A.size();
	</code>
***************************************************************************************************/

	virtual unsigned long int size() = 0;

};

/* Quick macro that makes it easier on derived classes to return size of their gobjects. */
#define AUTO_SIZE unsigned long size() {return sizeof(*this);}