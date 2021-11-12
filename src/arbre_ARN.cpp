#include "module/arbre_ARN.h"

Arbre_ARN::Arbre_ARN()
{
    racine = NULL;
}
Arbre_ARN::~Arbre_ARN()
{
    vide();
}
void Arbre_ARN::vide()
{
    vide_arbre_noeud(racine);
}
void Arbre_ARN::vide_arbre_noeud(Noeud_ARN* n)
{

    if (n == NULL)
        return;
    else
    {
        // On va faire le parcrous postfixe.
        vide_arbre_noeud(n->fg);
        vide_arbre_noeud(n->fd);
        // On est sur l'élément que l'on veut supprimer.
        delete n;
        n = NULL;
    }
    delete n;
    n = NULL;
}

Noeud_ARN* Arbre_ARN::rechercheElement(const Elem& e) const {     
    return recherche_element_noeud(e, racine);
}
Noeud_ARN* Arbre_ARN::recherche_element_noeud(const Elem& e, Noeud_ARN* n) const
{
    if(n == NULL)
        return NULL;
    else
    {
        if(n->cle == e)
            return n;
        else if(n->cle > e)
            recherche_element_noeud(e, n->fg);
        else if(n->cle < e)
            recherche_element_noeud(e, n->fd);
    }
    return n;
}





void Arbre_ARN::test_arbre_RN()
{
    assert(racine == NULL);
    racine = new Noeud_ARN(8, 'n');
    assert(racine->cle == 8);
    cout << "L'adresse mémoire de racine est : " << racine << endl;

    // On va tester la recherche sur la racine (c'est un peu pour le fun mais bon).
    Noeud_ARN* n = rechercheElement(8);
    assert(n != NULL && n == racine);
    
}