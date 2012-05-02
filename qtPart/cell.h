/***************************************************************************************************
 File Name:
  cell.h

 Purpose:
	Specification file for the cells of the game. Defines a class called Cell that represents the
	cells contained in the grid.

 Authors:
	Igor Janjic

 Version:
	1.0 (5/1/12) - DONE
***************************************************************************************************/

#ifndef CELL_H
#define CELL_H

#include "gobject.h"

class Cell : public Gobject
{

private:

	/* The different possible species allowed for a cell. As of now it's not really used... */
	enum species {normal};

	/* The breed of the cell. The breed can be any defined in enum Species. */
	species breed;

	/* Specifies a cell as either alive or dead with a TRUE value for alive and a FALSE value for
	dead. */
	bool health;

	/* The running number of cells created. */
	static int population;

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
***************************************************************************************************/

	Cell();

/***************************************************************************************************
 Method:
	Cell(species aBreed, bool aHealth)

 Scope:
	Public.

 Description:
	A constructor. Initializes the breed and health of the cell to the specified values. Iterates
    the population. If the health of the cell being created is specified as dead (FALSE), the living
    are incremented. Conversely, if the health of the cell being created is specified as dead
    (FALSE), the deceased are incremented.

 Parameters:
	1.	species aBreed - The breed of the cell.
	2.	bool aHealth - The health of the cell.
***************************************************************************************************/

	Cell(species aBreed, bool aHealth);

/***************************************************************************************************
 Method:
	~Cell()

 Scope:
	Public.

 Description:
	The destructor. Does nothing exciting.
***************************************************************************************************/

    ~Cell();

/***************************************************************************************************
 Method:
	species getBreed() const

 Scope:
	Public.

 Description:
    Gets the breed of the cell.

 Returns:
	This method returns the breed of the cell.
***************************************************************************************************/

	species getBreed() const;

/***************************************************************************************************
 Method:
	bool isHealthy() const

 Scope:
	Public.

 Description:
	Determines if a cell is alive or dead. A living cell has its health member set to TRUE, while a
    decease cell has its health member set to FALSE.

 Returns:
	This method returns TRUE if the cell is alive or FALSE if the cell is dead.
***************************************************************************************************/

	bool isHealthy() const;

/***************************************************************************************************
 Method:
	int getPopulation() const

 Scope:
	Public.

 Description:
    Gets the population of cells.

 Returns:
	This method returns the population of the cells.
***************************************************************************************************/

	int getPopulation() const;

/***************************************************************************************************
 Method:
	int getLiving() const

 Scope:
	Public.

 Description:
	Gets the population of living cells.

 Returns:
	This method returns the population of living cells.
***************************************************************************************************/

	int getLiving() const;

/***************************************************************************************************
 Method:
	int getDeceased() const

 Scope:
	Public.

 Description:
	Gets the population of deceased cells.

 Returns:
	This method returns the population of deceased cells.
***************************************************************************************************/

	int getDeceased() const;

/***************************************************************************************************
 Method:
	void setHealth(const bool newHealth)

 Scope:
	Public.

 Description:
	Revives or kills the cell. Sets the health member of the cell to the specified value. If the
    health of the cell is alive (TRUE) and the new health specified is dead (FALSE), the deceased
    are incremented. Conversely, if the health of the cell is dead (FALSE) and the new health
    specified is alive (TRUE), the living are incremented.

 Parameters:
	1.	bool newHealth - The new health of the cell (TRUE for alive, FALSE for dead).
***************************************************************************************************/

	void setHealth(bool newHealth);

/***************************************************************************************************
 Method:
	void setBreed(species newBreed)

 Scope:
	Public.

 Description:
	Sets the breed of the cell. Sets the breed member of the cell from normal to the specified one
    (unimplemented).

 Parameters:
	1.	newBreed- The new breed of the cell (available species are defined in enum species).
***************************************************************************************************/

	void setBreed(species newBreed);
    
    /* Macro that returns the size of the object. */
    AUTO_SIZE

};

#endif
