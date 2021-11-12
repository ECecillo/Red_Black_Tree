#include "module/Noeud_ARN.h"
#include <iostream>
#include <cassert>

using namespace std;

Noeud_ARN::Noeud_ARN()
{
    cle = 0;
    couleur = '\0';
    fg = fd = NULL;
    assert(cle == 0 && couleur == '\0' && fg == NULL && fd == NULL);
}
Noeud_ARN::Noeud_ARN(const Elem& e,const char& couleur_noeud)
{
    cle = e;
    couleur = couleur_noeud;
    fg = fd = NULL;
}
