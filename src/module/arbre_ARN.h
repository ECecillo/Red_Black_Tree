#ifndef ARBRE_ARN
#define ARBRE_ARN

#include "Noeud_ARN.h"

class Arbre_ARN
{
public:
    // Constructeurs
    Arbre_ARN();
    Arbre_ARN(const Arbre_ARN &a);
    ~Arbre_ARN();

    // Fonction et procédure membre.
    Noeud_ARN* rechercheElement(const Elem& e) const;
    Noeud_ARN* recherche_element_noeud(const Elem& e, Noeud_ARN* n) const;

    // Opérateur.
private:
    Noeud_ARN *racine; // Racine de l'abre.
};

#endif