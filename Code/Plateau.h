#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

//includes généraux

//includes fichiers du projet
#include "Tuile.h"


using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*---------------------------- Enumérations de la classe Plateau--------------------------*/
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//énumération des directions
enum class directionEnum{Right,Left,Top,Bottom};




////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------           Classe Plateau        ---------------------------*/
//Cette classe permet à la classe Tuile de throw des exceptions
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
class Plateau {
private:
	/*  attributs   */
    //Plateau de jeu contenant les tuiles posées
	vector<vector<Tuile*>> board;
    //taille du plateau
    size_t x;
	size_t y;

    //vecteurs qui contiennent des listes de chaque élément crée par les joueurs (chaque route à une liste, prairies, ville, ...)
	vector<list<pair<Tuile*,int>>> routesAll;
	vector<list<pair<Tuile*,int>>> prairiesAll;
	vector<list<pair<Tuile*,int>>> rivieresAll;
	vector<list<pair<Tuile*,int>>> villesAll;

    //permet au plateau de savoir les Meeples posés, le joueur qui l'a posé et la position exact du meeple (int étant la position du meeple sur la tuile)
	map<CouleurEnum,list<pair<pair<Tuile*,int>,meepleEnum>>> meeplesPose;

public:
	/*  constructeurs   */
	//constructeur : tout est initialisé à nullptr
    Plateau(); 

    //constructeur par recopie
	Plateau(const Plateau& p) = default;

	//opérateur d'affectation
	Plateau& operator=(const Plateau& p) = default;

	/*  destructeur */
	~Plateau() = default;
	
	/*  getters */
	//récupérer la taille du plateau
    size_t getSizeX() const { return x; }
	size_t getSizeY() const { return y; }
	
    //récupérer la position d'une tuile
    pair<int,int> getXYTuile(Tuile* t) const;
    //récupérer une tuile à partir de sa position
    Tuile * getTuileXY(size_t x, size_t y) const;
	//permet de savoir si une tuile est sur le plateau
	bool estSurPlateau(Tuile* t) const;
	//permet de savoir si il y a un meeple sur une tuile à une position donnée (certains arguments sont voués au retour)
	bool hayMeeple(Tuile* tile, int position, CouleurEnum& retourCouleurJ, meepleEnum& retourTypeM) const;	

    //getter du plateau
    const vector<vector<Tuile*>>& getPlateau() const { return board; };

	//getter des meeples posés
	const map<CouleurEnum,list<pair<pair<Tuile*,int>,meepleEnum>>>& getMeeplesPose() const { return meeplesPose; }

    /*  méthodes    */
	//permet de  savoir si le plateau est vide
	bool estVide() const;

	//Ajouter une tuile au plateau (coordonnées)
	void ajouter(Tuile* t, size_t x, size_t y);

	//vérification qu'il y a au moins une tuile adjacente à des coordonnées
	bool tuileAdjacente(size_t x, size_t y);
	//test de la compatibilité d'une tuile à des coordonnées du plateau
    bool verifRiver(size_t x, size_t y, Tuile * t);
	bool estCompatible(size_t x, size_t y,Tuile * t);

    //permet d'agrandir la matrice d'une taille t dans les 4 directions (si on arrive au bout de celui-ci)
	void agrandir(size_t t);

	//méthodes  qui facilite l'implémentation de l'automatisation du jeu (comptage, ...)
	void updateAllTerrains(size_t x, size_t y);
	bool verifierVilleComplete(size_t x, size_t y,int pos);
	bool verifierRouteComplete(size_t x, size_t y,int pos);
	int nombreRoute(size_t x, size_t y,int pos);
	int nombreVille(size_t x, size_t y,int pos);
	/*  utilitaires */
    //utilisée dans verifierVilleComplete
	directionEnum directionPos(int x);

	//manipuler meeple
	void addMeeple(CouleurEnum C,Tuile* T,int pos, meepleEnum typeMeeple);
	void retirerMeeple(CouleurEnum C,Tuile* T,int pos, meepleEnum typeMeeple);
};

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------    Affichage Classe Plateau     ---------------------------*/
//Définition des opérateur << pour permettre d'afficher la classe Plateau directement
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
ostream& operator<<(ostream& f, const Plateau& plateau);
ostream& operator<<(ostream& f, const map<CouleurEnum,list<pair<pair<Tuile*,int>,meepleEnum>>>& lMeeple);



#endif // PLATEAU_H_INCLUDED
