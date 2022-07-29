#include "ViewTile.h"
#include "Game.h"
#include "qmessagebox.h"
#include <QInputDialog>
#include <QDebug>

extern Game* game;

ViewTile::ViewTile(Tuile *t, QGraphicsItem *parent):QGraphicsPixmapItem(parent),tile(t){
    setAcceptHoverEvents(true);
    setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
    setIsPlaced(false);

    setTransformOriginPoint(50,50);

    //changes pixmap based on given tilen from constructor
    //Right now, it is a default tile.

    QString path=":/Images/VisualTiles/";
    int id=game->controller->getJeu()->getJeu()->tuileToID(tile);
    path.append(QString::number(id));
    path.append(".png");

    setPixmap(QPixmap(path).scaled(100,100));
}

ViewTile::ViewTile(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    setAcceptHoverEvents(true);
    setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
    setIsPlaced(false);

    setTransformOriginPoint(50,50);
    //changes pixmap based on given tile from constructor
    //Right now, it is a default tile.
    setPixmap(QPixmap(":/Images/VisualTiles/DEF.png").scaled(100,100));
}

bool ViewTile::displayMeeple(ViewMeeple* m, int p){
    meeple=m;
    meeple->pos=p;

    if(meeple->title->toPlainText()=="A"){
        meepleType=meepleEnum::Abbe;
    }
    if(meeple->title->toPlainText()=="G"){
        meepleType=meepleEnum::Grand;
    }
    else if(meeple->title->toPlainText()==""){
        meepleType=meepleEnum::Normal;
    }

    if(game->controller->getcurrentPlayer()->getTypeJoueur()==JoueursEnum::Humain){
        if(game->controller->poserMeeple(tile,p,game->controller->getcurrentPlayer(),meepleType)){
            //top
            if(p==0){
                meeple->setPos(10,5);
                meeple->setVisible(true);
            }
            if(p==1){
                meeple->setPos(50,5);
                meeple->setVisible(true);
            }
            if(p==2){
                meeple->setPos(80,5);
                meeple->setVisible(true);
            }

            //right
            if(p==3){
                meeple->setPos(90,10);
                meeple->setVisible(true);
            }
            if(p==4){
                meeple->setPos(90,50);
                meeple->setVisible(true);
            }
            if(p==5){
                meeple->setPos(90,80);
                meeple->setVisible(true);
            }

            //bottom
            if(p==6){
                meeple->setPos(80,90);
                meeple->setVisible(true);
            }
            if(p==7){
                meeple->setPos(50,90);
                meeple->setVisible(true);
            }
            if(p==8){
                meeple->setPos(10,90);
                meeple->setVisible(true);
            }

            //left
            if(p==9){
                meeple->setPos(10,80);
                meeple->setVisible(true);
            }
            if(p==10){
                meeple->setPos(10,50);
                meeple->setVisible(true);
            }
            if(p==11){
                meeple->setPos(10,10);
                meeple->setVisible(true);
            }

            //center
            if(p==12){
                meeple->setPos(50,50);
                meeple->setVisible(true);
            }

            return true;
        }
    }
    else if(game->controller->getcurrentPlayer()->getTypeJoueur()==JoueursEnum::IA){
        //top
        if(p==0){
            meeple->setPos(10,5);
            meeple->setVisible(true);
        }
        if(p==1){
            meeple->setPos(50,5);
            meeple->setVisible(true);
        }
        if(p==2){
            meeple->setPos(80,5);
            meeple->setVisible(true);
        }

        //right
        if(p==3){
            meeple->setPos(90,10);
            meeple->setVisible(true);
        }
        if(p==4){
            meeple->setPos(90,50);
            meeple->setVisible(true);
        }
        if(p==5){
            meeple->setPos(90,80);
            meeple->setVisible(true);
        }

        //bottom
        if(p==6){
            meeple->setPos(80,90);
            meeple->setVisible(true);
        }
        if(p==7){
            meeple->setPos(50,90);
            meeple->setVisible(true);
        }
        if(p==8){
            meeple->setPos(10,90);
            meeple->setVisible(true);
        }

        //left
        if(p==9){
            meeple->setPos(10,80);
            meeple->setVisible(true);
        }
        if(p==10){
            meeple->setPos(10,50);
            meeple->setVisible(true);
        }
        if(p==11){
            meeple->setPos(10,10);
            meeple->setVisible(true);
        }

        //center
        if(p==12){
            meeple->setPos(50,50);
            meeple->setVisible(true);
        }

        return true;
    }

    meeple->setVisible(false);
    return false;
}

void ViewTile::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(game->view->tileForMeeple!=NULL && (game->nxtPlayerBtn->isVisible() || game->finish->isVisible())) {//maybe remove meeple when place meeple is visible / rotate is invisible
        for(int i=0;i<game->view->board->boardSize;i++){
            for(int j=0;j<game->view->board->boardSize;j++){
                if(game->view->board->tiles[i][j]==this && game->controller->isMeeplerecallable(i,j)){
                    bool ok;
                    size_t score=(size_t) QInputDialog::getInt(game, "Add the score", "The Score to be added:",0,0,100,1,&ok);
                    if(ok){
                        game->controller->recallMeeple(i,j,score);

                        meeple->scene()->removeItem(meeple);
                    }
                    else{
                        return;
                    }
                }
            }
        }
       event->accept();
       return;
    }

    if(game->view->tileToPlace!=NULL){
        for(int i=0;i<game->view->board->boardSize;i++){
            for(int j=0;j<game->view->board->boardSize;j++){
                if(game->view->board->getTiles().at(i).at(j)==this){
                    if(!tilePresente() && isPlaced==false
                            && game->controller->getPlateau().tuileAdjacente(i,j) && game->controller->getPlateau().estCompatible(i,j,game->view->tileToPlace->tile)){

                        game->controller->getPlateau().ajouter(game->view->tileToPlace->tile,i,j);
                        game->view->tileToPlace->setIsPlaced(true);
                        game->view->replaceEmptyWithTile(this);
                        game->rotate->setVisible(false);
                        game->meepleLayoutContainer->setVisible(true);
                        game->drawnTileGroupBox->setTitle("Positions");
                        game->drawnTileGroupBox->setMinimumHeight(150);
                        game->drawnTile->setPixmap(QPixmap(":/Images/VisualTiles/POS.png").scaled(150,150));
                    }
                }
            }
        }
        event->accept();
        return;
    }


}
