/***************************************************************************************************
 File Name:
	cell.cpp

 Purpose:
	Implementation file for the cells of the game. Defines a class called Cell that represents the
	cells contained in the grid.

 Authors:
	Igor Janjic

 Version:
	1.0 (4/12/12)
***************************************************************************************************/

#include "cell.h"

// Initialize the population itterators to 0
int Cell::population = 0;
int Cell::living = 0;
int Cell::deceased = 0;

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

Cell::Cell()
{
	breed = normal;
	health = false;
	deceased++;
}

/***************************************************************************************************
 Method:
	Cell(const species aBreed, const bool aHealth)

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
	1.	const species aBreed - The breed of the cell.
	2.	const bool aHealth - The health of the cell.

 Returns:
	Nothing.

 Example:
	<code>
	Cell A(normal, FALSE);
	</code>

 Remarks:
	None.
***************************************************************************************************/

Cell::Cell(const species aBreed, const bool aHealth)
{
	breed = aBreed;
	health = aHealth;
	if(aHealth)
		living++;
	else
		deceased++;
}

/***************************************************************************************************
 Method:
	virtual ~Cell()

 Scope:
	Public.

 Summary:
	The destructor.

 Description:
	Does nothing exciting.

 Precondition:
	None.

 Parameters:
	None.

 Returns:
	Nothing.

 Example:
	<code>
	</code>

 Remarks:
	None.
***************************************************************************************************/

Cell::~Cell(){}

/***************************************************************************************************
 Method:
	virtual species getBreed() const

 Scope:
	Public.

 Summary:
	Gets the breed of the cell.

 Description:
	None.

 Precondition:
	None.

 Parameters:
	None.

 Returns:
	This method returns the breed of the cell.

 Example:
	<code>
	Cell A;
	species curBreed = A.getBreed();
	</code>

 Remarks:
	This method does not modify any members.
***************************************************************************************************/

Cell::species Cell::getBreed() const
{
	return breed;
}

/***************************************************************************************************
 Method:
	virtual bool isHealthy() const

 Scope:
	Public.

 Summary:
	Determines if the cell is dead or alive.

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
	Cell A;
	bool curHealth = A.isHealthy();
	</code>

 Remarks:
	This method does not modify any members.
***************************************************************************************************/

bool Cell::isHealthy() const
{
	return health;
}

/***************************************************************************************************
 Method:
	virtual int getPopulation() const

 Scope:
	Public.

 Summary:
	Gets the population of the cells.

 Description:
	None.

 Precondition:
	None.

 Parameters:
	None.

 Returns:
	This method returns the population of the cells.

 Example:
	<code>
	Cell A;
	int curPopulation = A.getPopulation();
	</code>

 Remarks:
	This method does not modify any members.
***************************************************************************************************/

int Cell::getPopulation() const
{
	return population;
}

/***************************************************************************************************
 Method:
	virtual int getLiving() const

 Scope:
	Public.

 Summary:
	Gets the population of living cells.

 Description:
	None.

 Precondition:
	None.

 Parameters:
	None.

 Returns:
	This method returns the population of living cells.

 Example:
	<code>
	Cell A;
	int curLiving = A.getLiving();
	</code>

 Remarks:
	This method does not modify any members.
***************************************************************************************************/

int Cell::getLiving() const
{
	return living;
}

/***************************************************************************************************
 Method:
	virtual int getDeceased() const

 Scope:
	Public.

 Summary:
	Gets the population of deceased cells.

 Description:
	None.

 Precondition:
	None.

 Parameters:
	None.

 Returns:
	This method returns the population of deceased cells.

 Example:
	<code>
	Cell A;
	int curDeceased = A.getDeceased();
	</code>

 Remarks:
	This method does not modify any members.
***************************************************************************************************/

int Cell::getDeceased() const
{
	return deceased;
}

/***************************************************************************************************
 Method:
	virtual void setHealth(const bool newHealth)

 Scope:
	Public.

 Summary:
	Revives or kills the cell.

 Description:
	Sets the health member of the cell to the specified value. If the health of the cell is alive
	(TRUE) and the new health specified is dead (FALSE), the deceased are incremented. Conversely,
	if the health of the cell is dead (FALSE) and the new health specified is alive (TRUE), the
	living are incremented.

 Precondition:
	None.

 Parameters:
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

void Cell::setHealth(const bool newHealth)
{
	if(health && !newHealth)
	{
		living--;
		deceased++;
	}
	else if(!health && newHealth)
	{
		living++;
		deceased--;
	}
	health = newHealth;
}

/***************************************************************************************************
 Method:
	virtual void setBreed(species newBreed)

 Scope:
	Public.

 Summary:
	Sets the breed of the cell.

 Description:
	Sets the breed member of the cell from normal to the specified one.

 Precondition:
	None.

 Parameters:
	1.	bool newBreed- The new breed of the cell (available species are defined in enum species).

 Returns:
	Nothing.

 Example:
	<code>
	setSpecies(normal);
	</code>

 Remarks:
	None.
***************************************************************************************************/

void Cell::setBreed(const species newBreed)
{
	breed = newBreed;
}