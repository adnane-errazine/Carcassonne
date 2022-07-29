#ifndef VIEWTILE_H
#define VIEWTILE_H

#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Tuile.h"
#include "Plateau.h"
#include "ViewMeeple.h"
#include "Jeu.h"

class ViewTile : public QGraphicsPixmapItem{
public:
    //constructors
    ViewTile(Tuile* t, QGraphicsItem* parent=nullptr);
    explicit ViewTile(QGraphicsItem* parent=nullptr);

    bool getIsPlaced();
    void setIsPlaced(bool b){isPlaced=b;};
    bool tilePresente() const { return tile!=nullptr; }
    bool displayMeeple(ViewMeeple* m, int p);

    void mousePressEvent(QGraphicsSceneMouseEvent* event);

    ViewMeeple* meeple;
    meepleEnum meepleType;
    bool isPlaced=false;
    int rotation=0;
    Tuile* tile=nullptr;
};

#endif // VIEWTILE_H
