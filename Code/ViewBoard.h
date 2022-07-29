#ifndef VIEWBOARD_H
#define VIEWBOARD_H

#include "ViewTile.h"

class ViewBoard{
public:
    // constructors
    ViewBoard(int size):boardSize(size){};
    QVector<QVector<ViewTile *>> tiles;

    // public methods
    void placeTiles(int x, int y, int size);
    QVector<QVector<ViewTile *>> getTiles(){return tiles;}

    int boardSize;
};

#endif // VIEWBOARD_H
