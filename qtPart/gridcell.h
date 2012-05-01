// A header file for a class representing a single cell in a grid of cells.
#ifndef GRIDCELL_H_
#define GRIDCELL_H_

#include <QPalette>
#include <QColor>
#include <QPushButton>
#include <Qt>
#include <QWidget>
#include <QFrame>
#include <QHBoxLayout>
#include <iostream>

// An enum representing the two different states a cell can have. 
enum CellType
{
    DEAD,                   // DEAD = Dead Cell. --> Color = White.
    LIVE                    // LIVE = Living Cell. ---> Color = White.
};

/*
Class: GridCell.
    A class representing a single cell in a grid.  Each cell is implemented
    as a QT QFrame that contains a single QPushButton.  The button is sized
    so that it takes up the entire frame.  Each cell also keeps track of what
    type of cell it is based on the CellType enum.
*/
class GridCell : public QFrame
{
    Q_OBJECT                            // Macro allowing us to have signals & slots on this object.

    private:    
        QPushButton* button;            // The button inside the cell that gives its clickability.
        CellType type;                  // The type of cell (DEAD or LIVE.)

    public slots:
        void handleClick();             // Callback for handling a click on the current cell.
        void setType(CellType type);    // Cell type mutator. Calls the "redrawCell" function.

    signals:
        void typeChanged(CellType type);        // Signal to notify listeners when the cell type has changed.

    public:
        GridCell(QWidget *parent = NULL);       // Constructor for creating a cell. Takes parent widget or default parent to NULL.
        virtual ~GridCell();                    // Destructor.
        void redrawCell();                      // Redraws cell: Sets new type/color.
        CellType getType() const;               //Simple getter for the cell type.

    private:
        Qt::GlobalColor getColorForCellType();  // Helper method. Returns color that cell should be based from its value.       
};

#endif
