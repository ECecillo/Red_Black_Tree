// LIFAP6 - Automne 2017 - R. Chaine

#include <cstdio> 
#include "module/element.h"
#include <cassert>

ostream &operator<<(ostream& flux, const Elem & e)
{
  e.affichageElement(flux);
  return flux;  
}
void Elem::affichageElement(ostream& flux) const
{
  flux << e;
}
bool Elem::operator<(const Elem& e_cmp)
{
  return (this->e < e_cmp.e);
}
bool Elem::operator>(const Elem& e_cmp)
{
  return (this->e > e_cmp.e);
}
bool Elem::operator==(const Elem& e_cmp) const
{
  assert(this->e == e_cmp.e);
  return (e_cmp.e == this->e);
}