#ifndef NOEUD_ARN
#define NOEUD_ARN

#include <iostream>
#include <cassert>
#include "element.h"

class Noeud_ARN
{
private:
    Elem cle; // clé ou valeur du noeud.
    Noeud_ARN *fg; // Fils gauche.
    Noeud_ARN *fd; // Fils droit.
    char couleur; // Couleur du noeud ('r' pour rouge et 'n' pour noir).

public:
    // Constructeur d'un noeud avec un element passé en paramètre et une couleur pour ce noeud.
    Noeud_ARN(const Elem& e, const char& couleur_noeud);
    Noeud_ARN();
    ~Noeud_ARN();
};

#endif