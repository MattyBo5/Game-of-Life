/***************************************************************************************************
 File Name:
  error.cpp

 Purpose:
	Implementation file for the exception handler. Defines a class called Error that handles all
    exceptions.

 Authors:
	Igor Janjic
***************************************************************************************************/

#include "error.h"

Error::Error() {}

void Error::allocFailHandler() const
{
    cerr << "Error: Dynamic memory allocation failed...\n";
    assert(0);
}

void Error::nullPointerHandler() const
{
    cerr << "Error: Null pointer exception...\n";
    assert(0);
}

void Error::appNotOpenHandler() const
{
    cerr << "Error: Unable to open app logfile...\n";
    assert(0);
}

void Error::clientNotOpenHandler() const
{
    cerr << "Error: Unable to open client logfile...\n";
    assert(0);
}

void Error::serverNotOpenHandler() const
{
    cerr << "Error: Unable to open server logfile...\n";
    assert(0);
}

void Error::singletonSingleHandler() const
{
    cerr << "Error: Smointer single exception...\n";
    assert(0);
}

void Error::universalHandler(exception error) const
{
    if(error == allocFail)
        allocFailHandler();
    if(error == nullPointer)
        nullPointerHandler();
    if(error == appNotOpen)
        appNotOpenHandler();
    if(error == clientNotOpen)
        clientNotOpenHandler();
    if(error == serverNotOpen)
        serverNotOpenHandler();
    if(error == singletonSingle)
        singletonSingleHandler();
}
