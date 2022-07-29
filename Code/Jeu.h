#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

//includes généraux

//includes fichiers du projet
#include "Tuile.h"


using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------            Classe Jeu           ---------------------------*/
//C'est la classe qui crée toutes les Tuiles (selon les extensions choisies, ce qu'elle prend en paramètres)
//la classe possède un attribut par groupe de Tuile ajouté par une extension
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
class Jeu 
{
public:
	/*  singleton   */
    //méthode de création de l'objet jeu
	static Jeu* getJeu(list<Extension::Extensions> extensions);
	static Jeu* getJeu();
	//destruction de l'instance de Jeu
    static void libereJeu();

	/*	attributs	*/
	//taille du dictionnaire (fixe)
	static const size_t T_DICO = 102;
	
private:
    /*  attribut instance   */
    // pointeur sur l'unique instance de la classe
    static Jeu* instance; 

	/*  constructeurs    */
	//constructeur 
    explicit Jeu(list<Extension::Extensions> extensions);
	//constructeur par recopie
	Jeu(const Jeu& j) = delete;
    //constructeur par afectation
	Jeu& operator=(const Jeu& j) = delete;
    
    /*  destructeur */
	//lors de la destruction de Jeu, il faut s'asurer que les objets utilisant les Tuiles (tout ce que jeu génère) sont bien supprimés / réinitialisés
    ~Jeu();

    /*  attributs   */
    //Tuiles du jeu de base
	vector<Tuile*> classique;
    //Tuiles de l'extension rivière 
	vector<Tuile*> riviere; 
    //Tuiles de l'extension Auberge & Cathédrale
	vector<Tuile*> auberge; 
    //Tuiles de l'extension paysan
	vector<Tuile*> paysan; 
    //Tuiles de l'extension abbé
	vector<Tuile*> abbe; 

    //dictionnaire de correspondance entre l'adresse d'une tuile et son id unique (int)
    array<Tuile*, T_DICO> dictionnaire;

    /*  méthodes de génération des tuiles (définies dans ensembleTuiles.cpp)   */
	//Fonction génératrice des Tuiles du jeu de base
    void tuilesClassique(); 
    //Fonction génératrice de l'extension rivière
	void tuilesRiviere(); 
    //Fonction génératrice des Tuiles de l'extension Auberge & Cathédrale
	void tuilesAuberge(); 
    //Fonction génératrice des Tuiles de l'extension paysan
	void tuilesPaysan(); 
    //Fonction génératrice des Tuiles de l'extension abbé
	void tuilesAbbe();

public:
	/*  Getters */
    //paquets de Tuiles
	vector<Tuile*>* getTuilesClassique();
	vector<Tuile*>* getTuilesRiviere();
	vector<Tuile*>* getTuilesAuberge();
	vector<Tuile*>* getTuilesPaysan();
	vector<Tuile*>* getTuilesAbbe();
    
	//getters pour le dictionnaire
	Tuile* IDToTuile(size_t i) { return dictionnaire[i]; }
	size_t tuileToID(Tuile * t) 
	{
		if (t)
		{
			for (size_t i = 0; i < T_DICO; i++)
			{
				if (t == IDToTuile(i)) return i;
			}
			throw JeuException("Tuile pas dans le dictionnaire");
		}
		//si le pointeur est nullptr on renvoi 0 (c'est un id de tuile mais tant pis (vu qu'on a des size_t on peut pas mettre -1)
		return 0; 
	}

	//dictionnaire de correspondance Tuile* -> id de la Tuile
    array<Tuile*, T_DICO> getDictionnaire();

	
};

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------    Affichage Classe Jeu	       ---------------------------*/
//Déclaration des opérateur << pour permettre d'afficher la classe  Jeu directement
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//affichage des vecteurs de Tuiles
ostream& operator<<(ostream& f, const vector<Tuile*> tuiles);
//affichage du dictionnaire
ostream& operator<<(ostream& f, const array<Tuile*, Jeu::T_DICO> dico);



#endif // JEU_H_INCLUDED
