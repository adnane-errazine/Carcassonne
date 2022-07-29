//includes généraux

//includes fichiers du projet
#include "Pioche.h"
#include "Tuile.h"
#include "Jeu.h"

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------    Affichage Classe Pioche      ---------------------------*/
//Définition des opérateur << pour permettre d'afficher la classe Pioche directement
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/* operator << sur une pioche */
ostream& operator<<(ostream& f, const stack <Tuile*>& pile)
{
    int j = 0;
    stack <Tuile*> pile2 = pile;
    while ( !pile2.empty() )
    {
        f << "Tuile " << j++ << " : " << endl;
        if (pile.top()) { f << *pile2.top() << endl; }
        else { f << "nullptr : " << pile2.top() << endl; }
        pile2.pop();
    }   
    return f;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*---------------------- Class Pioche, implémentation du singleton   ---------------------*/
//définition méthodes de création et destruction de Pioche (sachant que c'est un singleton)
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//initialisation de l'instance à nullptr
Pioche* Pioche::instance = nullptr;

//méthode qui retourne l'instance de pioche ou la crée si elle n'existe pas
Pioche* Pioche::setPioche(vector<Tuile*> *p, vector<Tuile*> *p1, vector<Tuile*> *p2, vector<Tuile*> *p3)
{    
    if (!instance)
        instance = new Pioche(p, p1, p2, p3);
    return instance;
}

Pioche* Pioche::getPioche()
{
    if (!instance)
        throw PiocheException("Tentative d'access a la pioche qui n'a pas ete cree!");
    return instance;
}

//méthode qui permet de détruire l'unique instance de pioche
void Pioche::liberePioche()
{
    if (instance) delete instance;
    instance = nullptr;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*---------------------- Constructeur de Pioche (privé)              ---------------------*/
//définition méthodes de création et destruction de Pioche (sachant que c'est un singleton)
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/* 
    Ce constructeur de Pioche prend en paramètre autant de vector de Tuile qu'on pourrait jouer d'extension simultanément.
    Peu importe l'ordre dans lequel sont données les paquets de tuiles des différentes extensions.
    En effet, on va toutes les mélanger de toute façon !
    Toutes les extensions sont regroupées en un seul vector de tuile : p
    De ce vector, je vais prendre au hasard une tuile et l'empiler sur ma pioche que je suis en train d'initialiser.
    Puis je raccourci mon vector de tuile p car je ne veux pas ajouter deux fois la même tuile dans ma pioche.
*/
Pioche::Pioche(vector<Tuile*> *p, vector<Tuile*> *p1, vector<Tuile*> *p2, vector<Tuile*> *p3)
{
    //si on à une liste de Tuiles initialisée
    if (p || p1 || p2 || p3)
    {
        //on met toutes les pioches passées en paramètres dans le même vector vT
        vector<Tuile*> vT;
        //ajout de p si il existe
        if (p && !p->empty())
        {
            for ( auto it: *p)
            {
                vT.push_back(it);
            }
        }
        //ajout de p si il existe
        if (p1 && !p1->empty())
        {
            for ( auto it: *p1)
            {
                vT.push_back(it);
            }
        }
        //ajout de p2 si il existe
        if (p2 && !p2->empty())
        {
            for ( auto it: *p2)
            {
                vT.push_back(it);
            }
        }
        //ajout de p3 si il existe
        if (p3 && !p3->empty())
        {
            for ( auto it: *p3)
            {
                vT.push_back(it);
            }
        }

        //variable qui stocke une tuile dans le cas où il fauille la placer à la fin (pour qu'elle soit en haut de la pioche et soit donc posée en premier)
        Tuile * lastTile = nullptr;
        //tuile a ajouter en premier dans la pile (elle sera donc tirée en dernier)
        Tuile * firstTile = nullptr;
        //on regarde si dans la pioche à créer si il y a la tuile d'origine de la rivière
        //on regarde si la tuile 72 à été crée (origine rivière)
        Tuile* tuile72 = Jeu::getJeu()->IDToTuile(72);
        if ( tuile72 )
        {
            if ( find(vT.begin(), vT.end(), tuile72) != vT.end() )
            {
                Log::flog << "ajout tuile origine rivière...";
                //on ajoute la tuile à la fin de la pioche
                lastTile = tuile72;
                //on supprime la tuile du vector
                size_t indiceDel = 0;
                for (auto it: vT) 
                {
                    if (it == tuile72) vT.erase(vT.begin() + indiceDel);
                    indiceDel++;
                }
                Log::flog << "done." << endl;

                //une fois qu'on à la premiere tuile de la pile on cherche la derniere tuile de celle-ci
                Tuile* tuile83 = Jeu::getJeu()->IDToTuile(83);
                if ( find(vT.begin(), vT.end(), tuile83) != vT.end() )
                {
                    Log::flog << "ajout tuile finale rivière...";
                    //on ajoute la tuile au début de la pioche
                    firstTile = tuile83;
                    //on supprime la tuile du vector
                    size_t indiceDel = 0;
                    for (auto it: vT) 
                    {
                        if (it == tuile83) vT.erase(vT.begin() + indiceDel);
                        indiceDel++;
                    }
                    Log::flog << "done." << endl;
                }else
                {
                    throw PiocheException("Impossible de trouver la derniere tuile de la rivière lors de la constructions de la pioche.");
                }
            }
        //dans le cas où l'extension rivière est choisie (tuile72 existe on veut commencer la partie avec la tuile riviere de base, cas ci-dessus)
        //sinon si la riviere n'a pas été choisie et donc pas crée on veut que ce soit la tuile d'origine de l'extension classique qui soit choisie (cas ci-dessous)
        }else 
        {   
            //ici on prend la tuile 7 mais ça pourrait aussi être les 8,9 ou 10 (les 4 tuiles ont les mêmes positions)
            Tuile* tuile7 = Jeu::getJeu()->IDToTuile(7);
            if ( tuile7 )
            {
                if ( find(vT.begin(), vT.end(), tuile7) != vT.end() )
                {
                    Log::flog << "ajout tuile origine classique...";
                    //on ajoute la tuile à la fin pour qu'elle soit en haut de la pioche
                    lastTile = tuile7;
                    //on supprime la tuile du vector
                    size_t indiceDel = 0;
                    for (auto it: vT)
                    {
                        if (it == tuile7) vT.erase(vT.begin() + indiceDel);
                        indiceDel++;
                    }
                    Log::flog << "done." << endl;
                }
            //ici on serait dans le cas où les extensions classique ou rivière ne serait pas sélectionnes -> pas de tuile de départ
            }else {
                throw PiocheException("Pas de tuile de départ à mettre au dessus de la pioche (il faut choisir au moins une extension parmi Classique et Riviere)");
            }
        }

        //ajout de la derniere tuile de la pile
        if (firstTile)
        {
            ajouter(firstTile);
            Log::flog << "firstTile added." << endl;
        }

        //vT contient désormais toutes les tuiles passées en paramètres
        //on insère désormais les tuiles au hasard dans le stack
        while ( !vT.empty() ) 
        {
            Log::flog << "while" << " | ";
            //je prends un indice au hasard
            size_t hasard = rand() %  (vT.size());
            Log::flog << "rand : " << hasard << " size : " << vT.size() << " | ";
            //je récupère la tuile au hasard
            Tuile* tuileHasard = vT.at(hasard);
            Log::flog << "rand tile : " << tuileHasard << " | ";
            //on ajoute l'élément dans le stack
            ajouter(tuileHasard);
            Log::flog << "added" << " | ";
            //on supprime la tuile du vector
            vT.erase(vT.begin() + hasard);
            Log::flog << "erased" << endl;
        }

        //ajout de la premiere tuile de la pile
        if (lastTile)
        {
            ajouter(lastTile);
            Log::flog << "lastTile added." << endl;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------            méthode piocher()                ---------------------*/
//renvoi la tuile en haut de la pioche
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/* 
    Cette méthode piocher prend la tuile tout en haut de la pile de tuile de la pioche
    et elle renvoie par pointeur la tuile choisie par le joueur,
    elle supprime aussi cette tuile de sa pioche puisque la tuile va être posée sur le plateau.
*/
Tuile* Pioche::piocher()
{
    if (estVide())
        throw PiocheException("La pioche est vide, impossible de piocher.");
    Tuile* tuileChoisie = pioche.top();
    //je supprime la tuile de la pioche car elle a été piochée
    pioche.pop(); 
    return tuileChoisie;  
}
