#include "module/arbre.h"
#include "module/Noeud.h"
#include "module/element.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cassert>
#include <stack>

using namespace std;

Arbre::Arbre()
{
    this->racine = 0;
    hauteur = 0;
}
Arbre::~Arbre()
{
    vide();
}

// Valeur de retour : Adresse du Noeud ou NULL dans le cas où l'élément n'est pas dans l'abre.
Noeud *Arbre::rechercheElement(const Elem &e) const
{
    return recherche_a_partir_Noeud(racine, e); // on fait appel recursif à partir de la première adresse de l'arbre qui est la racine?
}
Noeud *Arbre::recherche_a_partir_Noeud(Noeud *n, const Elem &e) const
{
    // Cas arrêt.
    if (n != NULL) // Si l'arbre est vide ou on est tombé sur un fg ou fd NULL on peut retourner faux.
    {
        if (n->cle == e) // On regarde si la clé est égale à l'élément que l'on recherche.
        {
            return n;
        }
        else if (n->cle > e) // Si notre élément est inférieure à la cle du noeud que l'on regarde on doit surement être à gauche.
            recherche_a_partir_Noeud(n->fg, e);
        else // On doit être à droite.
            recherche_a_partir_Noeud(n->fd, e);
    }
    return NULL;
}

void Arbre::insere_element(const Elem &e)
{
    racine = insere_element_partir_Noeud(racine, e);
    hauteur += 1;
}
Noeud *Arbre::insere_element_partir_Noeud(Noeud *n, const Elem &e)
{
    if (n == NULL)
        n = new Noeud(e);

    else if (n->cle > e)
        n->fg = insere_element_partir_Noeud(n->fg, e);
    else if (n->cle < e)
        n->fd = insere_element_partir_Noeud(n->fd, e);

    return n;
}

void Arbre::menu_choix_affichage_arbre() const
{
    cout << "Choisir l'affichage que vous voulez faire pour l'arbre : " << endl;
    cout << "1 - Affichage Infixe " << endl;
    cout << "2 - Affichage PostFixe " << endl;
    cout << "3 - Affichage  Préfixe" << endl;

    char choix;
    cin >> choix;
    switch (choix)
    {
    case '1':
        affichage_Infixe();
        break;
    case '2':
        affichage_PostFixe();
        break;
    case '3':
        affichage_Prefixe();
        break;

    default:
        cout << "Votre choix est incorrect veuillez réessayer." << endl;
        break;
    }
}

void Arbre::espacement_affichage_arbre(const int &profondeur) const
{
    for (int i = 0; i < profondeur; i++)
        cout << " ";
}

void Arbre::affichage_PostFixe() const
{
    int profondeur = 0;
    affichage_PostFixe_Noeud(racine, profondeur);
}

void Arbre::affichage_PostFixe_Noeud(Noeud *n, int &profondeur) const
{
    if (n == NULL)
    {
        espacement_affichage_arbre(profondeur);
        cout << "~";
    }
    if (n != NULL)
    {
        affichage_PostFixe_Noeud(n->fg, profondeur = +10);
        affichage_PostFixe_Noeud(n->fd, profondeur += 10);
        cout << endl;
        espacement_affichage_arbre(profondeur);
        cout << " [ " << n->cle << " ]" << endl;
    }
}

void Arbre::affichage_Infixe() const
{
    int profondeur = 0;
    affichage_Infixe_Noeud(racine, profondeur);
}
void Arbre::affichage_Infixe_Noeud(Noeud *n, int &profondeur) const
{
    if (n == NULL)
    {
        espacement_affichage_arbre(profondeur);
        cout << "~";
    }
    if (n != NULL)
    {
        affichage_Infixe_Noeud(n->fg, profondeur = +10);
        cout << endl;
        espacement_affichage_arbre(profondeur);
        cout << " [ " << n->cle << " ]" << endl;
        affichage_Infixe_Noeud(n->fd, profondeur += 10);
    }
}

void Arbre::affichage_Prefixe() const
{
    int profondeur = 0;
    cout << "La valeur de la racine est " << racine->cle << endl;
    affichage_Infixe_Noeud(racine, profondeur);
}
void Arbre::affichage_Prefixe_Noeud(Noeud *n, int &profondeur) const
{
    if (n == NULL)
    {
        espacement_affichage_arbre(profondeur);
        cout << "~";
    }
    if (n != NULL)
    {
        cout << endl;
        espacement_affichage_arbre(profondeur);
        cout << " [ " << n->cle << " ]" << endl;
        affichage_Prefixe_Noeud(n->fg, profondeur = +10);
        affichage_Prefixe_Noeud(n->fd, profondeur += 10);
    }
}

Noeud *Arbre::valeur_plus_petite_depuis_noeud(Noeud *&n)
{
    // On créer un nouveau Noeud pour parcourir le Sous arbre pour éviter de casser quoiquesoit.
    Noeud *noeud_actuel = n;
    while (noeud_actuel->fg != NULL) // Tant qu'on est pas NULL à gauche on boucle.
        noeud_actuel = noeud_actuel->fg;

    return noeud_actuel;
}

void Arbre::supprime_element(const Elem &e)
{
    racine = supprime_depuis_noeud(racine, e);
}
Noeud *Arbre::supprime_depuis_noeud(Noeud *n, const Elem &e)
{
    if (n == NULL) // Si l'arbre est vide ou on trouve pas l'élément on change rien donc on retourne l'arbre.
    {
        cout << "Pas trouvé" << endl;
        return n;
    }
    if (n->cle > e) // On va chercher dans le fils gauche et à la fin on va retourner le nouveau noeud sur lequel on doit pointer.
        n->fg = supprime_depuis_noeud(n->fg, e);
    else if (n->cle < e) // On va chercher dans le fils droit et même chose.
        n->fd = supprime_depuis_noeud(n->fd, e);
    else
    {
        // Si le noeud est une feuille.
        if (n->fg == NULL && n->fd == NULL)
            return NULL;
        // Pour chaque branche je regarde si je suis null à droite ou à gauche, si je suis null dans les deux je fais rien pour le moment (feuille).
        else if (n->fg == NULL)
        {
            Noeud *temp = n->fd; // On créer un pointeur temporaire sur le seul fils du noeud qui va remplacer le noeud que l'on va supprimer.
            delete n;            // On supprime le Noeud que l'on voulait enlever.
            return temp;         // On retourne le pointeur du Noeud qui va remplacer notre ancien noeud.
        }
        else if (n->fd == NULL)
        { // si on avait rien dans le gauche on
            Noeud *temp = n->fg;
            delete n;
            return temp;
        }
        // Maintenant que l'on a fait les cas où c'est feuille ou avec un seul élément on doit gérer le cas où on a plusieurs enfants.

        // On va devoir chercher le fils qui va remplacer le parent à savoir le fils le plus à gauche de sa droite.
        Noeud *temp = valeur_plus_petite_depuis_noeud(n->fd);

        // On a notre nouvelle valeur de noeud.
        n->cle = temp->cle;

        // Comme on a remplacé notre noeud par la valeur du noeud qui était au plus profond du sous arbre à sa droite, on va devoir rappeler la fonction sur le reste du sous arbre pour supprimer l'élément de manière propre si jamais il avait lui même des enfants.
        n->fd = supprime_depuis_noeud(n->fd, temp->cle);
    }
    return n;
}

void Arbre::vide()
{
    racine = vide_noeud(racine);
}
Noeud *Arbre::vide_noeud(Noeud *n)
{
    if (n == NULL)
        return n;
    else
    {
        // On va faire le parcrous postfixe.
        n->fg = vide_noeud(n->fg);
        n->fd = vide_noeud(n->fd);
        // On est sur l'élément que l'on veut supprimer.
        delete n;
        n = NULL;
    }
    return n;
}

bool Arbre::est_vide() const
{
    return racine == NULL;
}
Arbre::Arbre(const Arbre &l)
{
    // Constructeur par copie profonde.
    Noeud *n = l.racine;               // On créer un pointeur local sur la racine de l'abre que l'on veut recopier.
    racine = recopie_arbre(racine, n); // On attribue le nouvelle arbre.
}
Noeud *Arbre::recopie_arbre(Noeud *n, Noeud *&noeud_parcours_abr)
{
    // Cas 1: le noeud où on est est null on est arrivé à la fin d'une branche ou abr vide.
    if (noeud_parcours_abr == NULL)
        return NULL;

    // On créer un nouveau noeud avec nouvelle clé.
    Noeud *nouveau_noeud = new Noeud(noeud_parcours_abr->cle);

    // on rappelle la fonction sur la partie gauche, dès qu'on a fini de recopier sa partie gauche on va recopier la partie gauche.
    nouveau_noeud->fg = recopie_arbre(nouveau_noeud, noeud_parcours_abr->fg);
    nouveau_noeud->fd = recopie_arbre(nouveau_noeud, noeud_parcours_abr->fd);

    // Notre nouvelle arbre ou le nouveau noeud qui va venir dans notre arbre.
    return nouveau_noeud;
}

Arbre &Arbre::operator=(const Arbre &l)
{
    Noeud *parcours_l = l.racine;
    racine = recopie_arbre(racine, parcours_l);
    hauteur = l.hauteur;
    return *this;
}

void Arbre::tests_arbre()
{
    cout << "Constructeur ok" << endl;

    insere_element(4);
    Elem valeur_racine_abr_local = racine->cle;
    assert(valeur_racine_abr_local == 4);
    insere_element(10);
    insere_element(14);
    insere_element(2);
    insere_element(1);
    insere_element(7);
    insere_element(9);
    insere_element(12);
    insere_element(22);
    insere_element(22);
    insere_element(100);
    insere_element(45);
    insere_element(32);
    insere_element(29);
    insere_element(3);
    assert(hauteur == 15);
    cout << "Ajout ok" << endl;

    // Menu pour choisir un affichage.
    menu_choix_affichage_arbre();

    cout << "Construction d'un nouvelle arbre en fonction du premier" << endl;
    // On copie l'abre abr dans l'arbre abr2.
    Arbre abr2;
    abr2 = *this;
    
    Elem valeur_racine_abr2 = abr2.racine->cle;
    assert(abr2.hauteur == hauteur && valeur_racine_abr2 == valeur_racine_abr_local);

    cout << "Abr2 bien init" << endl;
    abr2.affichage_Infixe();

    cout << "Fin procédure Test Arbre binaire de recherche." << endl;
}