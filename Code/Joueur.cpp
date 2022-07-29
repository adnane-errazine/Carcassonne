//includes généraux

//includes fichiers du projet
#include "Tuile.h"
#include "Joueur.h"

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------       Utilitaires                --------------------------*/
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//fonction qui transforme une un type de joueur en string
const string toString(JoueursEnum t)
{
    switch (t) 
    {
        case JoueursEnum::Humain : return "Humain";
        case JoueursEnum::IA : return "Ordi";
        default: throw JoueurException("toString function problem");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------    Affichage Classe Joueur      ---------------------------*/
//Définition des opérateur << pour permettre d'afficher la classe Joueur directement
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
ostream& operator<<(ostream& f, const Joueur& joueur)
{
    f << "Joueur " << toString(joueur.getCouleurJoueur()) << " (" << toString(joueur.getTypeJoueur()) << ")" << " : " << endl;
    f << "  Nom : " << joueur.getPseudo() << endl;
    f << "  Score : " << joueur.getScore() << endl;
    return f;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------    Affichage Classe Meeple      ---------------------------*/
//Définition des opérateur << pour permettre d'afficher la classe Meeple directement
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
ostream& operator<<(ostream& f, const vector<Meeple*>& vMeeple)
{
    f << "[";
    for ( auto it: vMeeple )
    {
        f << *it << ";";
    }
    f << "]" << endl;
    return f;
}

ostream& operator<<(ostream& f, const Meeple& meeple)
{
    f << meeple.getType();
    return f;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*---------------------- Constructeur de Joueur                      ---------------------*/
//définition méthodes de création de Joueur
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
Joueur::Joueur(const string& n,const CouleurEnum& c,const JoueursEnum& t,list<Extension::Extensions> Ex): pseudo(n), couleurJoueur(c), score(0), type(t)
{
    //on crée des variables qui permettent de savoir les extensions choisies
    bool Classiq = false;
    bool Auber_cathed = false;
    bool Abb = false;
    for(auto it : Ex)
    {
        if(it==Extension::Extensions::Classique){Classiq=true;}
        if(it==Extension::Extensions::Auberges_cathedrales){Auber_cathed=true;}
        if(it==Extension::Extensions::Abbe){Abb=true;}
    }

    //création des meeples pour l'extention classique
    if ( Classiq)
    {
        for(size_t i=0;i<7;i++)
        {
                MeepleNormal* T = new MeepleNormal(couleurJoueur);
                meeplesDisponible.push_back(T);
        }
    }

    //création des meeples pour l'extention auberge et cathédrales
    if(Auber_cathed)
    {
        MeepleGrand* T1 = new MeepleGrand(couleurJoueur);
        meeplesDisponible.push_back(T1);
    }

    //création des meeples pour l'extention l'Abbé
    if(Abb)
    {
        MeepleAbbe* T2 = new MeepleAbbe(couleurJoueur);
        meeplesDisponible.push_back(T2);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------  Destructeur de Joueur                      ---------------------*/
//définition méthodes de destruction de Joueur
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
Joueur::~Joueur()
{
    for(size_t i=0;i<meeplesDisponible.size();++i)
    {
        delete meeplesDisponible[i];
    }

    for(size_t i=0;i<meeplesUtilise.size();++i)
    {
        delete meeplesUtilise[i];
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------  Gestion des Grands Meeples                 ---------------------*/
//définition méthodes de Gestion des Grands Meeples  
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//renvoi le nombre de Grands meeples dispos
int Joueur::nombreMeepleGrandDisponible()
{   int i=0;
    for (const auto& it : meeplesDisponible )
    {
        const MeepleGrand* pt = dynamic_cast<const MeepleGrand*> (it);
        if(pt != nullptr){++i;}
    }
    return i;
}

//renvoi le nombre de grands meeples utilisés
int Joueur::nombreMeepleGrandUtilise()
{   int i=0;
    for (const auto& it : meeplesDisponible )
    {
        const MeepleGrand* pt = dynamic_cast<const MeepleGrand*> (it);
        if(pt != nullptr){++i;}
    }
    return i;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------  Gestion des Meeples Normaux                ---------------------*/
//définition méthodes de Gestion des Meeples normaux  
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//renvoi le nombre de normal meeples dispos
int Joueur::nombreMeepleNormalDisponible()
{   int i=0;
    for (const auto& it : meeplesDisponible )
    {
        auto pt = dynamic_cast<const MeepleNormal*> (it);
        if(pt != nullptr){++i;}
    }
    return i;
}

//renvoi le nombre de normal meeples utilisés
int Joueur::nombreMeepleNormalUtilise()
{   int i=0;
    for (const auto& it : meeplesUtilise )
    {
        auto pt = dynamic_cast<const MeepleNormal*> (it);
        if(pt != nullptr){++i;}
    }
    return i;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------  Gestion des Meeples Abbés                  ---------------------*/
//définition méthodes de Gestion des Meeples abbés 
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//renvoi le nombre de abbé meeples dispos
int Joueur::nombreMeepleAbbeUtilise()
{   int i=0;
    for (const auto& it : meeplesUtilise )
    {
        auto pt = dynamic_cast<const MeepleAbbe*> (it);
        if(pt != nullptr){++i;}
    }
    return i;
}

//renvoi le nombre de abbé meeples utilisés
int Joueur::nombreMeepleAbbeDisponible()
{   int i=0;
    for (const auto& it : meeplesDisponible )
    {
        auto pt = dynamic_cast<const MeepleAbbe*> (it);
        if(pt != nullptr){++i;}
    }
    return i;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------  Poser des Meeples                          ---------------------*/
//définition méthodes de pose de Meeples 
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

//poser des Meeples abbe
void Joueur::poserMeepleAbbe()
{
    MeepleAbbe* pt=nullptr;
    for ( auto& it:meeplesDisponible)
    {
         pt = dynamic_cast< MeepleAbbe*> (it);
         if(pt!=nullptr)
         {
             meeplesDisponible.erase(remove(meeplesDisponible.begin(), meeplesDisponible.end(), pt), meeplesDisponible.end());
             break;
         }
    }
    meeplesUtilise.push_back(pt);

    //si le meeple n'a pas été trouvé on génère une erreur
    if (!pt) { throw JoueurException("Un abbé à voulu être placé mais il n'a pas été trouvé dans les meeple dispos"); }
}

//poser des meeples normaux
void Joueur::poserMeepleNormal()
{
    MeepleNormal* pt=nullptr;
    for ( auto& it:meeplesDisponible)
    {
         pt = dynamic_cast< MeepleNormal*> (it);
         if(pt!=nullptr)
         {
             meeplesDisponible.erase(remove(meeplesDisponible.begin(), meeplesDisponible.end(), pt), meeplesDisponible.end());
             break;
         }
    }
    meeplesUtilise.push_back(pt);
    //si le meeple n'a pas été trouvé on génère une erreur
    if (!pt) { throw JoueurException("Un meeple normal à voulu être placé mais il n'a pas été trouvé dans les meeple dispos"); }
}

//poser des grands meeples
void Joueur::poserMeepleGrand()
{
    MeepleGrand* pt=nullptr;
    for ( auto& it:meeplesDisponible)
    {
         pt = dynamic_cast< MeepleGrand*> (it);
         if(pt!=nullptr)
         {
             meeplesDisponible.erase(remove(meeplesDisponible.begin(), meeplesDisponible.end(), pt), meeplesDisponible.end());
             break;
         }
    }
    meeplesUtilise.push_back(pt);
    if (!pt) { throw JoueurException("Un meeple géant à voulu être placé mais il n'a pas été trouvé dans les meeple dispos"); }
}


////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------  Récupérer des Meeples                      ---------------------*/
//définition méthodes de récupération de Meeples
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////

//récupération de Meeples abbé
void Joueur::recupererMeepleAbbe()
{
    MeepleAbbe* pt=nullptr;
    for ( auto& it:meeplesUtilise)
    {
         pt = dynamic_cast< MeepleAbbe*> (it);
         if(pt!=nullptr)
         {
             meeplesUtilise.erase(remove(meeplesUtilise.begin(), meeplesUtilise.end(), pt), meeplesUtilise.end());
             break;
         }
    }
    meeplesDisponible.push_back(pt);
    if (!pt) { throw JoueurException("Un Abbé à voulu être retiré mais il n'a pas été trouvé dans les meeple utilisés"); }
}

//récupération de grands meeples
void Joueur::recupererMeepleGrand()
{
    MeepleGrand* pt=nullptr;
    for ( auto& it:meeplesUtilise)
    {
         pt = dynamic_cast< MeepleGrand*> (it);
         if(pt!=nullptr)
         {
             meeplesUtilise.erase(remove(meeplesUtilise.begin(), meeplesUtilise.end(), pt), meeplesUtilise.end());
             break;
         }
    }
    meeplesDisponible.push_back(pt);
    if (!pt) { throw JoueurException("Un grand meeple à voulu être retiré mais il n'a pas été trouvé dans les meeple utilisés"); }
}

//récupération de meeples normaux
void Joueur::recupererMeepleNormal()
{
    MeepleNormal* pt=nullptr;
    for ( auto& it:meeplesUtilise)
    {
         pt = dynamic_cast< MeepleNormal*> (it);
         if(pt!=nullptr)
         {
             meeplesUtilise.erase(remove(meeplesUtilise.begin(), meeplesUtilise.end(), pt), meeplesUtilise.end());
             break;
         }
    }
    meeplesDisponible.push_back(pt);
    if (!pt) { throw JoueurException("Un meeple normals à voulu être retiré mais il n'a pas été trouvé dans les meeple utilisés"); }
}

