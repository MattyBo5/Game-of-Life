/***************************************************************************************************
 File Name:
  cell.h

 Purpose:
	Specification file for the cells of the game. Defines a class called Cell that represents the
	cells contained in the grid.

 Authors:
	Igor Janjic
***************************************************************************************************/

#ifndef CELL_H
#define CELL_H

class Cell
{

private:

	/* The different possible species allowed for a cell. */
	enum species{normal};

	/* The breed of the cell. The breed can be any defined in enum Species. */
	species breed;

	/* Specifies a cell as either alive or dead with a TRUE value for alive and a FALSE value for
	dead. */
	bool health;

	/* The running number of cells created. */
	int population;

	/* The running number of alive cells. */
	static int living;

	/* The running number of deceased cells. */
	static int deceased;

public:

/***************************************************************************************************
 Method:
	Cell()

 Scope:
	Public.

 Summary:
	The default constructor.

 Description:
	Initializes the breed of the cell to normal and the health of the cell to dead (FALSE). Iterates
	the population and the deceased.

 Precondition:
	None.

 Parameters:
	None.

 Returns:
	Nothing.

 Example:
	<code>
	Cell A;
	</code>

 Remarks:
	None.

***************************************************************************************************/

	Cell();

/***************************************************************************************************
 Method:
	Cell(species aBreed, bool aHealth);

 Scope:
	Public.

 Summary:
	A constructor.

 Description:
	Initializes the breed and health of the cell to the specified values. Iterates the population.
	If the health of the cell being created is specified as dead (FALSE), the living are incremented.
	Conversely, if the health of the cell being created is specified as dead (FALSE), the deceased
	are incremented.

 Precondition:
	None.

 Parameters:
	None.

 Returns:
	Nothing.

 Example:
	<code>
	Cell A(normal, FALSE);
	</code>

 Remarks:
	None.

***************************************************************************************************/

	Cell(species aBreed, bool aHealth);

/***************************************************************************************************
 Method:
	void setHealth(int row, int col, bool newHealth);

 Scope:
	Public.

 Summary:
	Revives or kills the cell.

 Description:
	Sets the health data member of the cell to the specified value. If the health of the cell is
	alive (TRUE) and the new health specified is dead (FALSE), the deceased are incremented.
	Conversely, if the health of the cell is dead (FALSE) and the new health specified is alive
	(TRUE), the living are incremented.

 Precondition:
	None.

 Parameters:
	1.	bool newHealth - The new health of the cell (TRUE for alive, FALSE for dead).

 Returns:
	Nothing.

 Example:
	<code>
	setHealth(TRUE);
	</code>

 Remarks:
	None.
***************************************************************************************************/

	void setHealth(bool newHealth);

/***************************************************************************************************
 Method:
	void setSpecies(species newBreed);

 Scope:
	Public.

 Summary:
	Sets the species of the cell.

 Description:
	Sets the species data member of the cell from normal to the specified one.

 Precondition:
	None.

 Parameters:
	1.	bool newBreed- The new species of the cell (available species are defined in enum
		Species).

 Returns:
	Nothing.

 Example:
	<code>
	setSpecies(normal);
	</code>

 Remarks:
	None.
***************************************************************************************************/

	void setSpecies(species newBreed);

};

#endif
