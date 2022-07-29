//includes généraux

//includes fichiers du projet
#include "Tuile.h"
#include <ostream>

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------    Utilitaires       ---------------------------*/
//fonctions utiles à des méthodes/fonctions (conversions par exemple)
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//fonction qui transforme un terrain en string
const string toString(Terrain t)
{
    switch (t) {
        case Terrain::Abbaye : return "Abbaye";
        case Terrain::Prairie : return "Prairie";
        case Terrain::Riviere : return "Riviere";
        case Terrain::Route : return "Route";
        case Terrain::Ville : return "Ville";
        case Terrain::CroisementFerme : return "Village";
        default: throw TuileException("toString function problem");
    }
}

//fonction qui transforme une couleur en string
const string toString(CouleurEnum c)
{
    switch (c) {
        case CouleurEnum::bleu : return "Bleu";
        case CouleurEnum::mauve : return "Mauve";
        case CouleurEnum::rouge : return "Rouge";
        case CouleurEnum::vert : return "Vert";
        default: throw TuileException("toString function problem");
    }
}

//fonction qui transforme un meeple en string
const string toString(meepleEnum m)
{
    switch (m) {
        case meepleEnum::Abbe : return "Abbé";
        case meepleEnum::Grand : return "Géant";
        case meepleEnum::Normal : return "Normal";
        default: throw TuileException("toString function problem");
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------    Affichage Classe Tuile       ---------------------------*/
//Définition des opérateur << pour permettre d'afficher la classe  Tuile directement
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/* operator << sur un Terrain */
ostream& operator<<(ostream& f, const Terrain myField)
{
    f << toString(myField);
    return f;
}

/* operator << sur un vector<Terrain> */
ostream& operator<<(ostream& f, const vector<Terrain>& myVector)
{
    int j = 0;
    for(Terrain i : myVector)
      f << j++ << " = " << i << endl;
    return f;
}

/* operator << sur une Tuile */
ostream& operator<<(ostream& f, const Tuile& myTile)
{
    f << myTile.getPositions();
    return f;
}

//affichage des listes de terrain
ostream& operator<<(ostream& f, const vector<list<int>>& myTile)
{
    for (auto it: myTile)
        f << it << endl;
    return f;
}

//affichage des listes de terrain
ostream& operator<<(ostream& f, const list<int>& myTile)
{
    f << "[";
    for(auto i : myTile)
      f << i << ";";
    f << "]" << endl;
    return f;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------      Constructeurs de Tuile       -------------------------*/
//définition des constructeurs de Tuile
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//définition du constructeur par recopie de Tuile
Tuile::Tuile(const Tuile& a)
{
    //on recrée juste les attributs de l'autre tuile et on les met dans la nouvelle
    positions = a.positions;
    blasons = a.blasons;
    jardin = a.jardin;
    auberge = a.auberge;
    cathedrale = a.cathedrale;
    prairies = a.prairies;
    routes = a.routes;
    rivieres = a.rivieres;
    villes = a.villes;
    if ( !testTuile() )
        TuileException("Tuile incorrecte (constructeur de recopie)");
}

//définition du constructeur par affectation de Tuile
Tuile& Tuile::operator=(const Tuile& a)
{
    if (this != &a)
    {
    //on recrée juste les attributs de l'autre tuile et on les met dans la nouvelle
        positions = a.positions;
        blasons = a.blasons;
        jardin = a.jardin;
        auberge = a.auberge;
        cathedrale = a.cathedrale;
        prairies = a.prairies;
        routes = a.routes;
        rivieres = a.rivieres;
        villes = a.villes;
    }
    if ( !testTuile() )
        TuileException("Tuile incorrecte (operator=)");
    return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------      Getters de Tuile       -------------------------*/
//définition des getters de Tuile
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//renvoi l'équivalent de l'attribut praire avec en plus un pointeur vers la tuile pour chaque élément en utilisant pair 
vector<list<pair<Tuile*,int>>> Tuile::getPrairies()
{
    vector<list<pair<Tuile*,int>>> _prairies;
    for (auto const& it : prairies)
    {
        list<pair<Tuile*,int>> A;
        for(auto const& it2 : it)
        {
            A.push_back(make_pair(this,it2));
        }
        _prairies.push_back(A);
    }
    return _prairies;
}

//renvoi l'équivalent de l'attribut routes avec en plus un pointeur vers la tuile pour chaque élément en utilisant pair
vector<list<pair<Tuile*,int>>> Tuile::getRoutes()
{
    vector<list<pair<Tuile*,int>>> _routes;
    for (auto const& it : routes)
    {
        list<pair<Tuile*,int>> A;
        for(auto const& it2 : it)
        {
            A.push_back(make_pair(this,it2));
        }
        _routes.push_back(A);
    }
    return _routes;
}

//renvoi l'équivalent de l'attribut rivieres avec en plus un pointeur vers la tuile pour chaque élément en utilisant pair
vector<list<pair<Tuile*,int>>> Tuile::getRivieres()
{
    vector<list<pair<Tuile*,int>>> _rivieres;
    for (auto const& it : rivieres)
    {
        list<pair<Tuile*,int>> A;
        for(auto const& it2 : it)
        {
            A.push_back(make_pair(this,it2));
        }
        _rivieres.push_back(A);
    }
    return _rivieres;
}

//renvoi l'équivalent de l'attribut villes avec en plus un pointeur vers la tuile pour chaque élément en utilisant pair
vector<list<pair<Tuile*,int>>> Tuile::getVilles()
{

    vector<list<pair<Tuile*,int>>> _villes;
    for (auto const& it : villes)
    {
        list<pair<Tuile*,int>> A;
        for(auto const& it2 : it)
        {
            A.push_back(make_pair(this,it2));
        }
        _villes.push_back(A);
    }
    return _villes;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------      Rotation d'une Tuile         -------------------------*/
//méthode permettant de faire la rotation d'une tuile (vers la gauche)
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
void Tuile::rotationGauche()
{
    //rotation de l'attribut positions
    vector<Terrain> p2(positions);
    for(int i=0;i<12;i++)
    {
        p2[i]=positions[(i+3)%12];
    }

    //rotation de l'attribut blasons
    for(auto& it2 : blasons)
    {
        it2=((it2-3) % 12 + 12) % 12;
    }

    //rotation de l'attribut jardin
    for(auto& it2 : jardin)
    {
        it2=((it2-3) % 12 + 12) % 12;
    }

    //rotation de l'attribut auberge
    for(auto& it2 : auberge)
    {
        it2=((it2-3) % 12 + 12) % 12;
    }

    //rotation de l'attribut cathedrale
    for(auto& it2 : cathedrale)
    {
        it2=((it2-3) % 12 + 12) % 12;
    }

    //rotation de l'attribut prairies
    vector<list<int>> prairiesTempo(prairies);
    for(auto &  it : prairiesTempo)
    {
        for(auto& it2 : it)
        {
            it2=((it2-3) % 12 + 12) % 12;
        }
    }

    //rotation de l'atribut routes
    vector<list<int>> routesTempo(routes);
    for(auto &  it : routesTempo)
    {
        for(auto& it2 : it)
        {
            it2=((it2-3) % 12 + 12) % 12;
        }
}

//rotation de l'attribut villes
vector<list<int>> villesTempo(villes);
for(auto &  it : villesTempo)
{
    for(auto& it2 : it)
    {
        it2=((it2-3) % 12 + 12) % 12;
    }
}

//rotation de l'attribut rivieres
vector<list<int>> rivieresTempo(rivieres);
for(auto &  it : rivieresTempo)
{
    for(auto& it2 : it)
    {
        it2=((it2-3) % 12 + 12) % 12;
    }
}

//mise à jour des attributs
positions  = p2;
prairies = prairiesTempo;
routes = routesTempo;
rivieres = rivieresTempo;
villes = villesTempo;
if ( !testTuile() )
    TuileException("Tuile incorrecte (post rotation)");
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------      Test d'une Tuile             -------------------------*/
//méthode qui vériie qu'une Tuile est correct (par rapport à notre implémentation)
//elle regarde si les attributs de la Tuile contiennent des valeurs cohérentes avec le sujet
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
bool Tuile::testTuile() const
{
    bool retour = true;
    //test de l'attribut positions (on test juste sa taille puisque sont contenu est déjà correct (enum class Terrain))
    if (positions.size() != 13)
    {
        throw TuileException("Taille de l'attribut positions de Tuile incorrect");
        retour = false;
    }

    //test de l'attribut blasons (on vérifie que les blasons sont bien à une position valide de la Tuile [0,12])
    for (auto const it : blasons)
    {
        if (it < 0 || it > 12)
        {
            throw TuileException("Un blason de la tuile n'est pas positioné correctement");
            retour = false;
        }
    }

    //test de l'attribut jardin (on vérifie que les jardins sont bien à une position valide de la Tuile [0,12])
    for (auto const it : jardin)
    {
        if (it < 0 || it > 12)
        {
            throw TuileException("Un jardin de la tuile n'est pas positioné correctement");
            retour = false;
        }
    }

    //test de l'attribut auberge (on vérifie que les auberges sont bien à une position valide de la Tuile [0,12])
    for (auto const it : auberge)
    {
        if (it < 0 || it > 12)
        {
            throw TuileException("Une auberge de la tuile n'est pas positionée correctement");
            retour = false;
        }
    }

    //test de l'attribut cathedrale (on vérifie que les cathedrales sont bien à une position valide de la Tuile [0,12])
    for (auto const it : cathedrale)
    {
        if (it < 0 || it > 12)
        {
            throw TuileException("Une cathedrale de la tuile n'est pas positionée correctement");
            retour = false;
        }
    }

    //test de l'attribut prairies (on vérifie que les prairies sont bien à une position valide de la Tuile [0,12])
    for (auto const& it : prairies)
    {
        for(auto const it2 : it)
        {
            if (it2 < 0 || it2 > 12)
            {
                throw TuileException("Une prairie de la tuile n'est pas positionée correctement");
                retour = false;
            }
        }
    }

    //test de l'attribut routes (on vérifie que les routes sont bien à une position valide de la Tuile [0,12])
    for (auto const& it : routes)
    {
        for(auto const it2 : it)
        {
            if (it2 < 0 || it2 > 12)
            {
                throw TuileException("Une route de la tuile n'est pas positionée correctement");
                retour = false;
            }
        }
    }

    //test de l'attribut rivieres (on vérifie que les rivieres sont bien à une position valide de la Tuile [0,12])
    for (auto const& it : rivieres)
    {
        for(auto const it2 : it)
        {
            if (it2 < 0 || it2 > 12)
            {
                throw TuileException("Une riviere de la tuile n'est pas positionée correctement");
                retour = false;
            }
        }
    }

    //test de l'attribut villes (on vérifie que les villes sont bien à une position valide de la Tuile [0,12])
    for (auto const& it : villes)
    {
        for(auto const it2 : it)
        {
            if (it2 < 0 || it2 > 12)
            {
                throw TuileException("Une ville de la tuile n'est pas positionée correctement");
                retour = false;
            }
        }
    }

    return retour;
}

////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
/*----------------------------            Classe Log           ---------------------------*/
//complémentaire aux exceptions la classe log permet de créer un fichier log lors de l'exécution du programm
//on pourra ensuite écrire dans ce fichier (permet d'avoir des traces de l'exécution, voir dans quelles méthodes on est passé, les valeur de certaines variables, ...)
//permet de ne pas surcharger le terminal (notamment lorsau'on testera le jeu)
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
//initialisation de l'instance à nullptr
Log * Log::instance = nullptr;
fstream Log::flog;


//méthode de création de Log (permet aussi d'écrire des messages dans le fichier de log)
Log* Log::log(const string& msg)
{
    //si l'objet n'a pas encore été crée on le crée
    if (!instance)
        instance = new Log();

    //écriture du message dans le fichier
    instance->ecrire(msg);

    //retour de l'instance
    return instance;
}

Log* Log::log()
{
    const string msg = "";
    //si l'objet n'a pas encore été crée on le crée
    if (!instance)
        instance = new Log();

    //écriture du message dans le fichier
    instance->ecrire(msg);

    //retour de l'instance
    return instance;
}


//méthode de destruction de l'objet (ferme le fichier avant)
void Log::fermerLog()
{
    if (instance)
        delete instance;
}

//constructeur
Log::Log()
    {
        //création du nom du fichier de log (horodatage)
        //declaring argument of time()
//        time_t my_time = time(NULL);
//        auto heure = ctime(&my_time);
        string filename = "LogFile";
        //int i = 0;
//        while( heure[i] != '\0' )
//        {
//            if ( heure[i] == ' ' || heure[i] == '\n' )
//                filename += '_';
//            else
//                filename += heure[i];
//            i++;
//        }
        filename += ".txt";

        //ouverture du fichier
        flog.open(filename, fstream::out);

        //ecriture dans le fichier (permet aussi de vérifier si il est bien ouvert)
        ecrire("Ouverture du fichier de log");
        
    }

//destructeur de Log
Log::~Log()
{
    ecrire("Fermeture du fichier de log");
    flog.close();
}

//méthode qui permet d'écrire dans le fichier de log tout en vérifiant si il est bien ouvert
void Log::ecrire(const string& msg)
    {   
        if (!flog.is_open()) {
            throw TuileException("Le fichier de log n'est pas ouvert et une tentative d'écriture à été faite !");
        } else {
            flog << msg << endl;
        }
    }
