//includes généraux
#include <iostream>
#include <stack>
#include <QApplication>
#include <StartMenu.h>

//includes fichiers du projet
#include "Tuile.h"
#include "Jeu.h"
#include "Pioche.h"
#include "Plateau.h"
#include "Joueur.h"
#include "Controleur.h"
#include "Game.h"
#include "InfoMenu.h"

using namespace std;

Game* game;


int main(int argc, char* argv[])
{
    //création du fichier log au début de l'exécution du programme
    Log::log();
    //initialisation nombre aléa
    srand(time(NULL));
    try
    {
////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*----------------------------     Tests de la classe Log      ---------------------------*/
    ////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////
/*
    Log::log("1");
    Log::log("2");
    Log::log("3");
    Log::log("4");
    Log::log("5");
*/  
    ////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*----------------------------     Tests de la classe Tuile    ---------------------------*/
    ////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////
/*
    vector<Terrain> V;
    V.push_back(Terrain::Prairie);
    V.push_back(Terrain::Route);
    V.push_back(Terrain::Prairie);

    V.push_back(Terrain::Prairie);
    V.push_back(Terrain::Prairie);
    V.push_back(Terrain::Prairie);

    V.push_back(Terrain::Prairie);
    V.push_back(Terrain::Route);
    V.push_back(Terrain::Prairie);

    V.push_back(Terrain::Ville);
    V.push_back(Terrain::Ville);
    V.push_back(Terrain::Ville);

    V.push_back(Terrain::Route);

    Tuile D = Tuile(V);
    Tuile DD = Tuile(V);
    Tuile DDD = Tuile(V);
    Tuile DDDD = Tuile(V);
    //cout << &D << endl;
    //cout << D << endl;
*/
/*
    D.rotationGauche();
    D.rotationGauche();
    D.rotationGauche();
    D.rotationGauche();
    cout << D << endl;
    cout << D.testTuile() << endl;
*/
    ////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*----------------------------     Tests de la classe Jeu      ---------------------------*/
    ////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////
/* 
    list<Extension::Extensions> extensions;
    //extensions.push_back(Extension::Extensions::Classique);
    //extensions.push_back(Extension::Extensions::Riviere);
    extensions.push_back(Extension::Extensions::Auberges_cathedrales);
    //extensions.push_back(Extension::Extensions::Paysans);
    //extensions.push_back(Extension::Extensions::Abbe);
    Jeu* j = Jeu::getJeu(extensions);
    Log::flog << "Dictionnaire : " << endl;
    Log::flog << j->getDictionnaire() << endl;

    //Log::flog << "Dictionnaire : " << endl;
    //Log::flog << j->getDictionnaire() << endl;

    //cout << "jeu" << endl;
    //vector<Tuile*>* mesTuiles = j->getTuilesClassique();
 
    //array<Tuile*, Jeu::T_DICO> dico = j->getDictionnaire();
    //cout << "Classique : " << mesTuiles << endl;
    //cout << *mesTuiles << endl;
    //cout << mesTuiles->size() << endl;
    //cout << dico << endl;
    //Jeu::libereJeu();
*/
    ////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*----------------------------     Tests de la classe Pioche   ---------------------------*/
    ////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////
 /*
    vector<Tuile*> *pileTuiles = new vector<Tuile*>;
    pileTuiles->push_back(&D);
    pileTuiles->push_back(&DD);
    pileTuiles->push_back(&DDD);
    pileTuiles->push_back(&DDDD);
*/
 
    //Pioche* p = Pioche::getPioche(pileTuiles);
    //Pioche* p = Pioche::getPioche(j->getTuilesClassique());
    //cout << "pioche" << endl;
    //cout << p->getStack() << endl;
/*
    cout << "Taille de la pioche = " << p->Pioche::taillePioche() << endl;
    cout << "Est vide ? " << p->Pioche::estVide() << endl;
    
    cout << *p->Pioche::piocher() << endl;
    cout << "Taille de la pioche = " << p->Pioche::taillePioche() << endl;
    cout << "Est vide ? " << p->Pioche::estVide() << endl;
    
    cout << *p->Pioche::piocher() << endl;
    cout << "Taille de la pioche = " << p->Pioche::taillePioche() << endl;
    cout << "Est vide ? " << p->Pioche::estVide() << endl;
    
    cout << *p->Pioche::piocher() << endl;
    cout << "Taille de la pioche = " << p->Pioche::taillePioche() << endl;
    cout << "Est vide ? " << p->Pioche::estVide() << endl;
    
    cout << *p->Pioche::piocher() << endl;
    cout << "Taille de la pioche = " << p->Pioche::taillePioche() << endl;
    cout << "Est vide ? " << p->Pioche::estVide() << endl;
 */ 

    ////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*----------------------------     Tests de la classe Plateau  ---------------------------*/
    ////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////
/*
    Plateau plateau = Plateau();
    //cout << plateau.getSizeX() << endl;
    //cout << plateau.getSizeY() << endl;
    //Tuile * tuile = p->piocher();

    //cout << tuile << " : " << j->tuileToID(tuile) << endl;
    p->piocher();
    plateau.ajouter(p->piocher(), 50, 50);
    plateau.ajouter(p->piocher(), 49, 50);
    p->piocher();
    plateau.ajouter(p->piocher(), 51, 50);
    p->piocher();
    plateau.ajouter(p->piocher(), 50, 49);
    cout << j->tuileToID(p->piocher()) << endl;
    p->piocher();
    p->piocher();
    p->piocher();

    plateau.ajouter(j->IDToTuile(11), 50, 51);
    //cout << plateau.getTuileXY(50,49) << " : " << j->tuileToID(plateau.getTuileXY(50,50)) << endl;
    Log::flog << "affichage plateau..." << endl;
    cout << plateau;
    Log::flog << "Plateau affiché." << endl;

    //Tuile * tile = plateau.getTuileXY(50,50);
    //cout << tuile << endl;
    //cout << tile << endl;

    //cout << "taille jeu : " << j->getTuilesClassique()->size() << endl;
    //cout << "Taille de la pioche = " << p->Pioche::taillePioche() << endl;
    //while (!p->estVide())
    //{
    //    cout << j->tuileToID(p->piocher()) << endl;
    //}
*/

    ////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*----------------------------  Tests de la classe Controleur  ---------------------------*/
    ////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////
/*
    list<Extension::Extensions> extensions;
    extensions.push_back(Extension::Extensions::Classique);
    extensions.push_back(Extension::Extensions::Riviere);
    extensions.push_back(Extension::Extensions::Auberges_cathedrales);
    extensions.push_back(Extension::Extensions::Paysans);
    extensions.push_back(Extension::Extensions::Abbe);
    Controleur controller(extensions);
    controller.partieCmdLine();
*/
    ////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////
    /*----------------------------  Tests de la classe Controleur  ---------------------------*/
    ////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////   
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/Images/CarLogo.ico"));

    game=new Game();
    game->st=new StartMenu();
    game->st->show();

    app.exec();

////////////////////////////////////////////////////////////////////////////////////////////////
    }
    catch(TuileException i)
    {
        cout << endl << "throw TuileException() : " << i.getInfo() << endl;
        Log::flog << endl << "throw TuileException() : " << i.getInfo() << endl;
    }
    catch(JeuException i)
    {
        cout << endl << "throw JeuException() : " << i.getInfo() << endl;
        Log::flog << endl << "throw JeuException() : " << i.getInfo() << endl;
    }
    catch(PiocheException i)
    {
        cout << endl << "throw PiocheException() : " << i.getInfo() << endl;
        Log::flog << endl << "throw PiocheException() : " << i.getInfo() << endl;
    }
    catch(PlateauException i)
    {
        cout << endl << "throw PlateauException() : " << i.getInfo() << endl;
        Log::flog << endl << "throw PlateauException() : " << i.getInfo() << endl;
    }
    catch(JoueurException i)
    {
        cout << endl << "throw JoueurException() : " << i.getInfo() << endl;
        Log::flog << endl << "throw JoueurException() : " << i.getInfo() << endl;
    }
    catch(ControleurException i)
    {
        cout << endl << "throw ControleurException() : " << i.getInfo() << endl;
        Log::flog << endl << "throw ControleurException() : " << i.getInfo() << endl;
    }

    //fermeture du fichier log et destruction de l'objet associé
    Log::fermerLog();
    return 0;
}

