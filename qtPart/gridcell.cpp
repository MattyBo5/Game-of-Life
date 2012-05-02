#include <iostream>

#include "gridcell.h"
//#include "utility.h"

using namespace std;

// Constructor: Creates a grid cell.
GridCell::GridCell(QWidget *parent, World *world, const int x, const int y)
: QFrame(parent)
{ 
	master = world;
	row = x;
	col = y;
    this->type = DEAD;              // Default: Cell is DEAD (white).
    setFrameStyle(QFrame::Box);     // Set the frame style.  This is what gives each box its black border.

    this->button = new QPushButton(this);           //Creates button that fills entirety of each grid cell.
    this->button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);         // Expands button to fill space.
    this->button->setMinimumSize(19,19); //width,height                                 // Min height and width of button.

    QHBoxLayout *layout = new QHBoxLayout();                //Creates a simple layout to hold our button and add the button to it.
    layout->addWidget(this->button);
    setLayout(layout);

    layout->setStretchFactor(this->button,1);       // Lets the buttons expand all the way to the edges of the current frame with no space leftover
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);

    connect(this->button,SIGNAL(clicked()),this,SLOT(handleClick()));   // Connects clicked signal with handleClick slot.
    redrawCell();           // Calls function to redraw (set new type for) the cell.
}

// Basic destructor. 
GridCell::~GridCell()
{
    delete this->button;
}


// Accessor for the cell type.
CellType GridCell::getType() const
{
    return(this->type);
}

// Mutator for the cell type.  Also has the side effect of causing the cell to be redrawn on the GUI.
void GridCell::setType(CellType type)
{
    this->type = type;
    switch(this->type)
    {
        default:
        case DEAD:
        	master->setHealth(row, col, FALSE);
        	break;
        case LIVE:
        	master->setHealth(row, col, TRUE);
            break;
    }
    redrawCell();
}

// Handler slot for button clicks.  This method is called whenever the user clicks on this cell in the grid.
void GridCell::handleClick()
{                                   // When clicked on...
  if(this->type == DEAD)            // If type is DEAD (white), change to LIVE (black).
  {
  	type = LIVE;
  }
  else
  { 
    type = DEAD;                    // If type is LIVE (black), change to DEAD (white).
  }

  setType(type);                    // Sets new type (color). setType Calls redrawCell() to recolor.
}

// Method to check cell type and return the color of that type.  
Qt::GlobalColor GridCell::getColorForCellType()
{
    switch(this->type)
    {
        default:
        case DEAD:
            return Qt::white;
        case LIVE:
            return Qt::black;
    }
}


// Helper method. Forces current cell to be redrawn on the GUI.  Called whenever the setType method is invoked.
void GridCell::redrawCell()
{
    Qt::GlobalColor gc = getColorForCellType();         //Find out what color this cell should be.
    this->button->setPalette(QPalette(gc,gc));          //Force the button in the cell to be the proper color.
    this->button->setAutoFillBackground(true);
    this->button->setFlat(true);                        //Force QT to NOT draw the borders on the button
}

void GridCell::updateCell()
{
	if (master->isHealthy(row, col))
	{
		this->type = LIVE;
	}
	else
	{
		this->type = DEAD;
	}
	
	redrawCell();
}
