/***************************************************************************************************
 File Name:
  log.cpp

 Purpose:
	Implementation file for the data logger. Defines a class called Log that records errors as and
	when they occur as well as general purpose game state information (things that are working).

 Authors:
	Igor Janjic
***************************************************************************************************/

// Constant for maximum buffer size
#define MAX_BUFFER 1024

#include "log.h"

// Default constructor
Log::Log() {}

// Loads the messages into the strings array
bool Log::load()
{
	ifstream in("strings.txt");
	if(!in.is_open())
		return false;
	unsigned long int index = 0;
	while(!in.eof())
	{
		char buffer[MAX_BUFFER];
		in.getline(buffer, MAX_BUFFER);
		strings[index++] = buffer;
	}
	return true;
}

// Instantiates the data logger
Log& Log::instantiate()
{
	static Log log;
	return log;
}

// Opens all output buffers
bool Log::init()
{
	app.open("applog.txt");
	client.open("clientlog.txt");
	server.open("serverlog.txt");
	if(!load()) // If the strings weren't loaded, return FALSE
		return false;
	return true;
}

// Writes the message corresponding to each target to the appropriate output buffer
void Log::write(int target, const char *message, ...)
{
	// Handles ellipses ...
	va_list arguments;
	va_start(arguments, message);
	char buffer[MAX_BUFFER];
	vsprintf(buffer, message, arguments);
	// Preprocessor directives are used for saving the files if a crash occurs while debugging
	if(target & LOG_APP)
	{
		app << buffer << endl;
		#ifdef DEBUG
			app.flush();
		#endif
	}
	if(target & LOG_CLIENT)
	{
		client << buffer << endl;
		#ifdef DEBUG
			client.flush();
		#endif
	}
	if(target & LOG_SERVER)
	{
		server << buffer << endl;
		#ifdef DEBUG
			server.flush();
		#endif
	}
	va_end(arguments);
}

// Stores each message ID and calls write(target, buffer, ...)
void Log::write(int target, unsigned long int ID, ...)
{
	va_list arguments;
	va_start(arguments, ID);
	char buffer[MAX_BUFFER];
	vsprintf(buffer, strings[ID].c_str(), arguments);
	write(target, buffer);
	va_end(arguments);
}

