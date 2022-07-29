#include "Game.h"
#include "InfoMenu.h"
#include "StartMenu.h"

extern Game *game;

StartMenu::StartMenu(QWidget *parent){
    setParent(parent);
    QVBoxLayout *VBL=new QVBoxLayout;
    QHBoxLayout *HBL=new QHBoxLayout;
    QLabel *titleimg=new QLabel();
    QPixmap bckgrnd(":/Images/back.jpg");
    QPalette palette;
    QPushButton *playBtn=new QPushButton("Play!");
    QPushButton *quitBtn=new QPushButton("Quit");

    playBtn->setMaximumSize(110,30);
    quitBtn->setMaximumSize(110,30);
    connect(playBtn, &QPushButton::clicked, this, &StartMenu::playClick);
    connect(quitBtn, &QPushButton::clicked, this, &StartMenu::quitClick);
    HBL->addWidget(playBtn);
    HBL->addWidget(quitBtn);

    bckgrnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Window, bckgrnd);
    this->setPalette(palette);

    titleimg->setPixmap(QPixmap(":/Images/Title.png"));
    titleimg->setScaledContents(true);
    titleimg->adjustSize();


    VBL->addWidget(titleimg);
    titleimg->setBackgroundRole(QPalette::Window);
    VBL->addLayout(HBL);
    VBL->setAlignment(Qt::AlignCenter);


    this->setLayout(VBL);
    this->setMinimumSize(960,540);
    this->setWindowTitle("Carcasonne");
}
void StartMenu::quitClick(){
    this->close();
}

void StartMenu::playClick(){
    game->inf=new InfoMenu();
    game->inf->show();
    this->close();
}
