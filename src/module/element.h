// LIFAP6 - Automne 2017 - R. Chaine

#ifndef _ELEMENT
#define _ELEMENT
#include <iostream>

using namespace std;

class Elem
{
    friend ostream &operator<<(ostream& flux, const Elem &e);
public:
    Elem(){e = 0;};
    // Constructeur qui prend un entier en paramètre et qui donne à e la valeur de x.
    Elem(int x){e = x;};
    
    void affichageElement(ostream& flux) const;
    // Surcharge de < pour comparer les éléments où e_cmp sera l'élément auxquels on voudra comparer pour voir si il est plus grand que notre élément local.
    bool operator<(const Elem &e_cmp);
    bool operator>(const Elem &e_cmp);
    //On va comparer si 2 éléments sont égaux ou non.
    bool operator==(const Elem &e_cmp) const;
private:
    int e;
};

#endif
