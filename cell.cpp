/***************************************************************************************************
 File Name:
  cell.cpp

 Purpose:
	Implementation file for the cells of the game. Defines a class called Cell that represents the
	cells contained in the grid.

 Authors:
	Igor Janjic
***************************************************************************************************/

#include "cell.h"

int Cell::living = 0;
int Cell::deceased = 0;

Cell::Cell()
{
	breed = normal;
	health = false;
	deceased++;
}

Cell::Cell(species aBreed, bool aHealth)
{
	breed = aBreed;
	health = aHealth;
	if(aHealth)
		living++;
	else
		deceased++;
}

void Cell::setHealth(bool newHealth)
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

void Cell::setSpecies(species newBreed)
{
	breed = newBreed;
}
