/***************************************************************************************************
 File Name:
	smointer.h

 Purpose:
	Specification and implementation file for smart pointer class. Defines a class called Smointer
	(smart pointer) that takes care of reference counting for all Gobjects automatically. Templated
	for type safety.

 Authors:
	Igor Janjic

 Version:
	0.9 (4/19/12)
	Not done: Pointer math operators (although I'm not sure if they are needed yet).
***************************************************************************************************/

#ifndef SMOINTER_H
#define SMOINTER_H

#include <assert.h>

/***************************************************************************************************
 Class:
	Smointer

 Description:
	Defines a smart pointer abstract data type used to take care of reference counting for all
	gobjects automatically. Smointers act just like regular pointers. When a smointer is assigned to
	a gobject it automatically calls that gobject's addReference() and when it releases the gobject
	it automatically calls its releaseReference(). So whenever an assignment is done (ptr = gobj),
	reference counting is taken care of automatically. The smointer contains only one data member
	and that member points to the gobject the smointer is assigned to. The smointer class's function
	is to act as a wrapper for the pointer and includes most (except math) of the features regular
	pointers do and extra ones such as NULL pointer exception assertion. Since a smointer must be
	able to point to objects of all derived classes of gobjects, it is templated for type safety.
	This class is part of the memory management system.

 Precondition:
	T can only be a pointer to a gobject or any other object that inherits class Gobject (it must
	have addReference() and releaseReference()). Otherwise, there will be compilation errors.
***************************************************************************************************/

template<class T>
class Smointer
{

private:

	/* Pointer to a gobject (a gobject is any object that has Gobject as its base class). */
	T* gobj;

public:

/***************************************************************************************************
 Method:
	Smointer()

 Scope:
	Public.

 Description:
	The default constructor. Creates the smointer and sets it to point at NULL.

 Parameters:
	None.

 Example:
	<code>
	Smointer A;
	</code>
***************************************************************************************************/
	
	Smointer()
	{
		gobj = 0;
	}

/***************************************************************************************************
 Method:
	Smointer(T* aGobj)

 Scope:
	Public.

 Description:
	A constructor. Construction from a regular pointer. Sets gobj to NULL and the smointer's this
	pointer to the regular pointer.

 Parameters:
	1.	T* aGobj - The pointer to a gobject that the smointer's this pointer will point to.

 Example:
	<code>
	Gobject A;
	Smointer B(&A);
	</code>
***************************************************************************************************/
	
	Smointer(T* aGobj)
	{
		gobj = 0;
		*this = aGobj;
	}

/***************************************************************************************************
 Method:
	Smointer(const Smointer<T> &aSmointer)

 Scope:
	Public.

 Description:
	The copy constructor. Constructs a smointer from another smointer. Sets gobj to NULL and the
	smointer's this pointer to the specified smointer.

 Parameters:
	1.	const Smointer<T> &aSmointer - The specified smointer that the calling smointer's this
		pointer will be equated to.

 Example:
	<code>
	Smointer A;
	Smointer B(A);
	</code>
***************************************************************************************************/

	Smointer(const Smointer<T> &aSmointer)
	{
		gobj = 0;
		*this = aSmointer;
	}

/***************************************************************************************************
 Method:
	~Smointer()

 Scope:
	Public.

 Description:
	The default destructor. If gobj points to a gobject, the reference is released.
***************************************************************************************************/

	~Smointer()
	{
		if(gobj)
			gobj->releaseReference();
	}

/***************************************************************************************************
 Method:
	inline void operator =(T* aGobj)

 Scope:
	Public.

 Description:
	Overloads assignment operator for assigning a regular pointer to the smointer. If gobj already
	points to a gobject, release that gobject. Otherwise, set gobj equal to aGobj and if gobj is not
	NULL, add a reference to the gobject.

 Parameters:
	1.	T* aGobj - The pointer to a gobject the smointer is being equated to.
***************************************************************************************************/

	inline void operator =(T* aGobj)
	{
		if(gobj)
			gobj->releaseReference();
		gobj = aGobj;
		if(gobj)
			gobj->addReference();
	}

/***************************************************************************************************
 Method:
	inline void operator =(const Smointer<T> &aSmointer)

 Scope:
	Public.

 Description:
	Overloads assignment operator for assigning a smointer to the calling smointer. Functions
	exactly like the regular pointer overloaded assignment operator above.

 Parameters:
	1.	const Smointer<T> &aSmointer - The specified smointer that will be assigned to the calling
		smointer.
***************************************************************************************************/

	inline void operator =(const Smointer<T> &aSmointer)
	{
		if(gobj)
			gobj->releaseReference();
		gobj = aSmointer.gobj;
		if(gobj)
			gobj->addReference();
	}

/***************************************************************************************************
 Method:
	inline T& operator *() const

 Scope:
	Public.

 Description:
	Overloads dereference operator for dereferencing gobj with NULL pointer exception checking
	enforced.

 Parameters:
	None.
***************************************************************************************************/

	inline T& operator*() const
	{
		assert((gobj != 0) && "Tried to * on a NULL smointer.");
		return *gobj;
	}

/***************************************************************************************************
 Method:
	inline T& operator ->() const

 Scope:
	Public.

 Description:
	Overloads member access operator for accessing gobj with NULL pointer exception checking
	enforced.

 Parameters:
	None.
***************************************************************************************************/

	inline T* operator ->() const
	{
		assert((gobj != 0) && "Tried to -> on a NULL smointer.");
		return gobj;
	}

/***************************************************************************************************
 Method:
	inline T* operator T*() const

 Scope:
	Public.

 Description:
	Overloads conversion operator for easily converting smointer back to a regular gobject pointer. 

 Parameters:
	None.
***************************************************************************************************/

	inline operator T*() const
	{
		return gobj;
	}

/***************************************************************************************************
 Method:
	inline bool operator !()

 Scope:
	Public.

 Description:
	Overloads inequality operator for determining the negation of gobj.

 Parameters:
	None.
***************************************************************************************************/

	inline bool operator !()
	{
		return !(gobj);
	}

/***************************************************************************************************
 Method:
	inline bool operator ==(const T* aGobj) const

 Scope:
	Public.

 Description:
	Overloads equality operator for determining whether a smointer is equal to a regular pointer.

 Parameters:
	1.	const T* aGobj - The regular pointer that will be compared to the calling smointer's gobj.
***************************************************************************************************/

	inline bool operator ==(const T* aGobj) const
	{
		return (gobj == aGobj);
	}

/***************************************************************************************************
 Method:
	inline bool operator ==(const Smointer<T> &aSmointer) const

 Scope:
	Public.

 Description:
	Overloads equality operator for determining whether the smointer is equal to the specified
	smointer. Functions exactly like the regular pointer overloaded equality operator above.

 Parameters:
	1.	const Smointer<T> &aSmointer - The specified smointer whose gobj member will be compared to
		the calling smointer's gobj for equality.
***************************************************************************************************/

	inline bool operator ==(const Smointer<T> &aSmointer) const
	{
		return (gobj == aSmointer.gobj);
	}

/***************************************************************************************************
 Method:
	inline bool isValid() const;

 Scope:
	Public.

 Description:
	Determines whether the calling smointer's gobj is NULL.

 Parameters:
	None.

 Returns:
	This method returns TRUE if the calling smointer's gobj is not NULL and FALSE if the calling
	smointer's gobj is NULL.

 Example:
	<code>
	Smointer A;
	bool valid = A.isValid();
	</code>
***************************************************************************************************/

	inline bool isValid() const
	{
		return (gobj != 0);
	}

};

#endif
