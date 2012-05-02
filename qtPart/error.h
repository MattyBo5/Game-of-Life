/***************************************************************************************************
 File Name:
  error.h

 Purpose:
	Specification file for the exception handler. Defines a class called Error that handles all
    exceptions.

 Authors:
	Igor Janjic
***************************************************************************************************/

#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include <assert.h>
using std::cerr;

/***************************************************************************************************
 Class:
    Error

 Description:
    Handles all exceptions.

 Remarks:
    Each game class requiring exception handling should inherit this class.
***************************************************************************************************/

class Error
{
    
protected:
    
    /* All possible exceptions. */
    enum exception {allocFail, nullPointer, appNotOpen, clientNotOpen, serverNotOpen, singletonSingle};
    
/***************************************************************************************************
 Method:
    Error()

 Scope:
	Protected.

 Description:
	The default constructor. Does nothing interesting.

 Remarks:
	The default constructor is protected to prevent instantiation.
***************************************************************************************************/
    
    Error();
    
public:
    
/***************************************************************************************************
 Method:
    void allocFailHandler() const

 Scope:
    Public.

 Description:
    Exception handler for dynamic memory allocation. Prints an error message to standard error and
    crashes the program.
***************************************************************************************************/
    
    void allocFailHandler() const;
    
/***************************************************************************************************
 Method:
    void nullPointerHandler() const

 Scope:
    Public.

 Description:
    Exception handler for null pointer exceptions such as dereferencing a null pointer. Prints an
    error message to standard error and crashes the program.
***************************************************************************************************/
    
    void nullPointerHandler() const;
    
/***************************************************************************************************
 Method:
    void appNotOpenHandler() const

 Scope:
    Public.

 Description:
    Exception handler for when the app logfile is closed when it shouldn't be. Prints an error
    message to standard error and crashes the program.
***************************************************************************************************/
    
    void appNotOpenHandler() const;
    
/***************************************************************************************************
 Method:
    void clientNotOpenHandler() const

 Scope:
    Public.

 Description:
    Exception handler for when the client logfile is closed when it shouldn't be. Prints an error
    message to standard error and crashes the program.
***************************************************************************************************/
    
    void clientNotOpenHandler() const;
    
/***************************************************************************************************
 Method:
    void serverNotOpenHandler()

 Scope:
    Public.

 Description:
    Exception handler for when the server logfile is closed when it shouldn't be. Prints an error
    message to standard error and crashes the program.
***************************************************************************************************/
    
    void serverNotOpenHandler() const;
    
/***************************************************************************************************
 Method:
    void smointerNotNullHandler()

 Scope:
    Public.

 Description:
    Exception handler for when a smointer is not initially set to NULL. Prints an error message to
    standard error and crashes the program.
***************************************************************************************************/
    
    void singletonSingleHandler() const;
    
/***************************************************************************************************
 Method:
    void universalHandler()

 Scope:
    Public.

 Description:
    Universal handler that calls the appropriate exception handler.

 Parameters:
    1.  exception error - The error being handled.
***************************************************************************************************/
    
    void universalHandler(exception error) const;
    
};

#endif
