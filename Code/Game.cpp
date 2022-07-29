#include "StartMenu.h"
#include "qmessagebox.h"
#include <Game.h>
#include <QInputDialog>
#include <ViewTile.h>

GameView::GameView(QWidget *parent){
    setParent(parent);
    // set up the screen
    setDragMode(QGraphicsView::NoDrag);
    // set up the scene
    scene = new QGraphicsScene();
    setScene(scene);
}

void GameView::wheelEvent(QWheelEvent* event){
  if(event->angleDelta().y() > 0)
    scale(1.25, 1.25);
  else
    scale(0.8, 0.8);

}

void GameView::startView(){
    scene->clear();
    board = new ViewBoard(100);     //get from Controller the number of Tiles
    board->placeTiles(0,0,board->boardSize);


    for(int i=0; i<board->getTiles().size(); i++){
        for(int j=0; j<board->getTiles()[i].size(); j++){
            scene->addItem(board->getTiles()[i].at(j));
        }
    }
}

void GameView::replaceEmptyWithTile(ViewTile *emptyTile){
    tileToPlace->setPos(emptyTile->pos());

    for(int i=0;i<board->boardSize; i++){
        for(int j=0; j<board->boardSize; j++){
            if(board->tiles[i][j]==emptyTile){
                board->tiles[i][j]=tileToPlace;
            }
        }
    }

    scene->removeItem(emptyTile);
    scene->addItem(tileToPlace);

    tileForMeeple=tileToPlace;
    tileToPlace = NULL;
}

//-------------------------------------------------------------------------

Game::Game(QWidget* parent): QFrame(parent){

};

void Game::setUp(){
    setMinimumSize(1024, 768);
    //Controller::initialise

    currentLabel=new QLabel(QString::fromStdString(controller->getcurrentPlayer()->getPseudo()),this);

    view= new GameView(this);
    draw=new QPushButton("Draw Tile",this);
    rotate=new QPushButton("Rotate",this);
    meepleBtn=new QPushButton("Meeple",this);
    nxtPlayerBtn=new QPushButton("Next Player",this);
    finish=new QPushButton("Finish the Game",this);


    meepleLayoutContainer=new QWidget(this);
    QHBoxLayout *meepleLayout=new QHBoxLayout(meepleLayoutContainer);
    meepleLayout->addWidget(meepleBtn);

    connect(draw, &QPushButton::clicked, this, &Game::drawClick);
    connect(rotate, &QPushButton::clicked, this, &Game::rotateClick);
    connect(meepleBtn, &QPushButton::clicked, this, &Game::placeMeepleClick);
    connect(nxtPlayerBtn, &QPushButton::clicked, this, &Game::nextPlayerClick);
    connect(finish, &QPushButton::clicked, this, &Game::finishGame);

    for(int i=0;i<inf->extension.size();i++){
        if(inf->extension[i]->isChecked() && QString::compare(inf->extension[i]->text(),"Auberge et Cathedrales")==0){
            //if extension is activated
            grandMeepleBtn=new QPushButton("Big Meeple",this);
            connect(grandMeepleBtn, &QPushButton::clicked, this, &Game::placeGrandMeepleClick);
            meepleLayout->addWidget(grandMeepleBtn);
            continue;
        }

        if(inf->extension[i]->isChecked() && QString::compare(inf->extension[i]->text(),"L’Abbe")==0){
            //if extension is activated
            abbayeMeepleBtn=new QPushButton("Abbot",this);
            connect(abbayeMeepleBtn, &QPushButton::clicked, this, &Game::placeAbayeMeepleClick);
            meepleLayout->addWidget(abbayeMeepleBtn);
            continue;
        }
    }

    meepleLayout->addWidget(nxtPlayerBtn);
    meepleLayout->addWidget(finish);

    finish->setVisible(false);

    drawnTileGroupBox=new QGroupBox("Drawn Tile",this);
    drawnTile=new QLabel(drawnTileGroupBox);
    QVBoxLayout *drawnTileLayout=new QVBoxLayout();
    drawnTileLayout->addWidget(drawnTile);
    drawnTileGroupBox->setLayout(drawnTileLayout);
    drawnTileGroupBox->setMinimumHeight(100);
    drawnTileGroupBox->setMinimumHeight(150);
    drawnTileGroupBox->setVisible(false);

    QVBoxLayout *currentLay=new QVBoxLayout();
    QVBoxLayout *panelLay=new QVBoxLayout();
    QHBoxLayout *mainLay=new QHBoxLayout();
    QHBoxLayout *btnLay=new QHBoxLayout();

    currentLabelGroupBox=new QGroupBox("Current Player",this);
    currentLabelGroupBox->setLayout(currentLay);
    currentLabelGroupBox->setMaximumHeight(50);
    currentLay->addWidget(currentLabel);
    panelLay->addWidget(currentLabelGroupBox);

    for(int i=0;i<4;i++){
        if(inf->playerNames[i]->text()!="\0"){
            playerPanel(inf->playerNames[i]->text(),i);
            panels[i]->setMaximumHeight(100);
            panelLay->addWidget(panels[i]);
        }
    }

    panelLay->addWidget(drawnTileGroupBox);


    btnLay->addWidget(draw);
    btnLay->addWidget(rotate);
    btnLay->addWidget(meepleLayoutContainer);
    panelLay->addLayout(btnLay);


    mainLay->addLayout(panelLay);
    mainLay->addWidget(view);

    rotate->setVisible(false);
    meepleLayoutContainer->setFixedSize(300,50);
    meepleLayoutContainer->setVisible(false);

    setLayout(mainLay);
    view->startView();

    nextPlayerClick();
};

void Game::playerPanel(QString name,int i){
    panels[i]=new QGroupBox(name);

    QVBoxLayout *VL = new QVBoxLayout;
    score[i]=new QLabel("Score: 0",this);
    meeple[i]=new QLabel("Meeples: 7",this);

    VL->addWidget(score[i]);
    VL->addWidget(meeple[i]);

    if(grandMeepleBtn!=nullptr){
        //if extension is activated
        grandMeeple[i]=new QLabel("Grand Meeples: 1",this);
        VL->addWidget(grandMeeple[i]);
    }

    if(abbayeMeepleBtn!=nullptr){
        //if extension is activated
        abbaye[i]=new QLabel("Abbaye: 1",this);
        VL->addWidget(abbaye[i]);
    }


    panels[i]->setLayout(VL);

}

void Game::drawClick(){
    //call pioche() function to tileToPlace
    view->tileForMeeple=NULL;
    if(view->tileToPlace==NULL){
        view->tileToPlace=new ViewTile(controller->piocher());
        if(Jeu::getJeu()->tuileToID(view->tileToPlace->tile)==83){
            if(!Pioche::getPioche()->estVide()){
                throw ControleurException("Pioche Rivere dans la partie graphique n'est pas vide!");
            }
            else{
                Pioche::getPioche()->liberePioche();
                controller->setPioche(Pioche::setPioche(Jeu::getJeu()->getTuilesClassique(),Jeu::getJeu()->getTuilesPaysan(), Jeu::getJeu()->getTuilesAbbe(), Jeu::getJeu()->getTuilesAuberge()));
            }
        }
        if(controller->getcurrentPlayer()->getTypeJoueur()==JoueursEnum::Humain){
            drawnTile->setPixmap(view->tileToPlace->pixmap());
            drawnTile->adjustSize();
            drawnTileGroupBox->setVisible(true);

            draw->setVisible(false);
            rotate->setVisible(true);
        }
    }
}

void Game::rotateClick()
{

    if(view->tileToPlace==NULL){
        QMessageBox msg(QMessageBox::Icon::Warning, "Vous n'avez pas piocher un tuile!", "Vous n'avez pas piocher un tuile!");
        msg.exec();
    }

    else{
//      rotates just the pixmap
        QPixmap pixmap = view->tileToPlace->pixmap();
        QTransform transform;
        QTransform trans =transform.rotate(-90);
        pixmap=pixmap.transformed(trans);
        pixmap=pixmap.scaled(100,100);

        view->tileToPlace->setPixmap(pixmap);

        if(controller->getcurrentPlayer()->getTypeJoueur()==JoueursEnum::Humain){
            view->tileToPlace->tile->rotationGauche();
            drawnTile->setPixmap(view->tileToPlace->pixmap());
            drawnTile->adjustSize();
        }
    }

}

void Game::placeMeepleClick()
{
    if(view->tileForMeeple==NULL){
        QMessageBox msg(QMessageBox::Icon::Warning, "Vous n'avez pas placer un tuile!", "Vous n'avez pas placer un tuile!");
        msg.exec();
    }

    else{
        //add control for placcement
        bool ok;
        int pos = QInputDialog::getInt(this, "Insert Position Number (0-12)", "Position (0-12):",0,0,12,1,&ok);
        if(ok){
            if(pos<0||pos>12){
                QMessageBox msg(QMessageBox::Icon::Warning, "Position n'est pas valide!", "Position n'est pas valide!");
                msg.exec();
            }

            else{
                ViewMeeple *meep=new ViewMeeple(meepleEnum::Normal,controller->getcurrentPlayer()->getCouleurJoueur(), view->tileForMeeple);
                if(view->tileForMeeple->displayMeeple(meep,pos)){
                    view->tileForMeeple=NULL;
                    nextPlayerClick();
                }
                else{
                    QMessageBox msg(QMessageBox::Icon::Warning, "ERROR!", "Vous ne peut pas placer un Meeple!");
                    msg.exec();
                }
            }
        }
    }
};

void Game::placeGrandMeepleClick()
{
    if(view->tileForMeeple==NULL){
        QMessageBox msg(QMessageBox::Icon::Warning, "Vous n'avez pas placer un tuile!", "Vous n'avez pas placer un tuile!");
        msg.exec();
    }

    else{
        bool ok;
        int pos = QInputDialog::getInt(this, "Insert Position Number (0-12)", "Position (0-12):",0,0,12,1,&ok);
        if(ok){
            if(pos<0||pos>12){
                QMessageBox msg(QMessageBox::Icon::Warning, "Position n'est pas valide!", "Position n'est pas valide!");
                msg.exec();
            }

            else{
                ViewMeeple *meep=new ViewMeeple(meepleEnum::Grand,controller->getcurrentPlayer()->getCouleurJoueur(), view->tileForMeeple);
                if(view->tileForMeeple->displayMeeple(meep,pos)){
                    view->tileForMeeple=NULL;
                    nextPlayerClick();
                }
                else{
                    QMessageBox msg(QMessageBox::Icon::Warning, "ERROR!", "Vous ne peut pas placer un Meeple!");
                    msg.exec();
                }
            }
        }
    }
};

void Game::placeAbayeMeepleClick(){
    if(view->tileForMeeple==NULL){
        QMessageBox msg(QMessageBox::Icon::Warning, "Vous n'avez pas placer un tuile!", "Vous n'avez pas placer un tuile!");
        msg.exec();
    }
    else{
        bool ok;
        int pos = QInputDialog::getInt(this, "Insert Position Number (0-12)", "Position (0-12):",0,0,12,1,&ok);
        if(ok){
            if(pos<0||pos>12){
                QMessageBox msg(QMessageBox::Icon::Warning, "Position n'est pas valide!", "Position n'est pas valide!");
                msg.exec();
            }

            else{
                ViewMeeple *meep=new ViewMeeple(meepleEnum::Abbe,controller->getcurrentPlayer()->getCouleurJoueur(), view->tileForMeeple);
                if(view->tileForMeeple->displayMeeple(meep,pos)){
                    view->tileForMeeple=NULL;
                    nextPlayerClick();
                }
                else{
                    QMessageBox msg(QMessageBox::Icon::Warning, "ERROR!", "Vous ne peut pas placer un Meeple!");
                    msg.exec();
                }
            }
        }
    }
};

void Game::nextPlayerClick(){
    //update scores
    int i=0;
    for(auto it: controller->getJoueurs()){
        QString tmp="Score: ";
        tmp.append(QString::number(it->getScore()));
        score[i]->setText(tmp);

        tmp="Meeples: ";
        tmp.append(QString::number(it->nombreMeepleNormalDisponible()));
        meeple[i]->setText(tmp);

        if(grandMeepleBtn!=nullptr){
            //if extension is activated
            tmp="Grand Meeples: ";
            tmp.append(QString::number(it->nombreMeepleGrandDisponible()));
            grandMeeple[i]->setText(tmp);
        }

        if(abbayeMeepleBtn!=nullptr){
            //if extension is activated
            tmp="Abbaye: ";
            tmp.append(QString::number(it->nombreMeepleAbbeDisponible()));
            abbaye[i]->setText(tmp);
        }

        i++;
    }

    if(Pioche::getPioche()->estVide()){
        finish->setVisible(true);
        meepleBtn->setVisible(false);
        nxtPlayerBtn->setVisible(false);

        if(grandMeepleBtn!=nullptr){
            //if extension is activated
            grandMeepleBtn->setVisible(false);
        }

        if(abbayeMeepleBtn!=nullptr){
            //if extension is activated
            abbayeMeepleBtn->setVisible(false);
        }
    }

    else{
        //iterate to the other player
        controller->nextPlayer();
        //update Current Player Label
        currentLabel->setText(QString::fromStdString(controller->getcurrentPlayer()->getPseudo()));
        //hide (and / or) show the necessary buttons
        meepleLayoutContainer->setVisible(false);
        meepleBtn->setVisible(true);
        if(grandMeepleBtn!=nullptr){
            //if extension is activated
            grandMeepleBtn->setVisible(true);
        }

        if(abbayeMeepleBtn!=nullptr){
            //if extension is activated
            abbayeMeepleBtn->setVisible(true);
        }
        drawnTileGroupBox->setVisible(false);
        draw->setVisible(true);

        //check if player is IA
        if(controller->getcurrentPlayer()->getTypeJoueur()==JoueursEnum::IA){
            draw->setVisible(false);
            drawClick();

            //Getting positions for matrixes
            int x=0;
            int y=0;
            int r=0;

            //finding everything and adding the tile in controller!
            //controller->bruteForcePoseSNAIL(x,y,r,view->tileToPlace->tile);

            while(!controller->bruteForcePoseSNAIL(x,y,r,view->tileToPlace->tile))
            {
                view->tileToPlace=new ViewTile(controller->piocher());
                cout << "erreur : 123456789" << endl;
            }

            //rotating ViewTile
            for(int i=0;i<r;i++){
                rotateClick();
            }

            //adding ViewTile to scene
            view->tileToPlace->setPos(view->board->tiles[x][y]->pos());
            view->scene->removeItem(view->board->tiles[x][y]);
            view->board->tiles[x][y]=view->tileToPlace;
            view->scene->addItem(view->tileToPlace);

            view->tileForMeeple=view->tileToPlace;
            view->tileToPlace = NULL;

            int pos=0;
            meepleEnum type=meepleEnum::Normal;
            
            if(controller->bruteForcePoseMeepleG(view->tileForMeeple->tile,controller->getcurrentPlayer(),pos,type)){
                ViewMeeple *m =new ViewMeeple(type,controller->getcurrentPlayer()->getCouleurJoueur(), view->tileForMeeple);
                view->tileForMeeple->displayMeeple(m,pos);
            }

            meepleLayoutContainer->setVisible(true);
            meepleBtn->setVisible(false);
            if(grandMeepleBtn!=nullptr){
                //if extension is activated
                grandMeepleBtn->setVisible(false);
            }

            if(abbayeMeepleBtn!=nullptr){
                //if extension is activated
                abbayeMeepleBtn->setVisible(false);
            }
            nxtPlayerBtn->setVisible(true);
        }

    }
};

void Game::finishGame(){
    //CONDTION PROBLEM! When we call the size of getMeeplesPose(), we just get back the number of players(entries of the map).
    //We have to check if the list in each entry is empty.
    for(auto it: controller->getJoueurs()){
        if(controller->getPlateau().getMeeplesPose().at(it->getCouleurJoueur()).size() > 0){
            QMessageBox msg(QMessageBox::Icon::Warning, "ERREUR", "Vous n'avez pas retirer tous les Meeples!");
            msg.exec();
            return;
        }
    }

    Joueur *winner=*controller->getJoueurs().begin();
    int max=0;
    for(auto it: controller->getJoueurs()){
        if(it->getScore()>max){
            max=it->getScore();
            winner=it;
        }
    }
    QString tmp="Le gagnant de ce jeu est ";
    tmp.append(QString::fromStdString(winner->getPseudo()));
    tmp.append(" avec un score de ");
    tmp.append(QString::number(winner->getScore()));

    QMessageBox msg(QMessageBox::Icon::NoIcon, "Partie Termine", tmp);
    msg.exec();
    this->close();
};




