//includes généraux
#include <cstddef>
#include <string>
#include <utility>

//includes fichiers du projet
#include "Tuile.h"
#include "Controleur.h"


////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------    Affichage Classe Controleur  ---------------------------*/
//Définition des opérateur << pour permettre d'afficher la classe Controleur directement
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
ostream& operator<<(ostream& f, const list<Joueur*>& joueurs)
{
    for (auto j : joueurs)
    {
        f << *j << endl;
    }
    return f;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------          getters                      ---------------------*/
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
Joueur* Controleur::getJoueurs(const CouleurEnum& C)
{
    for (auto it : joueurs)
    {
        if(it->getCouleurJoueur()==C)
            return it;
    }
    throw ControleurException("Joueur de la couleur demandée non trouvé");
    return nullptr;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------    Méthodes partie graphique          ---------------------*/
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//méthode qui permet de récupérer les données des joueurs et de les initialiser
void Controleur::getWindowDialogueInfo(const string& J1,const string& C1,const bool T1)
{
    CouleurEnum color;
    JoueursEnum type;
    if(C1=="Rouge"){
        color=CouleurEnum::rouge;
    }
    if(C1=="Bleu"){
        color=CouleurEnum::bleu;
    }
    if(C1=="Vert"){
        color=CouleurEnum::vert;
    }
    if(C1=="Mauve"){
        color=CouleurEnum::mauve;
    }

    if(T1==true)
       type = JoueursEnum::IA;
    else
       type = JoueursEnum::Humain;

    joueurs.push_back(new Joueur(J1,color,type,extensions));
    currentPlayer=joueurs.end();
    --currentPlayer;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------    Méthode initJoueurs                      ---------------------*/
//méthode qui permet d'initialiser les joueurs au début d'une partie
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void Controleur::initJoueurs()
{
//    getWindowDialogueInfo();
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------    Méthode de gestion des Meeples           ---------------------*/
//méthodes qui permettent d'ajouter/retirer des meeples
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//ajouter un meeples
bool Controleur::poserMeeple(Tuile* T,int pos,Joueur* j,meepleEnum MT)
{  
    //mauvais appel de la fonction
    if (!T || !j || pos < 0 || pos > 12 ) { throw ControleurException("Mauvais appel de Controleur::poserMeeple"); }

    //boolean permettant de savoir si le meeple à été posé
    bool placed = false;
    if(MT==meepleEnum::Grand)
    { 
        placed = true;
        //vérification qu'un meeple est dispo
        if (!j->meepleGrand_est_Disponible())
        {
            cout << "Vous n'avez aucun Grand meeple disponible." << endl;
            placed = false;
        }

        //vérification que le terrais n'est pas de mauvais type
        if ( T->getPositionX(pos) == Terrain::CroisementFerme || T->getPositionX(pos) == Terrain::Riviere)
        {
            cout << "Vous ne pouvez pas placer un meeple Géant sur ce type de terrain." << endl;
            placed = false;
        }

        //on place le meeple si son emplacement est valide
        if (placed)
        {
            j->poserMeepleGrand();
            plateau.addMeeple(j->getCouleurJoueur(),T,pos, MT);
        }
    }

    if(MT==meepleEnum::Normal)
    {
        placed = true;
        //vérification qu'un meeple est dispo
        if(!j->meepleNormal_est_Disponible()) 
        {
            cout << "Vous n'avez aucun meeple Normal disponible." << endl;
            placed = false;
        }

        //vérification que le terrais n'est pas de mauvais type
        if ( T->getPositionX(pos) == Terrain::CroisementFerme || T->getPositionX(pos) == Terrain::Riviere)
        {
            cout << "Vous ne pouvez pas placer un meeple Normal sur ce type de terrain." << endl;
            placed = false;
        }

        //on place le meeple si son emplacement est valide
        if (placed)
        {
            j->poserMeepleNormal();
            plateau.addMeeple(j->getCouleurJoueur(),T,pos, MT);
        }
    }

    if(MT==meepleEnum::Abbe)
    {   
        placed = true;
        //vérification qu'un meeple est dispo
        if( !j->meepleAbbe_est_Disponible()) 
        {
            cout << "Vous n'avez aucun Abbé disponible." << endl;
            placed = false;
        }

        //vérification que le terrais n'est pas de mauvais type
        if ( T->getPositionX(pos) != Terrain::Abbaye )
        {
            cout << "Vous ne pouvez pas placer un Abbé en dehors d'une Abbaye ou un jardin." << endl;
            placed = false;
        }

        //on place le meeple si son emplacement est valide
        if (placed)
        {
            j->poserMeepleAbbe();
            plateau.addMeeple(j->getCouleurJoueur(),T,pos, MT);
        }
    }

    //renvoi false si on est entré dans aucune des conditions
    return placed;
}

//retirer un meeple
bool Controleur::retirerMeeple(Tuile* T,int pos,Joueur *j,meepleEnum MT)
{
    bool removed = false;
    if(MT==meepleEnum::Grand)
    {
        j->recupererMeepleGrand();
        plateau.retirerMeeple(j->getCouleurJoueur(),T,pos, MT);
        removed = true;
    }
    if(MT==meepleEnum::Normal)
    {
        j->recupererMeepleNormal();
        plateau.retirerMeeple(j->getCouleurJoueur(),T,pos, MT);
        removed = true;
    }

    if(MT==meepleEnum::Abbe)
    {
        j->recupererMeepleAbbe();
        plateau.retirerMeeple(j->getCouleurJoueur(),T,pos, MT);
        removed = true;
    }

    return removed;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------    Méthode Tour                             ---------------------*/
//méthode qui pourrait partager le travail de partie en gêrant un tour
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void Controleur::tour(Joueur* joueur)
{
    cout << "Erreur : appel de la fonction tour avec le joueur :" << *joueur << endl;
    //remplace le contenu d'une boucle while de partie
    //attention il faut bien redéfinir les variables x,y et aposer dans tour et les enlever de partie
    //pour l'instant j'ai laissé les boucles au cas ou on décide de poser automatiquement les tuiles
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------    Méthode Partie                           ---------------------*/
//Cette méthode gère une partie complète de A à Z, son travail pourrait être partagé avec la fonction tour
//elle communique directement avec l'interface graphique
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void Controleur::partie()
{

}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------    méthode partieCmdLine                    ---------------------*/
//Cette méthode gère une partie complète de A à Z, son travail pourrait être partagé avec la fonction tour
//elle permet de jouer en lignes de commande
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void Controleur::partieCmdLine()
{

    //initialisation des joueurs
    Log::flog << "Création des joueurs..." << endl;
    initJoueursCmdLine();
    Log::flog << "Création des joueurs done." << endl;
    //itérateur des joueurs
    auto joueur = joueurs.begin();

    //pointeur vers la tuile à poser
    Tuile* aposer = nullptr;
    //position sélectionnée de la tuile à poser
    int x;
    int y;
    //nombre de rotations
    int r;

    //début de partie (pioche riviére)
    Log::flog << "Pioche rivière..." << endl;
    pioche = Pioche::setPioche(jeu->getTuilesRiviere());

    //si la pioche n'est pas vide et que le plateau et vide on ajoute la premiere tuile de la pioche (qui est la tuile d'origine de la rivière)
    if (!pioche->estVide() && plateau.estVide())
    {
        plateau.ajouter(pioche->piocher(), 50, 50);
        cout << plateau << endl;
    }

    //boucle principale
    while(!pioche->estVide())
    {
        //variable de choix d'actions du joueur (pour les meeples)
        int choice = 0;
        //début du tour d'un joueur
        //pioche d'une tuile
        aposer = pioche->piocher();

        //cas où on pioche la dernière tuile de la rivière
        if (jeu->tuileToID(aposer) == 83)
        {
            //pose automatique de la derniere tuile de la rivière
            bruteForcePoseSNAIL(x, y, r, aposer);
            cout << plateau << endl;

        //sinon on demande au joueur de placer la tuile
        }
        else
        {
            //on récupère les coordonnées où placer la tuile
            cout << "Tour du " << **joueur << endl;
            cout << "Tuile à poser : " << jeu->tuileToID(aposer) << endl;
            //cas où le joueur est humain
            if ((*joueur)->getTypeJoueur() == JoueursEnum::Humain)
            {
                //saisie position tuile
                saisieCoosCmdLine( x, y, r, aposer);

                //ajout et affichage du plateau ainsi modifié
                plateau.ajouter(aposer,x,y);
                cout << plateau << endl;

                //ajout d'un meeple / rien
                cout << "Placement Meeple " << **joueur << endl;
                cout << "Meeples disponibles : " << (*joueur)->getMeeplesDisponible();
                cout << "Meeples sur le plateau : " << (*joueur)->getMeeplesUtilise() << endl;

                //sélection choix joueur
                do
                {
                    cout << "0:placer / 1:passer" << endl;
                    //cin >> choice;
                    choice = 1;
                }while(choice < 0 || choice > 1);
                
                //cas où le joueur souhaite placer un meeple
                if (choice == 0)
                {
                    poseMeepleCmdLine(aposer, *joueur);
                }

            //cas où le joueur est une IA
            }else 
            {
                //placement de la tuile
                bruteForcePoseSNAIL(x, y, r, aposer);
                //ajout de la tuile
                plateau.ajouter(aposer,x,y);
                //éventuelle pose d'une meeple
                bruteForcePoseMeeple(aposer, *joueur);
            }

            //retrait de meeples (et comptage)
            //affichage du plateau et des meeples qui sont dessus
            cout << plateau << endl;
            cout << "Liste de tous les Meeples posés sur le plateau : " << endl << plateau.getMeeplesPose();
            //si des schémas sont complétés / le joueur actuel souhaite récupérer un abbé c'est ici que ça se passe (le comptage se fait aussi à ce momment)
            choice = 1;
            do
            {
                cout << "Retrait de meeples et comptage de points -> 0:retirer / 1:passer" << endl;
                //cin >> choice;
            }while(choice < 0 || choice > 1);
            //tant que le joueur veut retirer des meeples on continue
            while(choice == 0)
            {        
                //cas où le joueur souhaite  retirer un meeple
                retraitMeepleCmdLine();
                //affichage du plateau et des meeples qui sont dessus
                cout << plateau << endl;
                cout << "Liste de tous les Meeples posés sur le plateau : " << endl << plateau.getMeeplesPose();
                //si on retire un meeple on veut aussi ajouter les points

                //demande au joueur si il souhaite continuer ou arreter de retirer
                do
                {
                    cout << "0:retirer nouveau / 1:passer" << endl;
                    cin >> choice;
                }while(choice < 0 || choice > 1);
            }

            //passage au joueur suivant
            ++joueur;
            //si on arrive é la fin de la liste de joueurs, on repart au début
            if (joueur == joueurs.end())
            {
                joueur = joueurs.begin();
            }
        }
    }
    Log::flog << "Pioche rivière done." << endl;

    //milieu de partie (pioche classique, abbé, paysan, auberge)
    Log::flog << "Pioche numéro 2..." << endl;
    pioche->liberePioche();
    pioche = Pioche::setPioche(jeu->getTuilesClassique(),jeu->getTuilesPaysan(), jeu->getTuilesAbbe(), jeu->getTuilesAuberge());

    //si la pioche n'est pas vide et que le plateau et vide on ajoute la premiere tuile de la pioche (qui est la tuile d'origine de l'extension classique)
    if (!pioche->estVide() && plateau.estVide())
    {
        plateau.ajouter(pioche->piocher(), 50, 50);
        cout << plateau << endl;
    }

    //boucle principale
    while(!pioche->estVide())
    {
        //variable de choix d'actions du joueur (pour les meeples)
        int choice = 0;
        //début du tour d'un joueur
        //pioche d'une tuile
        aposer = pioche->piocher();

        //on récupère les coordonnées où placer la tuile
        cout << "Tour du " << **joueur << endl;
        cout << "Tuile à poser : " << jeu->tuileToID(aposer) << endl;
        //cas où le joueur est humain
        if ((*joueur)->getTypeJoueur() == JoueursEnum::Humain)
        {
            //saisie position tuile
            saisieCoosCmdLine( x, y, r, aposer);

            //ajout et affichage du plateau ainsi modifié
            plateau.ajouter(aposer,x,y);
            cout << plateau << endl;

            //ajout d'un meeple / rien
            cout << "Placement Meeple " << **joueur << endl;
            cout << "Meeples disponibles : " << (*joueur)->getMeeplesDisponible();
            cout << "Meeples sur le plateau : " << (*joueur)->getMeeplesUtilise() << endl;

            //sélection choix joueur
            do
            {
                cout << "0:placer / 1:passer" << endl;
                cin >> choice;
            }while(choice < 0 || choice > 1);
            
            //cas où le joueur souhaite placer un meeple
            if (choice == 0)
            {
                poseMeepleCmdLine(aposer, *joueur);
            }

        //cas où le joueur est une IA
        }else 
        {
            //placement de la tuile
            bruteForcePoseSNAIL(x, y, r, aposer);
            //ajout de la tuile
            plateau.ajouter(aposer,x,y);
            //éventuelle pose d'une meeple
            bruteForcePoseMeeple(aposer, *joueur);
        }

        //retrait de meeples (et comptage)
        //affichage du plateau et des meeples qui sont dessus
        cout << plateau << endl;
        cout << "Liste de tous les Meeples posés sur le plateau : " << endl << plateau.getMeeplesPose();
        //si des schémas sont complétés / le joueur actuel souhaite récupérer un abbé c'est ici que ça se passe (le comptage se fait aussi à ce momment)
        choice = 1;
        do
        {
            cout << "Retrait de meeples et comptage de points -> 0:retirer / 1:passer" << endl;
            cin >> choice;
        }while(choice < 0 || choice > 1);
        //tant que le joueur veut retirer des meeples on continue
        while(choice == 0)
        {        
            //cas où le joueur souhaite  retirer un meeple
            retraitMeepleCmdLine();
            //affichage du plateau et des meeples qui sont dessus
            cout << plateau << endl;
            cout << "Liste de tous les Meeples posés sur le plateau : " << endl << plateau.getMeeplesPose();
            //si on retire un meeple on veut aussi ajouter les points

            //demande au joueur si il souhaite continuer ou arreter de retirer
            do
            {
                cout << "0:retirer nouveau / 1:passer" << endl;
                cin >> choice;
            }while(choice < 0 || choice > 1);
        }

        //passage au joueur suivant
        joueur++;
        //si on arrive é la fin de la liste de joueurs, on repart au début
        if (joueur == joueurs.end())
        {
           joueur = joueurs.begin();
        }
    }
    Log::flog << "Pioche numéro 2 done." << endl;
    //fin de la partie

}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------    méthode initJoueursCmdLine               ---------------------*/
//permet d'initialiser les joueurs lorsqu'on joue en lignes de commandes
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void Controleur::initJoueursCmdLine()
{
    //demande du nombre de joueurs
    int nbJoueurs;
    do
    {
        cout << "Nombre de joueurs (1-4) ?" << endl;
        //cin >> nbJoueurs;
        nbJoueurs = 4;
    }while ( nbJoueurs < 1 || nbJoueurs > 4 );
/*
    //création des joueurs à la main
    for (int i = 0; i<nbJoueurs; ++i)
    {
        //saisie du nom
        string n;
        cout << "Joueur " << i+1 << " (nom) : " << endl;
        cin >> n;

        //saisie de la couleur
        int c;
        CouleurEnum C;
        do
        {
            //input couleur et transformation en CouleurEnum
            cout << endl << "Joueur " << i+1 << " (couleur : 0:rouge,1:mauve,2:vert,3:bleu) : " << endl;
            cin >> c;
            switch(c)
            {
                case 0 : 
                    C = CouleurEnum::rouge;
                    break;
                case 1 : 
                    C = CouleurEnum::mauve;
                    break;
                case 2 : 
                    C = CouleurEnum::vert;
                    break;
                case 3 : 
                    C = CouleurEnum::bleu;
                    break;
                default : 
                    cout << "Merci d'entrer une couleur valide (entier entre 0 et 3)." << endl;
                    break;
            }            

            //vérification qu'aucun joueur n'ai pas déjà la couleur d'attribuée
            for ( auto j : joueurs )
            {
                if ( j->getCouleurJoueur() == C )
                {
                    cout << "La couleur " << toString(C) << " est déjà utilisée par " << getJoueurs(C)->getPseudo() << endl;
                    c = -1;
                }
            }
    
        }while ( c < 0 || c > 3 );

        //saisie le type de joueur
        int t;
        JoueursEnum T;
        do
        {
            //input type et transformation en JoueursEnum
            cout << endl << "Joueur " << i+1 << " (type : 0:humain, 1:ordi) : " << endl;
            cin >> t;
            switch(t)
            {
                case 0 : 
                    T = JoueursEnum::Humain;
                    break;
                case 1 : 
                    T = JoueursEnum::IA;
                    break;
                default : 
                    cout << "Merci d'entrer un type valide (entier entre 0 et 1)." << endl;
                    break;
            }            
        }while ( t < 0 || t > 1 );

        //ajout du joueur
        joueurs.push_back(new Joueur(n,C,T,extensions));
    }
*/
    //création automatique des joueurs (utile pour les tests)
    for (int i = 0; i<nbJoueurs; ++i)
    {
        CouleurEnum C;
        switch(i)
            {
                case 0 : 
                    C = CouleurEnum::rouge;
                    break;
                case 1 : 
                    C = CouleurEnum::mauve;
                    break;
                case 2 : 
                    C = CouleurEnum::vert;
                    break;
                case 3 : 
                    C = CouleurEnum::bleu;
                    break;
                default : 
                    cout << "Merci d'entrer une couleur valide (entier entre 0 et 3)." << endl;
                    break;
            }            
        joueurs.push_back(new Joueur("Joueur"+to_string(i+1),C,JoueursEnum::IA,extensions));
    }

}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------    méthode saisieCoosCmdLine                ---------------------*/
//permet de saisir  les coordonnées  de placement d'une tuile
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void Controleur::saisieCoosCmdLine( int& x, int& y, int& r, Tuile* aposer)
{
    //récupération de la position souhaitée par le joueur pour poser sa tuile
    //il faut aussi permettre au joueur de faire des rotations de Tuile
    do
    {   
        //récupération du nombre de rotations à appliquer à la tuile
        r = 0;
        cout << "Nombre de rotations gauche : ";
        cin >> r;
        for ( int tourner = 0; tourner <= r%4; ++tourner)
        {
            aposer->rotationGauche();
        }

        //valeur correspondantes
        x = 0;
        y = 0;
        //saisie des coordonnées pour placer la tuile
        bool coosValides;
        do
        {   
            coosValides = true;
            cout << "Saisir la coordonnée x : ";
            cin >> x;
            cout << "Saisir la coordonnée y : ";
            cin >> y;
            //vérification de la validité des coordonnées (d'abord qu'elles soient dans le plateau)
            if ( x >= static_cast<int>(plateau.getSizeX()) || y >= static_cast<int>(plateau.getSizeY()) || x < 0 || y < 0 )
            {
                coosValides = false;
                cout << "Merci de saisir des coordonnées valides (0 < x < " << plateau.getSizeX() << " et 0 < y < " << plateau.getSizeY() << ")" << endl;
            
            }else 
            {
                //ensuite, si les coos sont dans le tableau, on vérifié qu'il y ait bien au moins une tuile adjacente
                if( !plateau.tuileAdjacente(x, y))
                {
                        coosValides = false;
                        cout << "Il faut placer la tuile à coté d'au moins une autre tuile." << endl;
                }
                //enfin, on vérifie qu'il n'y a pas déjà une tuile à l'emplacement choisi
                if( plateau.getTuileXY(x, y) )
                {
                        coosValides = false;
                        cout << "On ne peut pas placer une tuile là où il y en a déjà une." << endl;
                }
            }
        }while (!coosValides);
        
        //vérification que le tableau fait la bonne taille par rapport aux coordonnées entrées (si non il est agrandit)
        //l'agrandissement est de 10 cases dans les 2 sens ici
        if(static_cast<int>(plateau.getSizeX()) <= x || static_cast<int>(plateau.getSizeY()) <= y || x<0 || y<0)
        {
            size_t agrandissement = 10;
            //méthode de plateau qui permet d'agrandir celui-ci (non implémentée)
            plateau.agrandir(agrandissement);
            x += agrandissement;
            y += agrandissement;
        }
    }while ( !plateau.estCompatible(x,y,aposer) );
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------    méthode bruteForcePose                   ---------------------*/
//permet de poser une tuile à un emplacement valide exception si tuile pas posable
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//départ de la recherche au milieu (en escargot)
bool Controleur::bruteForcePoseSNAIL( int& x, int& y, int& r, Tuile* aposer)
{
    //Log::flog << "BD -> Pose de la tuile ID = " << jeu->tuileToID(aposer) << endl;
    bool coosValides = true;
    //itération sur toutes les coordonnées
    vector<pair<int,int>> done;
    vector<pair<int,int>> next;
    vector<pair<int,int>> actual;
    next.push_back(make_pair(50,50));
    while( !next.empty() )
    {
        actual = next;
        next.clear();
        for (auto it: actual)
        {
            //on récupère les coordonnées de la case à explorer
            x = it.first;
            y = it.second;
            //on ajoute les voisines de cette case qui n'ont pas étés faites
            //top (NORTH)
            if(find(done.begin(), done.end(), make_pair(x-1,y)) == done.end() && find(next.begin(), next.end(), make_pair(x-1,y)) == next.end())
            {
                if ( x-1 > 0) next.push_back(make_pair(x-1,y));
            }
            //right (EAST)
            if(find(done.begin(), done.end(), make_pair(x,y+1)) == done.end() && find(next.begin(), next.end(), make_pair(x,y+1)) == next.end())
            {
                if ( y+1 < static_cast<int>(plateau.getSizeY())-1 ) next.push_back(make_pair(x,y+1));
            }
            //bottom (SOUTH)
            if(find(done.begin(), done.end(), make_pair(x+1,y)) == done.end() && find(next.begin(), next.end(), make_pair(x+1,y)) == next.end())
            {
                if ( x+1 < static_cast<int>(plateau.getSizeX())-1) next.push_back(make_pair(x+1,y));
            }
            //left (WEST)
            if(find(done.begin(), done.end(), make_pair(x,y-1)) == done.end() && find(next.begin(), next.end(), make_pair(x,y-1)) == next.end())
            {
                if ( y-1 > 0 ) next.push_back(make_pair(x,y-1));
            }

        //on ajoute la position actuelle à done pour ne pas le refaire
        done.push_back(it);

        //vérification de la validité des coordonnées
        if ( x < static_cast<int>(plateau.getSizeX())-1 && y < static_cast<int>(plateau.getSizeY())-1 && x > 0 && y > 0 )
        {
            //itération sur toutes les rotations
            for (r = 0; r < 4; ++r)
            {
                //Log::flog << "Itération " << "x = " << x << " y = " << y << " r = " << r << endl;
                coosValides = true;

                //vérification qu'il y ait bien au moins une tuile adjacente
                if( !plateau.tuileAdjacente(x, y))
                {
                    coosValides = false;

                    //Log::flog << "Il faut placer la tuile à coté d'au moins une autre tuile." << endl;
                }

                //on vérifie qu'il n'y a pas déjà une tuile à l'emplacement choisi
                if( plateau.getTuileXY(x, y) )
                {
                    coosValides = false;
                    //Log::flog << "On ne peut pas placer une tuile là où il y en a déjà une." << endl;
                }


                //on vérifie que la tuile est compatible avec la position valide
                if ( !plateau.estCompatible(x,y,aposer) )
                {
                    coosValides = false;
                    //Log::flog << "Coos valides mais tuile pas compatible." << endl;
                }
                //si les coordonnées sont valides on affiche celles-cies dans le fichier de log et on ajoute la tuile au plateau
                if (coosValides)
                {
                    //Log::flog << "Coordonnées valides trouvées pour " << jeu->tuileToID(aposer) << " en x = " << x << " et y = " << y << " et r = " << r << endl;
                    plateau.ajouter(aposer,x,y);
                    return true;
                }
                aposer->rotationGauche();
            }
        }
    }
}

//throw ControleurException("bruteForcePose n'a pas trouvé d'emplacement valide où la tuile piochée est compatible.");
return false;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------    méthode Meeple cmdLine                   ---------------------*/
//permet au joueur de poser / retirer un meeple
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//permet au joueur de poser un meeple
void Controleur::poseMeepleCmdLine(Tuile* tile, Joueur* joueur)
{   
    //on vérifie que le joueur ait des meeples à placer
    if (joueur->getMeeplesDisponible().size() > 0)
    {
        int choice = 0;
        //on itère tant que le placement n'est pas valide / le joueur n'annule pas l'action
        while (choice == 0)
        {
            choice = 1;
            //récupération de la position où mettre le meeple
            int positionMeeple = 12;
            do
            {
                cout << "position (entier : 0->12)" << endl;
                cin >> positionMeeple;
            }while(positionMeeple < 0 || positionMeeple > 12);
            
            //récupération du type de meeple à placer
            int typeMeeple = 1;
            meepleEnum typeM = meepleEnum::Normal;
            do
            {
                cout << "type du Meeple (0:géant / 1:normal / 2:abbé)" << endl;
                cin >> typeMeeple;
            }while(typeMeeple < 0 || typeMeeple > 2);
            
            //transformation du type de meeple en Meeple enum
            switch(typeMeeple)
            {
                case 0:
                    typeM = meepleEnum::Grand;
                    break;
                case 1:
                    typeM = meepleEnum::Normal;
                    break;
                case 2:
                    typeM = meepleEnum::Abbe;
                    break;
                default:
                    throw ControleurException("Erreur convertion typeMeeple");
                    break;
            }
            
            //on pose le meeple (et on vérifie que ça se soit bien passé)
            if(!poserMeeple(tile, positionMeeple, joueur, typeM))
            {
                //cas où la pose de meeple n'est pas valide (on propose au joueur de réessayer ou d'annuler)
                do
                {
                    cout << "0:réessayer / 1:abandonner" << endl;
                    cin >> choice;
                }while(choice < 0 || choice > 1);
            }
        }
    //cas où le joueur n'a pas de meeples disponibles
    }else 
    {
        cout << "Vous n'avez plus de Meeples (essayez d'en retirer)" << endl;
    }
}

//permet de retirer un meeple du plateau (appartenant au joueur)
void Controleur::retraitMeepleCmdLine()
{
    //cas où il y a des meeples sur le plateau
    if (plateau.getMeeplesPose().size() > 0)
    {
        //récupération de la tuile où se trouve le meeple
        size_t idTuile = 0;
        do
        {
            cout << "ID de la tuile où retirer le meeple" << endl;
            cin >> idTuile;
        }while(idTuile > 101);

        //si la tuile existe et est bien sur le plateau
        if (jeu->IDToTuile(idTuile) && plateau.estSurPlateau(jeu->IDToTuile(idTuile)))
        {
            //récupération de la position où retirer le meeple
            int positionMeeple = 12;
            do
            {
                cout << "position (entier : 0->12)" << endl;
                cin >> positionMeeple;
            }while(positionMeeple < 0 || positionMeeple > 12);

            //si il y a bien un meeple à cet endroit on le retire
            //variables de sauvegarde des informations du meeple
            CouleurEnum couleurJ;
            meepleEnum typeM;
            if (plateau.hayMeeple(jeu->IDToTuile(idTuile), positionMeeple, couleurJ, typeM))
            {
                //on retire le meeple
                if(!retirerMeeple(jeu->IDToTuile(idTuile), positionMeeple, getJoueurs(couleurJ), typeM))
                {
                    //cas où le retrait à échoué
                    throw ControleurException("Echec du retrait du meeple");
                }
                cout << "Meeple " << toString(typeM) << " " << toString(couleurJ) << " retiré de la tuile " << idTuile << " à la position " << positionMeeple << endl;

                //saisie de l'ajout au score du joueur à qui on à retiré un meeple
                int scoreToAdd = 0;
                do
                {
                    cout << "score à ajouter au joueur " << toString(couleurJ) << endl;
                    cin >> scoreToAdd;
                }while(scoreToAdd < 0);
                //mise à jour du score
                getJoueurs(couleurJ)->addScore(scoreToAdd);

            //cas où l'emplacement sélectionné n'est pas valide
            }else
            {
                cout << "Il n'y a pas de meeple à cet emplacement" << endl;
            }
        
        //cas où la tuile n'est pas sur le plateau
        }else
        {
            cout << "La tuile entrée n'est pas encore sur le plateau ou n'existe pas" << endl;
        }
    //cas où il n'y a pas de meeples posés sur le plateau
    }else
    {
        cout << "Il n'y a pas de Meeples sur la plateau de jeu.";
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------    méthode bruteForcePoseMeeple             ---------------------*/
//permet de poser un meeple sur une tuile
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//permet au joueur de poser un meeple automatiquement
void Controleur::bruteForcePoseMeeple(Tuile* tile, Joueur* joueur)
{   
    //boolean qui permet de savoir si on à déjà posé un meeple
    bool stopPosing = false;
    //variable qui permet de limiter le nombre de recherches
    int nbRand = 0;

    //on vérifie que le joueur ait des meeples à placer
    if (joueur->getMeeplesDisponible().size() > 0)
    {
        //itération sur les positions de la tuile
        //for (int positionMeeple = 0; positionMeeple < 13; ++positionMeeple)
        while(!stopPosing && nbRand < 100)
        {
            //choix d'une position aléatoire    
            int positionMeeple = rand() % 13;
            //Log::flog << "position aléa : " << positionMeeple << endl;
            ++nbRand;

            //itération sur les types de meeple
            for (int typeMeeple = 0; typeMeeple < 3; ++typeMeeple)
            {
                meepleEnum typeM = meepleEnum::Normal;
                switch(typeMeeple)
                {
                    case 0:
                        typeM = meepleEnum::Grand;
                        break;
                    case 1:
                        typeM = meepleEnum::Normal;
                        break;
                    case 2:
                        typeM = meepleEnum::Abbe;
                        break;
                    default:
                        throw ControleurException("Erreur convertion typeMeeple");
                        break;
                }
                
                //permet de ne poser qu'un seul meeple par appel de méthode
                if (!stopPosing)
                {
                    //on pose le meeple (et on vérifie que ça se soit bien passé)
                    if(poserMeeple(tile, positionMeeple, joueur, typeM))
                    {
                        //cas où la pose de meeple est valide (on ne veut plus poser de meeples)
                        stopPosing = true;
                    }
                }
            }
        }
    //cas où le joueur n'a pas de meeples disponibles
    }else 
    {
        Log::flog << "plus de meeples " << toString(joueur->getCouleurJoueur()) << endl;
    }
}

void Controleur::nextPlayer()
{
    ++currentPlayer;
    //si on arrive é la fin de la liste de joueurs, on repart au début
    if (currentPlayer == getJoueurs().end())
    {
        currentPlayer = getJoueurs().begin();
    }
}

bool Controleur::recallMeeple(size_t x, size_t y, size_t score)
{
    //cas où il y a des meeples sur le plateau
    if (plateau.getMeeplesPose().size() > 0)
    {
        //récupération de la tuile : si la tuile existe et est bien sur le plateau
        Tuile* tile = plateau.getTuileXY(x, y);
        if (tile)
        {
            auto meeples = plateau.getMeeplesPose();
            if(meeples.empty()) cout << "Pas de Meeples posés" << endl;
            for (const auto &it: meeples)
            {
                for (auto it2: it.second)
                {
                    //cas où on trouve bien la tuile dans laquelle il faut retirer un meeple (on le retire)
                    if (it2.first.first == tile)
                    {
                        getJoueurs(it.first)->addScore(score);
                        return retirerMeeple(tile, it2.first.second, getJoueurs(it.first), it2.second);
                    }
                }
            }
        //cas où la tuile n'est pas sur le plateau
        }else
        {
            cout << "La tuile entrée n'est pas encore sur le plateau" << endl;
        }
    //cas où il n'y a pas de meeples posés sur le plateau
    }else
    {
        cout << "Il n'y a pas de Meeples sur la plateau de jeu.";
    }
    //cas où on n'a pas retiré le meeple
    return false;
}

bool Controleur::isMeeplerecallable(size_t x, size_t y)
    {
        //cas où il y a des meeples sur le plateau
        if (plateau.getMeeplesPose().size() > 0)
        {
            //récupération de la tuile : si la tuile existe et est bien sur le plateau
            Tuile* tile = plateau.getTuileXY(x, y);
            if (tile)
            {
                auto meeples = plateau.getMeeplesPose();
                if(meeples.empty()) cout << "Pas de Meeples posés" << endl;
                for (auto it: meeples)
                {
                    for (auto it2: it.second)
                    {
                        //cas où on trouve bien la tuile dans laquelle il faut retirer un meeple (on le retire)
                        if (it2.first.first == tile)
                        {
                            return true;
                        }
                    }
                }
            //cas où la tuile n'est pas sur le plateau
            }else
            {
                cout << "La tuile entrée n'est pas encore sur le plateau" << endl;
            }
        //cas où il n'y a pas de meeples posés sur le plateau
        }else
        {
            cout << "Il n'y a pas de Meeples sur la plateau de jeu.";
        }
        //cas où on n'a pas retiré le meeple
        return false;
    }

bool Controleur::bruteForcePoseMeepleG(Tuile* tile, Joueur* joueur, int& positionMgraph, meepleEnum& typeMeeplegraph){
    //boolean qui permet de savoir si on à déjà posé un meeple
    bool stopPosing = false;
    //variable qui permet de limiter le nombre de recherches
    int nbRand = 0;

    //on vérifie que le joueur ait des meeples à placer
    if (joueur->getMeeplesDisponible().size() > 0)
    {
        //itération sur les positions de la tuile
        //for (int positionMeeple = 0; positionMeeple < 13; ++positionMeeple)
        while(!stopPosing && nbRand < 100)
        {
            //choix d'une position aléatoire
            int positionMeeple = rand() % 13;
            //Log::flog << "position aléa : " << positionMeeple << endl;
            ++nbRand;

            //itération sur les types de meeple
            for (int typeMeeple = 0; typeMeeple < 3; ++typeMeeple)
            {
                meepleEnum typeM = meepleEnum::Normal;
                switch(typeMeeple)
                {
                    case 0:
                        typeM = meepleEnum::Grand;
                        break;
                    case 1:
                        typeM = meepleEnum::Normal;
                        break;
                    case 2:
                        typeM = meepleEnum::Abbe;
                        break;
                    default:
                        throw ControleurException("Erreur convertion typeMeeple");
                        break;
                }

                //permet de ne poser qu'un seul meeple par appel de méthode
                if (!stopPosing)
                {
                    //on pose le meeple (et on vérifie que ça se soit bien passé)
                    if(poserMeeple(tile, positionMeeple, joueur, typeM))
                    {
                        //cas où la pose de meeple est valide (on ne veut plus poser de meeples)
                        typeMeeplegraph = typeM;
                        positionMgraph = positionMeeple;
                        stopPosing = true;
                        return true;
                    }
                }
            }
        }
    //cas où le joueur n'a pas de meeples disponibles
    }else
    {
        //cout << "plus de meeples " << toString(joueur->getCouleurJoueur()) << endl;
    }
    return false;
}
