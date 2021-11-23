// LIFAP6 - Automne 2021 - TP7,8

#include <iostream>
#include "module/element.h"

#include "module/Noeud.h"
#include "module/arbre.h"
#include "module/Noeud_ARN.h"
#include "module/arbre_ARN.h"
#include "module/performance.h"

using namespace std;

// Pre declaration pour le constructeur.
void menu_programme_principale();

int main(void)
{
  menu_programme_principale();
  //Arbre_ARN a;
  //a.test_arbre_RN();
  cout << "\033[2J\033[1;1H"; // Nettoie le terminale et remet le cursor à sa place de départ.

  return 0;
}




void menu_programme_principale()
{
  // Menu pour choisir l'arbre que l'on voudra tester (à faire à la fin).

  char choix_utilisateur;
  bool boucle_programme = true;
  while (boucle_programme)
  {
    cout << "Veuillez choisir quelle type de collection vous voulez tester : " << endl;
    cout << "- 1 - Arbre binaire de Recherche (TP6)" << endl;
    cout << "- 2 - Arbre Rouge et Noir" << endl;
    cout << "- 3 - Autre" << endl;
    cout << "- 4 - Quitte le programme." << endl;
    cin >> choix_utilisateur;
    if (choix_utilisateur == '1')
    {
      // Test ABR.
      Perfomance_Class perf_ABR(choix_utilisateur);
      perf_ABR.Test_Perfomance_Collection();
    }
    else if (choix_utilisateur == '2')
    {
      // TEST Arbre_RN
      Perfomance_Class perf_ARN(choix_utilisateur);
      perf_ARN.Test_Perfomance_Collection();
    }
    else if (choix_utilisateur == '3')
    {
      // Autres
      boucle_programme = false;
      // ...
    }
    else if (choix_utilisateur == '4')
    {
      boucle_programme = false;
    }
    else
    {
      cout << "Votre choix n'est pas valide" << endl;
    }
  }
}
