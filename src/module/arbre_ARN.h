#ifndef ARBRE_ARN
#define ARBRE_ARN

#include "Noeud_ARN.h"

static const char* SPLIT = "+" ;
static const char* V_BRANCH = "|" ;
static const char* H_BRANCH = "-" ;
static const char* UPPER_BRANCH = "+" ;
static const char* LOWER_BRANCH = "+" ;


class Arbre_ARN
{
public:
    // Constructeurs
    Arbre_ARN();
    Arbre_ARN(const Arbre_ARN &a);
    ~Arbre_ARN();

    // Fonction et procédure membre.
    Noeud_ARN *rechercheElement(const Elem &e) const;
    Noeud_ARN *recherche_element_noeud(const Elem &e, Noeud_ARN *n) const;

    // Procédure d'appel pour ajouter un élément e passé en paramètre.
    void insere_element(const Elem &e);
    // Procédure récursive qui va ajouter un élément à l'arbre rouge et noir en mettant une couleur au noeud.
    void insere_element_noeud(Noeud_ARN *&parent, const Elem &e);

    // Procédure qui va nous permettre de gérer les cas où l'arbre n'est plus équilibré après l'insertion(cf readme).
    void gere_cas_desequilibre_gauche(Noeud_ARN *&n);

    void gere_cas_desequilibre_droite(Noeud_ARN *&n);

    // Procédure qui va s'occuper de mettre le père et l'oncle en noir et le grand père passe en rouge.
    void gere_cas_oncle_pere_rouge(Noeud_ARN *&n);

    // Procédure qui gère le cas où le fg et sont fg sont en rouges avec une rotation droite.
    void gere_cas_ligne_rouge_gauche(Noeud_ARN *&n);
    void gere_cas_ligne_rouge_droite(Noeud_ARN *&n);

    void gere_cas_triangle_rouge_gauche(Noeud_ARN *&n);
    void gere_cas_triangle_rouge_droite(Noeud_ARN *&n);
    // Rotation du Noeud à droite.
    // Retourne le nouveau Noeud parent qui est le fils gauche du parent.
    void rotationDroite(Noeud_ARN *&parent);

    // Rotation Gauche
    void rotationGauche(Noeud_ARN *&parent);

    void afficher_noeud(Noeud_ARN* n, int profondeur, int code) const;
    void dessineArbreBR();

    // Vide l'arbre en profondeur.
    void vide();
    void vide_arbre_noeud(Noeud_ARN *n);
    // Procédure de test pour les arbre rouge et noir.
    void test_arbre_RN();
    // Opérateur.
private:
    Noeud_ARN *racine; // Racine de l'abre.
};

#endif