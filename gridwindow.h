// A header file for a QT window that holds a grid of cells.
#ifndef GRIDWINDOW_H_
#define GRIDWINDOW_H_

#include <vector>
#include <QWidget>
#include <QTimer>
#include <QGridLayout>
#include <QLabel>
#include <QApplication>
#include "gridcell.h"
#include "world.h"

/*
class GridWindow:
    This is the class representing the whole window that comes up when this program runs.  
    It contains a header section with a title, a middle section of MxN cells and a bottom section with buttons.
*/
class GridWindow : public QWidget
{
    Q_OBJECT                            // Macro to allow this object to have signals & slots.

    private:
        std::vector<std::vector<GridCell*> > cells;     // A 2D vector containing pointers to all the cells in the grid.
        QLabel *title;                                  // A pointer to the Title text on the window.
        QTimer *timer;                                  // Creates timer object.
        int rows;
        int cols;
        World *master;

    public slots:
        void handleClear();             // Handler function for clicking the Clear button.
        void handleStart();             // Handler function for clicking the Start button.
        void handlePause();             // Handler function for clicking the Pause button.
        void timerFired();              // Method called whenever timer fires.

    public:
        GridWindow(QWidget *parent = NULL,int rows=3,int cols=3, World *A = NULL);       // Constructor.
        virtual ~GridWindow();                                          // Destructor.
        std::vector<std::vector<GridCell*> >& getCells();               // Accessor for the array of grid cells.

    private:
        QHBoxLayout* setupHeader();                     // Helper function to construct the GUI header.
        QGridLayout* setupGrid();      // Helper function to constructor the GUI's grid.
        QHBoxLayout* setupButtonRow();     // Helper function to setup the row of buttons at the bottom.
};

#endif
