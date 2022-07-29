#include "Game.h"
#include "InfoMenu.h"
#include <QMessageBox>

extern Game* game;

InfoMenu::InfoMenu(QWidget *parent): QFrame(parent){
    createPlayerInfo();
    createExtensionInfo();

    QVBoxLayout *mai = new QVBoxLayout;
    okBtn=new QPushButton("OK");

    connect(okBtn, &QPushButton::clicked, this, &InfoMenu::okClick);

    mai->addWidget(extensionCheckGroupBox);
    mai->addWidget(formGroupBox);
    mai->addWidget(okBtn);

    setLayout(mai);
    setFixedSize(250,500);
    setWindowTitle("Settings");
}

void InfoMenu::createPlayerInfo(){
    formGroupBox = new QGroupBox("Player Information");
    QFormLayout *layout = new QFormLayout;

    for(int i = 0; i < 4; i++) {
        QComboBox * color = new QComboBox();
        color->addItem("Rouge");
        color->addItem("Mauve");
        color->addItem("Vert");
        color->addItem("Bleu");
        comboV.push_back(color);
        color->setCurrentIndex(i);
    }

    for(int i=0;i<4;i++){
        playerNames[i]=new QLineEdit;
        AI[i] = new QCheckBox("IA");
        layout->addRow(new QLabel("Name: "), playerNames[i]);
        layout->addRow(new QLabel("Color: "), comboV.at(i));
        layout->addRow(AI[i]);
    }

    comboV.at(1)->currentText().compare(comboV.at(0)->currentText());
    formGroupBox->setLayout(layout);

}

void InfoMenu::createExtensionInfo(){
    extensionCheckGroupBox = new QGroupBox("Extensions");
    QGridLayout *layout = new QGridLayout;

    QCheckBox* ex = new QCheckBox("Riviere");;
    extension.append(ex);

    ex = new QCheckBox("Auberge et Cathedrales");
    extension.append(ex);

    ex = new QCheckBox("Paysans");
    extension.append(ex);

    ex = new QCheckBox("L’Abbe");
    extension.append(ex);

    layout->addWidget(extension[0], 1, 0);
    layout->addWidget(extension[1], 1, 1);
    layout->addWidget(extension[2], 2, 0);
    layout->addWidget(extension[3], 2, 1);


    extensionCheckGroupBox->setLayout(layout);
}

void InfoMenu::okClick(){
    //Check if the same colors are picked


    for(int i=0; i<comboV.size(); i++){
       for(int j=i+1; j<comboV.size();j++){
          if(comboV.at(i)->currentText().compare(comboV.at(j)->currentText()) == 0){
                 QMessageBox msg(QMessageBox::Icon::Warning, "Attention...", "C'est le meme couleur!");
                 msg.exec();
                 return;
            }
        }
    }

    for(int i=0; i<4; i++){
        if(playerNames[i]->text()!="\0"){
            numPlayers++;
        }
    }

    if(numPlayers<2){
        QMessageBox msg(QMessageBox::Icon::Warning, "Pas assez joueurs!", "MINIMUM: 2 joueurs ou plus!");
        msg.exec();
        return;
    }

    std::list<Extension::Extensions> ex;
    for(int i=0;i<extension.size();i++){
        if(extension[i]->isChecked() && QString::compare(extension[i]->text(),"Riviere")==0){
            ex.push_back(Extension::Extensions::Riviere);
        }
        if(extension[i]->isChecked() && QString::compare(extension[i]->text(),"Auberge et Cathedrales")==0){
            ex.push_back(Extension::Extensions::Auberges_cathedrales);
        }
        if(extension[i]->isChecked() && QString::compare(extension[i]->text(),"Paysans")==0){
            ex.push_back(Extension::Extensions::Paysans);
        }
        if(extension[i]->isChecked() && QString::compare(extension[i]->text(),"L’Abbe")==0){
            ex.push_back(Extension::Extensions::Abbe);
        }
    }
    ex.push_back(Extension::Extensions::Classique);

    game->controller = new Controleur(ex);
    for(int i=0;i<numPlayers;i++){
        game->controller->getWindowDialogueInfo(playerNames[i]->text().toStdString(), comboV.at(i)->currentText().toStdString(), AI[i]->isChecked());
    }

    game->setUp();
    game->show();
    close();
};
