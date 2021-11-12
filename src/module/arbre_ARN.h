#ifndef ARBRE_ARN
#define ARBRE_ARN

#include "Noeud_ARN.h"

class Arbre_ARN {
    public:
        // Constructeurs
        Arbre_ARN();
        Arbre_ARN(const Arbre_ARN& a);
        ~Arbre_ARN();

        // Fonction et procédure membre.
        

        // Opérateur.
    private:
        Noeud_ARN* raicne; // Racine de l'abre.
};



#endif