#ifndef STARTMENU_H
#define STARTMENU_H
#include "InfoMenu.h"
#include <QPushButton>
#include <QGraphicsScene>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QPalette>

class StartMenu: public QWidget{
    Q_OBJECT
    public:
    StartMenu(QWidget *parent = nullptr);

    private:
    QLabel *titleimg;
    QPixmap bckgrnd;
    QPushButton *playBtn;
    QPushButton *quitBtn;

    void playClick();
    void quitClick();
};
#endif // STARTMENU_H
