/***************************************************************************************************
 File Name:
	world.h

 Purpose:
	Specification file for the world of the game. Defines a class called World that handles all of
	the logic of the world. This file does not specify any UI information about the world.

 Authors:
	Igor Janjic
***************************************************************************************************/

#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <string>
#include "cell.h"
#include "gobject.h"
#include "error.h"
using std::cerr;
using std::string;

/***************************************************************************************************
 Class:
	World

 Description:
	Defines the environment for the game to take place.

 Remarks:
	Depends on Cell class.
***************************************************************************************************/

class World : public Gobject, public Error
{

private:

    /* The grid of the game. The grid is a 2x2 dynamically allocated matrix whose elements are
    pointers to dynamically allocated instances of cells. */
    Cell** grid;
    
	/* The number of rows of the grid. */
	int rows;

	/* The number of columns of the grid. */
	int cols;

	/* The number of cells in the grid. Really just rows * columns but it's provided for
	convenience. */
	int size;

	/* The turn number of the game. */
	int turn;

	/* The rules are defined as follows:
        1.	Any live cell with fewer than (rule1) live neighbors dies, as if caused by
			under-population.
		2.	Any live cell with more than (rule3) live neighbors dies, as if by overcrowding.
		3.	Any dead cell with exactly (rule4) live neighbors becomes a live cell, as if by
			reproduction. */
	struct Rules
	{
		int rule1;
		int rule2;
		int rule3;
	};

	/* Contains the current configuration for rules. */
	Rules rules;

protected:

/***************************************************************************************************
 Method:
	Cell* find(int row, int col)

 Scope:
	Protected.

 Description:
	Determines the pointer to the cell at the specified location.

 Parameters:
	1.	int row - The row of the cell (first index of matrix).
	2.	int col - The column of the cell (second index of matrix).

 Returns:
	This method returns a pointer to the cell at the specified location.
***************************************************************************************************/

    Cell* find(int row, int col);

/***************************************************************************************************
 Method:
	Cell* findNeighbor(int row, int col, int index)

 Scope:
	Protected.

 Description:
	Determines the pointer to the neighbor of a cell at the specified location.

 Parameters:
	1.  int row - The row of the cell whose neighbor is being found.
	2.	int col - The column of the cell whose neighbor is being found.
	3.	int index - The index of the neighbor. Each cell has 8 neighbors that surround it in a 3x3
    shell. The top left neighbor is first (starting at at 0) and each subsequent neighbor is
    linearly clockwise from the previous.

 Returns:
	This method returns a pointer to the specified neighbor of a specified cell. If a cell is
	specified with no neighbor in the specified location, NULL is returned.
***************************************************************************************************/

	Cell* findNeighbor(int row, int col, int index);

/***************************************************************************************************
 Method:
	bool checkRule1(bool health, int numLiving) const

 Scope:
	Protected.

 Description:
	Checks whether a cell would die by under-population given the conditions of its existence.

 Parameters:
	1.	bool health - The health of the cell.
	2.	int numLiving - The number of living neighbors the cell has.

 Returns:
	This method returns TRUE if the cell is alive after rule 1 is applied or FALSE if the cell is
	dead after rule 1 is applied.
***************************************************************************************************/

	bool checkRule1(bool health, int numLiving) const;

/***************************************************************************************************
 Method:
	bool checkRule2(bool health, int numLiving) const

 Scope:
	Protected.

 Description:
	Checks whether a cell would die by overcrowding given the conditions of its existence.

 Parameters:
	1.	bool health - The health of the cell.
	2.	int numLiving - The number of living neighbors the cell has.

 Returns:
	This method returns TRUE if the cell is alive after rule 2 is applied or FALSE if the cell is
	dead after rule 2 is applied.
***************************************************************************************************/

    bool checkRule2(bool health, int numLiving) const;

/***************************************************************************************************
 Method:
	bool checkRule3(bool health, int numLiving) const

 Scope:
	Protected.

 Description:
	Checks whether a cell would revive given the conditions of its existence.

 Parameters:
	1.	bool health - The health of the cell.
	2.	int numLiving - The number of living neighbors the cell has.

 Returns:
	This method returns TRUE if the cell is alive after rule 3 is applied or FALSE if the cell is
	dead after rule 3 is applied.
***************************************************************************************************/

	bool checkRule3(bool health, int numLiving) const;

public:

/***************************************************************************************************
 Method:
	World()

 Scope:
	Public.

 Description:
	The default constructor. Initializes the number of rows and columns of the grid to 100. The size
    is set to 1000. Each cell is initialized to it's default configuration (normal and dead). The
    turn number is set to 0. The rules are set to their default values.
***************************************************************************************************/

	World();

/***************************************************************************************************
 Method:
	World(int aSize, int rule1, int rule2, int rule3)

 Scope:
	Public.

 Description:
	A constructor. Initializes the number of rows and columns of the grid by size / 2. The size of
    the grid is then set to rows * columns. Each cell is initialized to it's default configuration
    (normal and dead). The turn number is set to 0. The rules are set to their specified values. A
    value of 0 for a rule sets that particular to rule to its default value.

 Parameters:
	1.	int aSize - The value used to determine the size of the grid.
	2.	int rule1 - The value rule 1 will be set to.
	3.	int rule2 - The value rule 2 will be set to.
	4.	int rule3 - The value rule 3 will be set to.

 Remarks:
	Memory tests for recommended sizes must be performed.
***************************************************************************************************/

	World(int aSize, int rule1, int rule2, int rule3);

/***************************************************************************************************
 Method:
	World(int numRows, int numCols)

 Scope:
	Public.

 Description:
	A constructor. Initializes the number of rows and columns of the grid to the specified values.
    The size of the grid is set to rows * columns. Each cell is initialized to it's default
    configuration (normal and dead). The turn number is set to 0. The rules are set to their
    specified values. A value of 0 for a rule sets that particular to rule to its default value.

 Parameters:
	1.	const int numRows - The number of rows the grid will be set to.
	2.	const int numCols - The number of cols the grid will be set to.
	3.	const int rule1 - The value rule 1 will be set to.
	4.	const int rule2 - The value rule 2 will be set to.
	5.	const int rule3 - The value rule 3 will be set to.

 Remarks:
	Memory tests for recommended sizes must be performed.
***************************************************************************************************/

	World(int numRows, int numCols, int rule1, int rule2, int rule3);

/***************************************************************************************************
 Method:
	~World()

 Scope:
	Public.

 Description:
	The default destructor. Frees the grid.
***************************************************************************************************/

	~World();

/***************************************************************************************************
 Method:
	int getRows() const

 Scope:
	Public.

 Description:
	Gets the number of rows of the grid.

 Returns:
	This method returns the number of rows of the grid.
***************************************************************************************************/

	int getRows() const;

/***************************************************************************************************
 Method:
	int getCols() const

 Scope:
	Public.

 Description:
	Gets the number of columns of the grid.

 Returns:
	This method returns the number of columns of the grid.
***************************************************************************************************/

	int getCols() const;

/***************************************************************************************************
 Method:
	int getSize() const

 Scope:
	Public.

 Description:
	Gets the size of the grid.

 Returns:
	This method returns the size of the grid.
***************************************************************************************************/

	int getSize() const;

/***************************************************************************************************
 Method:
	int getTurn() const

 Scope:
	Public.

 Description:
	Gets the turn number of the game.

 Returns:
	This method returns the turn number of the game.
***************************************************************************************************/

	int getTurn() const;

/***************************************************************************************************
 Method:
	int getRule1() const

 Scope:
	Public.

 Description:
	Gets rule 1 of the game.

 Returns:
	This method returns the value of rule 1 of the game.
***************************************************************************************************/

	int getRule1() const;

/***************************************************************************************************
 Method:
	int getRule2() const

 Scope:
	Public.

 Description:
	Gets rule 2 of the game.

 Returns:
	This method returns the value of rule 2 of the game.
***************************************************************************************************/

	int getRule2() const;

/***************************************************************************************************
 Method:
	int getRule3() const

 Scope:
	Public.

 Description:
	Gets rule 3 of the game.

 Returns:
	This method returns the value of rule 3 of the game.
***************************************************************************************************/

	int getRule3() const;

/***************************************************************************************************
 Method:
	int getLivingNeighbors(int row, int col) const

 Scope:
	Public.

 Description:
	Determines the number of living neighbors a cell has.

 Parameters:
    1.  int row - The row of the cell.
	2.	int col - The column of the cell.

 Returns:
	This method returns the number of living neighbors a cell has.

 Remarks:
	For a cell located on the boundary of the world, those neighbors that do not exist are
	considered dead.
***************************************************************************************************/

	int getLivingNeighbors(int row, int col);

/***************************************************************************************************
 Method:
	bool isHealthy(int row, int col) const

 Scope:
	Public.

 Parameters:
    1.  int row - The row of the cell.
	2.	int col - The column of the cell.
 
 Description:
	Determines if the specified cell is dead or alive. A living cell has its health member set to
    TRUE, while an decease cell has its health member set to FALSE.

 Returns:
	This method returns TRUE if the cell is alive and FALSE if the cell is dead.
***************************************************************************************************/

	bool isHealthy(int row, int col);

/***************************************************************************************************
 Method:
	void setHealth(int row, int col, bool newHealth)

 Scope:
	Public.

 Description:
	Revives or kills the specified cell.

 Parameters:
	1.	int row - The row of the cell.
	2.	int col - The column of the cell.
	3.	bool newHealth - The new health of the cell (TRUE for alive, FALSE for dead).
***************************************************************************************************/

	void setHealth(int row, int col, bool newHealth);

/***************************************************************************************************
 Method:
	void setRule1(int rule)

 Scope:
	Public.

 Description:
	Sets the under-population limit. Any live cell with fewer than (rule1) live neighbors dies, as
    if caused by under-population.

 Parameters:
	1.	int rule - The rule that rule1 will be set to. If a value of 0 is passed, the default rule
        will be used.

 Remarks:
	If an invalid rule is given (a rule that is outside of the integer range (0, 8]), the particular
	rule will be set to the default value.
***************************************************************************************************/

	void setRule1(int rule);

/***************************************************************************************************
 Method:
	void setRule2(int rule)

 Scope:
	Public.

 Description:
	Sets the overcrowding limit for living cells. Any live cell with more than (rule2) live
    neighbors dies, as if by overcrowding.

 Parameters:
	1.	int rule - The rule that rule2 will be set to. If a value of 0 is passed, the default rule
        will be used.

 Remarks:
	If an invalid rule is given (a rule that is outside of the integer range (0, 8]), the particular
	rule will be set to the default value.
***************************************************************************************************/

	void setRule2(int rule);

/***************************************************************************************************
 Method:
	void setRule3(int rule)

 Scope:
	Public.

 Description:
	Sets the reproduction limit for living cells. Any dead cell with exactly (rule3) live neighbors
    becomes a live cell, as if by reproduction.

 Parameters:
	1.	int rule - The rule that rule3 will be set to. If a value of 0 is passed, the default rule
    will be used.

 Remarks:
	If an invalid rule is given (a rule that is outside of the integer range (0, 8]), the particular
	rule will be set to the default value.
***************************************************************************************************/

	void setRule3(int rule);

/***************************************************************************************************
 Method:
	void play(int numTurns)

 Scope:
	Public.

 Description:
	Plays the game a specified number of turns.

 Precondition:
	The size of the world cannot change during the function call.

 Parameters:
	1.	int numTurns - The number of turns the game will be played.
***************************************************************************************************/

	void play(int numTurns);


};

#endif
