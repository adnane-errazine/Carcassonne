#ifndef TUILE_H_INCLUDED
#define TUILE_H_INCLUDED
//includes généraux
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <utility>
#include <algorithm>
#include <map>
#include <fstream>
//#include <time.h>

//includes fichiers du projet

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------            Classe Log           ---------------------------*/
//complémentaire aux exceptions la classe log permet de créer un fichier log lors de l'exécution du programm
//on pourra ensuite écrire dans ce fichier (permet d'avoir des traces de l'exécution, voir dans quelles méthodes on est passé, les valeur de certaines variables, ...)
//permet de ne pas surcharger le terminal (notamment lorsau'on testera le jeu)
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//cette classe est un singleton
class Log
{
public :
    /*  singleton   */
    //méthode qui permet de créer l'unique objet log et de logger des messages dans le fichier de log
    static Log* log(const string& msg);
    //surcharge de la méthode précédente (sans arguments)
    static Log* log();
	//méthode qui permet de supprimer l'objet (elle ferme le fichier avant)
    static void fermerLog();

    /*  methodes    */
    //fichier dans lequel on écrit (il est publique, ce qui permet d'écrire n'importe quoi qui a un operator<< de défini
    static fstream flog;

private :
    /*  attribut instance   */
    //pointeur sur l'unique instance de la classe
    static Log * instance;

    /*  constructeurs   */
    //constructeur de log
    Log();
	
    //constructeur par recopie
    Log(const Log& f) = delete;

    //constructeur par affectation
	Log& operator=(const Log& f) = delete;
	
    /*  destructeur */
    ~Log();

    /*  autres méthodes */
    //méthode qui permet d'écrire dans le fichier de log tout en vérifiant si il est bien ouvert
    void ecrire(const string& msg);
    //méthode qui ferme le fichier
    void fermer() { flog.close(); }
};

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*---------------------------- Enumérations de la classe Tuile ---------------------------*/
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//énumération des extensions au sein d'un namespace
namespace Extension{
    enum class Extensions{Classique,Riviere,Auberges_cathedrales,Paysans,Abbe};
}

//énumération permettant de distinguer les différents meeples
enum class meepleEnum{Grand,Normal,Abbe};

//énumération qui donne les couleurs qui peuvent être attribuées aux joueurs
enum class CouleurEnum{rouge,mauve,vert,bleu};

//énumération des différents types de terrains que l'on peut retrouver au sein d'une tuile
enum class Terrain{Route, Ville, Prairie, Riviere, Abbaye, CroisementFerme};

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------    Utilitaires       ---------------------------*/
//fonctions utiles à des méthodes/fonctions (conversions par exemple)
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//fonction qui transforme un terrain en string
//pas besoin de mettre const après la méthodes car n'appartenant pas à la classe elle ne pourra pas modifier les attributs de la tuils
const string toString(Terrain t);
//fonction qui transforme une couleur en string
const string toString(CouleurEnum c);
//fonction qui transforme un meeple en string
const string toString(meepleEnum m);

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------     Classe JeuException       ---------------------------*/
//Cette classe permet throw des exceptions sur le classe Jeu
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
class JeuException
{
public:
	JeuException(const string& i) :info(i) {}
	string getInfo() const { return info; }
private:
	string info;
};

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------     Classe TuileException       ---------------------------*/
//Cette classe permet throw des exceptions sur le classe Tuile
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
class TuileException
{
public:
	TuileException(const string& i) :info(i) {}
	string getInfo() const { return info; }
private:
	string info;
};

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------     Classe PiocheException       ---------------------------*/
//Cette classe permet throw des exceptions sur le classe Pioche
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
class PiocheException
{
public:
	PiocheException(const string& i) :info(i) {}
	string getInfo() const { return info; }
private:
	string info;
};

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------     Classe PlateauException       ---------------------------*/
//Cette classe permet throw des exceptions sur le classe Plateau
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
class PlateauException
{
public:
	PlateauException(const string& i) :info(i) {}
	string getInfo() const { return info; }
private:
	string info;
};

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------     Classe JoueurException       ---------------------------*/
//Cette classe permet throw des exceptions sur les classes Joueur et Meeple
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
class JoueurException
{
public:
	JoueurException(const string& i) :info(i) {}
	string getInfo() const { return info; }
private:
	string info;
};

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------     Classe ControleurException  ---------------------------*/
//Cette classe permet throw des exceptions sur les classes Controleur
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
class ControleurException
{
public:
	ControleurException(const string& i) :info(i) {}
	string getInfo() const { return info; }
private:
	string info;
};


////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------           Classe Tuile          ---------------------------*/
//définition de la classe Tuile
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
class Tuile
{
private:
    /*  attributs privés de la classe  Tuile */
    //vector contenant 13 éléments qui permet de déterminer la manière dont est divisée une tuile
    vector<Terrain> positions;
    //stock les positions des blasons
    list<int> blasons; 
    //stock les positions des jardins
    list<int> jardin;
    //stock les position des auberge
    list<int> auberge; 
    // stock les cathédrale
    list<int> cathedrale;
    //vector qui contient une liste par prairie différente 
    vector<list<int>> prairies;
    //vector qui contient une liste par route différente
    vector<list<int>> routes;
    //vector qui contient une liste par rivière différente
    vector<list<int>> rivieres;
    //vector qui contient une liste par ville différente
    vector<list<int>> villes;

public:
    /*  Constructeurs / Destructeurs    */
	//constructeur
    explicit Tuile(vector<Terrain> pos) : positions(pos) { if ( !testTuile() ) TuileException("Tuile incorrecte (constructeur)"); }
    //constructeur par recopie
    Tuile(const Tuile& a);
    //opérateur d'affectation
    Tuile& operator=(const Tuile& a);
    //destructeur
    ~Tuile() = default;

    /*  Getters */
    const vector<Terrain>& getPositions() const { return this->positions; }
    Terrain getPositionX(int x) const { return positions[x]; }
    //getters qui renvoient l'équivalent de leur attribut dans tuile avec en plus un pointeur
    //vers la tuile pour chaque élément (en utilisant pair)
    vector<list<pair<Tuile*,int>>> getPrairies();
    vector<list<pair<Tuile*,int>>> getRoutes();
    vector<list<pair<Tuile*,int>>> getRivieres();
    vector<list<pair<Tuile*,int>>> getVilles();

    /*  getters des attributs   */
    const list<int> getBlasons() const { return blasons; }
    const list<int> getJardin() const { return jardin; }
    const list<int> getAuberge() const { return auberge; }
    const list<int> getCathedrale() const { return cathedrale; }
    const vector<list<int>> getnPrairies() const { return prairies; }
    const vector<list<int>> getnRoutes() const { return routes; }
    const vector<list<int>> getnRivieres() const { return rivieres; }
    const vector<list<int>> getnVilles() const { return villes; }

    /*  Setters */
    void setPrairies(vector<list<int>> p){ prairies = p; testTuile(); }
    void setRoutes(vector<list<int>> r){ routes = r; testTuile(); }
    void setVilles(vector<list<int>> v){ villes = v; testTuile(); }
    void setRivieres(vector<list<int>> r){ rivieres = r; testTuile(); }
    
    void setBlasons(list<int> b){ blasons = b; testTuile(); }
    void setBlasons(int x)
    {
        list<int> T;
        T.push_back(x);
        setBlasons(T);
        testTuile();
    }

    void setJardin(list<int> j){ jardin = j; testTuile(); }
    void setJardin(int x)
    {
        list<int> T;
        T.push_back(x);
        setJardin(T);
        testTuile();
    }

    void setAuberge(list<int> a){ auberge = a; testTuile(); }
    void setAuberge(int x)
    {
        list<int> T;
        T.push_back(x);
        setAuberge(T);
        testTuile();
    }

    void setCathedrale(list<int> c){ cathedrale = c; testTuile(); }
    void setCathedrale(int x)
    {
        list<int> T;
        T.push_back(x);
        setCathedrale(T);
        testTuile();
    }


    /*  Autres méthodes */
    //permet de faire tourner la tuile 1 fois vers la gauche
    void rotationGauche();
    //méthode qui vériie qu'une Tuile est correct (par rapport à notre implémentation)
    //elle regarde si les attributs de la Tuile contiennent des valeurs cohérentes avec le sujet
    bool testTuile() const;
};

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------    Affichage Classe Tuile       ---------------------------*/
//Déclaration des opérateur << pour permettre d'afficher la classe  Tuile directement
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//affichage des terrains
ostream& operator<<(ostream& f, const Terrain myField);
//affichage du vecteur terrain
ostream& operator<<(ostream& f, const vector<Terrain>& myVector);
//affichage de la tuile
ostream& operator<<(ostream& f, const Tuile& myTile);
//affichage des listes de terrain
ostream& operator<<(ostream& f, const vector<list<int>>& myTile);
//affichage des listes de terrain
ostream& operator<<(ostream& f, const list<int>& myTile);

#endif // TUILE_H_INCLUDED
