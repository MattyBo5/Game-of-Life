/***************************************************************************************************
 File Name:
  log.h

 Purpose:
	Specification file for the data logger. Defines a class called Log that records errors as and
	when they occur as well as general purpose game state information (things that are working).

 Authors:
	Igor Janjic
***************************************************************************************************/

#ifndef LOG_H
#define LOG_H

#include <fstream>
#include <cstdarg>
#include "singleton.h"
using std::ofstream;
using std::ifstream;
using std::string;
using std::endl;

/***************************************************************************************************
 Class:
	Log

 Description:
	This class defines a system for recording errors as and when they occur as well as general
	purpose program state information that may be useful for debugging and testing. The logger
	supports writing to multiple logfiles, predefined localizable messages, and code parameters in
	strings. The logger writes to three files: CLIENT, SERVER, and APP. CLIENT will contain
	information about the video, sound, and other player related tasks. SERVER will contain
	information about the which games are being stopped and played, and other AI/physics messages.
	The purpose of the APP file is to contain kernel level information along with other
	miscellaneous messages. If other logfile's are needed they can be easily be added later but
	these three will suffice for now. To keep the program as cross-platform as possible,
	preprocessor directives will be used to compile those parts of the class that are platform
	dependent. The class can only be instantiated once, through a Singleton object. This class is
	part of the data logging system.
***************************************************************************************************/

/* Predefined constants for indexing files. */
const int LOG_APP = 1;
const int LOG_CLIENT = 2;
const int LOG_SERVER = 3;

/* Constant for maximum log size. */
#define MAX_LOG 256

class Log
{

private:

	/* Output buffer for APP logfile. */
	ofstream app;

	/* Output buffer for CLIENT logfile. */
	ofstream client;

	/* Output buffer for SERVER logfile. */
	ofstream server;

	/* Contains the messages to be written. */
	string strings[MAX_LOG];

protected:

/***************************************************************************************************
 Method:
	Log()

 Scope:
	Protected.

 Description:
	The default constructor. Does nothing interesting.

 Parameters:
	None.

 Remarks:
	The default constructor is protected to prevent instantiation.
***************************************************************************************************/
	
	Log();

/***************************************************************************************************
 Method:
	bool load()

 Scope:
	Protected.

 Description:
	Loads the strings into the log array from "strings.txt"

 Parameters:
	None.

 Example:
	<code>
	// Class instantiated earlier in program
	bool check = A->load();
	</code>

 Returns:
	This method returns TRUE if the load was successful, otherwise it returns FALSE.
***************************************************************************************************/

	bool load();

public:

/***************************************************************************************************
 Method:
	static Log& instantiate()

 Scope:
	Public.

 Description:
	Creates an instance of the class and returns its pointer. Can only be used once.

 Parameters:
	None.

 Example:
	None.

 Returns:
	This method returns a pointer to the newly created object.
***************************************************************************************************/

	static Log& instantiate();

/***************************************************************************************************
 Method:
	bool init();

 Scope:
	Public.

 Description:
	Opens output buffers for all files.

 Parameters:
	None.

 Example:
	<code>
	// Class instantiated earlier in program
	bool check = A->init();
	</code>

 Returns:
	This method returns TRUE if the initialization was successful, otherwise it returns FALSE.
***************************************************************************************************/

	bool init();

/***************************************************************************************************
 Method:
	void write(int target, const char *message, ...);

 Scope:
	Public.

 Description:
	Writes the message to all of the files specified.

 Parameters:
	1.	int target - The target of the message. Defined in log.h.
	2.	const char* message- The message being written.

 Example:
	<code>
	// Class instantiated earlier in program
	const message[] = "Error!";
	A.write(1, message);
	</code>

 Returns:
	Nothing.
***************************************************************************************************/

	void write(int target, const char* message, ...);

/***************************************************************************************************
 Method:
	void write(int target, unsigned long int ID ...);

 Scope:
	Public.

 Description:
	Writes the message ID to all of the files specified.

 Parameters:
	1.	int target - The target of the message. Defined in log.h.
	2.	const char* message- The message being written.

 Example:
	None.

 Returns:
	Nothing.
***************************************************************************************************/

	void write(int target, unsigned long int ID, ...);
}

#endif
