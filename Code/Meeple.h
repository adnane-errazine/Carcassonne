#ifndef MEEPLE_H_INCLUDED
#define MEEPLE_H_INCLUDED

//includes généraux

//includes fichiers du projet
#include "Tuile.h"



using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------          Classe Meeple           --------------------------*/
//Cette classe permet à la classe Joueur de jouer différents types Meeples (héritage)
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*  classe mère */
class Meeple
{
private:
    //à priori cet attribut n'est pas necessaire pour les extensions demandés, mais c'est potentiellement utile pour d'autres, notamment un échange temporaire des meeples.
    CouleurEnum couleurMeeple;

public:
    Meeple(CouleurEnum c):couleurMeeple(c){ }
    CouleurEnum getCouleurMeeple(){return couleurMeeple;}
    void setCouleurMeeple(CouleurEnum c){couleurMeeple=c;}
    virtual ~Meeple(){}
    virtual int getPoids()=0;
    virtual string getType() const=0;
};

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------     Classe héritée de Meeple     --------------------------*/
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
class MeepleGrand : public Meeple
{
private:
    int Poids=2;

public:
    MeepleGrand(CouleurEnum c):Meeple(c){}
    ~MeepleGrand(){}
    int getPoids() override {return Poids;}
    string getType() const override { return "Grand"; }
};

class MeepleNormal : public Meeple
{
private:
    int Poids=1;

public:
    MeepleNormal(CouleurEnum c):Meeple(c){}
    ~MeepleNormal(){}
    int getPoids() override {return Poids;}
    string getType() const override { return "Normal"; }
};

class MeepleAbbe : public Meeple
{
private:
    int Poids=1;

public:
    MeepleAbbe(CouleurEnum c):Meeple(c){}
    ~MeepleAbbe(){}
    int getPoids() override {return Poids;}
    string getType() const override { return "Abbé"; }
};

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------    Affichage Classe Meeple      ---------------------------*/
//Définition des opérateur << pour permettre d'afficher la classe Meeple directement
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
ostream& operator<<(ostream& f, const Meeple& meeple);

#endif // MEEPLE_H_INCLUDED