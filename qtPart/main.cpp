// Main file for running the grid window application.
#include <QApplication>
#include "gridwindow.h"
//#include "timerwindow.h"
#include <stdexcept>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

void Welcome();             // Welcome Function - Prints upon running program; outputs program name, student name/id, class section.
void Rules();               // Rules Function: Prints the rules for Conway's Game of Life.

using namespace std;

// A simple main method to create the window class  and then pop it up on the screen.
int main(int argc, char *argv[])
{
	World A = new World(25, 35, 0, 0, 0);
    Welcome();                                      // Calls Welcome function to print student/assignment info.
    Rules();                                        // Prints Conway's Game Rules.
    QApplication app(argc, argv);                   // Creates the overall windowed application.
    int rows = 25, cols = 35;                       //The number of rows & columns in the game grid.
    GridWindow widget(NULL,rows,cols, &A);          // Creates the actual window (for the grid).
    widget.show();                                  // Shows the window on the screen.
    return app.exec();                              // Goes into visual loop; starts executing GUI.
}    

// Welcome Function: Prints my name/id, my class number, the assignment, and the program name.
void Welcome()                                                              
{
    cout << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl;
    cout << "Name/ID - Gabe Audick #7681539807" << endl;
    cout << "Class/Assignment - CSCI-102 Disccusion 29915: Homework Assignment #4" << endl;
    cout << "-------------------------------------------------------------------------------------------------" << endl << endl;
}

// Rules Function: Prints the rules for Conway's Game of Life.
void Rules()
{
    cout << "Welcome to Conway's Game of Life." << endl;
    cout << "Game Rules:" << endl;
    cout << "\t 1) Any living cell with fewer than two living neighbours dies, as if caused by underpopulation." << endl;
    cout << "\t 2) Any live cell with more than three live neighbours dies, as if by overcrowding." << endl;
    cout << "\t 3) Any live cell with two or three live neighbours lives on to the next generation." << endl;
    cout << "\t 4) Any dead cell with exactly three live neighbours becomes a live cell." << endl << endl;
    cout << "Enjoy." << endl << endl;
}
