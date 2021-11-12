#include "module/arbre_ARN.h"

Arbre_ARN::Arbre_ARN()
{
    racine = NULL;
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