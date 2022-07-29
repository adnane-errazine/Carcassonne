//includes généraux

//includes fichiers du projet
#include "Jeu.h"
#include "Tuile.h"

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------    Affichage Classe Jeu       ---------------------------*/
//Définition des opérateur << pour permettre d'afficher la classe Jeu directement
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/* operator << sur un groupe de Tuiles */
ostream& operator<<(ostream& f, const vector<Tuile*> tuiles)
{
    int j = 0;
    for(auto it : tuiles)
    {
    f << "Tuile " << j++ << " : " << endl;
    if (it) { f << *it << endl; }
    else { f << "nullptr : " << it << endl; }
    }   
    return f;
}

//operator << pour le dictionnaire
ostream& operator<<(ostream& f, const array<Tuile*, Jeu::T_DICO> dico)
{
    int j = 0;

    //(positions)
    for(auto it : dico)
    {
      f << "ID : " << j++ << endl;
      if (it) { f << *it << endl; }
      else { f << "nullptr : " << it << endl; }
    }

    //(pas positions)
    // for(auto it : dico)
    // {
    //   f << "ID : " << j++ << endl;
    //   if (it) 
    //   { 
    //     f << "basons : " << endl;
    //     f << it->getBlasons() << endl;
    //     f << "jardin : " << endl;
    //     f << it->getJardin() << endl;
    //     f << "auberge : " << endl;
    //     f << it->getAuberge() << endl;
    //     f << "cathedrale : " << endl;
    //     f << it->getCathedrale() << endl;
    //     f << "prairies : " << endl;
    //     f << it->getnPrairies() << endl;    
    //     f << "routes : " << endl;
    //     f << it->getnRoutes() << endl;
    //     f << "rivières : " << endl;
    //     f << it->getnRivieres() << endl;
    //     f << "villes : " << endl;
    //     f << it->getnVilles() << endl;
    //   }
    //   else { f << "nullptr : " << it << endl; }
    // }
    
    return f;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------    Class Jeu, implémentation du singleton   ---------------------*/
//définition méthodes de création et destruction de Jeu (sachant que c'est un singleton)
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//initialisation de l'instance à nullptr
Jeu* Jeu::instance = nullptr;

//méthode qui permet de créer une l'instance de Jeu (se contente de la renvoyer si elle existe déjà)
Jeu* Jeu::getJeu(list<Extension::Extensions> extensions)
{
    if (!instance) instance = new Jeu(extensions);
    return instance;
}

//méthode qui permet de récupérer l'instance de jeu
Jeu* Jeu::getJeu()
{
    if (!instance) throw JeuException("Tentative d'accès à l'instance mais le jeu n'est pas encore crée");
    return instance;
}

//méthode qui permet la destruction de l'objet
void Jeu::libereJeu()
{
    if (instance) delete instance;
    instance = nullptr;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------                Constructeur de Jeu          ---------------------*/
//Définition du constructeur de Jeu
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//méthode privée (singleton)
Jeu::Jeu(list<Extension::Extensions> extensions)
{
    //test de l'argument
    if (extensions.empty())
        throw JeuException("Aucune extension donnée au constructeur de Jeu");
    
    //initialisation du dictionnaire à nullptr
    for(size_t i = 0; i < dictionnaire.size(); i++) dictionnaire[i] = nullptr;

    //initialisation des attributs contenant les tuiles (selon les extensions choisies)
    for(Extension::Extensions it : extensions) 
    {
        if(it == Extension::Extensions::Classique) tuilesClassique();
        if(it == Extension::Extensions::Riviere) tuilesRiviere();
        if(it == Extension::Extensions::Auberges_cathedrales) tuilesAuberge();
        if(it == Extension::Extensions::Paysans) tuilesPaysan();
        if(it == Extension::Extensions::Abbe) tuilesAbbe();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------                Destructeur de Jeu           ---------------------*/
//Définition du destructeur de Jeu
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//méthode privée (singleton)
Jeu::~Jeu()
{
    //on doit détruire  chacune des Tuiles (Tuile compose Jeu)
    for (size_t i = 0; i < classique.size(); i++) delete classique.at(i);
    for (size_t i = 0; i < riviere.size(); i++) delete riviere.at(i);
    for (size_t i = 0; i < auberge.size(); i++) delete auberge.at(i);
    for (size_t i = 0; i < paysan.size(); i++) delete paysan.at(i);
    for (size_t i = 0; i < abbe.size(); i++) delete abbe.at(i);
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*--------------------------           Getters de Jeu           --------------------------*/
//Définition des getters de Jeu
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//ces méthodes renvoient un pointeur vers les vecteurs de Tuiles
vector<Tuile*>* Jeu::getTuilesClassique() {return &classique;}
vector<Tuile*>* Jeu::getTuilesRiviere() {return &riviere;}
vector<Tuile*>* Jeu::getTuilesAuberge() {return &auberge;}
vector<Tuile*>* Jeu::getTuilesPaysan() {return &paysan;}
vector<Tuile*>* Jeu::getTuilesAbbe() {return &abbe;}

//getter du dictionnaire
array<Tuile*, Jeu::T_DICO> Jeu::getDictionnaire() {return dictionnaire;}