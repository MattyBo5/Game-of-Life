/***************************************************************************************************
 File Name:
  singleton.h

 Purpose:
	Specification and implementation file for a base class for limiting the instantiation of a
	derived class to only one object. Useful when only one object is needed for the specific
	application. Defines a class called Singleton to serve as a base class for future
	single-instance derived classes.

 Authors:
	Igor Janjic

 Version:
	1.0 (4/19/12)
***************************************************************************************************/

#ifndef SINGLETON_H
#define SINGLETON_H

#include <assert.h>

/***************************************************************************************************
 Class:
	Singleton

 Description:
	The class is a base class for limiting the instantiation of a derived class to only one object.
	The programmer is responsible for creating the singleton and deleting it when they are finished
	since it is not a memory managed (gobject) object. To destroy a singleton, simply call
	delete aDerivedClass::getSingletonPtr(), where aDerivedClass has Singleton as its base class.
***************************************************************************************************/

template<class T>
class Singleton
{
private:

	/* Singleton pointer. */
	static T* single;

public:

/***************************************************************************************************
 Method:
	Singleton()

 Scope:
	Public.

 Description:
	The default constructor. Asserts that the singleton's pointer was allocated successfully. Sets
	the singleton's pointer to the whole of the object rather than just the singleton.

 Parameters:
	None.
***************************************************************************************************/

	Singleton()
	{
		assert(!single);
		// Point the singleton to the start of the whole, rather than the start of the singleton
		int offset = (int)(T*)1 - (int)(Singleton<T>*)(T*)1;
		single = (T*)((int)this + offset);
	}

/***************************************************************************************************
 Method:
	~Singleton()

 Scope:
	Public.

 Description:
	The destructor. Asserts that the singleton's pointer is NULL. Sets the singleton's pointer to
	NULL.
***************************************************************************************************/

	~Singleton()
	{
		assert(single);
		single = 0;
	}

/***************************************************************************************************
 Method:
	static T& getSingleton()

 Scope:
	Public.

 Description:
	Asserts that the singleton's pointer is not NULL, then dereferences the singleton's pointer.

 Parameters:
	None.

 Returns:
	This method returns the dereferenced pointer of the singleton.
***************************************************************************************************/

	static T& getSingleton()
	{
		assert(single);
		return *single;
	}

/***************************************************************************************************
 Method:
	static T* getSingletonPtr()

 Scope:
	Public.

 Description:
	Asserts that the singleton's pointer is not NULL, the returns the pointer.

 Parameters:
	None.

 Returns:
	This method returns the singleton's pointer.
***************************************************************************************************/

	static T* getSingletonPtr()
	{
		assert(single);
		return single;
	}
};

/* Static initializer to give the singleton's pointer an initial value of 0. */
template<class T> T* Singleton <T>::single = 0;

#endif
