//includes généraux

//includes fichiers du projet
#include "Jeu.h"
#include "Tuile.h"

void Jeu::tuilesClassique() {
   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //A
    vector<Terrain> V_A;
    V_A.push_back(Terrain::Prairie); // 0
    V_A.push_back(Terrain::Prairie); // 1
    V_A.push_back(Terrain::Prairie); // 2
    V_A.push_back(Terrain::Prairie); // 3
    V_A.push_back(Terrain::Prairie); // 4
    V_A.push_back(Terrain::Prairie); // 5
    V_A.push_back(Terrain::Prairie); // 6
    V_A.push_back(Terrain::Route);   // 7
    V_A.push_back(Terrain::Prairie); // 8
    V_A.push_back(Terrain::Prairie);  // 9
    V_A.push_back(Terrain::Prairie);  // 10
    V_A.push_back(Terrain::Prairie);  // 11
    V_A.push_back(Terrain::Abbaye);  // 12
    Tuile* A = new Tuile(V_A);
    vector<list<int>> _prairiesA;
    vector<list<int>> _routesA;
    list<int> LP1A;
    LP1A.push_back(0);
    LP1A.push_back(1);
    LP1A.push_back(2);
    LP1A.push_back(3);
    LP1A.push_back(4);
    LP1A.push_back(5);
    LP1A.push_back(6);
    LP1A.push_back(8);
    LP1A.push_back(9);
    LP1A.push_back(10);
    LP1A.push_back(11);
    _prairiesA.push_back(LP1A);
    A->setPrairies(_prairiesA);
    list<int> LR1A;
    LR1A.push_back(7);
    _routesA.push_back(LR1A);
    A->setRoutes(_routesA);
    list<int> LA_A;
    LA_A.push_back(12);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //B
    vector<Terrain> V_B;
    V_B.push_back(Terrain::Prairie); // 0
    V_B.push_back(Terrain::Prairie); // 1
    V_B.push_back(Terrain::Prairie); // 2
    V_B.push_back(Terrain::Prairie); // 3
    V_B.push_back(Terrain::Prairie); // 4
    V_B.push_back(Terrain::Prairie); // 5
    V_B.push_back(Terrain::Prairie); // 6
    V_B.push_back(Terrain::Prairie); // 7
    V_B.push_back(Terrain::Prairie); // 8
    V_B.push_back(Terrain::Prairie); // 9
    V_B.push_back(Terrain::Prairie); // 10
    V_B.push_back(Terrain::Prairie); // 11
    V_B.push_back(Terrain::Abbaye);  // 12
    Tuile* B = new Tuile(V_B);
    vector<list<int>> _prairies_B;
    list<int> LP1_B;
    LP1_B.push_back(0);
    LP1_B.push_back(1);
    LP1_B.push_back(2);
    LP1_B.push_back(3);
    LP1_B.push_back(4);
    LP1_B.push_back(5);
    LP1_B.push_back(6);
    LP1_B.push_back(7);
    LP1_B.push_back(8);
    LP1_B.push_back(9);
    LP1_B.push_back(10);
    LP1_B.push_back(11);
    _prairies_B.push_back(LP1_B);
    B->setPrairies(_prairies_B);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //C
    vector<Terrain> V_C;
    V_C.push_back(Terrain::Ville); // 0
    V_C.push_back(Terrain::Ville); // 1
    V_C.push_back(Terrain::Ville); // 2
    V_C.push_back(Terrain::Ville); // 3
    V_C.push_back(Terrain::Ville); // 4
    V_C.push_back(Terrain::Ville); // 5
    V_C.push_back(Terrain::Ville); // 6
    V_C.push_back(Terrain::Ville);  // 7
    V_C.push_back(Terrain::Ville); // 8
    V_C.push_back(Terrain::Ville);  // 9
    V_C.push_back(Terrain::Ville);  // 10
    V_C.push_back(Terrain::Ville);  // 11
    V_C.push_back(Terrain::Ville);  // 12
    Tuile* C = new Tuile(V_C);
    vector<list<int>> _villes_C;
    list<int> LV1_C;
    LV1_C.push_back(0);
    LV1_C.push_back(1);
    LV1_C.push_back(2);
    LV1_C.push_back(3);
    LV1_C.push_back(4);
    LV1_C.push_back(5);
    LV1_C.push_back(6);
    LV1_C.push_back(7);
    LV1_C.push_back(8);
    LV1_C.push_back(9);
    LV1_C.push_back(10);
    LV1_C.push_back(11);
    LV1_C.push_back(12);
    _villes_C.push_back(LV1_C);
    C->setVilles(_villes_C);
    C->setBlasons(1);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //D
    vector<Terrain> V_D;
    V_D.push_back(Terrain::Ville); // 0
    V_D.push_back(Terrain::Ville); // 1
    V_D.push_back(Terrain::Ville); //2
    V_D.push_back(Terrain::Prairie); //3
    V_D.push_back(Terrain::Route); // 4
    V_D.push_back(Terrain::Prairie); // 5
    V_D.push_back(Terrain::Prairie); // 6
    V_D.push_back(Terrain::Prairie); // 7
    V_D.push_back(Terrain::Prairie); //8
    V_D.push_back(Terrain::Prairie); //9
    V_D.push_back(Terrain::Route); // 10
    V_D.push_back(Terrain::Prairie); // 11
    V_D.push_back(Terrain::Route); // 12
    Tuile* D = new Tuile(V_D);
    vector<list<int>> _villes_D;
    list<int> LV1_D;
    LV1_D.push_back(0);
    LV1_D.push_back(1);
    LV1_D.push_back(2);
    _villes_D.push_back(LV1_D);
    D->setVilles(_villes_D);
    vector<list<int>> _route_D;
    list<int> LR1_D;
    LR1_D.push_back(4);
    LR1_D.push_back(10);
    LR1_D.push_back(12);
    _route_D.push_back(LR1_D);
    D->setRoutes(_route_D);
    vector<list<int>> _prairies_D;
    list<int> LP1_D;
    LP1_D.push_back(5);
    LP1_D.push_back(6);
    LP1_D.push_back(7);
    LP1_D.push_back(8);
    LP1_D.push_back(9);
    list<int> LP2_D;
    LP2_D.push_back(3);
    LP2_D.push_back(11);
    _prairies_D.push_back(LP2_D);
    _prairies_D.push_back(LP1_D);
    D->setPrairies(_prairies_D);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //E
    vector<Terrain> V_E;
    V_E.push_back(Terrain::Ville); // 0
    V_E.push_back(Terrain::Ville); // 1
    V_E.push_back(Terrain::Ville); //2
    V_E.push_back(Terrain::Prairie); //3
    V_E.push_back(Terrain::Prairie); // 4
    V_E.push_back(Terrain::Prairie); // 5
    V_E.push_back(Terrain::Prairie); // 6
    V_E.push_back(Terrain::Prairie); // 7
    V_E.push_back(Terrain::Prairie); //8
    V_E.push_back(Terrain::Prairie); //9
    V_E.push_back(Terrain::Prairie); // 10
    V_E.push_back(Terrain::Prairie); // 11
    V_E.push_back(Terrain::Prairie); // 12
    Tuile* E = new Tuile(V_E);
    vector<list<int>> _villes_E;
    list<int> LV_E;
    LV_E.push_back(0);
    LV_E.push_back(1);
    LV_E.push_back(2);
    _villes_E.push_back(LV_E);
    E->setVilles(_villes_E);
    vector<list<int>> _prairies_E;
    list<int> LP1_E;
    LP1_E.push_back(3);
    LP1_E.push_back(4);
    LP1_E.push_back(5);
    LP1_E.push_back(6);
    LP1_E.push_back(7);
    LP1_E.push_back(8);
    LP1_E.push_back(9);
    LP1_E.push_back(10);
    LP1_E.push_back(11);
    _prairies_E.push_back(LP1_E);
    E->setPrairies(_prairies_E);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //F
    vector<Terrain> V_F;
    V_F.push_back(Terrain::Prairie); // 0
    V_F.push_back(Terrain::Prairie); // 1
    V_F.push_back(Terrain::Prairie); //2
    V_F.push_back(Terrain::Ville); //3
    V_F.push_back(Terrain::Ville); // 4
    V_F.push_back(Terrain::Ville); // 5
    V_F.push_back(Terrain::Prairie); // 6
    V_F.push_back(Terrain::Prairie); // 7
    V_F.push_back(Terrain::Prairie); //8
    V_F.push_back(Terrain::Ville); //9
    V_F.push_back(Terrain::Ville); // 10
    V_F.push_back(Terrain::Ville); // 11
    V_F.push_back(Terrain::Ville); // 12
    Tuile* F = new Tuile(V_F);
    vector<list<int>> _villes_F;
    list<int> LV_F;
    LV_F.push_back(3);
    LV_F.push_back(4);
    LV_F.push_back(5);
    LV_F.push_back(9);
    LV_F.push_back(10);
    LV_F.push_back(11);
    LV_F.push_back(12);
    _villes_F.push_back(LV_F);
    F->setVilles(_villes_F);
    vector<list<int>> _prairies_F;
    list<int> LP1_F;
    LP1_F.push_back(0);
    LP1_F.push_back(1);
    LP1_F.push_back(2);
    list<int> LP2_F;
    LP2_F.push_back(6);
    LP2_F.push_back(7);
    LP2_F.push_back(8);
    _prairies_F.push_back(LP1_F);
    _prairies_F.push_back(LP2_F);
    F->setPrairies(_prairies_F);
    F->setBlasons(4);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //G
    vector<Terrain> V_G;
    V_G.push_back(Terrain::Prairie); // 0
    V_G.push_back(Terrain::Prairie); // 1
    V_G.push_back(Terrain::Prairie); //2
    V_G.push_back(Terrain::Ville); //3
    V_G.push_back(Terrain::Ville); // 4
    V_G.push_back(Terrain::Ville); // 5
    V_G.push_back(Terrain::Prairie); // 6
    V_G.push_back(Terrain::Prairie); // 7
    V_G.push_back(Terrain::Prairie); //8
    V_G.push_back(Terrain::Ville); //9
    V_G.push_back(Terrain::Ville); // 10
    V_G.push_back(Terrain::Ville); // 11
    V_G.push_back(Terrain::Ville); // 12
    Tuile* G = new Tuile(V_G);
    vector<list<int>> _villes_G;
    list<int> LV_G;
    LV_G.push_back(3);
    LV_G.push_back(4);
    LV_G.push_back(5);
    LV_G.push_back(9);
    LV_G.push_back(10);
    LV_G.push_back(11);
    LV_G.push_back(12);
    _villes_G.push_back(LV_G);
    G->setVilles(_villes_G);
    vector<list<int>> _prairies_G;
    list<int> LP1_G;
    LP1_G.push_back(0);
    LP1_G.push_back(1);
    LP1_G.push_back(2);
    list<int> LP2_G;
    LP2_G.push_back(6);
    LP2_G.push_back(7);
    LP2_G.push_back(8);
    _prairies_G.push_back(LP1_G);
    _prairies_G.push_back(LP2_G);
    F->setPrairies(_prairies_G);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //H   to be continued
vector<Terrain> V_H;
    V_H.push_back(Terrain::Prairie); // 0
    V_H.push_back(Terrain::Prairie); // 1
    V_H.push_back(Terrain::Prairie); //2
    V_H.push_back(Terrain::Ville); //3
    V_H.push_back(Terrain::Ville); // 4
    V_H.push_back(Terrain::Ville); // 5
    V_H.push_back(Terrain::Prairie); // 6
    V_H.push_back(Terrain::Prairie); // 7
    V_H.push_back(Terrain::Prairie); //8
    V_H.push_back(Terrain::Ville); //9
    V_H.push_back(Terrain::Ville); // 10
    V_H.push_back(Terrain::Ville); // 11
    V_H.push_back(Terrain::Prairie); // 12
    Tuile* H = new Tuile(V_H);
    vector<list<int>> _villes_H;
    list<int> LV1_H;
    LV1_H.push_back(3);
    LV1_H.push_back(4);
    LV1_H.push_back(5);
    list<int> LV2_H;
    LV2_H.push_back(9);
    LV2_H.push_back(10);
    LV2_H.push_back(11);
    _villes_H.push_back(LV1_H);
    _villes_H.push_back(LV2_H);
    H->setVilles(_villes_H);
    vector<list<int>> _prairies_H;
    list<int> LP_H;
    LP_H.push_back(0);
    LP_H.push_back(1);
    LP_H.push_back(2);
    LP_H.push_back(6);
    LP_H.push_back(7);
    LP_H.push_back(8);
    LP_H.push_back(12);
    _prairies_H.push_back(LP_H);
    H->setPrairies(_prairies_H);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //I
    vector<Terrain> V_I;
    V_I.push_back(Terrain::Ville); // 0
    V_I.push_back(Terrain::Ville); // 1
    V_I.push_back(Terrain::Ville); //2
    V_I.push_back(Terrain::Prairie); //3
    V_I.push_back(Terrain::Prairie); // 4
    V_I.push_back(Terrain::Prairie); // 5
    V_I.push_back(Terrain::Prairie); // 6
    V_I.push_back(Terrain::Prairie); // 7
    V_I.push_back(Terrain::Prairie); //8
    V_I.push_back(Terrain::Ville); //9
    V_I.push_back(Terrain::Ville); // 10
    V_I.push_back(Terrain::Ville); // 11
    V_I.push_back(Terrain::Prairie); // 12
    Tuile* I = new Tuile(V_I);
    vector<list<int>> _villes_I;
    list<int> LV1_I;
    LV1_I.push_back(0);
    LV1_I.push_back(1);
    LV1_I.push_back(2);
    list<int> LV2_I;
    LV2_I.push_back(9);
    LV2_I.push_back(10);
    LV2_I.push_back(11);
    _villes_I.push_back(LV1_I);
    _villes_I.push_back(LV2_I);
    I->setVilles(_villes_I);
    vector<list<int>> _prairies_I;
    list<int> LP_I;
    LP_I.push_back(3);
    LP_I.push_back(4);
    LP_I.push_back(5);
    LP_I.push_back(6);
    LP_I.push_back(7);
    LP_I.push_back(8);
    LP_I.push_back(12);
    _prairies_I.push_back(LP_I);
    I->setPrairies(_prairies_I);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //J
    vector<Terrain> V_J;
    V_J.push_back(Terrain::Ville); // 0
    V_J.push_back(Terrain::Ville); // 1
    V_J.push_back(Terrain::Ville); //2
    V_J.push_back(Terrain::Prairie); //3
    V_J.push_back(Terrain::Route); // 4
    V_J.push_back(Terrain::Prairie); // 5
    V_J.push_back(Terrain::Prairie); // 6
    V_J.push_back(Terrain::Route); // 7
    V_J.push_back(Terrain::Prairie); //8
    V_J.push_back(Terrain::Prairie); //9
    V_J.push_back(Terrain::Prairie); // 10
    V_J.push_back(Terrain::Prairie); // 11
    V_J.push_back(Terrain::Route); // 12
    Tuile* J = new Tuile(V_J);
    vector<list<int>> _villes_J;
    list<int> LV_J;
    LV_J.push_back(0);
    LV_J.push_back(1);
    LV_J.push_back(2);
    _villes_J.push_back(LV_J);
    J->setVilles(_villes_J);
    vector<list<int>> _prairies_J;
    list<int> LP1_J;
    LP1_J.push_back(5);
    LP1_J.push_back(6);
    list<int> LP2_J;
    LP2_J.push_back(3);
    LP2_J.push_back(11);
    LP2_J.push_back(10);
    LP2_J.push_back(9);
    LP2_J.push_back(8);
    _prairies_J.push_back(LP1_J);
    _prairies_J.push_back(LP2_J);
    J->setPrairies(_prairies_J);
    vector<list<int>> _route_J;
    list<int> LR1_J;
    LR1_J.push_back(4);
    LR1_J.push_back(7);
    LR1_J.push_back(12);
    _route_J.push_back(LR1_J);
    J->setRoutes(_route_J);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //K
    vector<Terrain> V_K;
    V_K.push_back(Terrain::Ville); // 0
    V_K.push_back(Terrain::Ville); // 1
    V_K.push_back(Terrain::Ville); //2
    V_K.push_back(Terrain::Prairie); //3
    V_K.push_back(Terrain::Prairie); // 4
    V_K.push_back(Terrain::Prairie); // 5
    V_K.push_back(Terrain::Prairie); // 6
    V_K.push_back(Terrain::Route); // 7
    V_K.push_back(Terrain::Prairie); //8
    V_K.push_back(Terrain::Prairie); //9
    V_K.push_back(Terrain::Route); // 10
    V_K.push_back(Terrain::Prairie); // 11
    V_K.push_back(Terrain::Route); // 12
    Tuile* K = new Tuile(V_K);
    vector<list<int>> _villes_K;
    list<int> LV_K;
    LV_K.push_back(0);
    LV_K.push_back(1);
    LV_K.push_back(2);
    _villes_K.push_back(LV_K);
    K->setVilles(_villes_K);
    vector<list<int>> _prairies_K;
    list<int> LP1_K;
    LP1_K.push_back(8);
    LP1_K.push_back(9);
    list<int> LP2_K;
    LP2_K.push_back(3);
    LP2_K.push_back(4);
    LP2_K.push_back(5);
    LP2_K.push_back(6);
    LP2_K.push_back(11);
    _prairies_K.push_back(LP1_K);
    _prairies_K.push_back(LP2_K);
    K->setPrairies(_prairies_K);
    vector<list<int>> _route_K;
    list<int> LR1_K;
    LR1_K.push_back(10);
    LR1_K.push_back(7);
    LR1_K.push_back(12);
    _route_K.push_back(LR1_K);
    K->setRoutes(_route_K);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //L
    vector<Terrain> V_L;
    V_L.push_back(Terrain::Ville); // 0
    V_L.push_back(Terrain::Ville); // 1
    V_L.push_back(Terrain::Ville); //2
    V_L.push_back(Terrain::Prairie); //3
    V_L.push_back(Terrain::Route); // 4
    V_L.push_back(Terrain::Prairie); // 5
    V_L.push_back(Terrain::Prairie); // 6
    V_L.push_back(Terrain::Route); // 7
    V_L.push_back(Terrain::Prairie); //8
    V_L.push_back(Terrain::Prairie); //9
    V_L.push_back(Terrain::Route); // 10
    V_L.push_back(Terrain::Prairie); // 11
    V_L.push_back(Terrain::CroisementFerme); // 12
    Tuile* L = new Tuile(V_L);
    vector<list<int>> _villes_L;
    list<int> LV_L;
    LV_L.push_back(0);
    LV_L.push_back(1);
    LV_L.push_back(2);
    _villes_L.push_back(LV_L);
    L->setVilles(_villes_L);
    vector<list<int>> _route_L;
    list<int> LR1_L;
    LR1_L.push_back(10);
    list<int> LR2_L;
    LR2_L.push_back(7);
    list<int> LR3_L;
    LR3_L.push_back(4);
    _route_L.push_back(LR1_L);
    _route_L.push_back(LR2_L);
    _route_L.push_back(LR3_L);
    L->setRoutes(_route_L);
    vector<list<int>> _prairies_L;
    list<int> LP1_L;
    LP1_L.push_back(3);
    LP1_L.push_back(11);
    list<int> LP2_L;
    LP2_L.push_back(5);
    LP2_L.push_back(6);
    list<int> LP3_L;
    LP3_L.push_back(8);
    LP3_L.push_back(9);
    _prairies_L.push_back(LP1_L);
    _prairies_L.push_back(LP2_L);
    _prairies_L.push_back(LP3_L);
    L->setPrairies(_prairies_L);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //X
    vector<Terrain> V_X;
    V_X.push_back(Terrain::Prairie); // 0
    V_X.push_back(Terrain::Route); // 1
    V_X.push_back(Terrain::Prairie); //2
    V_X.push_back(Terrain::Prairie); //3
    V_X.push_back(Terrain::Route); // 4
    V_X.push_back(Terrain::Prairie); // 5
    V_X.push_back(Terrain::Prairie); // 6
    V_X.push_back(Terrain::Route); // 7
    V_X.push_back(Terrain::Prairie); //8
    V_X.push_back(Terrain::Prairie); //9
    V_X.push_back(Terrain::Route); // 10
    V_X.push_back(Terrain::Prairie); // 11
    V_X.push_back(Terrain::CroisementFerme); // 12
    Tuile* X = new Tuile(V_X);
    vector<list<int>> _route_X;
    list<int> LR1_X;
    LR1_X.push_back(1);
    list<int> LR2_X;
    LR2_X.push_back(4);
    list<int> LR3_X;
    LR3_X.push_back(7);
    list<int> LR4_X;
    LR4_X.push_back(10);
    _route_X.push_back(LR1_X);
    _route_X.push_back(LR2_X);
    _route_X.push_back(LR3_X);
    _route_X.push_back(LR4_X);
    X->setRoutes(_route_X);
    vector<list<int>> _prairies_X;
    list<int> LP1_X;
    LP1_X.push_back(0);
    LP1_X.push_back(11);
    list<int> LP2_X;
    LP2_X.push_back(2);
    LP2_X.push_back(3);
    list<int> LP3_X;
    LP3_X.push_back(5);
    LP3_X.push_back(6);
    list<int> LP4_X;
    LP4_X.push_back(8);
    LP4_X.push_back(9);
    _prairies_X.push_back(LP1_X);
    _prairies_X.push_back(LP2_X);
    _prairies_X.push_back(LP3_X);
    _prairies_X.push_back(LP4_X);
    X->setPrairies(_prairies_X);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //W
    vector<Terrain> V_W;
    V_W.push_back(Terrain::Prairie); // 0
    V_W.push_back(Terrain::Prairie); // 1
    V_W.push_back(Terrain::Prairie); //2
    V_W.push_back(Terrain::Prairie); //3
    V_W.push_back(Terrain::Route); // 4
    V_W.push_back(Terrain::Prairie); // 5
    V_W.push_back(Terrain::Prairie); // 6
    V_W.push_back(Terrain::Route); // 7
    V_W.push_back(Terrain::Prairie); //8
    V_W.push_back(Terrain::Prairie); //9
    V_W.push_back(Terrain::Route); // 10
    V_W.push_back(Terrain::Prairie); // 11
    V_W.push_back(Terrain::CroisementFerme); // 12
    Tuile* W = new Tuile(V_W);
    vector<list<int>> _route_W;
    list<int> LR1_W;
    LR1_W.push_back(10);
    list<int> LR2_W;
    LR2_W.push_back(4);
    list<int> LR3_W;
    LR3_W.push_back(7);
    _route_W.push_back(LR1_W);
    _route_W.push_back(LR2_W);
    _route_W.push_back(LR3_W);
    W->setRoutes(_route_W);
    vector<list<int>> _prairies_W;
    list<int> LP1_W;
    LP1_W.push_back(0);
    LP1_W.push_back(11);
    LP1_W.push_back(2);
    LP1_W.push_back(3);
    LP1_W.push_back(1);
    list<int> LP2_W;
    LP2_W.push_back(5);
    LP2_W.push_back(6);
    list<int> LP3_W;
    LP3_W.push_back(8);
    LP3_W.push_back(9);
    _prairies_W.push_back(LP1_W);
    _prairies_W.push_back(LP2_W);
    _prairies_W.push_back(LP3_W);
    W->setPrairies(_prairies_W);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //M
    vector<Terrain> V_M;
    V_M.push_back(Terrain::Ville); // 0
    V_M.push_back(Terrain::Ville); // 1
    V_M.push_back(Terrain::Ville); //2
    V_M.push_back(Terrain::Ville); //3
    V_M.push_back(Terrain::Ville); // 4
    V_M.push_back(Terrain::Ville); // 5
    V_M.push_back(Terrain::Prairie); // 6
    V_M.push_back(Terrain::Prairie); // 7
    V_M.push_back(Terrain::Prairie); //8
    V_M.push_back(Terrain::Prairie); //9
    V_M.push_back(Terrain::Prairie); // 10
    V_M.push_back(Terrain::Prairie); // 11
    V_M.push_back(Terrain::Prairie); // 12
    Tuile* M = new Tuile(V_M);
    vector<list<int>> _villes_M;
    list<int> LV_M;
    LV_M.push_back(0);
    LV_M.push_back(1);
    LV_M.push_back(2);
    LV_M.push_back(3);
    LV_M.push_back(4);
    LV_M.push_back(5);
    _villes_M.push_back(LV_M);
    M->setVilles(_villes_M);
    vector<list<int>> _prairies_M;
    list<int> LP_M;
    LP_M.push_back(6);
    LP_M.push_back(7);
    LP_M.push_back(8);
    LP_M.push_back(9);
    LP_M.push_back(10);
    LP_M.push_back(11);
    LP_M.push_back(12);
    _prairies_M.push_back(LP_M);
    M->setPrairies(_prairies_M);
    M->setBlasons(3);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //N
    vector<Terrain> V_N;
    V_N.push_back(Terrain::Ville); // 0
    V_N.push_back(Terrain::Ville); // 1
    V_N.push_back(Terrain::Ville); //2
    V_N.push_back(Terrain::Ville); //3
    V_N.push_back(Terrain::Ville); // 4
    V_N.push_back(Terrain::Ville); // 5
    V_N.push_back(Terrain::Prairie); // 6
    V_N.push_back(Terrain::Prairie); // 7
    V_N.push_back(Terrain::Prairie); //8
    V_N.push_back(Terrain::Prairie); //9
    V_N.push_back(Terrain::Prairie); // 10
    V_N.push_back(Terrain::Prairie); // 11
    V_N.push_back(Terrain::Prairie); // 12
    Tuile* N = new Tuile(V_N);
    vector<list<int>> _villes_N;
    list<int> LV_N;
    LV_N.push_back(0);
    LV_N.push_back(1);
    LV_N.push_back(2);
    LV_N.push_back(3);
    LV_N.push_back(4);
    LV_N.push_back(5);
    _villes_N.push_back(LV_N);
    N->setVilles(_villes_N);
    vector<list<int>> _prairies_N;
    list<int> LP_N;
    LP_N.push_back(6);
    LP_N.push_back(7);
    LP_N.push_back(8);
    LP_N.push_back(9);
    LP_N.push_back(10);
    LP_N.push_back(11);
    LP_N.push_back(12);
    _prairies_N.push_back(LP_N);
    N->setPrairies(_prairies_N);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //O
    vector<Terrain> V_O;
    V_O.push_back(Terrain::Ville); // 0
    V_O.push_back(Terrain::Ville); // 1
    V_O.push_back(Terrain::Ville); //2
    V_O.push_back(Terrain::Prairie); //3
    V_O.push_back(Terrain::Route); // 4
    V_O.push_back(Terrain::Prairie); // 5
    V_O.push_back(Terrain::Prairie); // 6
    V_O.push_back(Terrain::Route); // 7
    V_O.push_back(Terrain::Prairie); //8
    V_O.push_back(Terrain::Ville); //9
    V_O.push_back(Terrain::Ville); // 10
    V_O.push_back(Terrain::Ville); // 11
    V_O.push_back(Terrain::Route); // 12
    Tuile* O = new Tuile(V_O);
    vector<list<int>> _villes_O;
    list<int> LV_O;
    LV_O.push_back(0);
    LV_O.push_back(1);
    LV_O.push_back(2);
    LV_O.push_back(9);
    LV_O.push_back(10);
    LV_O.push_back(11);
    _villes_O.push_back(LV_O);
    O->setVilles(_villes_O);
    vector<list<int>> _prairies_O;
    list<int> LP1_O;
    LP1_O.push_back(3);
    LP1_O.push_back(8);
    list<int> LP2_O;
    LP2_O.push_back(5);
    LP2_O.push_back(6);
    _prairies_O.push_back(LP1_O);
    _prairies_O.push_back(LP2_O);
    O->setPrairies(_prairies_O);
    vector<list<int>> _route_O;
    list<int> LR_O;
    LR_O.push_back(4);
    LR_O.push_back(7);
    LR_O.push_back(12);
    _route_O.push_back(LR_O);
    O->setRoutes(_route_O);
    O->setBlasons(0);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //P
    vector<Terrain> V_P;
    V_P.push_back(Terrain::Ville); // 0
    V_P.push_back(Terrain::Ville); // 1
    V_P.push_back(Terrain::Ville); //2
    V_P.push_back(Terrain::Prairie); //3
    V_P.push_back(Terrain::Route); // 4
    V_P.push_back(Terrain::Prairie); // 5
    V_P.push_back(Terrain::Prairie); // 6
    V_P.push_back(Terrain::Route); // 7
    V_P.push_back(Terrain::Prairie); //8
    V_P.push_back(Terrain::Ville); //9
    V_P.push_back(Terrain::Ville); // 10
    V_P.push_back(Terrain::Ville); // 11
    V_P.push_back(Terrain::Route); // 12
    Tuile* P = new Tuile(V_P);
    vector<list<int>> _villes_P;
    list<int> LV_P;
    LV_P.push_back(0);
    LV_P.push_back(1);
    LV_P.push_back(2);
    LV_P.push_back(9);
    LV_P.push_back(10);
    LV_P.push_back(11);
    _villes_P.push_back(LV_P);
    P->setVilles(_villes_P);
    vector<list<int>> _prairies_P;
    list<int> LP1_P;
    LP1_P.push_back(3);
    LP1_P.push_back(8);
    list<int> LP2_P;
    LP2_P.push_back(5);
    LP2_P.push_back(6);
    _prairies_P.push_back(LP1_P);
    _prairies_P.push_back(LP2_P);
    P->setPrairies(_prairies_P);
    vector<list<int>> _route_P;
    list<int> LR_P;
    LR_P.push_back(4);
    LR_P.push_back(7);
    LR_P.push_back(12);
    _route_P.push_back(LR_P);
    P->setRoutes(_route_P);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Q
    vector<Terrain> V_Q;
    V_Q.push_back(Terrain::Ville); // 0
    V_Q.push_back(Terrain::Ville); // 1
    V_Q.push_back(Terrain::Ville); //2
    V_Q.push_back(Terrain::Ville); //3
    V_Q.push_back(Terrain::Ville); // 4
    V_Q.push_back(Terrain::Ville); // 5
    V_Q.push_back(Terrain::Prairie); // 6
    V_Q.push_back(Terrain::Prairie); // 7
    V_Q.push_back(Terrain::Prairie); //8
    V_Q.push_back(Terrain::Ville); //9
    V_Q.push_back(Terrain::Ville); // 10
    V_Q.push_back(Terrain::Ville); // 11
    V_Q.push_back(Terrain::Ville); // 12
    Tuile* Q = new Tuile(V_Q);
    vector<list<int>> _villes_Q;
    list<int> LV_Q;
    LV_Q.push_back(0);
    LV_Q.push_back(1);
    LV_Q.push_back(2);
    LV_Q.push_back(3);
    LV_Q.push_back(4);
    LV_Q.push_back(5);
    LV_Q.push_back(9);
    LV_Q.push_back(10);
    LV_Q.push_back(11);
    LV_Q.push_back(12);
    _villes_Q.push_back(LV_Q);
    Q->setVilles(_villes_Q);
    vector<list<int>> _prairies_Q;
    list<int> LPQ_Q;
    LPQ_Q.push_back(6);
    LPQ_Q.push_back(7);
    LPQ_Q.push_back(8);
    _prairies_Q.push_back(LPQ_Q);
    Q->setPrairies(_prairies_Q);
    Q->setBlasons(0);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //R
    vector<Terrain> V_R;
    V_R.push_back(Terrain::Ville); // 0
    V_R.push_back(Terrain::Ville); // 1
    V_R.push_back(Terrain::Ville); //2
    V_R.push_back(Terrain::Ville); //3
    V_R.push_back(Terrain::Ville); // 4
    V_R.push_back(Terrain::Ville); // 5
    V_R.push_back(Terrain::Prairie); // 6
    V_R.push_back(Terrain::Prairie); // 7
    V_R.push_back(Terrain::Prairie); //8
    V_R.push_back(Terrain::Ville); //9
    V_R.push_back(Terrain::Ville); // 10
    V_R.push_back(Terrain::Ville); // 11
    V_R.push_back(Terrain::Ville); // 12
    Tuile* R = new Tuile(V_R);
    vector<list<int>> _villes_R;
    list<int> LV_R;
    LV_R.push_back(0);
    LV_R.push_back(1);
    LV_R.push_back(2);
    LV_R.push_back(3);
    LV_R.push_back(4);
    LV_R.push_back(5);
    LV_R.push_back(9);
    LV_R.push_back(10);
    LV_R.push_back(11);
    LV_R.push_back(12);
    _villes_R.push_back(LV_R);
    R->setVilles(_villes_R);
    vector<list<int>> _prairies_R;
    list<int> LPQ_R;
    LPQ_R.push_back(6);
    LPQ_R.push_back(7);
    LPQ_R.push_back(8);
    _prairies_R.push_back(LPQ_R);
    R->setPrairies(_prairies_R);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //S
    vector<Terrain> V_S;
    V_S.push_back(Terrain::Ville); // 0
    V_S.push_back(Terrain::Ville); // 1
    V_S.push_back(Terrain::Ville); //2
    V_S.push_back(Terrain::Ville); //3
    V_S.push_back(Terrain::Ville); // 4
    V_S.push_back(Terrain::Ville); // 5
    V_S.push_back(Terrain::Prairie); // 6
    V_S.push_back(Terrain::Route); // 7
    V_S.push_back(Terrain::Prairie); //8
    V_S.push_back(Terrain::Ville); //9
    V_S.push_back(Terrain::Ville); // 10
    V_S.push_back(Terrain::Ville); // 11
    V_S.push_back(Terrain::Ville); // 12
    Tuile* S = new Tuile(V_S);
    vector<list<int>> _villes_S;
    list<int> LV_S;
    LV_S.push_back(0);
    LV_S.push_back(1);
    LV_S.push_back(2);
    LV_S.push_back(3);
    LV_S.push_back(4);
    LV_S.push_back(5);
    LV_S.push_back(9);
    LV_S.push_back(10);
    LV_S.push_back(11);
    LV_S.push_back(12);
    _villes_S.push_back(LV_S);
    S->setVilles(_villes_S);
    vector<list<int>> _prairies_S;
    list<int> LP1_S;
    LP1_S.push_back(6);
    list<int> LP2_S;
    LP2_S.push_back(8);
    _prairies_S.push_back(LP1_S);
    _prairies_S.push_back(LP2_S);
    S->setPrairies(_prairies_S);
    vector<list<int>> _route_S;
    list<int> LR_S;
    LR_S.push_back(7);
    _route_S.push_back(LR_S);
    S->setRoutes(_route_S);
    S->setBlasons(0);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //T
    vector<Terrain> V_T;
    V_T.push_back(Terrain::Ville); // 0
    V_T.push_back(Terrain::Ville); // 1
    V_T.push_back(Terrain::Ville); //2
    V_T.push_back(Terrain::Ville); //3
    V_T.push_back(Terrain::Ville); // 4
    V_T.push_back(Terrain::Ville); // 5
    V_T.push_back(Terrain::Prairie); // 6
    V_T.push_back(Terrain::Route); // 7
    V_T.push_back(Terrain::Prairie); //8
    V_T.push_back(Terrain::Ville); //9
    V_T.push_back(Terrain::Ville); // 10
    V_T.push_back(Terrain::Ville); // 11
    V_T.push_back(Terrain::Ville); // 12
    Tuile* T = new Tuile(V_T);
    vector<list<int>> _villes_T;
    list<int> LV_T;
    LV_T.push_back(0);
    LV_T.push_back(1);
    LV_T.push_back(2);
    LV_T.push_back(3);
    LV_T.push_back(4);
    LV_T.push_back(5);
    LV_T.push_back(9);
    LV_T.push_back(10);
    LV_T.push_back(11);
    LV_T.push_back(12);
    _villes_T.push_back(LV_T);
    T->setVilles(_villes_T);
    vector<list<int>> _prairies_T;
    list<int> LP1_T;
    LP1_T.push_back(6);
    list<int> LP2_T;
    LP2_T.push_back(8);
    _prairies_T.push_back(LP1_T);
    _prairies_T.push_back(LP2_T);
    T->setPrairies(_prairies_T);
    vector<list<int>> _route_T;
    list<int> LR_T;
    LR_T.push_back(7);
    _route_T.push_back(LR_T);
    T->setRoutes(_route_T);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //U
    vector<Terrain> V_U;
    V_U.push_back(Terrain::Prairie); // 0
    V_U.push_back(Terrain::Route); // 1
    V_U.push_back(Terrain::Prairie); //2
    V_U.push_back(Terrain::Prairie); //3
    V_U.push_back(Terrain::Prairie); // 4
    V_U.push_back(Terrain::Prairie); // 5
    V_U.push_back(Terrain::Prairie); // 6
    V_U.push_back(Terrain::Route); // 7
    V_U.push_back(Terrain::Prairie); //8
    V_U.push_back(Terrain::Prairie); //9
    V_U.push_back(Terrain::Prairie); // 10
    V_U.push_back(Terrain::Prairie); // 11
    V_U.push_back(Terrain::Route); // 12
    Tuile* U = new Tuile(V_U);
    vector<list<int>> _route_U;
    list<int> LR_U;
    LR_U.push_back(1);
    LR_U.push_back(12);
    LR_U.push_back(7);
    _route_U.push_back(LR_U);
    U->setRoutes(_route_U);
    vector<list<int>> _prairies_U;
    list<int> LP1_U;
    LP1_U.push_back(0);
    LP1_U.push_back(11);
    LP1_U.push_back(10);
    LP1_U.push_back(9);
    LP1_U.push_back(8);
    list<int> LP2_U;
    LP2_U.push_back(2);
    LP2_U.push_back(3);
    LP2_U.push_back(4);
    LP2_U.push_back(5);
    LP2_U.push_back(6);
    _prairies_U.push_back(LP1_U);
    _prairies_U.push_back(LP2_U);
    U->setPrairies(_prairies_U);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //V
    vector<Terrain> V_V;
    V_V.push_back(Terrain::Prairie); // 0
    V_V.push_back(Terrain::Prairie); // 1
    V_V.push_back(Terrain::Prairie); //2
    V_V.push_back(Terrain::Prairie); //3
    V_V.push_back(Terrain::Prairie); // 4
    V_V.push_back(Terrain::Prairie); // 5
    V_V.push_back(Terrain::Prairie); // 6
    V_V.push_back(Terrain::Route); // 7
    V_V.push_back(Terrain::Prairie); //8
    V_V.push_back(Terrain::Prairie); //9
    V_V.push_back(Terrain::Route); // 10
    V_V.push_back(Terrain::Prairie); // 11
    V_V.push_back(Terrain::Route); // 12
    Tuile* V = new Tuile(V_V);
    vector<list<int>> _route_V;
    list<int> LR_V;
    LR_V.push_back(10);
    LR_V.push_back(12);
    LR_V.push_back(7);
    _route_V.push_back(LR_V);
    V->setRoutes(_route_V);
    vector<list<int>> _prairies_V;
    list<int> LP1_V;
    LP1_V.push_back(11);
    LP1_V.push_back(0);
    LP1_V.push_back(1);
    LP1_V.push_back(2);
    LP1_V.push_back(3);
    LP1_V.push_back(4);
    LP1_V.push_back(5);
    LP1_V.push_back(6);
    list<int> LP2_V;
    LP2_V.push_back(8);
    LP2_V.push_back(9);
    _prairies_V.push_back(LP1_V);
    _prairies_V.push_back(LP2_V);
    V->setPrairies(_prairies_V);
/////////////////////////////////////////////////////////////////
    Tuile* A1 = new Tuile(*A);
    classique.push_back(A);
    classique.push_back(A1);
    dictionnaire[0]=A;
    dictionnaire[1]=A1;
/////////////////////////////////////////////////////////////////
    Tuile* B1 = new Tuile(*B);
    Tuile* B2 = new Tuile(*B);
    Tuile* B3 = new Tuile(*B);
    classique.push_back(B);
    classique.push_back(B1);
    classique.push_back(B2);
    classique.push_back(B3);
    dictionnaire[2]=B;
    dictionnaire[3]=B1;
    dictionnaire[4]=B2;
    dictionnaire[5]=B3;
/////////////////////////////////////////////////////////////////
    classique.push_back(C);
    dictionnaire[6]=C;
/////////////////////////////////////////////////////////////////
    Tuile* D1 = new Tuile(*D);
    Tuile* D2 = new Tuile(*D);
    Tuile* D3 = new Tuile(*D);
    classique.push_back(D);
    classique.push_back(D1);
    classique.push_back(D2);
    classique.push_back(D3);
    dictionnaire[7]=D;
    dictionnaire[8]=D1;
    dictionnaire[9]=D2;
    dictionnaire[10]=D3;
/////////////////////////////////////////////////////////////////
    Tuile* E1 = new Tuile(*E);
    Tuile* E2 = new Tuile(*E);
    Tuile* E3 = new Tuile(*E);
    Tuile* E4 = new Tuile(*E);
    classique.push_back(E);
    classique.push_back(E1);
    classique.push_back(E2);
    classique.push_back(E3);
    classique.push_back(E4);
    dictionnaire[11]=E;
    dictionnaire[12]=E1;
    dictionnaire[13]=E2;
    dictionnaire[14]=E3;
    dictionnaire[15]=E4;
/////////////////////////////////////////////////////////////////
    Tuile* F1 = new Tuile(*F);
    classique.push_back(F);
    classique.push_back(F1);
    dictionnaire[16]=F;
    dictionnaire[17]=F1;
/////////////////////////////////////////////////////////////////
    classique.push_back(G);
    dictionnaire[18]=G;
/////////////////////////////////////////////////////////////////
    Tuile* H1 = new Tuile(*H);
    Tuile* H2 = new Tuile(*H);
    classique.push_back(H);
    classique.push_back(H1);
    classique.push_back(H2);
    dictionnaire[19]=H;
    dictionnaire[20]=H1;
    dictionnaire[21]=H2;
/////////////////////////////////////////////////////////////////
    Tuile* I1 = new Tuile(*I);
    classique.push_back(I);
    classique.push_back(I1);
    dictionnaire[22]=I;
    dictionnaire[23]=I1;
/////////////////////////////////////////////////////////////////
    Tuile* J1 = new Tuile(*J);
    Tuile* J2 = new Tuile(*J);
    classique.push_back(J);
    classique.push_back(J1);
    classique.push_back(J2);
    dictionnaire[24]=J;
    dictionnaire[25]=J1;
    dictionnaire[26]=J2;
/////////////////////////////////////////////////////////////////
    Tuile* K1 = new Tuile(*K);
    Tuile* K2 = new Tuile(*K);
    classique.push_back(K);
    classique.push_back(K1);
    classique.push_back(K2);
    dictionnaire[27]=K;
    dictionnaire[28]=K1;
    dictionnaire[29]=K2;
/////////////////////////////////////////////////////////////////
    Tuile* L1 = new Tuile(*L);
    Tuile* L2 = new Tuile(*L);
    classique.push_back(L);
    classique.push_back(L1);
    classique.push_back(L2);
    dictionnaire[30]=L;
    dictionnaire[31]=L1;
    dictionnaire[32]=L2;
/////////////////////////////////////////////////////////////////
    Tuile* M1 = new Tuile(*M);
    classique.push_back(M);
    classique.push_back(M1);
    dictionnaire[33]=M;
    dictionnaire[34]=M1;
/////////////////////////////////////////////////////////////////
    Tuile* N1 = new Tuile(*N);
    Tuile* N2 = new Tuile(*N);
    classique.push_back(N);
    classique.push_back(N1);
    classique.push_back(N2);
    dictionnaire[35]=N;
    dictionnaire[36]=N1;
    dictionnaire[37]=N2;
/////////////////////////////////////////////////////////////////
    Tuile* O1 = new Tuile(*O);
    classique.push_back(O);
    classique.push_back(O1);
    dictionnaire[38]=O;
    dictionnaire[39]=O1;
/////////////////////////////////////////////////////////////////
    Tuile* P1 = new Tuile(*P);
    Tuile* P2 = new Tuile(*P);
    classique.push_back(P);
    classique.push_back(P1);
    classique.push_back(P2);
    dictionnaire[40]=P;
    dictionnaire[41]=P1;
    dictionnaire[42]=P2;
/////////////////////////////////////////////////////////////////
    classique.push_back(Q);
    dictionnaire[43]=Q;
/////////////////////////////////////////////////////////////////
    Tuile* R1 = new Tuile(*R);
    Tuile* R2 = new Tuile(*R);
    classique.push_back(R);
    classique.push_back(R1);
    classique.push_back(R2);
    dictionnaire[44]=R;
    dictionnaire[45]=R1;
    dictionnaire[46]=R2;
/////////////////////////////////////////////////////////////////
    Tuile* S1 = new Tuile(*S);
    classique.push_back(S);
    classique.push_back(S1);
    dictionnaire[47]=S;
    dictionnaire[48]=S1;
/////////////////////////////////////////////////////////////////
    classique.push_back(T);
    dictionnaire[49]=T;
/////////////////////////////////////////////////////////////////
    Tuile* U1 = new Tuile(*U);
    Tuile* U2 = new Tuile(*U);
    Tuile* U3 = new Tuile(*U);
    Tuile* U4 = new Tuile(*U);
    Tuile* U5 = new Tuile(*U);
    Tuile* U6 = new Tuile(*U);
    Tuile* U7 = new Tuile(*U);
    classique.push_back(U);
    classique.push_back(U1);
    classique.push_back(U2);
    classique.push_back(U3);
    classique.push_back(U4);
    classique.push_back(U5);
    classique.push_back(U6);
    classique.push_back(U7);
    dictionnaire[50]=U;
    dictionnaire[51]=U1;
    dictionnaire[52]=U2;
    dictionnaire[53]=U3;
    dictionnaire[54]=U4;
    dictionnaire[55]=U5;
    dictionnaire[56]=U6;
    dictionnaire[57]=U7;
/////////////////////////////////////////////////////////////////
    Tuile* V1 = new Tuile(*V);
    Tuile* V2 = new Tuile(*V);
    Tuile* V3 = new Tuile(*V);
    Tuile* V4 = new Tuile(*V);
    Tuile* V5 = new Tuile(*V);
    Tuile* V6 = new Tuile(*V);
    Tuile* V7 = new Tuile(*V);
    Tuile* V8 = new Tuile(*V);
    classique.push_back(V);
    classique.push_back(V1);
    classique.push_back(V2);
    classique.push_back(V3);
    classique.push_back(V4);
    classique.push_back(V5);
    classique.push_back(V6);
    classique.push_back(V7);
    classique.push_back(V8);
    dictionnaire[58]=V;
    dictionnaire[59]=V1;
    dictionnaire[60]=V2;
    dictionnaire[61]=V3;
    dictionnaire[62]=V4;
    dictionnaire[63]=V5;
    dictionnaire[64]=V6;
    dictionnaire[65]=V7;
    dictionnaire[66]=V8;
/////////////////////////////////////////////////////////////////
    Tuile* W1 = new Tuile(*W);
    Tuile* W2 = new Tuile(*W);
    Tuile* W3 = new Tuile(*W);
    classique.push_back(W);
    classique.push_back(W1);
    classique.push_back(W2);
    classique.push_back(W3);
    dictionnaire[67]=W;
    dictionnaire[68]=W1;
    dictionnaire[69]=W2;
    dictionnaire[70]=W3;
/////////////////////////////////////////////////////////////////
    classique.push_back(X);
    dictionnaire[71]=X;
/////////////////////////////////////////////////////////////////
}

void Jeu::tuilesRiviere() {
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //F1
    vector<Terrain> V_F1;
    V_F1.push_back(Terrain::Prairie); // 0
    V_F1.push_back(Terrain::Prairie); // 1
    V_F1.push_back(Terrain::Prairie); // 2
    V_F1.push_back(Terrain::Prairie); // 3
    V_F1.push_back(Terrain::Prairie); // 4
    V_F1.push_back(Terrain::Prairie); // 5
    V_F1.push_back(Terrain::Prairie); // 6
    V_F1.push_back(Terrain::Riviere); // 7
    V_F1.push_back(Terrain::Prairie); // 8
    V_F1.push_back(Terrain::Prairie); // 9
    V_F1.push_back(Terrain::Prairie); // 10
    V_F1.push_back(Terrain::Prairie); // 11
    V_F1.push_back(Terrain::Riviere); // 12
    Tuile* F1 = new Tuile(V_F1);
    vector<list<int>> _prairies_F1;
    list<int> LP1_F1;
    LP1_F1.push_back(0);
    LP1_F1.push_back(1);
    LP1_F1.push_back(2);
    LP1_F1.push_back(3);
    LP1_F1.push_back(4);
    LP1_F1.push_back(5);
    LP1_F1.push_back(6);
    LP1_F1.push_back(8);
    LP1_F1.push_back(9);
    LP1_F1.push_back(10);
    LP1_F1.push_back(11);
    _prairies_F1.push_back(LP1_F1);
    F1->setPrairies(_prairies_F1);
    vector<list<int>> _rivieres_F1;
    list<int> LR1_F1;
    LR1_F1.push_back(7);
    LR1_F1.push_back(12);
    _rivieres_F1.push_back(LR1_F1);
    F1->setRivieres(_rivieres_F1);

    riviere.push_back(F1);
    dictionnaire[72]=F1;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //F2
    vector<Terrain> V_F2;
    V_F2.push_back(Terrain::Ville); // 0
    V_F2.push_back(Terrain::Ville); // 1
    V_F2.push_back(Terrain::Ville); // 2
    V_F2.push_back(Terrain::Prairie); // 3
    V_F2.push_back(Terrain::Riviere); // 4
    V_F2.push_back(Terrain::Prairie); // 5
    V_F2.push_back(Terrain::Prairie); // 6
    V_F2.push_back(Terrain::Route); // 7
    V_F2.push_back(Terrain::Prairie); // 8
    V_F2.push_back(Terrain::Prairie); // 9
    V_F2.push_back(Terrain::Riviere); // 10
    V_F2.push_back(Terrain::Prairie); // 11
    V_F2.push_back(Terrain::Riviere); // 12 
    //Pos 12 : Pas besoin de dire que c'est une route car de toute façon c'est une fin de route
    Tuile* F2 = new Tuile(V_F2);
    vector<list<int>> _prairies_F2;
    list<int> LP1_F2;
    LP1_F2.push_back(3);
    list<int> LP2_F2;
    LP2_F2.push_back(5);
    LP2_F2.push_back(6);
    list<int> LP3_F2;
    LP3_F2.push_back(8);
    LP3_F2.push_back(9);
    list<int> LP4_F2;
    LP4_F2.push_back(11);
    _prairies_F2.push_back(LP1_F2);
    _prairies_F2.push_back(LP2_F2);
    _prairies_F2.push_back(LP3_F2);
    _prairies_F2.push_back(LP4_F2);
    F2->setPrairies(_prairies_F2);
    vector<list<int>> _rivieres_F2;
    list<int> LR1_F2;
    LR1_F2.push_back(4);
    LR1_F2.push_back(10);
    LR1_F2.push_back(12);
    _rivieres_F2.push_back(LR1_F2);
    F2->setRivieres(_rivieres_F2);
    vector<list<int>> _routes_F2;
    list<int> LO1_F2;
    LO1_F2.push_back(7);
    _routes_F2.push_back(LO1_F2);
    F2->setRoutes(_routes_F2);
    vector<list<int>> _villes_F2;
    list<int> LV1_F2;
    LV1_F2.push_back(0);
    LV1_F2.push_back(1);
    LV1_F2.push_back(2);
    _villes_F2.push_back(LV1_F2);
    F2->setVilles(_villes_F2);

    riviere.push_back(F2);
    dictionnaire[73]=F2;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //F3
    vector<Terrain> V_F3;
    V_F3.push_back(Terrain::Ville); // 0
    V_F3.push_back(Terrain::Ville); // 1
    V_F3.push_back(Terrain::Ville); // 2
    V_F3.push_back(Terrain::Prairie); // 3
    V_F3.push_back(Terrain::Riviere); // 4
    V_F3.push_back(Terrain::Prairie); // 5
    V_F3.push_back(Terrain::Ville); // 6
    V_F3.push_back(Terrain::Ville); // 7
    V_F3.push_back(Terrain::Ville); // 8
    V_F3.push_back(Terrain::Prairie); // 9
    V_F3.push_back(Terrain::Riviere); // 10
    V_F3.push_back(Terrain::Prairie); // 11
    V_F3.push_back(Terrain::Riviere); // 12 

    Tuile* F3 = new Tuile(V_F3);
    vector<list<int>> _prairies_F3;
    vector<list<int>> _rivieres_F3;
    vector<list<int>> _villes_F3;
    list<int> LP1_F3;
    list<int> LP2_F3;
    list<int> LR1_F3;
    list<int> LV1_F3;
    list<int> LV2_F3;
    LV1_F3.push_back(0);
    LV1_F3.push_back(1);
    LV1_F3.push_back(2);
    LP1_F3.push_back(3);
    LR1_F3.push_back(4);
    LP2_F3.push_back(5);
    LV2_F3.push_back(6);
    LV2_F3.push_back(7);
    LV2_F3.push_back(8);
    LP2_F3.push_back(9);
    LR1_F3.push_back(10);
    LP1_F3.push_back(11);
    LR1_F3.push_back(12);

    _prairies_F3.push_back(LP1_F3);
    _prairies_F3.push_back(LP2_F3);
    _rivieres_F3.push_back(LR1_F3);
    _villes_F3.push_back(LV1_F3);
    _villes_F3.push_back(LV2_F3);
    
    F3->setPrairies(_prairies_F3);
    F3->setRivieres(_rivieres_F3);
    F3->setVilles(_villes_F3);

    riviere.push_back(F3);
    dictionnaire[74]=F3;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //F4
    vector<Terrain> V_F4;
    V_F4.push_back(Terrain::Prairie); // 0
    V_F4.push_back(Terrain::Prairie); // 1
    V_F4.push_back(Terrain::Prairie); // 2
    V_F4.push_back(Terrain::Prairie); // 3
    V_F4.push_back(Terrain::Riviere); // 4
    V_F4.push_back(Terrain::Prairie); // 5
    V_F4.push_back(Terrain::Prairie); // 6
    V_F4.push_back(Terrain::Prairie); // 7
    V_F4.push_back(Terrain::Prairie); // 8
    V_F4.push_back(Terrain::Prairie); // 9
    V_F4.push_back(Terrain::Riviere); // 10
    V_F4.push_back(Terrain::Prairie); // 11
    V_F4.push_back(Terrain::Riviere); // 12 
    
    Tuile* F4 = new Tuile(V_F4);
    vector<list<int>> _prairies_F4;
    vector<list<int>> _rivieres_F4;
    list<int> LP1_F4;
    list<int> LP2_F4;
    list<int> LR1_F4;
    LP1_F4.push_back(0);
    LP1_F4.push_back(1);
    LP1_F4.push_back(2);
    LP1_F4.push_back(3);
    LR1_F4.push_back(4);
    LP2_F4.push_back(5);
    LP2_F4.push_back(6);
    LP2_F4.push_back(7);
    LP2_F4.push_back(8);
    LP2_F4.push_back(9);
    LR1_F4.push_back(10);
    LP1_F4.push_back(11);
    LR1_F4.push_back(12);

    _prairies_F4.push_back(LP1_F4);
    _prairies_F4.push_back(LP2_F4);
    _rivieres_F4.push_back(LR1_F4);
    
    F4->setPrairies(_prairies_F4);
    F4->setRivieres(_rivieres_F4);

    riviere.push_back(F4);
    dictionnaire[75]=F4;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //F5
    vector<Terrain> V_F5;
    V_F5.push_back(Terrain::Ville); // 0
    V_F5.push_back(Terrain::Ville); // 1
    V_F5.push_back(Terrain::Ville); // 2
    V_F5.push_back(Terrain::Ville); // 3
    V_F5.push_back(Terrain::Ville); // 4
    V_F5.push_back(Terrain::Ville); // 5
    V_F5.push_back(Terrain::Prairie); // 6
    V_F5.push_back(Terrain::Riviere); // 7
    V_F5.push_back(Terrain::Prairie); // 8
    V_F5.push_back(Terrain::Prairie); // 9
    V_F5.push_back(Terrain::Riviere); // 10
    V_F5.push_back(Terrain::Prairie); // 11
    V_F5.push_back(Terrain::Riviere); // 12 

    Tuile* F5 = new Tuile(V_F5);
    vector<list<int>> _prairies_F5;
    vector<list<int>> _rivieres_F5;
    vector<list<int>> _villes_F5;
    list<int> LP1_F5;
    list<int> LP2_F5;
    list<int> LR1_F5;
    list<int> LV1_F5;
    LV1_F5.push_back(0);
    LV1_F5.push_back(1);
    LV1_F5.push_back(2);
    LV1_F5.push_back(3);
    LV1_F5.push_back(4);
    LV1_F5.push_back(5);
    LP1_F5.push_back(6);
    LR1_F5.push_back(7);
    LP2_F5.push_back(8);
    LP2_F5.push_back(9);
    LR1_F5.push_back(10);
    LP1_F5.push_back(11);
    LR1_F5.push_back(12);

    _prairies_F5.push_back(LP1_F5);
    _prairies_F5.push_back(LP2_F5);
    _rivieres_F5.push_back(LR1_F5);
    _villes_F5.push_back(LV1_F5);
    
    F5->setPrairies(_prairies_F5);
    F5->setRivieres(_rivieres_F5);
    F5->setVilles(_villes_F5);

    riviere.push_back(F5);
    dictionnaire[76]=F5;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //F6
    vector<Terrain> V_F6;
    V_F6.push_back(Terrain::Prairie); // 0
    V_F6.push_back(Terrain::Riviere); // 1
    V_F6.push_back(Terrain::Prairie); // 2
    V_F6.push_back(Terrain::Prairie); // 3
    V_F6.push_back(Terrain::Prairie); // 4
    V_F6.push_back(Terrain::Prairie); // 5
    V_F6.push_back(Terrain::Prairie); // 6
    V_F6.push_back(Terrain::Riviere); // 7
    V_F6.push_back(Terrain::Prairie); // 8
    V_F6.push_back(Terrain::Prairie); // 9
    V_F6.push_back(Terrain::Prairie); // 10
    V_F6.push_back(Terrain::Prairie); // 11
    V_F6.push_back(Terrain::Riviere); // 12 

    Tuile* F6 = new Tuile(V_F6);
    vector<list<int>> _prairies_F6;
    vector<list<int>> _rivieres_F6;
    list<int> LP1_F6;
    list<int> LP2_F6;
    list<int> LR1_F6;
    LP1_F6.push_back(0);
    LR1_F6.push_back(1);
    LP2_F6.push_back(2);
    LP2_F6.push_back(3);
    LP2_F6.push_back(4);
    LP2_F6.push_back(5);
    LP2_F6.push_back(6);
    LR1_F6.push_back(7);
    LP1_F6.push_back(8);
    LP1_F6.push_back(9);
    LP1_F6.push_back(10);
    LP1_F6.push_back(11);
    LR1_F6.push_back(12);

    _prairies_F6.push_back(LP1_F6);
    _prairies_F6.push_back(LP2_F6);
    _rivieres_F6.push_back(LR1_F6);
    
    F6->setPrairies(_prairies_F6);
    F6->setRivieres(_rivieres_F6);

    riviere.push_back(F6);
    dictionnaire[77]=F6;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //F7
    vector<Terrain> V_F7;
    V_F7.push_back(Terrain::Prairie); // 0
    V_F7.push_back(Terrain::Riviere); // 1
    V_F7.push_back(Terrain::Prairie); // 2
    V_F7.push_back(Terrain::Prairie); // 3
    V_F7.push_back(Terrain::Prairie); // 4
    V_F7.push_back(Terrain::Prairie); // 5
    V_F7.push_back(Terrain::Prairie); // 6
    V_F7.push_back(Terrain::Prairie); // 7
    V_F7.push_back(Terrain::Prairie); // 8
    V_F7.push_back(Terrain::Prairie); // 9
    V_F7.push_back(Terrain::Riviere); // 10
    V_F7.push_back(Terrain::Prairie); // 11
    V_F7.push_back(Terrain::Riviere); // 12

    Tuile* F7 = new Tuile(V_F7);
    vector<list<int>> _prairies_F7;
    vector<list<int>> _rivieres_F7;
    list<int> LP1_F7;
    list<int> LP2_F7;
    list<int> LR1_F7;
    LP1_F7.push_back(0);
    LR1_F7.push_back(1);
    LP2_F7.push_back(2);
    LP2_F7.push_back(3);
    LP2_F7.push_back(4);
    LP2_F7.push_back(5);
    LP2_F7.push_back(6);
    LP2_F7.push_back(7);
    LP2_F7.push_back(8);
    LP2_F7.push_back(9);
    LR1_F7.push_back(10);
    LP1_F7.push_back(11);
    LR1_F7.push_back(12);

    _prairies_F7.push_back(LP1_F7);
    _prairies_F7.push_back(LP2_F7);
    _rivieres_F7.push_back(LR1_F7);

    F7->setPrairies(_prairies_F7);
    F7->setRivieres(_rivieres_F7);

    riviere.push_back(F7);
    dictionnaire[78]=F7;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //F8
    vector<Terrain> V_F8;
    V_F8.push_back(Terrain::Prairie); // 0
    V_F8.push_back(Terrain::Prairie); // 1
    V_F8.push_back(Terrain::Prairie); // 2
    V_F8.push_back(Terrain::Prairie); // 3
    V_F8.push_back(Terrain::Riviere); // 4
    V_F8.push_back(Terrain::Prairie); // 5
    V_F8.push_back(Terrain::Prairie); // 6
    V_F8.push_back(Terrain::Route); // 7
    V_F8.push_back(Terrain::Prairie); // 8
    V_F8.push_back(Terrain::Prairie); // 9
    V_F8.push_back(Terrain::Riviere); // 10
    V_F8.push_back(Terrain::Prairie); // 11
    V_F8.push_back(Terrain::Abbaye); // 12 

    Tuile* F8 = new Tuile(V_F8);
    vector<list<int>> _prairies_F8;
    vector<list<int>> _rivieres_F8;
    vector<list<int>> _routes_F8;
    list<int> LP1_F8;
    list<int> LP2_F8;
    list<int> LP3_F8;
    list<int> LR1_F8;
    list<int> LO1_F8;
    list<int> LA_F8;
    LP1_F8.push_back(0);
    LP1_F8.push_back(1);
    LP1_F8.push_back(2);
    LP1_F8.push_back(3);
    LR1_F8.push_back(4);
    LP2_F8.push_back(5);
    LP2_F8.push_back(6);
    LO1_F8.push_back(7);
    LP3_F8.push_back(8);
    LP3_F8.push_back(9);
    LR1_F8.push_back(10);
    LP1_F8.push_back(11);
    LA_F8.push_back(12);

    _prairies_F8.push_back(LP1_F8);
    _prairies_F8.push_back(LP2_F8);
    _prairies_F8.push_back(LP3_F8);
    _rivieres_F8.push_back(LR1_F8);
    _routes_F8.push_back(LO1_F8);

    F8->setPrairies(_prairies_F8);
    F8->setRivieres(_rivieres_F8);
    F8->setRoutes(_routes_F8);

    riviere.push_back(F8);
    dictionnaire[79]=F8;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //F9
    vector<Terrain> V_F9;
    V_F9.push_back(Terrain::Prairie); // 0
    V_F9.push_back(Terrain::Route); // 1
    V_F9.push_back(Terrain::Prairie); // 2
    V_F9.push_back(Terrain::Prairie); // 3
    V_F9.push_back(Terrain::Riviere); // 4
    V_F9.push_back(Terrain::Prairie); // 5
    V_F9.push_back(Terrain::Prairie); // 6
    V_F9.push_back(Terrain::Riviere); // 7
    V_F9.push_back(Terrain::Prairie); // 8
    V_F9.push_back(Terrain::Prairie); // 9
    V_F9.push_back(Terrain::Route); // 10
    V_F9.push_back(Terrain::Prairie); // 11
    V_F9.push_back(Terrain::Prairie); // 12 

    Tuile* F9 = new Tuile(V_F9);
    vector<list<int>> _prairies_F9;
    vector<list<int>> _rivieres_F9;
    vector<list<int>> _routes_F9;
    list<int> LP1_F9;
    list<int> LP2_F9;
    list<int> LP3_F9;
    list<int> LR1_F9;
    list<int> LO1_F9;
    LP1_F9.push_back(0);
    LO1_F9.push_back(1);
    LP2_F9.push_back(2);
    LP2_F9.push_back(3);
    LR1_F9.push_back(4);
    LP3_F9.push_back(5);
    LP3_F9.push_back(6);
    LR1_F9.push_back(7);
    LP2_F9.push_back(8);
    LP2_F9.push_back(9);
    LO1_F9.push_back(10);
    LP1_F9.push_back(11);
    LP2_F9.push_back(12);

    _prairies_F9.push_back(LP1_F9);
    _prairies_F9.push_back(LP2_F9);
    _prairies_F9.push_back(LP3_F9);
    _rivieres_F9.push_back(LR1_F9);
    _routes_F9.push_back(LO1_F9);

    F9->setPrairies(_prairies_F9);
    F9->setRivieres(_rivieres_F9);
    F9->setRoutes(_routes_F9);

    riviere.push_back(F9);
    dictionnaire[80]=F9;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //F10
    vector<Terrain> V_F10;
    V_F10.push_back(Terrain::Prairie); // 0
    V_F10.push_back(Terrain::Prairie); // 1
    V_F10.push_back(Terrain::Prairie); // 2
    V_F10.push_back(Terrain::Prairie); // 3
    V_F10.push_back(Terrain::Riviere); // 4
    V_F10.push_back(Terrain::Prairie); // 5
    V_F10.push_back(Terrain::Prairie); // 6
    V_F10.push_back(Terrain::Riviere); // 7
    V_F10.push_back(Terrain::Prairie); // 8
    V_F10.push_back(Terrain::Prairie); // 9
    V_F10.push_back(Terrain::Prairie); // 10
    V_F10.push_back(Terrain::Prairie); // 11
    V_F10.push_back(Terrain::Riviere); // 12 

    Tuile* F10 = new Tuile(V_F10);
    vector<list<int>> _prairies_F10;
    vector<list<int>> _rivieres_F10;
    list<int> LP1_F10;
    list<int> LP2_F10;
    list<int> LR1_F10;
    LP1_F10.push_back(0);
    LP1_F10.push_back(1);
    LP1_F10.push_back(2);
    LP1_F10.push_back(3);
    LR1_F10.push_back(4);
    LP2_F10.push_back(5);
    LP2_F10.push_back(6);
    LR1_F10.push_back(7);
    LP1_F10.push_back(8);
    LP1_F10.push_back(9);
    LP1_F10.push_back(10);
    LP1_F10.push_back(11);
    LR1_F10.push_back(12);

    _prairies_F10.push_back(LP1_F10);
    _prairies_F10.push_back(LP2_F10);
    _rivieres_F10.push_back(LR1_F10);

    F10->setPrairies(_prairies_F10);
    F10->setRivieres(_rivieres_F10);

    F10->setJardin(0);

    riviere.push_back(F10);
    dictionnaire[81]=F10;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //F11
    vector<Terrain> V_F11;
    V_F11.push_back(Terrain::Prairie); // 0
    V_F11.push_back(Terrain::Riviere); // 1
    V_F11.push_back(Terrain::Prairie); // 2
    V_F11.push_back(Terrain::Prairie); // 3
    V_F11.push_back(Terrain::Route); // 4
    V_F11.push_back(Terrain::Prairie); // 5
    V_F11.push_back(Terrain::Prairie); // 6
    V_F11.push_back(Terrain::Riviere); // 7
    V_F11.push_back(Terrain::Prairie); // 8
    V_F11.push_back(Terrain::Prairie); // 9
    V_F11.push_back(Terrain::Route); // 10
    V_F11.push_back(Terrain::Prairie); // 11
    V_F11.push_back(Terrain::Route); // 12 

    Tuile* F11 = new Tuile(V_F11);
    vector<list<int>> _prairies_F11;
    vector<list<int>> _rivieres_F11;
    vector<list<int>> _routes_F11;
    list<int> LP1_F11;
    list<int> LP2_F11;
    list<int> LP3_F11;
    list<int> LP4_F11;
    list<int> LO1_F11;
    list<int> LR1_F11;
    LP1_F11.push_back(0);
    LR1_F11.push_back(1);
    LP2_F11.push_back(2);
    LP2_F11.push_back(3);
    LO1_F11.push_back(4);
    LP3_F11.push_back(5);
    LP3_F11.push_back(6);
    LR1_F11.push_back(7);
    LP4_F11.push_back(8);
    LP4_F11.push_back(9);
    LO1_F11.push_back(10);
    LP1_F11.push_back(11);
    LO1_F11.push_back(12);
    LR1_F11.push_back(12);

    _prairies_F11.push_back(LP1_F11);
    _prairies_F11.push_back(LP2_F11);
    _prairies_F11.push_back(LP3_F11);
    _prairies_F11.push_back(LP4_F11);
    _routes_F11.push_back(LO1_F11);
    _rivieres_F11.push_back(LR1_F11);

    F11->setPrairies(_prairies_F11);
    F11->setRivieres(_rivieres_F11);
    F11->setRoutes(_routes_F11);

    riviere.push_back(F11);
    dictionnaire[82]=F11;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //F12
    vector<Terrain> V_F12;
    V_F12.push_back(Terrain::Prairie); // 0
    V_F12.push_back(Terrain::Prairie); // 1
    V_F12.push_back(Terrain::Prairie); // 2
    V_F12.push_back(Terrain::Prairie); // 3
    V_F12.push_back(Terrain::Prairie); // 4
    V_F12.push_back(Terrain::Prairie); // 5
    V_F12.push_back(Terrain::Prairie); // 6
    V_F12.push_back(Terrain::Riviere); // 7
    V_F12.push_back(Terrain::Prairie); // 8
    V_F12.push_back(Terrain::Prairie); // 9
    V_F12.push_back(Terrain::Prairie); // 10
    V_F12.push_back(Terrain::Prairie); // 11
    V_F12.push_back(Terrain::Riviere); // 12 

    Tuile* F12 = new Tuile(V_F12);
    vector<list<int>> _prairies_F12;
    vector<list<int>> _rivieres_F12;
    list<int> LP1_F12;
    list<int> LR1_F12;
    LP1_F12.push_back(0);
    LP1_F12.push_back(1);
    LP1_F12.push_back(2);
    LP1_F12.push_back(3);
    LP1_F12.push_back(4);
    LP1_F12.push_back(5);
    LP1_F12.push_back(6);
    LR1_F12.push_back(7);
    LP1_F12.push_back(8);
    LP1_F12.push_back(9);
    LP1_F12.push_back(10);
    LP1_F12.push_back(11);
    LR1_F12.push_back(12);

    _prairies_F12.push_back(LP1_F12);
    _rivieres_F12.push_back(LR1_F12);

    F12->setPrairies(_prairies_F12);
    F12->setRivieres(_rivieres_F12);

    riviere.push_back(F12);
    dictionnaire[83]=F12;
}

void Jeu::tuilesAuberge() {
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//////// EA

    vector<Terrain> V_EA;
    V_EA.push_back(Terrain::Prairie); // 0
    V_EA.push_back(Terrain::Prairie); // 1
    V_EA.push_back(Terrain::Prairie); //2
    V_EA.push_back(Terrain::Prairie); //3
    V_EA.push_back(Terrain::Prairie); // 4
    V_EA.push_back(Terrain::Prairie); // 5
    V_EA.push_back(Terrain::Prairie); // 6
    V_EA.push_back(Terrain::Route); // 7
    V_EA.push_back(Terrain::Prairie); //8
    V_EA.push_back(Terrain::Prairie); //9
    V_EA.push_back(Terrain::Route); // 10
    V_EA.push_back(Terrain::Prairie); // 11
    V_EA.push_back(Terrain::Route); // 12
    Tuile* EA = new Tuile(V_EA);
    vector<list<int>> _route_EA;
    list<int> LR_EA;
    LR_EA.push_back(10);
    LR_EA.push_back(12);
    LR_EA.push_back(7);
    _route_EA.push_back(LR_EA);
    EA->setRoutes(_route_EA);
    vector<list<int>> _prairies_EA;
    list<int> LP1_EA;
    LP1_EA.push_back(0);
    LP1_EA.push_back(1);
    LP1_EA.push_back(2);
    LP1_EA.push_back(3);
    LP1_EA.push_back(4);
    LP1_EA.push_back(5);
    LP1_EA.push_back(6);
    LP1_EA.push_back(11);
    list<int> LP2_EA;
    LP2_EA.push_back(8);
    LP2_EA.push_back(9);
    _prairies_EA.push_back(LP1_EA);
    _prairies_EA.push_back(LP2_EA);
    EA->setPrairies(_prairies_EA);
    EA->setAuberge(1);
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//////// EB
    vector<Terrain> V_EB;
    V_EB.push_back(Terrain::Prairie); // 0
    V_EB.push_back(Terrain::Prairie); // 1
    V_EB.push_back(Terrain::Prairie); //2
    V_EB.push_back(Terrain::Prairie); //3
    V_EB.push_back(Terrain::Route); // 4
    V_EB.push_back(Terrain::Prairie); // 5
    V_EB.push_back(Terrain::Prairie); // 6
    V_EB.push_back(Terrain::Prairie); // 7
    V_EB.push_back(Terrain::Prairie); //8
    V_EB.push_back(Terrain::Prairie); //9
    V_EB.push_back(Terrain::Route); // 10
    V_EB.push_back(Terrain::Prairie); // 11
    V_EB.push_back(Terrain::Route); // 12
    Tuile* EB = new Tuile(V_EB);
    vector<list<int>> _route_EB;
    list<int> LR_EB;
    LR_EB.push_back(10);
    LR_EB.push_back(12);
    LR_EB.push_back(4);
    _route_EB.push_back(LR_EB);
    EB->setRoutes(_route_EB);
    vector<list<int>> _prairies_EB;
    list<int> LP1_EB;
    LP1_EB.push_back(0);
    LP1_EB.push_back(1);
    LP1_EB.push_back(2);
    LP1_EB.push_back(3);
    LP1_EB.push_back(11);
    list<int> LP2_EB;
    LP2_EB.push_back(6);
    LP2_EB.push_back(5);
    LP2_EB.push_back(7);
    LP2_EB.push_back(8);
    LP2_EB.push_back(9);
    _prairies_EB.push_back(LP1_EB);
    _prairies_EB.push_back(LP2_EB);
    EB->setPrairies(_prairies_EB);
    EB->setJardin(6);
    EB->setAuberge(1);
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//////// EC
    vector<Terrain> V_EC;
    V_EC.push_back(Terrain::Prairie); // 0
    V_EC.push_back(Terrain::Prairie); // 1
    V_EC.push_back(Terrain::Prairie); //2
    V_EC.push_back(Terrain::Prairie); //3
    V_EC.push_back(Terrain::Route); // 4
    V_EC.push_back(Terrain::Prairie); // 5
    V_EC.push_back(Terrain::Prairie); // 6
    V_EC.push_back(Terrain::Route); // 7
    V_EC.push_back(Terrain::Prairie); //8
    V_EC.push_back(Terrain::Prairie); //9
    V_EC.push_back(Terrain::Route); // 10
    V_EC.push_back(Terrain::Prairie); // 11
    V_EC.push_back(Terrain::CroisementFerme); // 12
    Tuile* EC = new Tuile(V_EC);
    vector<list<int>> _route_EC;
    list<int> LR1_EC;
    LR1_EC.push_back(10);
    list<int> LR2_EC;
    LR2_EC.push_back(4);
    list<int> LR3_EC;
    LR3_EC.push_back(4);
    _route_EC.push_back(LR1_EC);
    _route_EC.push_back(LR2_EC);
    _route_EC.push_back(LR3_EC);
    EC->setRoutes(_route_EC);
    vector<list<int>> _prairies_EC;
    list<int> LP1_EC;
    LP1_EC.push_back(0);
    LP1_EC.push_back(1);
    LP1_EC.push_back(2);
    LP1_EC.push_back(3);
    LP1_EC.push_back(11);
    list<int> LP2_EC;
    LP2_EC.push_back(6);
    LP2_EC.push_back(5);
    list<int> LP3_EC;
    LP3_EC.push_back(8);
    LP3_EC.push_back(9);
    _prairies_EB.push_back(LP1_EC);
    _prairies_EB.push_back(LP2_EC);
    _prairies_EB.push_back(LP3_EC);
    EC->setPrairies(_prairies_EC);
    EC->setAuberge(3);
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//////// ED
    vector<Terrain> V_ED;
    V_ED.push_back(Terrain::Prairie); // 0
    V_ED.push_back(Terrain::Prairie); // 1
    V_ED.push_back(Terrain::Prairie); //2
    V_ED.push_back(Terrain::Prairie); //3
    V_ED.push_back(Terrain::Route); // 4
    V_ED.push_back(Terrain::Prairie); // 5
    V_ED.push_back(Terrain::Prairie); // 6
    V_ED.push_back(Terrain::Prairie); // 7
    V_ED.push_back(Terrain::Prairie); //8
    V_ED.push_back(Terrain::Prairie); //9
    V_ED.push_back(Terrain::Route); // 10
    V_ED.push_back(Terrain::Prairie); // 11
    V_ED.push_back(Terrain::Abbaye); // 12
    Tuile* ED = new Tuile(V_ED);
    vector<list<int>> _route_ED;
    list<int> LR1_ED;
    LR1_ED.push_back(10);
    list<int> LR2_ED;
    LR2_ED.push_back(4);
    _route_ED.push_back(LR1_ED);
    _route_ED.push_back(LR2_ED);
    ED->setRoutes(_route_ED);
    vector<list<int>> _prairies_ED;
    list<int> LP1_ED;
    LP1_ED.push_back(0);
    LP1_ED.push_back(1);
    LP1_ED.push_back(2);
    LP1_ED.push_back(3);
    LP1_ED.push_back(11);
    list<int> LP2_ED;
    LP2_ED.push_back(6);
    LP2_ED.push_back(5);
    LP2_ED.push_back(7);
    LP2_ED.push_back(8);
    LP2_ED.push_back(9);
    _prairies_ED.push_back(LP1_ED);
    _prairies_ED.push_back(LP2_ED);
    ED->setPrairies(_prairies_ED);
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//////// EE
    vector<Terrain> V_EE;
    V_EE.push_back(Terrain::Prairie); // 0
    V_EE.push_back(Terrain::Route); // 1
    V_EE.push_back(Terrain::Prairie); //2
    V_EE.push_back(Terrain::Prairie); //3
    V_EE.push_back(Terrain::Route); // 4
    V_EE.push_back(Terrain::Prairie); // 5
    V_EE.push_back(Terrain::Prairie); // 6
    V_EE.push_back(Terrain::Route); // 7
    V_EE.push_back(Terrain::Prairie); //8
    V_EE.push_back(Terrain::Prairie); //9
    V_EE.push_back(Terrain::Route); // 10
    V_EE.push_back(Terrain::Prairie); // 11
    V_EE.push_back(Terrain::Prairie); // 12
    Tuile* EE = new Tuile(V_EE);
    vector<list<int>> _route_EE;
    list<int> LR1_EE;
    LR1_EE.push_back(10);
    LR1_EE.push_back(1);
    list<int> LR2_EE;
    LR2_EE.push_back(4);
    LR2_EE.push_back(7);
    _route_EE.push_back(LR1_EE);
    _route_EE.push_back(LR2_EE);
    EE->setRoutes(_route_EE);
    vector<list<int>> _prairies_EE;
    list<int> LP1_EE;
    LP1_EE.push_back(0);
    LP1_EE.push_back(11);
    list<int> LP2_EE;
    LP2_EE.push_back(3);
    LP2_EE.push_back(2);
    LP2_EE.push_back(8);
    LP2_EE.push_back(9);
    LP2_EE.push_back(12);
    list<int> LP3_EE;
    LP3_EE.push_back(5);
    LP3_EE.push_back(6);
    _prairies_EE.push_back(LP1_EE);
    _prairies_EE.push_back(LP2_EE);
    _prairies_EE.push_back(LP3_EE);
    EE->setPrairies(_prairies_EE);
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//////// EF
    vector<Terrain> V_EF;
    V_EF.push_back(Terrain::Ville); // 0
    V_EF.push_back(Terrain::Ville); // 1
    V_EF.push_back(Terrain::Ville); //2
    V_EF.push_back(Terrain::Prairie); //3
    V_EF.push_back(Terrain::Route); // 4
    V_EF.push_back(Terrain::Prairie); // 5
    V_EF.push_back(Terrain::Prairie); // 6
    V_EF.push_back(Terrain::Prairie); // 7
    V_EF.push_back(Terrain::Prairie); //8
    V_EF.push_back(Terrain::Ville); //9
    V_EF.push_back(Terrain::Ville); // 10
    V_EF.push_back(Terrain::Ville); // 11
    V_EF.push_back(Terrain::Ville); // 12
    Tuile* EF = new Tuile(V_EF);
    vector<list<int>> _route_EF;
    list<int> LR_EF;
    LR_EF.push_back(4);
    _route_EF.push_back(LR_EF);
    EF->setRoutes(_route_EF);
    vector<list<int>> _prairies_EF;
    list<int> LP1_EF;
    LP1_EF.push_back(3);
    list<int> LP2_EF;
    LP2_EF.push_back(5);
    LP2_EF.push_back(6);
    LP2_EF.push_back(7);
    LP2_EF.push_back(8);
    _prairies_EF.push_back(LP1_EF);
    _prairies_EF.push_back(LP2_EF);
    EF->setPrairies(_prairies_EF);
    vector<list<int>> _villes_EF;
    list<int> LV_EF;
    LV_EF.push_back(0);
    LV_EF.push_back(1);
    LV_EF.push_back(2);
    LV_EF.push_back(11);
    LV_EF.push_back(9);
    LV_EF.push_back(10);
    _villes_EF.push_back(LV_EF);
    EF->setVilles(_villes_EF);
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//////// EG
    vector<Terrain> V_EG;
    V_EG.push_back(Terrain::Prairie); // 0
    V_EG.push_back(Terrain::Prairie); // 1
    V_EG.push_back(Terrain::Prairie); //2
    V_EG.push_back(Terrain::Prairie); //3
    V_EG.push_back(Terrain::Prairie); // 4
    V_EG.push_back(Terrain::Prairie); // 5
    V_EG.push_back(Terrain::Prairie); // 6
    V_EG.push_back(Terrain::Prairie); // 7
    V_EG.push_back(Terrain::Prairie); //8
    V_EG.push_back(Terrain::Ville); //9
    V_EG.push_back(Terrain::Ville); // 10
    V_EG.push_back(Terrain::Ville); // 11
    V_EG.push_back(Terrain::Ville); // 12
    Tuile* EG = new Tuile(V_EG);
    vector<list<int>> _villes_EG;
    list<int> LV_EG;
    LV_EG.push_back(11);
    LV_EG.push_back(10);
    LV_EG.push_back(9);
    LV_EG.push_back(12);
    _villes_EG.push_back(LV_EG);
    EG->setVilles(_villes_EG);
    vector<list<int>> _prairies_EG;
    list<int> LP1_EG;
    LP1_EG.push_back(0);
    LP1_EG.push_back(1);
    LP1_EG.push_back(2);
    list<int> LP2_EG;
    LP2_EG.push_back(3);
    LP2_EG.push_back(4);
    LP2_EG.push_back(5);
    LP2_EG.push_back(6);
    LP2_EG.push_back(7);
    LP2_EG.push_back(8);
    _prairies_EG.push_back(LP1_EG);
    _prairies_EG.push_back(LP2_EG);
    EG->setPrairies(_prairies_EG);
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//////// EH
    vector<Terrain> V_EH;
    V_EH.push_back(Terrain::Ville); // 0
    V_EH.push_back(Terrain::Ville); // 1
    V_EH.push_back(Terrain::Ville); //2
    V_EH.push_back(Terrain::Ville); //3
    V_EH.push_back(Terrain::Ville); // 4
    V_EH.push_back(Terrain::Ville); // 5
    V_EH.push_back(Terrain::Ville); // 6
    V_EH.push_back(Terrain::Ville); // 7
    V_EH.push_back(Terrain::Ville); //8
    V_EH.push_back(Terrain::Ville); //9
    V_EH.push_back(Terrain::Ville); // 10
    V_EH.push_back(Terrain::Ville); // 11
    V_EH.push_back(Terrain::Prairie); // 12
    Tuile* EH = new Tuile(V_EH);
    vector<list<int>> _villes_EH;
    list<int> LV1_EH;
    LV1_EH.push_back(0);
    LV1_EH.push_back(1);
    LV1_EH.push_back(2);
    list<int> LV2_EH;
    LV2_EH.push_back(3);
    LV2_EH.push_back(4);
    LV2_EH.push_back(5);
    list<int> LV3_EH;
    LV3_EH.push_back(6);
    LV3_EH.push_back(7);
    LV3_EH.push_back(8);
    list<int> LV4_EH;
    LV4_EH.push_back(9);
    LV4_EH.push_back(10);
    LV4_EH.push_back(11);
    _villes_EH.push_back(LV1_EH);
    _villes_EH.push_back(LV2_EH);
    _villes_EH.push_back(LV3_EH);
    _villes_EH.push_back(LV4_EH);
    EH->setVilles(_villes_EH);
    vector<list<int>> _prairies_EH;
    list<int> LP1_EH;
    LP1_EH.push_back(12);
    _prairies_EH.push_back(LP1_EH);
    EH->setPrairies(_prairies_EH);
    EH->setJardin(12);
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//////// EI
    vector<Terrain> V_EI;
    V_EI.push_back(Terrain::Ville); // 0
    V_EI.push_back(Terrain::Ville); // 1
    V_EI.push_back(Terrain::Ville); //2
    V_EI.push_back(Terrain::Prairie); //3
    V_EI.push_back(Terrain::Route); // 4
    V_EI.push_back(Terrain::Prairie); // 5
    V_EI.push_back(Terrain::Ville); // 6
    V_EI.push_back(Terrain::Ville); // 7
    V_EI.push_back(Terrain::Ville); //8
    V_EI.push_back(Terrain::Prairie); //9
    V_EI.push_back(Terrain::Route); // 10
    V_EI.push_back(Terrain::Prairie); // 11
    V_EI.push_back(Terrain::CroisementFerme); // 12
    Tuile* EI = new Tuile(V_EI);
    vector<list<int>> _villes_EI;
    list<int> LV1_EI;
    LV1_EI.push_back(0);
    LV1_EI.push_back(1);
    LV1_EI.push_back(2);
    list<int> LV2_EI;
    LV2_EI.push_back(6);
    LV2_EI.push_back(7);
    LV2_EI.push_back(8);
    _villes_EI.push_back(LV1_EI);
    _villes_EI.push_back(LV2_EI);
    EI->setVilles(_villes_EI);
    vector<list<int>> _route_EI;
    list<int> LR1_EI;
    LR1_EI.push_back(4);
    list<int> LR2_EI;
    LR2_EI.push_back(10);
    _route_EI.push_back(LR1_EI);
    _route_EI.push_back(LR2_EI);
    EI->setRoutes(_route_EI);
    vector<list<int>> _prairies_EI;
    list<int> LP1_EI;
    LP1_EI.push_back(3);
    list<int> LP2_EI;
    LP2_EI.push_back(5);
    list<int> LP3_EI;
    LP3_EI.push_back(9);
    list<int> LP4_EI;
    LP4_EI.push_back(11);
    _prairies_EI.push_back(LP1_EI);
    _prairies_EI.push_back(LP2_EI);
    _prairies_EI.push_back(LP3_EI);
    _prairies_EI.push_back(LP4_EI);
    EI->setPrairies(_prairies_EI);
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//////// EJ
    vector<Terrain> V_EJ;
    V_EJ.push_back(Terrain::Ville); // 0
    V_EJ.push_back(Terrain::Ville); // 1
    V_EJ.push_back(Terrain::Ville); //2
    V_EJ.push_back(Terrain::Prairie); //3
    V_EJ.push_back(Terrain::Prairie); // 4
    V_EJ.push_back(Terrain::Prairie); // 5
    V_EJ.push_back(Terrain::Prairie); // 6
    V_EJ.push_back(Terrain::Route); // 7
    V_EJ.push_back(Terrain::Prairie); //8
    V_EJ.push_back(Terrain::Prairie); //9
    V_EJ.push_back(Terrain::Prairie); // 10
    V_EJ.push_back(Terrain::Prairie); // 11
    V_EJ.push_back(Terrain::Route); // 12
    Tuile* EJ = new Tuile(V_EJ);
    vector<list<int>> _villes_EJ;
    list<int> LV_EJ;
    LV_EJ.push_back(0);
    LV_EJ.push_back(1);
    LV_EJ.push_back(2);
    _villes_EJ.push_back(LV_EJ);
    EJ->setVilles(_villes_EJ);
    vector<list<int>> _route_EJ;
    list<int> LR_EJ;
    LR_EJ.push_back(7);
    LR_EJ.push_back(12);
    _route_EJ.push_back(LR2_EI);
    EJ->setRoutes(_route_EJ);

    vector<list<int>> _prairies_EJ;
    list<int> LP1_EJ;
    LP1_EJ.push_back(3);
    LP1_EJ.push_back(4);
    LP1_EJ.push_back(5);
    LP1_EJ.push_back(6);
    list<int> LP2_EJ;
    LP2_EJ.push_back(8);
    LP2_EJ.push_back(9);
    LP2_EJ.push_back(10);
    LP2_EJ.push_back(11);
    _prairies_EJ.push_back(LP1_EJ);
    _prairies_EJ.push_back(LP2_EJ);
    EJ->setPrairies(_prairies_EJ);
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//////// EK
    vector<Terrain> V_EK;
    V_EK.push_back(Terrain::Ville); // 0
    V_EK.push_back(Terrain::Ville); // 1
    V_EK.push_back(Terrain::Ville); //2
    V_EK.push_back(Terrain::Ville); //3
    V_EK.push_back(Terrain::Ville); // 4
    V_EK.push_back(Terrain::Ville); // 5
    V_EK.push_back(Terrain::Ville); // 6
    V_EK.push_back(Terrain::Ville); // 7
    V_EK.push_back(Terrain::Ville); //8
    V_EK.push_back(Terrain::Ville); //9
    V_EK.push_back(Terrain::Ville); // 10
    V_EK.push_back(Terrain::Ville); // 11
    V_EK.push_back(Terrain::Ville); // 12
    Tuile* EK = new Tuile(V_EK);
    vector<list<int>> _villes_EK;
    list<int> LV_EK;
    LV_EK.push_back(0);
    LV_EK.push_back(1);
    LV_EK.push_back(2);
    LV_EK.push_back(3);
    LV_EK.push_back(4);
    LV_EK.push_back(5);
    LV_EK.push_back(6);
    LV_EK.push_back(7);
    LV_EK.push_back(8);
    LV_EK.push_back(9);
    LV_EK.push_back(10);
    LV_EK.push_back(11);
    LV_EK.push_back(12);
    _villes_EK.push_back(LV_EK);
    EK->setVilles(_villes_EK);
    EK->setCathedrale(12);
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//////// EL
    vector<Terrain> V_EL;
    V_EL.push_back(Terrain::Ville); // 0
    V_EL.push_back(Terrain::Ville); // 1
    V_EL.push_back(Terrain::Ville); //2
    V_EL.push_back(Terrain::Prairie); //3
    V_EL.push_back(Terrain::Route); // 4
    V_EL.push_back(Terrain::Prairie); // 5
    V_EL.push_back(Terrain::Prairie); // 6
    V_EL.push_back(Terrain::Route); // 7
    V_EL.push_back(Terrain::Prairie); //8
    V_EL.push_back(Terrain::Ville); //9
    V_EL.push_back(Terrain::Ville); // 10
    V_EL.push_back(Terrain::Ville); // 11
    V_EL.push_back(Terrain::Route); // 12
    Tuile* EL = new Tuile(V_EL);
    vector<list<int>> _villes_EL;
    list<int> LV_EL;
    LV_EL.push_back(0);
    LV_EL.push_back(1);
    LV_EL.push_back(2);
    LV_EL.push_back(11);
    LV_EL.push_back(10);
    LV_EL.push_back(9);
    _villes_EL.push_back(LV_EL);
    EL->setVilles(_villes_EL);
    vector<list<int>> _prairies_EL;
    list<int> LP1_EL;
    LP1_EL.push_back(5);
    LP1_EL.push_back(6);
    list<int> LP2_EL;
    LP2_EL.push_back(3);
    LP2_EL.push_back(8);
    _prairies_EL.push_back(LP1_EL);
    _prairies_EL.push_back(LP2_EL);
    EL->setPrairies(_prairies_EL);
    vector<list<int>> _route_EL;
    list<int> LR_EL;
    LR_EL.push_back(4);
    LR_EL.push_back(12);
    LR_EL.push_back(7);
    _route_EL.push_back(LR_EL);
    EL->setRoutes(_route_EL);
    EL->setBlasons(11);
    EL->setAuberge(5);
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//////// EM
    vector<Terrain> V_EM;
    V_EM.push_back(Terrain::Ville); // 0
    V_EM.push_back(Terrain::Ville); // 1
    V_EM.push_back(Terrain::Ville); //2
    V_EM.push_back(Terrain::Prairie); //3
    V_EM.push_back(Terrain::Prairie); // 4
    V_EM.push_back(Terrain::Prairie); // 5
    V_EM.push_back(Terrain::Prairie); // 6
    V_EM.push_back(Terrain::Route); // 7
    V_EM.push_back(Terrain::Prairie); //8
    V_EM.push_back(Terrain::Prairie); //9
    V_EM.push_back(Terrain::Route); // 10
    V_EM.push_back(Terrain::Prairie); // 11
    V_EM.push_back(Terrain::Route); // 12
    Tuile* EM = new Tuile(V_EM);
    vector<list<int>> _villes_EM;
    list<int> LV_EM;
    LV_EM.push_back(0);
    LV_EM.push_back(1);
    LV_EM.push_back(2);
    _villes_EM.push_back(LV_EL);
    EM->setVilles(_villes_EM);
    vector<list<int>> _route_EM;
    list<int> LR_EM;
    LR_EM.push_back(10);
    LR_EM.push_back(12);
    LR_EM.push_back(7);
    _route_EM.push_back(LR_EL);
    EM->setRoutes(_route_EM);
    vector<list<int>> _prairies_EM;
    list<int> LP1_EM;
    LP1_EM.push_back(3);
    LP1_EM.push_back(4);
    LP1_EM.push_back(5);
    LP1_EM.push_back(6);
    LP1_EM.push_back(11);
    list<int> LP2_EM;
    LP2_EM.push_back(8);
    LP2_EM.push_back(9);
    _prairies_EM.push_back(LP1_EM);
    _prairies_EM.push_back(LP2_EM);
    EM->setPrairies(_prairies_EM);
    EM->setAuberge(4);
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//////// EN
    vector<Terrain> V_EN;
    V_EN.push_back(Terrain::Ville); // 0
    V_EN.push_back(Terrain::Ville); // 1
    V_EN.push_back(Terrain::Ville); //2
    V_EN.push_back(Terrain::Prairie); //3
    V_EN.push_back(Terrain::Prairie); // 4
    V_EN.push_back(Terrain::Prairie); // 5
    V_EN.push_back(Terrain::Prairie); // 6
    V_EN.push_back(Terrain::Route); // 7
    V_EN.push_back(Terrain::Prairie); //8
    V_EN.push_back(Terrain::Ville); //9
    V_EN.push_back(Terrain::Ville); // 10
    V_EN.push_back(Terrain::Ville); // 11
    V_EN.push_back(Terrain::Ville); // 12
    Tuile* EN = new Tuile(V_EN);
    vector<list<int>> _villes_EN;
    list<int> LV_EN;
    LV_EN.push_back(0);
    LV_EN.push_back(1);
    LV_EN.push_back(2);
    LV_EN.push_back(11);
    LV_EN.push_back(10);
    LV_EN.push_back(9);
    _villes_EN.push_back(LV_EN);
    EN->setVilles(_villes_EN);
    vector<list<int>> _prairies_EN;
    list<int> LP1_EN;
    LP1_EN.push_back(3);
    LP1_EN.push_back(4);
    LP1_EN.push_back(5);
    LP1_EN.push_back(6);
    list<int> LP2_EN;
    LP2_EN.push_back(8);
    _prairies_EN.push_back(LP1_EN);
    _prairies_EN.push_back(LP2_EN);
    EN->setPrairies(_prairies_EN);
    vector<list<int>> _route_EN;
    list<int> LR_EN;
    LR_EN.push_back(7);
    _route_EN.push_back(LR_EN);
    EN->setRoutes(_route_EN);
    EN->setAuberge(4);
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//////// EO
    vector<Terrain> V_EO;
    V_EO.push_back(Terrain::Ville); // 0
    V_EO.push_back(Terrain::Ville); // 1
    V_EO.push_back(Terrain::Ville); //2
    V_EO.push_back(Terrain::Ville); //3
    V_EO.push_back(Terrain::Ville); // 4
    V_EO.push_back(Terrain::Ville); // 5
    V_EO.push_back(Terrain::Prairie); // 6
    V_EO.push_back(Terrain::Prairie); // 7
    V_EO.push_back(Terrain::Prairie); //8
    V_EO.push_back(Terrain::Ville); //9
    V_EO.push_back(Terrain::Ville); // 10
    V_EO.push_back(Terrain::Ville); // 11
    V_EO.push_back(Terrain::Prairie); // 12
    Tuile* EO = new Tuile(V_EO);
    vector<list<int>> _villes_EO;
    list<int> LV1_EO;
    LV1_EO.push_back(0);
    LV1_EO.push_back(1);
    LV1_EO.push_back(2);
    list<int> LV2_EO;
    LV2_EO.push_back(3);
    LV2_EO.push_back(4);
    LV2_EO.push_back(5);
    list<int> LV3_EO;
    LV3_EO.push_back(9);
    LV3_EO.push_back(10);
    LV3_EO.push_back(11);
    _villes_EO.push_back(LV1_EO);
    _villes_EO.push_back(LV2_EO);
    _villes_EO.push_back(LV3_EO);
    EO->setVilles(_villes_EO);

    vector<list<int>> _prairies_EO;
    list<int> LP1_EO;
    LP1_EO.push_back(12);
    LP1_EO.push_back(7);
    LP1_EO.push_back(6);
    LP1_EO.push_back(8);
    _prairies_EO.push_back(LP1_EO);
    EO->setPrairies(_prairies_EO);
    EO->setAuberge(12);
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//////// EP
    vector<Terrain> V_EP;
    V_EP.push_back(Terrain::Ville); // 0
    V_EP.push_back(Terrain::Ville); // 1
    V_EP.push_back(Terrain::Ville); //2
    V_EP.push_back(Terrain::Ville); //3
    V_EP.push_back(Terrain::Ville); // 4
    V_EP.push_back(Terrain::Ville); // 5
    V_EP.push_back(Terrain::Prairie); // 6
    V_EP.push_back(Terrain::Prairie); // 7
    V_EP.push_back(Terrain::Prairie); //8
    V_EP.push_back(Terrain::Ville); //9
    V_EP.push_back(Terrain::Ville); // 10
    V_EP.push_back(Terrain::Ville); // 11
    V_EP.push_back(Terrain::Prairie); // 12
    Tuile* EP = new Tuile(V_EP);
    vector<list<int>> _villes_EP;
    list<int> LV1_EP;
    LV1_EP.push_back(0);
    LV1_EP.push_back(1);
    LV1_EP.push_back(2);
    LV1_EP.push_back(3);
    LV1_EP.push_back(4);
    LV1_EP.push_back(5);
    list<int> LV2_EP;
    LV2_EP.push_back(9);
    LV2_EP.push_back(10);
    LV2_EP.push_back(11);
    _villes_EP.push_back(LV1_EP);
    _villes_EP.push_back(LV2_EP);
    EP->setVilles(_villes_EP);
    vector<list<int>> _prairies_EP;
    list<int> LP1_EP;
    LP1_EP.push_back(12);
    LP1_EP.push_back(7);
    LP1_EP.push_back(6);
    LP1_EP.push_back(8);
    _prairies_EP.push_back(LP1_EO);
    EP->setPrairies(_prairies_EP);
    EP->setBlasons(2);
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//////// EQ
    vector<Terrain> V_EQ;
    V_EQ.push_back(Terrain::Prairie); // 0
    V_EQ.push_back(Terrain::Route); // 1
    V_EQ.push_back(Terrain::Prairie); //2
    V_EQ.push_back(Terrain::Ville); //3
    V_EQ.push_back(Terrain::Ville); // 4
    V_EQ.push_back(Terrain::Ville); // 5
    V_EQ.push_back(Terrain::Prairie); // 6
    V_EQ.push_back(Terrain::Route); // 7
    V_EQ.push_back(Terrain::Prairie); //8
    V_EQ.push_back(Terrain::Ville); //9
    V_EQ.push_back(Terrain::Ville); // 10
    V_EQ.push_back(Terrain::Ville); // 11
    V_EQ.push_back(Terrain::Ville); // 12
    Tuile* EQ = new Tuile(V_EQ);
    vector<list<int>> _villes_EQ;
    list<int> LV_EQ;
    LV_EQ.push_back(3);
    LV_EQ.push_back(4);
    LV_EQ.push_back(5);
    LV_EQ.push_back(12);
    LV_EQ.push_back(11);
    LV_EQ.push_back(10);
    LV_EQ.push_back(9);
    _villes_EQ.push_back(LV_EQ);
    EQ->setVilles(_villes_EQ);
    vector<list<int>> _prairies_EQ;
    list<int> LP1_EQ;
    LP1_EQ.push_back(0);
    list<int> LP2_EQ;
    LP2_EQ.push_back(2);
    list<int> LP3_EQ;
    LP3_EQ.push_back(6);
    list<int> LP4_EQ;
    LP4_EQ.push_back(8);
    _prairies_EQ.push_back(LP1_EQ);
    _prairies_EQ.push_back(LP2_EQ);
    _prairies_EQ.push_back(LP3_EQ);
    _prairies_EQ.push_back(LP4_EQ);
    EQ->setPrairies(_prairies_EQ);
    vector<list<int>> _route_EQ;
    list<int> LR1_EQ;
    LR1_EQ.push_back(1);
    list<int> LR2_EQ;
    LR2_EQ.push_back(7);
    _route_EQ.push_back(LR1_EQ);
    _route_EQ.push_back(LR2_EQ);
    EQ->setRoutes(_route_EQ);
    EQ->setBlasons(4);
////////////////////////////////////////////////////
////////////////////////////////////////////////////
    auberge.push_back(EA);
    dictionnaire[84]=EA;
    auberge.push_back(EB);
    dictionnaire[85]=EB;
    auberge.push_back(EC);
    dictionnaire[86]=EC;
    auberge.push_back(ED);
    dictionnaire[87]=ED;
    auberge.push_back(EE);
    dictionnaire[88]=EE;
    auberge.push_back(EF);
    dictionnaire[89]=EF;
    auberge.push_back(EG);
    dictionnaire[90]=EG;
    auberge.push_back(EH);
    dictionnaire[91]=EH;
    auberge.push_back(EI);
    dictionnaire[92]=EI;
    auberge.push_back(EJ);
    dictionnaire[93]=EJ;
    auberge.push_back(EK);
    dictionnaire[94]=EK;
    Tuile* EK1 = new Tuile(*EK);
    dictionnaire[95]=EK1;
    auberge.push_back(EL);
    dictionnaire[96]=EL;
    auberge.push_back(EM);
    dictionnaire[97]=EM;
    auberge.push_back(EN);
    dictionnaire[98]=EN;
    auberge.push_back(EO);
    dictionnaire[99]=EO;
    auberge.push_back(EP);
    dictionnaire[100]=EP;
    auberge.push_back(EQ);
    dictionnaire[101]=EQ;
}

void Jeu::tuilesPaysan() {

}

void Jeu::tuilesAbbe() {

}
