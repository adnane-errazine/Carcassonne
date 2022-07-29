#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWheelEvent>
#include <QWidget>
#include "qboxlayout.h"
#include "qgraphicsitem.h"
#include "qgraphicssceneevent.h"
#include "qgroupbox.h"
#include "qlabel.h"
#include "qpushbutton.h"


#include "Controleur.h"
#include "StartMenu.h"
#include "ViewBoard.h"
#include "InfoMenu.h"
#include "Pioche.h"




class GameView: public QGraphicsView{
public:

    GameView(QWidget* parent=nullptr);

    void replaceEmptyWithTile(ViewTile* emptyTile);
    void startView();

    ViewBoard* board;
    QGraphicsScene* scene;
    ViewTile* tileToPlace=NULL;
    ViewTile* tileForMeeple=NULL;

protected Q_SLOTS:
    void wheelEvent(QWheelEvent *event);
};


class Game: public QFrame{
public:
    // constructors
    Game(QWidget* parent=nullptr);

    // public attributes
    GameView *view;
    QGroupBox *currentLabelGroupBox;
    QGroupBox *drawnTileGroupBox;
    QGroupBox *panels[4];

    QLabel *currentLabel;
    QLabel *score[4];
    QLabel *meeple[4];
    QLabel *grandMeeple[4];
    QLabel *abbaye[4];

    QLabel *drawnTile;

    QPushButton *draw;
    QPushButton *rotate;
    QWidget *meepleLayoutContainer;
    QPushButton *meepleBtn;
    QPushButton *grandMeepleBtn=nullptr;
    QPushButton *abbayeMeepleBtn=nullptr;
    QPushButton *nxtPlayerBtn;
    QPushButton *finish;

    StartMenu *st;
    InfoMenu *inf;
    Controleur *controller;

    //public methods
    void setUp();
    void nextPlayerClick();

private:
    void playerPanel(QString name, int i);
    void drawClick();
    void rotateClick();
    void placeMeepleClick();
    void placeGrandMeepleClick();
    void placeAbayeMeepleClick();
    void finishGame();
};
#endif // GAME_H
