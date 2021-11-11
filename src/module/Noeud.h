#ifndef NOEUD_SKIPLIST
#define NOEUD_SKIPLIST

#include "element.h"
#include <iostream>
#include <vector>

using namespace std;

class Noeud
{
    friend class Arbre;

protected:
    Elem cle;  // valeur du noeud.
    Noeud *fg; // Adresse vers le prochain noeud à gauche (element doit être plus petit que la clé).
    Noeud *fd; // Adresse vers le prochain noeud à droite (element doit être plus petit que la clé).
public:
    Noeud();
    // on créer un nouveau Noeud avec un element e.
    Noeud(const Elem &e);
    //~Noeud();
};

#endif