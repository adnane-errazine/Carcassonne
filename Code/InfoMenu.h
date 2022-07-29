#ifndef INFOMENU_H
#define INFOMENU_H

#include <QWidget>
#include <qcombobox.h>
#include <QCheckBox>
#include <QLayout>
#include <QDialog>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QObject>
#include <QLabel>
#include <QGroupBox>
#include <QLineEdit>
#include <QFormLayout>

class InfoMenu: public QFrame{
public:
    InfoMenu(QWidget *parent = nullptr);

    int numPlayers=0;
    QLineEdit* playerNames[4];
    QVector <QCheckBox*> extension;

private:
    QCheckBox* AI[4];
    QPushButton* okBtn;
    QGroupBox* extensionCheckGroupBox;
    QGroupBox* formGroupBox;
    QDialogButtonBox* buttonBox;
    QVector <QComboBox*> comboV;


private:
    void createPlayerInfo();
    void createExtensionInfo();
    void okClick();
};
#endif // INFOMENU_H
