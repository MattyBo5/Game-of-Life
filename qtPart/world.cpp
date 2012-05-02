/***************************************************************************************************
 File Name:
	world.cpp

 Purpose:
	Implementation file for the world of the game. Defines a class called World that handles all of
	the logic of the world. This file does not specify any UI information about the world.

 Authors:
	Igor Janjic
***************************************************************************************************/

#include "world.h"

/*string World::allocFail() const
{
	return "Error... Dynamic memory allocation failed.\n";
}*/

Cell* World::find(int row, int col)
{
	if((row < 0) || (col > cols))
		return 0;
	return grid[row][col];
}

Cell* World::findNeighbor(int row, int col, int index)
{
	int nRow, nCol;
	// Determine the special cases (boundary of world)
	if((row == 0) && (index >= 0 && index <= 2))
		return 0;
	else if((row == (rows - 1)) && (index >= 4 && index <= 6))
		return 0;
	else if((col == 0) && ((index == 0) || (index == 6) || (index == 7)))
		return 0;
	else if((col == (cols - 1)) && ((index >= 2) && (index <= 4)))
		return 0;
	else
	{
		switch(index) // Determine the coordinates of the neighbor
		{
			case 0:
				nRow = row - 1;
				nCol = col - 1;
				break;
			case 1:
				nRow = row - 1;
				nCol = col;
				break;
			case 2:
				nRow = row - 1;
				nCol = col + 1;
				break;
			case 3:
				nRow = row;
				nCol = col + 1;
				break;
			case 4:
				nRow = row + 1;
				nCol = col + 1;
				break;
			case 5:
				nRow = row + 1;
				nCol = col;
				break;
			case 6:
				nRow = row + 1;
				nCol = col - 1;
				break;
			case 7:
				nRow = row;
				nCol = col - 1;
		}
		return find(nRow, nCol);
	}
}

bool World::checkRule1(const bool health, const int numLiving) const
{
	if((health == true) && (numLiving < rules.rule1))
		return false;
	else
		return health;
}

bool World::checkRule2(const bool health, const int numLiving) const
{
	if(health == true && (numLiving > rules.rule2))
		return false;
	else
		return health;
}

bool World::checkRule3(const bool health, const int numLiving) const
{
	if(health == false && (numLiving == rules.rule3))
		return true;
	else
		return health;
}

World::World()
{
	rows = 25;
	cols = 35;
	size = rows * cols;
	turn = 0;
	setRule1(0);
	setRule2(0);
	setRule3(0);
		
	for(int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			grid[i][j] = new Cell();
		}
	}
}

World::~World()
{
	// Free the grid
	for(int i = 0; i < cols; i++)
		delete[] grid[i];
	delete[] grid;
}

int World::getRows() const
{
	return rows;
}

int World::getCols() const
{
	return cols;
}

int World::getSize() const
{
	return size;
}

int World::getTurn() const
{
	return turn;
}

int World::getRule1() const
{
	return rules.rule1;
}

int World::getRule2() const
{
	return rules.rule2;
}

int World::getRule3() const
{
	return rules.rule3;
}

int World::getLivingNeighbors(const int row, const int col)
{
	int tally = 0;
	for(int i = 0; i < 8; i++)
	{
		Cell* curNeighbor = findNeighbor(row, col, i);
		if(curNeighbor != 0) // If the current Neighbor doesn't exist, don't worry about it
		{
			if(curNeighbor->isHealthy())
				tally++;
		}
	}
	return tally;
}

bool World::isHealthy(const int row, const int col)
{
	Cell* cell = find(row, col);
	if(cell == 0)
	{
		//throw NullPointerException;
		return false;
	}
	return cell->isHealthy();
}

void World::setHealth(const int row, const int col, const bool newHealth)
{
	Cell* cell = find(row, col);
	//if(cell == 0)
	//	throw NullPointerException;
	//else
		cell->setHealth(newHealth);
}

void World::setRule1(const int rule)
{
	if((rule > 0) && (rule <= 8))
		rules.rule1 = rule;
	else
		rules.rule1 = 2;
}

void World::setRule2(const int rule)
{
	if((rule > 0) && (rule <= 8))
		rules.rule2 = rule;
	else
		rules.rule2 = 3;
}

void World::setRule3(const int rule)
{
	if((rule > 0) && (rule <= 8))
		rules.rule3 = rule;
	else
		rules.rule3 = 3;
}

void World::play(const int numTurns)
{
	for(int i = 0; i < numTurns; i++)
	{
		for(int j = 0; j < rows; j++)
		{
			for(int k = 0; k < cols; k++)
			{
				bool health, newHealth;
				int numLiving;
				health = isHealthy(j, k);
				numLiving = getLivingNeighbors(j, k);
				/* The following if-else chain is structured the way it is to promote efficiency in 
				checking the rules for each cell. If the first rule changes the health of the cell,
				the next don't need to be checked, and so on. Could have put the repeated code in a
				function but I think it might be more efficient this way. Not sure though... */
				newHealth = checkRule1(health, numLiving); // Check rule 1
				if(health != newHealth)
					setHealth(j, k, newHealth);
				else
				{
					newHealth = checkRule2(health, numLiving); // Check rule 2
					if(health != newHealth)
						setHealth(j, k, newHealth);
					else
					{
						newHealth = checkRule3(health, numLiving); // Check rule 3
						if(health != newHealth)
							setHealth(j, k, newHealth);
					}
				}
				// Otherwise, leave the cell alone.
			}
		}
	}
}
