#ifndef VIEWMEEPLE_H
#define VIEWMEEPLE_H

#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "Tuile.h"

class ViewMeeple: public QGraphicsEllipseItem{
public:
    //ViewMeeple(const Meeple & t, QString color, QGraphicsItem* parent=nullptr);
    ViewMeeple(QString c, QGraphicsItem* parent=nullptr);
    ViewMeeple(meepleEnum m, CouleurEnum c, QGraphicsItem* parent=nullptr);
    QString color;

    QGraphicsTextItem *title=nullptr;
    int pos;
};

#endif // VIEWMEEPLE_H
