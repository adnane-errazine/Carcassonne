#ifndef CONTROLEUR_H_INCLUDED
#define CONTROLEUR_H_INCLUDED

//includes généraux

//includes fichiers du projet
#include "Tuile.h"
#include "Jeu.h"
#include "Pioche.h"
#include "Plateau.h"
#include "Joueur.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*---------------------------- Classe Controleur                --------------------------*/
//Controleur est la classe qui gère le bon déroulement de Carcassonne. 
//Elle crée les objets necessaires à une partie et permet de jouer une partie de A à Z
//Certaines méthodes sont implémentées pour faire fonctionner le jeu en lignes de commandes mais l'objectif de cette classe reste de faire tourner le jeu en version graphique;
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
class Controleur
{
private:
    /*  attributs   */
	//le plateau de jeu
	Plateau plateau;
	//les listes de tuiles
	Jeu *jeu;
	//la liste des extensions
	list<Extension::Extensions> extensions;
	//liste des joueurs d'une partie
	list<Joueur*> joueurs;
	//la pioche actuelle (l'objet est détruit et recrée au cours d'une même partie)
	Pioche *pioche;

public:
    /*  constructeurs   */
	//constructeur (la pioche et les joueurs ne sont pas initialisés ils le seront dans la méthode partie())
    Controleur(list<Extension::Extensions> gameExtensions) : plateau(), jeu(Jeu::getJeu(gameExtensions)), extensions(gameExtensions) {
        if(!jeu->getTuilesRiviere()->empty()){
            pioche=Pioche::setPioche(jeu->getTuilesRiviere());
        }
        else if(!jeu->getTuilesClassique()->empty()){
            pioche=Pioche::setPioche(jeu->getTuilesClassique());
        }
        else
            throw ControleurException("Pas de Tuiles pour init la pioche!");
    }
	
    //constructeur par recopie
	Controleur(const Controleur& c) = delete;

	//opérateur d'affectation
	Controleur& operator=(const Controleur& c) = delete;

	/*  destructeur */
	~Controleur() 
    { 
        pioche->liberePioche();
        jeu->libereJeu();
    }

	/*  getters */
    //renvoi le plateau (pas fait pour le modifier)
    Plateau& getPlateau(){ return plateau; }
    //renvoi le jeu (pas fait pour être modifié)
    const Jeu* getJeu() const { return jeu; }
    //renvoi les extensions (pas fait pour être modifié)
    const list<Extension::Extensions>& getExtensions() const { return extensions; }
    //renvoi les joueurs (pas fait pour être modifié)
    const list<Joueur*>& getJoueurs() const { return joueurs; }
    //renvoi la pioche actuelle (pas faite pour être modifié)
    const Pioche* getPioche() const { return pioche; }
    //renvoi un joueur selon sa couleur
    Joueur* getJoueurs(const CouleurEnum& C);
    
    /*  méthodes de gestion de la partie    */
    //méthode qui gère une partie
    void partie();
    //initialisation des joueurs d'une partie
	void initJoueurs();
    //méthode qui gère un tour (actuellement non utilisée / non implémentée (la méthode partie fait le travail)
	void tour(Joueur* joueur);
	// manipulation Meeple
	bool poserMeeple(Tuile* T,int pos,Joueur* j,meepleEnum MT);
	bool retirerMeeple(Tuile* T,int pos,Joueur *j,meepleEnum MT);
	
    /*  méthodes de la partie graphique */
    void getWindowDialogueInfo(const string& J1, const string &C1, const bool T1);
	//void getWindowDialogueInfo(const string& J1,const CouleurEnum& C1,const JoueursEnum& T1,const string& J2,const CouleurEnum& C2,const JoueursEnum& T2,const string& J3,const CouleurEnum& C3,const JoueursEnum& T3);
	//void getWindowDialogueInfo(const string& J1,const CouleurEnum& C1,const JoueursEnum& T1,const string& J2,const CouleurEnum& C2,const JoueursEnum& T2);
	
	/*  méthodes pour jouer en commandline */
	//initialisation des joueurs d'une partie
	void initJoueursCmdLine();
	//méthode qui permet la saisie de coordonnées de placemet d'une tuile
	void saisieCoosCmdLine( int& x, int& y, int& r, Tuile* aposer);
	//méthode pour les Meeples
	void poseMeepleCmdLine(Tuile* tile, Joueur* joueur);
	void retraitMeepleCmdLine();
    //méthode qui gère une partie
    void partieCmdLine();
	//autres méthodes
    bool bruteForcePoseSNAIL( int& x, int& y, int& r, Tuile* aposer);
	void bruteForcePoseMeeple(Tuile* tile, Joueur* joueur);

    //Methodes pour la partie graphique
    private:
    std::list<Joueur*>::const_iterator currentPlayer;

    public:
    auto getFirstPlayer() const {return joueurs.begin();}
    Joueur* getcurrentPlayer(){return *currentPlayer;}
    void nextPlayer();
    Tuile* piocher(){return pioche->piocher();}
    void setPioche(Pioche* p){pioche=p;}
    bool recallMeeple(size_t x, size_t y, size_t score);
    bool isMeeplerecallable(size_t x, size_t y);
    bool bruteForcePoseMeepleG(Tuile* tile, Joueur* joueur, int& positionMgraph, meepleEnum& typeMeeplegraph);
};

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------    Affichage Classe Controleur  ---------------------------*/
//Définition des opérateur << pour permettre d'afficher la classe Controleur directement
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
ostream& operator<<(ostream& f, const list<Joueur*>& joueurs);

#endif // CONTROLEUR_H_INCLUDED
