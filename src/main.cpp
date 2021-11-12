// LIFAP6 - Automne 2017 - R. Chaine

#include <iostream>
#include "module/element.h"
#include "module/arbre.h"
#include "module/Noeud.h"
#include <iostream>
#include <string.h>

using namespace std;

void menu_programme_principale();

int main(void)
{
  menu_programme_principale();
  cout << "\033[2J\033[1;1H"; // Nettoie le terminale et remet le cursor à sa place de départ.

  return 0;
}

void menu_programme_principale()
{
  // Menu pour choisir l'arbre que l'on voudra tester (à faire à la fin).

  string choix_utilisateur;
  bool boucle_programme = true;
  while (boucle_programme)
  {
    cout << "Veuillez choisir quelle type de collection vous voulez tester : " << endl;
    cout << "- 1 - Arbre binaire de Recherche (TP6)" << endl;
    cout << "- 2 - Arbre Rouge et Noir" << endl;
    cout << "- 3 - Autre" << endl;
    cout << "- quit - Quitte le programme." << endl;
    cin >> choix_utilisateur;
    if (choix_utilisateur == "1")
    {
      // Test ABR.
      Arbre abr;
      abr.tests_arbre();
    }
    else if (choix_utilisateur == "2")
    {
      // TEST Arbre_RN
      // ...
    }
    else if (choix_utilisateur == "3")
    {
      // Autres
      // ...
    }
    else if (choix_utilisateur == "quit")
    {
      boucle_programme = false;
    }
    else
    {
      cout << "Votre choix n'est pas valide" << endl;
    }
  }
}