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

    // Procédure d'appel pour ajouter un élément e passé en paramètre.
    void insere_element(const Elem& e);
    // Procédure récursive qui va ajouter un élément à l'arbre rouge et noir en mettant une couleur au noeud.
    Noeud_ARN* insere_element_noeud(const Elem&e, Noeud_ARN* parent);

    // Rotation du Noeud à droite.
    // Retourne le nouveau Noeud parent qui est le fils gauche du parent.
    void rotationDroite(Noeud_ARN* parent);

    // Rotation Gauche 
    void rotationGauche(Noeud_ARN* parent);


    // Vide l'arbre en profondeur.
    void vide();
    void vide_arbre_noeud(Noeud_ARN* n);
    // Procédure de test pour les arbre rouge et noir.
    void test_arbre_RN();
    // Opérateur.
private:
    Noeud_ARN *racine; // Racine de l'abre.
};

#endif