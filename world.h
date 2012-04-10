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

#include "cell.h"

/***************************************************************************************************
 Class:
	World

 Summary:
	Handles all of the logic for the world.

 Description:
	None.

 Remarks:
	None.
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

/***************************************************************************************************
 Method:
	Cell* find(int row, int col)

 Scope:
	Private.

 Summary:
	Determines the pointer to the cell at the specified location.

 Description:
	None.

 Precondition:
	None.

 Parameters:
	1.	int row - The row of the cell (first index of matrix).
	2.	int col - The column of the cell (second index of matrix).

 Returns:
	This method returns a pointer to the cell at the specified location.

 Example:
	<code>
	Cell* aCell = find(0, 0); // Find the cell located at the top left corner of the grid
	</code>

 Remarks:
	None.
***************************************************************************************************/

	Cell* find(int row, int col);

/***************************************************************************************************
 Method:
	Cell* findNeighbor(Cell* aCell, int index)

 Scope:
	Private.

 Summary:
	Determines the pointer to the neighbor of a cell at a specied location.

 Description:
	None.

 Precondition:
	None.

 Parameters:
	1.	int row - The row of the cell whose neighbor is being found.
	2.	int col - The column of the cell whose neighbor is being found.
	3.	int index - The index of the neighbor. Each cell has 8 neighbors that surround it in a 3x3
		shell. The top left neighbor is first and each subsequent neighbor is linearly clockwise
		from the previous.

 Returns:
	This method returns a pointer to the specified neighbor of a specified cell. If a cell is
	specified with no neighbor in the specified location, NULL is returned.

 Example:
	<code>
	Cell* aCell = findNeighbor(0, 0, 0);
	</code>

 Remarks:
	Calls find().
***************************************************************************************************/

	Cell* findNeighbor(int row, int col, int index);

public:

/***************************************************************************************************
 Method:
	World()

 Scope:
	Public.

 Summary:
	The default constructor.

 Description:
	Initializes the number of rows and columns of the grid to 100. The size is set to 1000. The turn
	number is set to 0.

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
	World(int aSize)

 Scope:
	Public.

 Summary:
	A constructor.

 Description:
	Initializes the number of rows and columns of the grid by size / 2. The size of the grid is then
	set to rows * columns. The turn number is set to 0.

 Precondition:
	None.

 Parameters:
	1.	int aSize - The value used to determine the size of the grid.

 Returns:
	Nothing.

 Example:
	<code>
	World A(1000);
	</code>

 Remarks:
	Memory tests for recommended sizes must be performed.
***************************************************************************************************/

	World(int aSize);

/***************************************************************************************************
 Method:
	World(int numRows, int numCols)

 Scope:
	Public.

 Summary:
	A constructor.

 Description:
	Initializes the number of rows and columns of the grid to the specified values. The size of the
	grid is set to rows * columns. The turn number is set to 0.

 Precondition:
	None.

 Parameters:
	1.	int numRows - The number of rows the grid will be set to.
	2.	int numCols - The number of cols the grid will be set to.

 Returns:
	Nothing.

 Example:
	<code>
	World A(100, 100);
	</code>

 Remarks:
	Memory tests for recommended sizes must be performed.
***************************************************************************************************/

	World(int numRows, int numCols);

/***************************************************************************************************
 Method:
	~World()

 Scope:
	Public.

 Summary:
	The default destructor.

 Description:
	None.

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

	~World();

};

#endif
