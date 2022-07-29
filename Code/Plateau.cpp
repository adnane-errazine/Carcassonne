//includes généraux

//includes fichiers du projet
#include "Tuile.h"
#include "Plateau.h"
#include "Jeu.h"

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------    Affichage Classe Plateau     ---------------------------*/
//Définition des opérateur << pour permettre d'afficher la classe Plateau directement
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
ostream& operator<<(ostream& f, const Plateau& plateau)
{
    size_t largeur = 40;
    size_t hauteur = 40;
    vector<vector<Tuile*>> board = plateau.getPlateau();
    size_t i = hauteur;
    size_t j = largeur;
    for ( auto it = board.begin()+hauteur; it != board.end()-hauteur; ++it )
    {
        f << "| ";
        j = largeur;
        for ( auto it2 = it->begin()+largeur; it2 != it->end()-largeur; ++it2  )
        {
            //Log::flog << "getTuileXY( "<< i << "," << j << " ) aff...";
            //cas où une tuile est présente sur la case
            if (plateau.getTuileXY(i,j))
            {
                size_t id = Jeu::getJeu()->tuileToID(plateau.getTuileXY(i,j));
                //en fonction du nombre de caractères dans le chiffre on ajoute des espaces pour améliorer l'affichage du plateau
                if ( id < 10 )
                {
                    f << " " << id << " " << " | ";
                }
                else if ( id < 100 )
                {
                    f << id << " " << " | ";
                }
                else
                {
                    f << id << " | ";
                }
            //cas où la case est vide
            }else
            {
                f << "   " << " | ";
            }
            //Log::flog << "affiché." << endl;
            j++;
        }
        i++;
        f << endl;
    }
    return f;
}

//affichage des meeples posés sur le plateau
ostream& operator<<(ostream& f, const map<CouleurEnum,list<pair<pair<Tuile*,int>,meepleEnum>>>& lJoueurs)
{
    for (auto j: lJoueurs) 
    {
        cout << "Meeples posés du joueur " << toString(j.first) << " : " << endl;
        for (auto it: j.second)
        {
            cout << "Tuile : " << Jeu::getJeu()->tuileToID(it.first.first) << " position : " << it.first.second << " type du Meeple : " << toString(it.second) << endl;
        }
    }
    return f;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*---------------------- Constructeur de Plateau                     ---------------------*/
//définition méthodes de création de Plateau
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//constructeur
Plateau::Plateau():x(100), y(100)
{
    vector<Tuile*> t(x,nullptr);
    vector<vector< Tuile*>> t2(y,t);
    board=t2;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------   Méthode tuileAdjacente                     ---------------------*/
//permet de vérifier il existe une tuile adjacente à des coordonnées x, y
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
bool Plateau::tuileAdjacente(size_t x, size_t y)
{
    bool adjacenteExiste = false;
    if ( x < getSizeX() && y < getSizeY() )
    {
            //top (NORTH)
            if(board[x-1][y]!=nullptr)
            {
                adjacenteExiste = true;
            }
            //right (EAST)
            if(board[x][y+1]!=nullptr)
            {
                adjacenteExiste = true;
            }
            //bottom (SOUTH)
            if(board[x+1][y]!=nullptr)
            {
                adjacenteExiste = true;
            }
            //left (WEST)
            if(board[x][y-1]!=nullptr)
            {
                adjacenteExiste = true;
            }
    }
    else 
    {
        throw PlateauException("tuileAdjacente appelée avec des coordonnées invalides");
    }
    return adjacenteExiste;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------   Méthode estCompatible                     ---------------------*/
//permet de vérifier si une tuile est compatible à des coordonnées x, y
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//vérif rivière permet d'empêcher la riviere de tourner 2 faois d'affilée ou 3 fois dans le meme sens
bool Plateau::verifRiver(size_t x, size_t y, Tuile * t)
{
    //cout << "!!!!!!!!!!!! verifRiver !!!!!!!!!!!!" << endl;
    //initialisation de la recherche
    bool compatible = true;
    int orientation = 0;
    size_t xa = 50;
    size_t ya = 50;
    Tuile * ta = nullptr;
    Tuile * prev = nullptr;
    Tuile * next = getTuileXY(50, 50);;
    int prevDir = 12;
    int nextDir = 12;
    int prevRota = 0;

    //vérifications diverses
    if ( x < getSizeX() && y < getSizeY() )
    {
        if (t)
        {
                if ( 73 > Jeu::getJeu()->tuileToID(t) && Jeu::getJeu()->tuileToID(t) > 82 )
                    throw PlateauException("verifRiver appelée avec une autre tuile qu'une tuile riviere.");
                if ( 72 != Jeu::getJeu()->tuileToID((getTuileXY(50, 50))) )
                    throw PlateauException("verifRiver appelée alors que la tuile de départ n'est pas celle de riviere.");

                //début du controle de la validité de la rivière
                do
                {
                    ta = next;
                    prevDir = nextDir;
                    //on trouve la tuile rivière suivante (ne doit pas être la précédente)
                    //left (WEST)
                    if (ta->getPositionX(10) == Terrain::Riviere && prevDir != 4)
                    {
                        ya--;
                        prev = next;
                        next = getTuileXY(xa, ya);
                        nextDir = 10;

                        //détermination du virage
                        //tout droit
                        if ( prevDir == 10 ) orientation += 0;
                        //virage à droite (on vérifie que le virage précédent n'était pas déjà dans le meme sens)
                        if ( prevDir == 7 ){ orientation += 1; if (prevRota == 1) compatible = false; prevRota = 1; }
                        //virage à gauche (on vérifie que le virage précédent n'était pas déjà dans le meme sens)
                        if ( prevDir == 1 ) { orientation += -1; if (prevRota == -1) compatible = false; prevRota = -1; }

                    }
                    //down (SOUTH)
                    if (ta->getPositionX(7) == Terrain::Riviere && prevDir != 1)
                    {
                        xa++;
                        prev = next;
                        next = getTuileXY(xa, ya);
                        nextDir = 7;

                        //détermination du virage
                        //tout droit
                        if ( prevDir == 7 ) orientation += 0;
                        //virage à droite (on vérifie que le virage précédent n'était pas déjà dans le meme sens)
                        if ( prevDir == 4 ) { orientation += 1; if (prevRota == 1) compatible = false; prevRota = 1; }
                        //virage à gauche (on vérifie que le virage précédent n'était pas déjà dans le meme sens)
                        if ( prevDir == 10 ) { orientation += -1; if (prevRota == -1) compatible = false; prevRota = -1; }
                    }
                    //right (EAST)
                    if (ta->getPositionX(4) == Terrain::Riviere && prevDir != 10)
                    {
                        ya++;
                        prev = next;
                        next = getTuileXY(xa, ya);
                        nextDir = 4;

                        //détermination du virage
                        //tout droit
                        if ( prevDir == 4 ) orientation += 0;
                        //virage à droite (on vérifie que le virage précédent n'était pas déjà dans le meme sens)
                        if ( prevDir == 1 ) { orientation += 1; if (prevRota == 1) compatible = false; prevRota = 1; }
                        //virage à gauche (on vérifie que le virage précédent n'était pas déjà dans le meme sens)
                        if ( prevDir == 7 ) { orientation += -1; if (prevRota == -1) compatible = false; prevRota = -1; }
                    }
                    //up (NORTH)
                    if (ta->getPositionX(1) == Terrain::Riviere && prevDir != 7)
                    {
                        xa--;
                        prev = next;
                        next = getTuileXY(xa, ya);
                        nextDir = 1;

                        //détermination du virage
                        //tout droit
                        if ( prevDir == 1 ) orientation += 0;
                        //virage à droite (on vérifie que le virage précédent n'était pas déjà dans le meme sens)
                        if ( prevDir == 10 ) { orientation += 1; if (prevRota == 1) compatible = false; prevRota = 1; }
                        //virage à gauche (on vérifie que le virage précédent n'était pas déjà dans le meme sens)
                        if ( prevDir == 4 ) { orientation += -1; if (prevRota == -1) compatible = false; prevRota = -1; }
                    }

                    //cout << "xa = " << xa << " ya = " << ya << endl;

                    //cas où on est au bout de la rivière (ajout de la tuile suivante)
                    if (next == nullptr && prev != t)
                    {
                        if (xa == x && ya == y)
                        {
                            next = t;
                        }else
                        {
                            compatible = false;
                        }
                    }

                    //vérification qu'on est toujours dans la rivière
                    if (next != nullptr && 72 > Jeu::getJeu()->tuileToID(next) && Jeu::getJeu()->tuileToID(next) > 83 )
                        throw PlateauException("verifRiver : construction invalide de la riviere (next).");
                }while ( next && compatible );

                //détermination du renvoi de la fonction en fonction de l'orientation actuelle
                if (orientation < -1 || orientation > 1)
                    compatible = false;

        }
        else
        {
            throw PlateauException("verifRiver appelée avec une tuile inexistante");
        }
    }
    else
    {
        throw PlateauException("verifRiver appelée avec des coordonnées invalides");
    }

    return compatible;
}

//est compatible détermine si une tuile peut être placée à des coordonnées x,y (en fonction de ses voisins)
bool Plateau::estCompatible(size_t x, size_t y, Tuile * t)
{
    //cout << "!!!!!!!!!!!!!!!        EST COMPATIBLE      !!!!!!!!!!!!!!!" << endl;
    bool a=true;
    bool b=true;
    bool c=true;
    bool d=true;
    bool ra=true;
    bool rb=true;
    bool rc=true;
    bool rd=true;
    bool re=true;
    if ( x < getSizeX() && y < getSizeY() )
    {
        if (t)
        {
            //dans le cas où on a une tuile rivière  on veut que la rivière soit connectée ! (pas de vérif pour la tuile 72, posée en premiere)
            if ( 72 < Jeu::getJeu()->tuileToID(t) && Jeu::getJeu()->tuileToID(t) <= 83 )
            {
                ra=false;
                rb=false;
                rc=false;
                rd=false;
                //left (WEST)
                if (t->getPositionX(10) == Terrain::Riviere)
                {
                    ra = board[x][y-1]!=nullptr;
                }
                //down (SOUTH)
                if (t->getPositionX(7) == Terrain::Riviere)
                {
                    rb = board[x+1][y]!=nullptr;
                }
                //right (EAST)
                if (t->getPositionX(4) == Terrain::Riviere)
                {
                    rc = board[x][y+1]!=nullptr;
                }
                //up (NORTH)
                if (t->getPositionX(1) == Terrain::Riviere)
                {
                    rd = board[x-1][y]!=nullptr;
                }
                if ((ra || rb || rc || rd) && Jeu::getJeu()->tuileToID(t) != 83)
                {
                    re = verifRiver(x, y, t);
                }
            }

            //left (WEST)
            if(board[x][y-1]!=nullptr)
            {
                a=(t->getPositionX(11)==board[x][y-1]->getPositionX(3) && t->getPositionX(10)==board[x][y-1]->getPositionX(4) && t->getPositionX(9)==board[x][y-1]->getPositionX(5) );
                //cout << "WEST : " << Jeu::getJeu()->tuileToID(board[x][y-1]) << endl <<  *board[x][y-1] << endl;
            }
            //down (SOUTH)
            if(board[x+1][y]!=nullptr)
            {
                //cout << "SOUTH : " << Jeu::getJeu()->tuileToID(board[x+1][y]) << endl <<  *board[x+1][y] << endl;
                b=(t->getPositionX(8)==board[x+1][y]->getPositionX(0) && t->getPositionX(7)==board[x+1][y]->getPositionX(1) && t->getPositionX(6)==board[x+1][y]->getPositionX(2) );
            }
            //right (EAST)
            if(board[x][y+1]!=nullptr)
            {
                //cout << "EAST : " << Jeu::getJeu()->tuileToID(board[x][y+1]) << endl <<  *board[x][y+1] << endl;
                c=(t->getPositionX(3)==board[x][y+1]->getPositionX(11) && t->getPositionX(4)==board[x][y+1]->getPositionX(10) && t->getPositionX(5)==board[x][y+1]->getPositionX(9) );
            }
            //up (NORTH)
            if(board[x-1][y]!=nullptr)
            {
                //cout << "NORTH : " << Jeu::getJeu()->tuileToID(board[x-1][y]) << endl <<  *board[x-1][y] << endl;
                d=(t->getPositionX(0)==board[x-1][y]->getPositionX(8) && t->getPositionX(1)==board[x-1][y]->getPositionX(7) && t->getPositionX(2)==board[x-1][y]->getPositionX(6) );
            }
        }
        else
        {
            throw PlateauException("estCompatible appelée avec une tuile inexistante");
        }
    }
    else
    {
        throw PlateauException("estCompatible appelée avec des coordonnées invalides");
    }
    return (a && b && c && d && re && (ra || rb || rc || rd));
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------   getXYTuile  et  getTuileXY et isSurPlateau---------------------*/
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//getter des coordonnées d'une Tuile à partir de son pointeur
pair<int,int> Plateau::getXYTuile(Tuile* t) const
{
    if (!t) throw PlateauException("Recherche d'une tuile inexistante");
    int a,b;
    for(size_t i=0;i<y;i++)
    {
        for(size_t j=0;j<x;j++)
        {
            if(board[i][j]==t)
            {
                a=i;
                b=j;
                return make_pair(a,b);
            }
        }
    }
    throw PlateauException("Plateau::getXYTuile tuile non trouvée");
}

//récupérer une tuile à partir de sa position
Tuile * Plateau::getTuileXY(size_t x, size_t y) const
{
    return board[x][y];
}

//permet de savoir si une tuile est sur le plateau
bool Plateau::estSurPlateau(Tuile* t) const
{
    if (!t) throw PlateauException("Recherche d'une tuile inexistante");
    for(size_t i=0;i<y;i++)
    {
        for(size_t j=0;j<x;j++)
        {
            if(board[i][j]==t)
            {
                return true;
            }
        }
    }
    //cas où la tuile n'a pas été trouvée
    return false;
}

//permet de savoir si il y a un meeple sur une tuile à une position donnée (certains arguments sont voués au retour)
bool Plateau::hayMeeple(Tuile* tile, int position, CouleurEnum& retourCouleurJ, meepleEnum& retourTypeM) const
{
    //itération sur les joueurs
    for (auto j: meeplesPose) 
    {
        //on sauvegarde la couleur du joueur
        retourCouleurJ = j.first;

        //itération sur les meeples posés
        for (auto it: j.second)
        {
            //on sauvegarde le type du meeple
            retourTypeM = it.second;
            //si on trouve la tuile
            if (it.first.first == tile && it.first.second == position)
            {
                return true;
            }
        }
    }
    //cas où on ne trouve pas de meeple à la position donnée
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------   ajouter                                   ---------------------*/
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/* 
    Méthode ajouter, permet d'ajouter une tuiles du plateau board.
    Nous l'utilisons par exemple quand un joueur pose une tuile lors de son tour de jeu.
    Ajouter prend en paramètre la tuile à ajouter sous la forme d'un pointeur, 
    ainsi que x et y, des size_t qui seront sa position dans le board.
    Cette méthode vérifié la compatibilité de la tuile avant de la poser
*/
void Plateau::ajouter(Tuile* t, size_t x, size_t y)
{
    if(!estCompatible(x,y,t)){throw PlateauException("tu as essayé d'ajouter une tuile non compatible... pas cool hein !");}
    this->board[x][y] = t;
    //Log::flog << "updateAllTerrains commencée..." << endl;
    //updateAllTerrains(x,y);
    //Log::flog << "updateAllTerrains terminée." << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------   Méthodes de gestion des Meeples dans le Plateau----------------*/
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void Plateau::addMeeple(CouleurEnum C,Tuile* T,int pos, meepleEnum typeMeeple)
{
    if ( !T || pos > 12 || pos < 0)
        throw PlateauException("Ajout d'un meeple mais tuile ou position incorrecte");
    meeplesPose[C].push_back(make_pair(make_pair(T,pos), typeMeeple));
}

void Plateau::retirerMeeple(CouleurEnum C,Tuile* T,int pos, meepleEnum typeMeeple)
{
    if ( !T || pos > 12 || pos < 0)
        throw PlateauException("Retrait d'un meeple mais tuile ou position incorrecte");
    meeplesPose[C].remove(make_pair(make_pair(T,pos), typeMeeple));
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------    estVide                                  ---------------------*/
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//permet de  savoir si le plateau est vide
bool Plateau::estVide() const
{
    bool empty = true;
    for (auto it: board)
    {
        for (auto it2: it)
        {
            if (it2)
            {
                empty = false;
            }
        }
    } 
    return empty;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------   agrandir                                  ---------------------*/
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/* 
    Méthode agrandir de Plateau permet d'agrandir le plateau si la taille initiale n'était pas assez grande.
    Cependant, nous nous débrouillons pour ne jamais en avoir besoin en initialisant un tableau suffisamment grand.
    Cette méthode est définie vide car nous l'utilisons dans le controleur,
    mais sachant qu'on ne rentrera pas dans les cas d'utilisation de cette méthode,
    nous n'écrivons pas l'intérieur de sa définition qui reste donc vide : {} 
*/
void Plateau::agrandir(size_t t)
{
    cout << "Tentative d'agrandir le plateau d'une taille " << t << endl;
    throw PlateauException("tentative d'agrandir le plateau d'une taille");
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------   Méthode pour l'automatisation du Jeu      ---------------------*/
//diverses méthodes qui facilitent l'automatisation du jeu
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void Plateau::updateAllTerrains(size_t x,size_t y) // #version1.5 // CETTE FONCTION NECESSITE QUE estCompatible VRAI POUR LES MEMES COORDONNEES
{
    list<int> PositionDeContact;
    //////////// regrouper les points de contact et les points sans contact
    if(board[x-1][y]!=nullptr) // Points contact top
    {
        PositionDeContact.push_back(0);
        PositionDeContact.push_back(1);
        PositionDeContact.push_back(2);
    }
    if(board[x][y+1]!=nullptr) // Points contact right
    {
        PositionDeContact.push_back(3);
        PositionDeContact.push_back(4);
        PositionDeContact.push_back(5);
    }
    if(board[x+1][y]!=nullptr)// Points contact Bottom
    {
        PositionDeContact.push_back(6);
        PositionDeContact.push_back(7);
        PositionDeContact.push_back(8);
    }
    if(board[x][y-1]!=nullptr) // Points contact Left
    {
        PositionDeContact.push_back(9);
        PositionDeContact.push_back(10);
        PositionDeContact.push_back(11);
    }
    list<int> PositionSansContact;
    for(int i=0;i<12;i++)
    {
        if(find(PositionDeContact.begin(),PositionDeContact.end(),i)==PositionDeContact.end())
        {PositionSansContact.push_back(i);}
    }
    ///////////////////////////////////////////////////////////////
    /////////////////////////// PARTIE Positions AVEC CONTACT //////////////////////////////////////////////////////
    // position 11 est lié à la position 3 de la tuile situé à gauche de x,y

    for(int c= 0;c<12;c++)
    {  // TABLEAU DE CORRESPONDACE TO ADD

        if(find(PositionDeContact.begin(),PositionDeContact.end(),c)!=PositionDeContact.end())
        {
            Tuile* TuileAdjacent;
            int posAdjacent;
            switch(c)
            {
            case 0:
                TuileAdjacent=board[x][y+1];
                posAdjacent=8;
                break;
            case 1:
                TuileAdjacent=board[x][y+1];
                posAdjacent=7;
                break;
            case 2:
                TuileAdjacent=board[x][y+1];
                posAdjacent=6;
                break;
            case 3:
                TuileAdjacent=board[x+1][y];
                posAdjacent=11;
                break;
            case 4:
                TuileAdjacent=board[x+1][y];
                posAdjacent=10;
                break;
            case 5:
                TuileAdjacent=board[x+1][y];
                posAdjacent=9;
                break;
            case 6:
                TuileAdjacent=board[x][y-1];
                posAdjacent=2;
                break;
            case 7:
                TuileAdjacent=board[x][y-1];
                posAdjacent=1;
                break;
            case 8:
                TuileAdjacent=board[x][y-1];
                posAdjacent=0;
                break;
            case 9:
                TuileAdjacent=board[x-1][y];
                posAdjacent=5;
                break;
            case 10:
                TuileAdjacent=board[x-1][y];
                posAdjacent=4;
                break;
            case 11:
                TuileAdjacent=board[x-1][y];
                posAdjacent=3;
                break;
            default:
                    TuileException("\nfonction updateALL exception  switch TuileAdjacent position avec contact.");
            }

            //Terrain A=board[x][y-1]->getPositionX(3); // cette variable sert à vérifier davantage le bon fonctionnement, si non comme 11 est de meme type de 3 tuile gauche
            vector<list<pair<Tuile*,int>>>* _terrainAll;
            vector<list<pair<Tuile*,int>>> XYgetTerrain;
            switch(board[x][y]->getPositionX(c)) // retourne le type de terrain de cette position afin de chercher directement sur les vecteurs concerné
            {
                case Terrain::Route:
                    _terrainAll =&routesAll;
                    XYgetTerrain=board[x][y]->getRoutes();
                    break;
                case Terrain::Ville:
                    _terrainAll =&villesAll;
                    XYgetTerrain=board[x][y]->getVilles();
                    break;
                case Terrain::Riviere:
                    _terrainAll =&rivieresAll;
                    XYgetTerrain=board[x][y]->getRivieres();
                    break;
                case Terrain::Prairie:
                    _terrainAll =&prairiesAll;
                    XYgetTerrain=board[x][y]->getPrairies();
                    break;
                default:
                    TuileException("\nfonction updateALL exception switch terrain position avec contact.");
            }


                int i=0; // représente l'indice du vecteur routeALL ou se trouve position 3 de la tuile gauche
                bool loopBreakerOptimiser=false; // ce boolean permet de ne pas continuer les 2 boucle si l'objectif est atteint
                for(auto &it : *(_terrainAll) ) // à changer switch
                {
                    for (auto &it2 : it )
                    {
                        if(it2.first==TuileAdjacent && it2.second==posAdjacent) ///////////////////////////// PROBLEM TABLEAU CORRESPONDANCE
                        {
                            loopBreakerOptimiser=true;
                            break;
                        }
                        if(loopBreakerOptimiser){break;}
                    }
                if(loopBreakerOptimiser){break;}
                i++;
                }
                //  routeALL[i] est la liste qui contient (board[x+-1][y+-1],c) exemple : board[x][y-1],3
                // on cherche l'index du vecteur prarie de la tuile board[x][y] qui contient position 11
                int j=0;
                bool loopBreakerOptimiser2=false;
                for(auto const &it : XYgetTerrain)
                {
                    for(auto const &it2:it)
                    {
                        if(it2.first==board[x][y] && it2.second==static_cast<int>(c))
                        {
                            loopBreakerOptimiser2=true;
                            break;
                        }
                        if(loopBreakerOptimiser2){break;}
                    }
                    if(loopBreakerOptimiser2){break;}
                    j++;
                }// reste à ajouter board[x][y]->routes[j] à routeALL[i] pour case : terrain::route
                (*_terrainAll)[i].insert((*_terrainAll)[i].end(),XYgetTerrain[j].begin(),XYgetTerrain[j].end());

                // puis je recupère toutes les positions dans tuile[x][y]->routes[j] et les retirer de PositionDeContact ainsi que  PositionSansContact
                // à refaire avec une fonction !
                list<int> Resultat;
                for(auto const& it : XYgetTerrain[j])
                {
                    Resultat.push_back(it.second); // on regroupe toutes les positions lié à c // exemple : de la pos 11 ( meme routes) et 11 inclus !!!
                }
                // on retire list Resultat de la liste positions de contact et positions sans contacte pour ne pas avoir de la redondance.
                for( auto const &it : PositionDeContact)
                {
                    if(find(Resultat.begin(),Resultat.end(),it)!=Resultat.end())
                    {
                        PositionDeContact.remove(it);
                    }
                }
                for( auto const &it : PositionSansContact)
                {
                    if(find(Resultat.begin(),Resultat.end(),it)!=Resultat.end())
                    {
                        PositionSansContact.remove(it);
                    }
                }
            }
        }

    /////////////////////////// PARTIE Positions SANS CONTACT ///////////////////////////////////////////////
    // l'exemple de la position 5 qui lié à la position 9 de la tuile à droite mais dans ce cas il n'y a pas de tuile à droite
    for(int c= 0;c<12;c++) // boucle sur les 12 points
    {
        if(find(PositionSansContact.begin(),PositionSansContact.end(),c)!=PositionSansContact.end())
        {

            // 5 existe dans ce vecteur alors on sait d'avance que la zones ou se trouve 5 est indépendante.
            // step 1 : en se basant sur le type de 5,

            vector<list<pair<Tuile*,int>>>* _terrainAll;
            vector<list<pair<Tuile*,int>>> XYgetTerrain;
            switch(board[x][y]->getPositionX(c)) // retourne le type de terrain de cette position afin de chercher directement sur les vecteurs concerné
            {
                case Terrain::Route:
                    _terrainAll =&routesAll;
                    XYgetTerrain=board[x][y]->getRoutes();
                    break;
                case Terrain::Ville:
                    _terrainAll =&villesAll;
                    XYgetTerrain=board[x][y]->getVilles();
                    break;
                case Terrain::Riviere:
                    _terrainAll =&rivieresAll;
                    XYgetTerrain=board[x][y]->getRivieres();
                    break;
                case Terrain::Prairie:
                    _terrainAll =&prairiesAll;
                    XYgetTerrain=board[x][y]->getPrairies();
                    break;
                default:
                    TuileException("\nfonction updateALL exception switch terrain position sans contact.");
            }

                //on cherche le vector associé à cette position dans les prairies propres à la tuile et on utilise le même code dans la premiere partie
                int j=0;
                bool loopBreakerOptimiser3=false;
                for(auto &it : XYgetTerrain)
                {
                    for(auto const &it2:it)
                    {
                        if(it2.first==board[x][y] && it2.second==static_cast<int>(c)) //
                        {
                            loopBreakerOptimiser3=true;
                            break;
                        }
                        if(loopBreakerOptimiser3){break;}
                    }
                    if(loopBreakerOptimiser3){break;}
                    j++;
                }
                ///// on rajoute ce vecteur au grand vecteur des prairies.
                (*_terrainAll).push_back(XYgetTerrain[j]); // on ajoute que la liste d'indice j car cette liste contient l'element 5

                // puis je recupère toutes les positions dans tuile[x][y]->routes[j] et les retirer de PositionDeContact ainsi que  PositionSansContact
                // à refaire avec une fonction !
                list<int> Resultat;
                for(auto const& it : XYgetTerrain[j])
                {
                    Resultat.push_back(it.second); // on regroupe toutes les positions lié à 11 ( meme routes) et 11 inclus !!!
                }
                // on retire list Resultat de la liste positions sans contacte pour ne pas avoir de la redondance.
                // à refaire avec une fonction
                for( auto const &it : PositionSansContact)
                {
                    if(find(Resultat.begin(),Resultat.end(),it)!=Resultat.end())
                    {
                        PositionSansContact.remove(it);
                    }
                }
        }
     }
}

bool Plateau::verifierVilleComplete(size_t x, size_t y,int pos)
{
    int j=0;
    bool loopBreakerOptimiser=false;
    for(auto const &it : villesAll)
        {
        for(auto const &it2:it)
            {
            if(it2.first==board[x][y] && it2.second==pos)
                {
                loopBreakerOptimiser=true;
                break;
                }
            if(loopBreakerOptimiser){break;}
            }
        if(loopBreakerOptimiser){break;}
        j++;
        }
        bool complet=true;
        for( auto const &it :villesAll[j])
        {
        //it = ( (tuile1,9) , (tuile2,6))
        pair<int,int> a=getXYTuile(it.first);
            switch(directionPos(it.second))
            {
            case directionEnum::Top:
                if(board[a.first][a.second+1]==nullptr){complet=false;} /////////////////////////////////////////////// à voir avec la bonne direction
                break;
            case directionEnum::Right:
                if(board[a.first+1][a.second]==nullptr){complet=false;}
                break;
            case directionEnum::Bottom:
                if(board[a.first][a.second-1]==nullptr){complet=false;}
                break;
            case directionEnum::Left:
                if(board[a.first-1][a.second]==nullptr){complet=false;}
                break;
            }
        }
        return complet;
}

bool Plateau::verifierRouteComplete(size_t x, size_t y,int pos)
{
    int j=0;
    bool loopBreakerOptimiser=false;
    for(auto const &it : routesAll)
        {
        for(auto const &it2:it)
            {
            if(it2.first==board[x][y] && it2.second==pos)
                {
                loopBreakerOptimiser=true;
                break;
                }
            if(loopBreakerOptimiser){break;}
            }
        if(loopBreakerOptimiser){break;}
        j++;
        }
        bool complet=true;
        for( auto const &it :routesAll[j])
        {
        //it = ( (tuile1,9) , (tuile2,6),...)
        pair<int,int> a=getXYTuile(it.first);
            switch(directionPos(it.second))
            {
            case directionEnum::Top:
                if(board[a.first][a.second+1]==nullptr){complet=false;} /////////////////////////////////////////////// à voir avec la bonne direction
                break;
            case directionEnum::Right:
                if(board[a.first+1][a.second]==nullptr){complet=false;}
                break;
            case directionEnum::Bottom:
                if(board[a.first][a.second-1]==nullptr){complet=false;}
                break;
            case directionEnum::Left:
                if(board[a.first-1][a.second]==nullptr){complet=false;}
                break;
            }
        }
        return complet;
    
}

int Plateau::nombreRoute(size_t x, size_t y,int pos)
{
    int j=0;
    bool loopBreakerOptimiser=false;
    for(auto const &it : routesAll)
        {
        for(auto const &it2:it)
            {
            if(it2.first==board[x][y] && it2.second==pos)
                {
                loopBreakerOptimiser=true;
                break;
                }
            if(loopBreakerOptimiser){break;}
            }
        if(loopBreakerOptimiser){break;}
        j++;
        }
    vector<Tuile*> Tab;
    for( auto const &it :routesAll[j])
    {
        Tab.push_back(it.first);
    }
    Tab.erase( unique( Tab.begin(), Tab.end() ), Tab.end() );
    return Tab.size();
}

int Plateau::nombreVille(size_t x, size_t y,int pos)
{
    int j=0;
    bool loopBreakerOptimiser=false;
    for(auto const &it : villesAll)
        {
        for(auto const &it2:it)
            {
            if(it2.first==board[x][y] && it2.second==pos)
                {
                loopBreakerOptimiser=true;
                break;
                }
            if(loopBreakerOptimiser){break;}
            }
        if(loopBreakerOptimiser){break;}
        j++;
        }
    vector<Tuile*> Tab;
    for( auto const &it :villesAll[j])
    {
        Tab.push_back(it.first);
    }
    Tab.erase( unique( Tab.begin(), Tab.end() ), Tab.end() );
    return Tab.size();
}

directionEnum Plateau::directionPos(int x)
{
    if(x==0 || x==1 || x==2)
    {
        return directionEnum::Top;
    }
        if(x==3 || x==4 || x==5)
    {
        return directionEnum::Right;
    }
        if(x==6 || x==7 || x==8)
    {
        return directionEnum::Bottom;
    }
        if(x==9 || x==10 || x==11)
    {
        return directionEnum::Left;
    }
    throw PlateauException("Plateau::directionPos erreur");
}
