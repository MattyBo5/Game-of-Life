/***************************************************************************************************
 File Name:
	blob.h

 Purpose:
	Specification and implementation file for statically allocated game buffers. Defines a class
	called Blob with base class Gobject that handles access control and provides asserts to check
	that no memory outside of the buffers is being accessed. Pretty much a wrapper class for
	statically allocated arrays.

 Authors:
	Igor Janjic

 Version:
	1.0 (4/19/12)
***************************************************************************************************/

#ifndef BLOB_H
#define BLOB_H

#include <assert.h>
#include "gobject.h"

/***************************************************************************************************
 Class:
	Blob

 Base Class:
	Gobject

 Description:
	The class provides access control for live objects in case the buffer pointer is reallocated or
	deleted by the programmer. A buffer is created by passing the buffer type and size as template
	arguments. Forcing access to go through the [] and T* operators attempts to protect the buffer
	from the outside world. With the asserts, there are opportunities to check that memory outside
	of the buffer is not being accessed. This class is part of the memory management system.
***************************************************************************************************/

template<class T, int i>
class Blob : public Gobject
{

private:

	/* Main statically allocated array-based data structure. */
	T buffer[i];

public:

/* Constructor and destructor are supplied by compiler. */

/***************************************************************************************************
 Method:
	inline T& operator [](int index)

 Scope:
	Public.

 Description:
	Overloads array access operator for accessing the contents of the buffer at the specified index.
	If the buffer is being accessed outside of its memory scope, an assertion is thrown.

 Parameters:
	1.	int index - The index of the element attempting to be accessed in the buffer.
***************************************************************************************************/

	inline T& operator [](int index)
	{
		assert((index < i) && "Bad index on Blob::[].");
		return buffer[index];
	}

/***************************************************************************************************
 Method:
	inline operator T*()

 Scope:
	Public.

 Description:
	Overloads T* operator for accessing the buffer in its entirety.

 Parameters:
	None.
***************************************************************************************************/

	inline operator T*()
	{
		return buffer;
	}

/***************************************************************************************************
 Method:
	AUTO_SIZE

 Scope:
	Public.

 Description:
	Macro that defines a method size for getting the size of the instantiated object.

 Parameters:
	None.

 Returns:
	This method returns the size of the instantiated object.

 Example:
	<code>
	Blob A;
	int size = A.size();
	</code>
***************************************************************************************************/

	AUTO_SIZE;

};

#endif
