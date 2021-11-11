#include "module/element.h"
#include <iostream>
#include <vector>
#include "module/Noeud.h"
#include <stdlib.h>

using namespace std;

Noeud::Noeud()
{
    this->cle = 0;
    fg = NULL;
    fd = NULL;
}

Noeud::Noeud(const Elem &e)
{
    // cle = e et fg et fd sont vide (feuille).
    cle = e;
    fg = fd = NULL;
}

