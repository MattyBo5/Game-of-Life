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

Cell* World::find(int row, int col)
{
	return &grid[row][col];
}

Cell* World::findNeighbor(int row, int col, int index)
{
	int nRow, nCol;
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
	// Determine the special cases (boundary of world)
	if((row == 0) && (index >= 0 && index <= 2))
		return 0;
	else if((row == rows) && (index >= 4 && index <= 6))
		return 0;
	else if((col == 0) && ((index == 0) || (index == 6) || (index == 7)))
		return 0;
	else if((col = cols) && ((index >= 2) && (index <= 4)))
		return 0;
	else
		return find(nRow, nCol);
}

World::World()
{
	rows = 100;
	cols = 100;
	size = rows * cols;
	turn = 0;
	//grid = new Cell[rows, cols];
}

World::World(int aSize)
{
	rows = aSize / 2;
	cols = aSize / 2;
	size = rows * cols;
	//grid = new Cell[rows, cols];
	turn = 0;
}

World::World(int numRows, int numCols)
{
	rows = numRows;
	cols = numCols;
	size = rows * cols;
	turn = 0;
}

World::~World()
{

}
