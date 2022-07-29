#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

//includes généraux
#include <algorithm>

//includes fichiers du projet
#include "Tuile.h"
#include "Meeple.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*---------------------------- Enumérations de la classe Joueur --------------------------*/
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//énumération qui permet de différencier un joueur d'une IA
enum class JoueursEnum{Humain,IA};

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------       Utilitaires                --------------------------*/
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//fonction qui transforme un type de joueur en string
const string toString(JoueursEnum t);

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------           Classe Joueur          --------------------------*/
//Cette classe permet la gestion des joueurs et des Meeple
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
class Joueur
{
private:
    /*  attributs   */
    string pseudo;
    CouleurEnum couleurJoueur;
    int score;
    JoueursEnum type;

    //permet au joueur de savoir quels Meeples créer
    list<Extension::Extensions> extension;

    //joueur est reponsable de la vie d'un meeple alors on fait NEW Meeple lors de la construction d'un joueur
    vector<Meeple*> meeplesUtilise; 
    vector<Meeple*> meeplesDisponible;

public:
    /*  constructeurs   */
    //constructeur
    Joueur(const string& n,const CouleurEnum& c,const JoueursEnum& J,list<Extension::Extensions> Ex);
    //constructeur par recopie
	Joueur(const Joueur& p) = delete;
	//opérateur d'affectation
	Joueur& operator=(const Joueur& p) = delete;

	/*  destructeur */
    ~Joueur();

    /*  getters */
    const string& getPseudo() const {return pseudo;}
    int getScore() const {return score;}
    CouleurEnum getCouleurJoueur() const {return couleurJoueur;}
    JoueursEnum getTypeJoueur() const { return type; }
    const vector<Meeple*>& getMeeplesUtilise() const { return meeplesUtilise; }
    const vector<Meeple*>& getMeeplesDisponible() const { return meeplesDisponible; }

    /*  setters */
    void setPseudo(string s){pseudo=s;}
    void setScore(int a){score=a;}
    void addScore(int a){score+=a;}

    /*  méthodes de gestion des Meeples */
    //grand Meeple
    int nombreMeepleGrandDisponible();
    bool meepleGrand_est_Disponible(){return nombreMeepleGrandDisponible()!=0;}
    int nombreMeepleGrandUtilise();
    //bool meepleGrandUtilise(){return nombreMeepleGrandUtilise()!=0;}
    
    //Meeples normal
    int nombreMeepleNormalUtilise();
    //bool meepleNormalUtilise(){return nombreMeepleNormalUtilise()!=0;}
    int nombreMeepleNormalDisponible();
    bool meepleNormal_est_Disponible(){return nombreMeepleNormalDisponible()!=0;}
    
    //Meeples Abbe
    int nombreMeepleAbbeDisponible();
    bool meepleAbbe_est_Disponible(){return nombreMeepleAbbeDisponible()!=0;}
    int nombreMeepleAbbeUtilise();
    //bool meepleAbbeUtilie(){return nombreMeepleAbbeUtilise()!=0;}
    
    //poser un Meeple
    void poserMeepleGrand();
    void poserMeepleNormal();
    void poserMeepleAbbe();
    
    //récupérer un Meeple
    void recupererMeepleGrand();
    void recupererMeepleNormal();
    void recupererMeepleAbbe();
};

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------    Affichage Classe Joueur      ---------------------------*/
//Définition des opérateur << pour permettre d'afficher la classe Joueur directement
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
ostream& operator<<(ostream& f, const Joueur& joueur);
ostream& operator<<(ostream& f, const vector<Meeple*>& vMeeple);
ostream& operator<<(ostream& f, const Meeple& meeple);


#endif // JOUEUR_H_INCLUDED