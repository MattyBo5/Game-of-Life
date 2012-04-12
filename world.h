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

using std::cerr;
using std::string;

/***************************************************************************************************
 Class:
	World

 Summary:
	Defines the environment for the game to take place.

 Description:
	None.

 Remarks:
	Depends on Cell class.
***************************************************************************************************/

class World
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
		1.	Any live cell with fewer than (rule1) live neighbours dies, as if caused by
			under-population.
		2.	Any live cell with more than (rule3) live neighbours dies, as if by overcrowding.
		3.	Any dead cell with exactly (rule4) live neighbours becomes a live cell, as if by
			reproduction. */
	struct Rules
	{
		int rule1;
		int rule2;
		int rule3;
	};

	/* Contains the current configuration for rules. */
	Rules rules;

	/* Exception member for dynamic memory allocation. */
	static const int AllocFailException = 0;

	/* Exception for a NULL pointer. */
	static const int NullPointerException = 1;

protected:

/***************************************************************************************************
 Method:
	virtual string allocFail() const

 Scope:
	Protected.

 Summary:
	Exception handler for dynamic memory allocation failure.

 Description:
	Sends an error message to std error.

 Precondition:
	None.

 Parameters:
	None.

 Returns:
	Nothing.

 Example:
	<code>
	allocFailException();
	</code>

 Remarks:
	None.
***************************************************************************************************/

	virtual string allocFail() const;

/***************************************************************************************************
 Method:
	virtual Cell* find(const int row, const int col)

 Scope:
	Protected.

 Summary:
	Determines the pointer to the cell at the specified location.

 Description:
	None.

 Precondition:
	None.

 Parameters:
	1.	const int row - The row of the cell (first index of matrix).
	2.	const int col - The column of the cell (second index of matrix).

 Returns:
	This method returns a pointer to the cell at the specified location.

 Example:
	<code>
	Cell* aCell = find(0, 0); // Find the cell located at the top left corner of the grid
	</code>

 Remarks:
	None.
***************************************************************************************************/

	virtual Cell* find(const int row, const int col);

/***************************************************************************************************
 Method:
	virtual Cell* findNeighbor(Cell* aCell, int index)

 Scope:
	Protected.

 Summary:
	Determines the pointer to the neighbor of a cell at a specied location.

 Description:
	None.

 Precondition:
	None.

 Parameters:
	1.	const int row - The row of the cell whose neighbor is being found.
	2.	const int col - The column of the cell whose neighbor is being found.
	3.	const int index - The index of the neighbor. Each cell has 8 neighbors that surround it in a
		3x3 shell. The top left neighbor is first (starting at at 0) and each subsequent neighbor is
		linearly clockwise from the previous.

 Returns:
	This method returns a pointer to the specified neighbor of a specified cell. If a cell is
	specified with no neighbor in the specified location, NULL is returned.

 Example:
	<code>
	Cell* aCell = findNeighbor(0, 0, 0);
	</code>

 Remarks:
	None.
***************************************************************************************************/

	virtual Cell* findNeighbor(const int row, const int col, const int index);

/***************************************************************************************************
 Method:
	virtual bool checkRule1(const bool health, const int numLiving) const

 Scope:
	Protected.

 Summary:
	Checks whether a cell would die by under-population given the conditions of its existence.

 Description:
	None.

 Precondition:
	None.

 Parameters:
	1.	const bool health - The health of the cell.
	2.	const int numLiving - The number of living neighbors the cell has.

 Returns:
	This method returns TRUE if the cell is alive after rule 1 is applied or FALSE if the cell is
	dead after rule 1 is applied.

 Example:
	<code>
	bool newHealth = checkRule1(TRUE, 0);
	</code>

 Remarks:
	None.
***************************************************************************************************/

	virtual bool checkRule1(const bool health, const int numLiving) const;

/***************************************************************************************************
 Method:
	virtual bool checkRule2(const bool health, const int numLiving) const

 Scope:
	Protected.

 Summary:
	Checks whether a cell would die by overcrowding given the conditions of its existence.

 Description:
	None.

 Precondition:
	None.

 Parameters:
	1.	const bool health - The health of the cell.
	2.	const int numLiving - The number of living neighbors the cell has.

 Returns:
	This method returns TRUE if the cell is alive after rule 2 is applied or FALSE if the cell is
	dead after rule 2 is applied.

 Example:
	<code>
	bool newHealth = checkRule2(TRUE, 0);
	</code>

 Remarks:
	None.
***************************************************************************************************/

	virtual bool checkRule2(const bool health, const int numLiving) const;

/***************************************************************************************************
 Method:
	virtual bool checkRule3(const bool health, const int numLiving) const

 Scope:
	Protected.

 Summary:
	Checks whether a cell would revive given the conditions of its existence.

 Description:
	None.

 Precondition:
	None.

 Parameters:
	1.	const bool health - The health of the cell.
	2.	const int numLiving - The number of living neighbors the cell has.

 Returns:
	This method returns TRUE if the cell is alive after rule 3 is applied or FALSE if the cell is
	dead after rule 3 is applied.

 Example:
	<code>
	bool newHealth = checkRule3(TRUE, 0);
	</code>

 Remarks:
	None.
***************************************************************************************************/

	virtual bool checkRule3(const bool health, const int numLiving) const;

public:

/***************************************************************************************************
 Method:
	World()

 Scope:
	Public.

 Summary:
	The default constructor.

 Description:
	Initializes the number of rows and columns of the grid to 100. The size is set to 1000. Each
	cell is initialized to it's default configuration (normal and dead). The turn number is set to
	0. The rules are set to their default values.

 Precondition:
	None.

 Parameters:
	None.

 Returns:
	Nothing.

 Example:
	<code>
	World A;
	</code>

 Remarks:
	None.
***************************************************************************************************/

	World();

/***************************************************************************************************
 Method:
	World(const int aSize, const int rule1, const int rule2, const int rule3)

 Scope:
	Public.

 Summary:
	A constructor.

 Description:
	Initializes the number of rows and columns of the grid by size / 2. The size of the grid is then
	set to rows * columns. Each cell is initialized to it's default configuration (normal and dead).
	The turn number is set to 0. The rules are set to their specified values. A value of 0 for a
	rule sets that particular to rule to its default value.

 Precondition:
	None.

 Parameters:
	1.	const int aSize - The value used to determine the size of the grid.
	2.	const int rule1 - The value rule 1 will be set to.
	3.	const int rule2 - The value rule 2 will be set to.
	4.	const int rule3 - The value rule 3 will be set to.

 Returns:
	Nothing.

 Example:
	<code>
	World A(1000, 0, 0, 0);
	</code>

 Remarks:
	Memory tests for recommended sizes must be performed.
***************************************************************************************************/

	World(const int aSize, const int rule1, const int rule2, const int rule3);

/***************************************************************************************************
 Method:
	World(const int numRows, const int numCols)

 Scope:
	Public.

 Summary:
	A constructor.

 Description:
	Initializes the number of rows and columns of the grid to the specified values. The size of the
	grid is set to rows * columns. Each cell is initialized to it's default configuration (normal
	and dead). The turn number is set to 0. The rules are set to their specified values. A value of
	0 for a rule sets that particular to rule to its default value.

 Precondition:
	None.

 Parameters:
	1.	const int numRows - The number of rows the grid will be set to.
	2.	const int numCols - The number of cols the grid will be set to.
	3.	const int rule1 - The value rule 1 will be set to.
	4.	const int rule2 - The value rule 2 will be set to.
	5.	const int rule3 - The value rule 3 will be set to.

 Returns:
	Nothing.

 Example:
	<code>
	World A(100, 100, 0, 0, 0);
	</code>

 Remarks:
	Memory tests for recommended sizes must be performed.
***************************************************************************************************/

	World(const int numRows, const int numCols, const int rule1, const int rule2, const int rule3);

/***************************************************************************************************
 Method:
	virtual ~World()

 Scope:
	Public.

 Summary:
	The default destructor.

 Description:
	Frees the grid.

 Precondition:
	None.

 Parameters:
	None.

 Returns:
	Nothing.

 Example:
	None.

 Remarks:
	None.
***************************************************************************************************/

	virtual ~World();

/***************************************************************************************************
 Method:
	virtual int getRows() const

 Scope:
	Public.

 Summary:
	Gets the number of rows of the grid.

 Description:
	None.

 Precondition:
	None.

 Parameters:
	None.

 Returns:
	This method returns the number of rows of the grid.

 Example:
	<code>
	World A;
	int numRows = A.getRows();
	</code>

 Remarks:
	None.
***************************************************************************************************/

	virtual int getRows() const;

/***************************************************************************************************
 Method:
	virtual int getCols() const

 Scope:
	Public.

 Summary:
	Gets the number of columns of the grid.

 Description:
	None.

 Precondition:
	None.

 Parameters:
	None.

 Returns:
	This method returns the number of columns of the grid.

 Example:
	<code>
	World A;
	int numCols = A.getCols();
	</code>

 Remarks:
	None.
***************************************************************************************************/

	virtual int getCols() const;

/***************************************************************************************************
 Method:
	virtual int getSize() const

 Scope:
	Public.

 Summary:
	Gets the size of the grid.

 Description:
	None.

 Precondition:
	None.

 Parameters:
	None.

 Returns:
	This method returns the size of the grid.

 Example:
	<code>
	World A;
	int curSize = A.getSize();
	</code>

 Remarks:
	None.
***************************************************************************************************/

	virtual int getSize() const;

/***************************************************************************************************
 Method:
	virtual int getTurn() const

 Scope:
	Public.

 Summary:
	Gets the turn number of the game.

 Description:
	None.

 Precondition:
	None.

 Parameters:
	None.

 Returns:
	This method returns the turn number of the game.

 Example:
	<code>
	Life A;
	int curTurn = A.getTurn();
	</code>

 Remarks:
	None.
***************************************************************************************************/

	virtual int getTurn() const;

/***************************************************************************************************
 Method:
	virtual int getRule1() const

 Scope:
	Public.

 Summary:
	Gets rule 1 of the game.

 Description:
	None.

 Precondition:
	None.

 Parameters:
	None.

 Returns:
	This method returns the value of rule 1 of the game.

 Example:
	<code>
	World A;
	int rule1 = A.getRule1();
	</code>

 Remarks:
	This method does not modify any members.
***************************************************************************************************/

	virtual int getRule1() const;

/***************************************************************************************************
 Method:
	virtual int getRule2() const

 Scope:
	Public.

 Summary:
	Gets rule 2 of the game.

 Description:
	None.

 Precondition:
	None.

 Parameters:
	None.

 Returns:
	This method returns the value of rule 2 of the game.

 Example:
	<code>
	World A;
	int rule2 = A.getRule2();
	</code>

 Remarks:
	This method does not modify any members.
***************************************************************************************************/

	virtual int getRule2() const;

/***************************************************************************************************
 Method:
	virtual int getRule3() const

 Scope:
	Public.

 Summary:
	Gets rule 3 of the game.

 Description:
	None.

 Precondition:
	None.

 Parameters:
	None.

 Returns:
	This method returns the value of rule 3 of the game.

 Example:
	<code>
	World A;
	int rule3 = A.getRule3();
	</code>

 Remarks:
	This method does not modify any members.
***************************************************************************************************/

	virtual int getRule3() const;

/***************************************************************************************************
 Method:
	virtual int getLivingNeighbors(const int row, const int col)

 Scope:
	Public.

 Summary:
	Determines the number of living neighbors a cell has.

 Description:
	None.

 Precondition:
	None.

 Parameters:
	None.

 Returns:
	This method returns the number of living neighbors a cell has.

 Example:
	<code>
	World A;
	int numLivingNeighbors = getLivingNeighbors(0, 0);
	</code>

 Remarks:
	For a cell located on the boundary of the world, those neighbors that do not exist are
	considered dead.
***************************************************************************************************/

	virtual int getLivingNeighbors(const int row, const int col);

/***************************************************************************************************
 Method:
	virtual bool isHealthy() const

 Scope:
	Public.

 Summary:
	Determines if the specified cell is dead or alive.

 Description:
	A living cell has its health member set to TRUE, while an decease cell has its health
	member set to FALSE.

 Precondition:
	None.

 Parameters:
	None.

 Returns:
	This method returns TRUE if the cell is alive and FALSE if the cell is dead.

 Example:
	<code>
	World A;
	bool curHealth = A.isHealthy();
	</code>

 Remarks:
	None.
***************************************************************************************************/

	virtual bool isHealthy(const int row, const int col);

/***************************************************************************************************
 Method:
	virtual void setHealth(const bool newHealth)

 Scope:
	Public.

 Summary:
	Revives or kills the specified cell.

 Description:
	None.

 Precondition:
	None.

 Parameters:
	1.	const int row - The row of the cell whose health is being changed.
	2.	const int col - The column of the cell whose health is being changed.
	1.	const bool newHealth - The new health of the cell (TRUE for alive, FALSE for dead).

 Returns:
	Nothing.

 Example:
	<code>
	setHealth(TRUE);
	</code>

 Remarks:
	None.
***************************************************************************************************/

	virtual void setHealth(const int row, const int col, const bool newHealth);

/***************************************************************************************************
 Method:
	virtual void setRule1(const int rule)

 Scope:
	Public.

 Summary:
	Sets the under-population limit.

 Description:
	Any live cell with fewer than (rule1) live neighbours dies, as if caused by under-population.

 Precondition:
	None.

 Parameters:
	1.	const int rule - The rule that rule1 will be set to. If a value of 0 is passed, the default
		rule will be used.

 Returns:
	Nothing.

 Example:
	<code>
	World A;
	A.setRule1(0);
	</code>

 Remarks:
	If an invalid rule is given (a rule that is outside of the integer range (0, 8]), the particular
	rule will be set to the default value.
***************************************************************************************************/

	virtual void setRule1(const int rule);

/***************************************************************************************************
 Method:
	virtual void setRule2(const int rule)

 Scope:
	Public.

 Summary:
	Sets the overcrowding limit for living cells.

 Description:
	Any live cell with more than (rule2) live neighbours dies, as if by overcrowding.

 Precondition:
	None.

 Parameters:
	1.	const int rule - The rule that rule2 will be set to. If a value of 0 is passed, the default
		rule will be used.

 Returns:
	Nothing.

 Example:
	<code>
	World A;
	A.setRule2(0);
	</code>

 Remarks:
	If an invalid rule is given (a rule that is outside of the integer range (0, 8]), the particular
	rule will be set to the default value.
***************************************************************************************************/

	virtual void setRule2(const int rule);

/***************************************************************************************************
 Method:
	virtual void setRule3(const int rule)

 Scope:
	Public.

 Summary:
	Sets the reproduction limit for living cells.

 Description:
	Any dead cell with exactly (rule3) live neighbours becomes a live cell, as if by reproduction.

 Precondition:
	None.

 Parameters:
	1.	const int rule - The rule that rule3 will be set to. If a value of 0 is passed, the default
		rule will be used.

 Returns:
	Nothing.

 Example:
	<code>
	World A;
	A.setRule3(0);
	</code>

 Remarks:
	If an invalid rule is given (a rule that is outside of the integer range (0, 8]), the particular
	rule will be set to the default value.
***************************************************************************************************/

	virtual void setRule3(const int rule);

/***************************************************************************************************
 Method:
	virtual void play(const int numTurns)

 Scope:
	Public.

 Summary:
	Plays the game a specified number of turns.

 Description:
	None.

 Precondition:
	The size of the world cannot change during the function call.

 Parameters:
	1.	const int numTurns - The number of turns the game will be played.

 Returns:
	Nothing.

 Example:
	<code>
	World A;
	A.play(1);
	</code>

 Remarks:
	None.
***************************************************************************************************/

	virtual void play(const int numTurns);

};

#endif