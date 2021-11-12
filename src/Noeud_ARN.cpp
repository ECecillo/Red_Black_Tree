#include "module/Noeud_ARN.h"
#include <iostream>

using namespace std;

Noeud_ARN::Noeud_ARN()
{
    cle = 0;
    couleur = '\0';
    fg = fd = NULL;
}
Noeud_ARN::Noeud_ARN(const Elem& e,const char& couleur_noeud)
{
    cle = e;
    couleur = couleur_noeud;
    fg = fd = NULL;
}
