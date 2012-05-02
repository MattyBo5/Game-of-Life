/***************************************************************************************************
 File Name:
	cell.cpp

 Purpose:
	Implementation file for the cells of the game. Defines a class called Cell that represents the
	cells contained in the grid.

 Authors:
	Igor Janjic

 Version:
	1.0 (5/1/12) - DONE
***************************************************************************************************/

#include "cell.h"

// Initialize the population iterators to 0
int Cell::population = 0;
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

Cell::~Cell(){}

Cell::species Cell::getBreed() const
{
	return breed;
}

bool Cell::isHealthy() const
{
	return health;
}

int Cell::getPopulation() const
{
	return population;
}

int Cell::getLiving() const
{
	return living;
}

int Cell::getDeceased() const
{
	return deceased;
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

void Cell::setBreed(species newBreed)
{
	breed = newBreed;
}
