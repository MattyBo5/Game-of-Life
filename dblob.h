/***************************************************************************************************
 File Name:
  dblob.h

 Purpose:
	Specification and implementation file for dynamically allocated game buffers. Defines a class
	called DBlob with base class Gobject that handles access control and provides asserts to check
	that no memory outside of the buffers is being accessed. Pretty much a wrapper class for
	dynamically allocated arrays.

 Authors:
	Igor Janjic
	
 Version:
	1.0 (4/19/12)
***************************************************************************************************/

#include <assert.h>
#include "gobject.h"

/***************************************************************************************************
 Class:
	DBlob

 Base Class:
	Gobject

 Description:
	The class provides access control for live objects in case the buffer pointer is reallocated or
	deleted by the programmer. A buffer is created by passing the buffer type through the template
	argument and the size of the buffer in the constructor. Forcing access to go through the [] and
	T* operators attempts to protect the buffer from the outside world. With the asserts, there are
	opportunities to check that memory outside of the buffer is not being accessed. This class is
	part of the memory management system.
***************************************************************************************************/

template<class T>
class DBlob : public Gobject
{

private:

	/* The size of the data being stored in the buffer. */
	unsigned long int dataSize;

	/* Main dynamically allocated array-based data structure. */
	T *buffer;

public:

/***************************************************************************************************
 Method:
	DBlob(unsigned long int size)

 Scope:
	Public.

 Description:
	The default constructor. Sets the size of the buffer through the argument provided. Dynamically
	allocates the buffer with the specified size. If the buffer is not successfully allocated, an
	assertion is thrown.

 Parameters:
	1.	unsigned long int size - The size the buffer will be set to.

 Example:
	<code>
	DBlob A(10);
	</code>
***************************************************************************************************/

	DBlob(unsigned long int size)
	{
		dataSize = size;
		buffer = new T[size];
		assert((buffer != 0) && "DBlob buffer could not be created.");
	}

/***************************************************************************************************
 Method:
	~DBlob()

 Scope:
	Public.

 Description:
	The default destructor. If the buffer is not NULL, delete it.
***************************************************************************************************/

	~DBlob()
	{
		if(buffer)
			delete[] buffer;
	}

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
		assert((index < dataSize) && "Bad index on DBlob::[].");
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
	unsigned long int size()

 Scope:
	Public.

 Description:
	Determines the size of the instantiated object.

 Parameters:
	None.

 Returns:
	This method returns the size of the instantiated object.

 Example:
	<code>
	DBlob A(10);
	unsigned long int size = A.size();
	</code>
***************************************************************************************************/

	unsigned long int size()
	{
		return (dataSize + sizeof(this));
	}

/***************************************************************************************************
 Method:
	unsigned long int blobSize()

 Scope:
	Public.

 Description:
	Determines the size of the buffer.

 Parameters:
	None.

 Returns:
	This method returns the size of the buffer in the blob.

 Example:
	<code>
	DBlob A(10);
	unsigned long int size = A.blobSize();
	</code>
***************************************************************************************************/

	unsigned long blobSize()
	{
		return dataSize;
	}

};