#include "ViewMeeple.h"


ViewMeeple::ViewMeeple(meepleEnum m, CouleurEnum c, QGraphicsItem *parent):QGraphicsEllipseItem(parent){
    setRect(0,0,10,10);
    setAcceptHoverEvents(true);
    setTransformOriginPoint(0,0);
    setBrush(Qt::white);

    if(m==meepleEnum::Normal){
        title=new QGraphicsTextItem("",this);
    }

    if(m==meepleEnum::Grand){
        title=new QGraphicsTextItem("G",this);
        title->setDefaultTextColor(Qt::white);
        title->setScale(0.5);
        title->setPos(0.5,-1.5);
    }

    if(m==meepleEnum::Abbe){
        title=new QGraphicsTextItem("A",this);
        title->setDefaultTextColor(Qt::white);
        title->setScale(0.5);
        title->setPos(0.5,-1.5);
    }

    if(c==CouleurEnum::rouge){
        setBrush(Qt::red);
    }
    if(c==CouleurEnum::bleu){
        setBrush(QColor(0,191,255));
    }
    if(c==CouleurEnum::vert){
        setBrush(QColor(50,205,50));
    }
    if(c==CouleurEnum::mauve){
        setBrush(QColor(238, 0, 238));
    } 

}
