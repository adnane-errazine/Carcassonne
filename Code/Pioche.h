#ifndef PIOCHE_H_INCLUDED
#define PIOCHE_H_INCLUDED

//includes généraux
#include <stack>

//includes fichiers du projet
#include "Tuile.h"

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------            Classe Pioche        ---------------------------*/
//Classe qui mélange les tuile et en crée un stack dans lequel on peut piocher
//n'a aucun pouvoir sur le vie d'une tuile
//cette classe est un singleton
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
class Pioche 
{
public:
	/*  singleton   */
	//Méthode de manipulation de la pioche à utiliser à la place des constructeur/destructeur
    static Pioche* setPioche(vector<Tuile*> *p=nullptr, vector<Tuile*> *p1=nullptr, vector<Tuile*> *p2=nullptr, vector<Tuile*> *p3=nullptr);
    static Pioche* getPioche();
    static void liberePioche();
	
	/*  méthodes    */
	//méthode qui ajoute une tuile en haut de la pioche
	inline void ajouter(Tuile* tuile) { pioche.push(tuile); }
	//méthode qui permet de piocher
    Tuile* piocher();
    //vérifie si la pioche est vide
    bool estVide(){ return pioche.empty(); }
	//renvoi la taille de la pioche
    size_t taillePioche() const { return pioche.size(); }
    
    /*  getters */
    stack <Tuile*> getStack() const { return pioche; }

private:
    /*  attribut instance   */
    //pointeur sur l'unique instance de la classe
	static Pioche* instance; 
	
    /*  constructeurs   */
    //constructeur (privé)
    explicit Pioche(vector<Tuile*> *p, vector<Tuile*> *p1, vector<Tuile*> *p2, vector<Tuile*> *p3);
	//constructeur par recopie
	Pioche(const Pioche& p) = delete;
    //constructeur par affectation
	Pioche& operator=(const Pioche& p) = delete;
	
    /*  destructeur */
    ~Pioche() = default;

	/*  attributs   */
    //la pioche
	stack <Tuile*> pioche;
};

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------    Affichage Classe Pioche      ---------------------------*/
//Définition des opérateur << pour permettre d'afficher la classe Pile directement
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
ostream& operator<<(ostream& f, const stack <Tuile*>& pile);

#endif // PIOCHE_H_INCLUDED
