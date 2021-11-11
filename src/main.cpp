// LIFAP6 - Automne 2017 - R. Chaine

#include <iostream>
#include "module/element.h"
#include "module/arbre.h"
#include "module/Noeud.h"
#include <iostream>
//#include <cassert>

using namespace std;

int main(void)
{
  Arbre abr;
  cout << "Constructeur ok" << endl;
  abr.insere_element(4);
  abr.insere_element(10);
  abr.insere_element(14);
  abr.insere_element(2);
  abr.insere_element(1);
  abr.insere_element(7);
  abr.insere_element(9);
  abr.insere_element(12);
  abr.insere_element(22);
  abr.insere_element(22);
  abr.insere_element(100);
  abr.insere_element(45);
  abr.insere_element(32);
  abr.insere_element(29);
  abr.insere_element(3);
  cout << "Ajout ok" << endl;
  abr.menu_choix_affichage_arbre();

  // On copie l'abre abr dans l'arbre abr2.
  Arbre abr2;
  abr2 = abr;
  cout << "Nouvelle arbre" << endl;
  abr2.affichage_Infixe();

  // Menu pour choisir l'arbre que l'on voudra tester (à faire à la fin).
  /* 
  char choix_utilisateur;
  cout << "Veuillez choisir quelle type de collection vous voulez tester : " << endl;
  cout << "- 1 - Arbre binaire de Recherche (TP6)" << endl;
  cout << " - 2 - Arbre Rouge et Noir" << endl;
  cout << "- 3 - Autre" << endl;
  cin >> choix_utilisateur;
  switch (choix_utilisateur)
  {
  case '1':
    // Créer un menu
    break;
  
  default:
    break;
  }
 */
  return 0;
}
