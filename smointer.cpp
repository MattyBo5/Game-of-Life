/***************************************************************************************************
 File Name:
	smointer.h

 Purpose:
	Specification file for smart pointer class. Defines a class called Smointer (smart pointer) that
	takes care of reference counting for all Gobjects automatically. Templated for type safety.

 Authors:
	Igor Janjic

 Version:
	0.9
	Not done: Pointer math operators (although I'm not sure if they are needed yet).
***************************************************************************************************/

#include "smointer.h"

// Default constructor.
template<class T>
Smointer<T>::Smointer()
{
	obj = 0;
}

// Construct from regular pointer
template<class T>
Smointer<T>::Smointer(T* anObj)
{
	obj = 0;
	*this = anObj;
}

// Copy constructor
template<class T>
Smointer<T>::Smointer(const Smointer<T> &aSmointer)
{
	obj = 0;
	*this = aSmointer;
}

// Destructor
template<class T>
Smointer<T>::~Smointer()
{
	if(obj)
		obj->releaseReference();
}

// Overloads assignment operator from regular pointer
template<class T>
inline Smointer<T>& Smointer<T>::operator=(T* anObj)
{
	if(obj)
		obj->releaseReference();
	obj = anObj;
	if(obj)
		obj->addReference();
}

// Overloads assignment operator from smointer
template<class T>
inline Smointer<T>& Smointer<T>::operator=(const Smointer<T> &aSmointer)
{
	if(obj)
		obj->releaseReference();
	obj = aSmointer.obj;
	if(obj)
		obj->addReference();
}

// Overloads dereference operator
template<class T>
inline T& Smointer<T>::operator*() const
{
	assert((obj != 0) && "Tried to * on a NULL smointer");
	return *obj;
}

// Overloads access operator
template<class T>
inline T* Smointer<T>::operator->() const
{
	assert((obj != 0) && "Tried to -> on a NULL smointer");
	return obj;
}

// Overloads T* operator for easy conversion to regular pointer
template<class T>
inline Smointer<T>::operator T*() const
{
	return obj;
}

// Overloads negation operator
template<class T>
inline bool Smointer<T>::operator !()
{
	return !(obj);
}

// Overloads equality operator for regular pointer
template<class T>
inline bool Smointer<T>::operator ==(const T* anObj) const
{
	return (obj == anObj);
}

// Overloads equality operator for smointer
template<class T>
inline bool Smointer<T>::operator ==(const Smointer<T> &aSmointer) const
{
	return (obj == aSmointer.obj);
}

// Determines if smointer's gobj is NULL
template<class T>
inline bool Smointer<T>::isValid() const
{
	return (obj != 0);
}