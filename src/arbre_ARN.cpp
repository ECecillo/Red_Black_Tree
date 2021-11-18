#include "module/arbre_ARN.h"
#include <unistd.h>

Arbre_ARN::Arbre_ARN()
{
    racine = NULL;
}
Arbre_ARN::~Arbre_ARN()
{
    vide();
}
void Arbre_ARN::vide()
{
    vide_arbre_noeud(racine);
}
void Arbre_ARN::vide_arbre_noeud(Noeud_ARN *n)
{

    if (n == NULL)
        return;
    else
    {
        // On va faire le parcrous postfixe.
        vide_arbre_noeud(n->fg);
        vide_arbre_noeud(n->fd);
        // On est sur l'élément que l'on veut supprimer.
        delete n;
        n = NULL;
    }
    delete n;
    n = NULL;
}

Noeud_ARN *Arbre_ARN::rechercheElement(const Elem &e) const
{
    return recherche_element_noeud(e, racine);
}
Noeud_ARN *Arbre_ARN::recherche_element_noeud(const Elem &e, Noeud_ARN *n) const
{
    if (n == NULL)
        return NULL;
    else
    {
        if (n->cle == e)
            return n;
        else if (n->cle > e)
            recherche_element_noeud(e, n->fg);
        else if (n->cle < e)
            recherche_element_noeud(e, n->fd);
    }
    return n;
}

void Arbre_ARN::insere_element(const Elem &e)
{
    // Procédure récursif
    insere_element_noeud(racine, e);
    if (racine->couleur == 'r')
        racine->couleur = 'n';
//    dessineArbreBR();
}
void Arbre_ARN::insere_element_noeud(Noeud_ARN *&n, const Elem &e)
{
    cout << e << endl;
    // On fait comme pour l'insertion dans les arbres Binaire de recherche pour le moment et le nouveau noeud est de couleur rouge auto.
    if (n == NULL) // Si on a rien dans l'abr (on est en train d'ajouter la racine).
    {
        cout << "On ajoute le nouvelle élément" << endl;
        n = new Noeud_ARN(e, 'r'); // On met la couleur à noir car la racine doit être Noir d'après la première propriété.
    }
    else if (n->cle > e)
    {
        cout << n->cle << " " << n->couleur << endl;
        cout << "J'insere à gauche" << endl;
        insere_element_noeud(n->fg, e);
        // Appel de la procédure qui va tester pour chaque par rapport au noeud N à la remonté si on est équilibré ou pas.
        gere_cas_desequilibre_gauche(n);
        return;
    }
    else if (n->cle < e)
    {
        insere_element_noeud(n->fd, e);
        gere_cas_desequilibre_droite(n);
        return;
    }
}
void Arbre_ARN::gere_cas_desequilibre_gauche(Noeud_ARN *&n)
{
    cout << "Debut proc desequilibre gauche" << endl;
    if (n->cle == 10)
        cout << n->fg->cle << " " << n->fg->couleur << endl;
    if (n->fd != NULL)
    {
        cout << "ALLO " << endl;
        sleep(1);
        if (n->fg->couleur == 'r' &&
            n->fd->couleur == 'r')
        {
            cout << "Cas oncle" << endl;
            gere_cas_oncle_pere_rouge(n);
        }
    }
    else if ( n->fg->fg != NULL)
    {
        if (n->fg->couleur == 'r' && n->fg->fg->couleur == 'r')
        {
            cout << "Cas ligne" << endl;
            gere_cas_ligne_rouge_gauche(n);
        }
    }
    else if(n->fg->fd != NULL)
    {
        if (n->fg->couleur == 'r' && n->fg->fd->couleur == 'r')
        {
            cout << "Triangle gauche" << endl;
            gere_cas_triangle_rouge_gauche(n);
        }
    }
}
void Arbre_ARN::gere_cas_desequilibre_droite(Noeud_ARN *&n)
{
    cout << "Procédure gere desequilibre droite " << endl;
    cout << "Valeur du noeud parent actuel " << n->cle << " " << n->couleur << endl;
    cout << n->fd->fd << endl;
    sleep(1);
    cout << "Debut" << endl;
    //cout << n->fg << endl;
    if (n->fg != NULL)
    {
        if (n->fg->couleur == 'r' &&
            n->fd->couleur == 'r')
        {
            cout << "Cas oncle" << endl;
            gere_cas_oncle_pere_rouge(n);
        }
    }
    else if (n->fd->fd != NULL)
    {
        if (n->fd->couleur == 'r' && n->fd->fd->couleur == 'r')
        {
            cout << "Cas ligne rouge" << endl;
            gere_cas_ligne_rouge_droite(n);
        }
    }
    else if (n->fd->fg != NULL)
    {
        if (n->fd->couleur == 'r' && n->fd->fg->couleur == 'r')
        {
            cout << "Cas triangle" << endl;
            gere_cas_triangle_rouge_droite(n);
        }
    }
}
void Arbre_ARN::gere_cas_oncle_pere_rouge(Noeud_ARN *&n)
{
    // Je passe le père et l'oncle en noir.
    // Père.
    n->fg->couleur = 'n';
    // Oncle
    n->fd->couleur = 'n';
    // Je passe le grand père en rouge.
    n->couleur = 'r';
}
void Arbre_ARN::gere_cas_ligne_rouge_gauche(Noeud_ARN *&n)
{
    // Parent devient 'grand parent'.
    rotationDroite(n);
    // Le nouveau Grand-parent est le Parent_Noeud.
    // On inverse les couleurs du grand-parent et du Parent.
    char temp = n->fd->couleur;
    n->fd->couleur = n->couleur;
    n->couleur = temp;

    assert(n->couleur == 'n' && n->fd->couleur == 'r');
}
void Arbre_ARN::gere_cas_triangle_rouge_gauche(Noeud_ARN *&n)
{
    // Double rotation à faire.
    // 1 - Rotation sur le fils-gauche du grand-père où le noeud droit du gauche est devenu Parent.
    rotationGauche(n->fg);
    // 2 - Rotation sur le nouveau père(ancienement noeud droit du noeud gauche de n), ce dernier va avoir le grand père à sa droite (Devient oncle)
    rotationDroite(n);

    // ===============
    // On inverse les couleur du nouveau père avec l'ancien grand père.
    char temp = n->couleur;      // couleur du grand père.
    n->couleur = n->fd->couleur; // Le nouveau père prend la couleur du grand père.
    n->fd->couleur = temp;       // le grand père va prendre l'ancienne couleur du père qui est n mtn.
}
void Arbre_ARN::gere_cas_ligne_rouge_droite(Noeud_ARN *&n)
{
    // Parent devient 'grand parent'.
    rotationGauche(n);
    // Le nouveau Grand-parent est le Parent_Noeud.
    // On inverse les couleurs du grand-parent et du Parent.
    char temp = n->fg->couleur;
    n->fg->couleur = n->couleur;
    n->couleur = temp;
}
void Arbre_ARN::gere_cas_triangle_rouge_droite(Noeud_ARN *&n)
{

    // Double rotation à faire.
    // 1 - Rotation sur le fils-gauche du grand-père où le noeud droit du gauche est devenu Parent.
    // 2 - Rotation sur le nouveau père(ancienement noeud droit du noeud gauche de n), ce dernier va avoir le grand père à sa droite (Devient oncle)
    rotationDroite(n->fd);
    rotationGauche(n);

    // ===============
    // On inverse les couleur du nouveau père avec l'ancien grand père.
    char temp = n->couleur;      // couleur du grand père.
    n->couleur = n->fd->couleur; // Le nouveau père prend la couleur du grand père.
    n->fd->couleur = temp;       // le grand père va prendre l'ancienne couleur du père qui est n mtn.
}

void Arbre_ARN::rotationGauche(Noeud_ARN *&parent)
{
    Noeud_ARN *Pivot = parent->fd;
    parent->fd = Pivot->fg;
    // Il faut également que le Parent du pivot soit le grand père de l'ancien Parent:
    // Si ancien parent à gauche du grand père alors le pointeur gauche du grand père est le Pivot.

    // Sinon si l'ancien parent était à droite du grand-père, le fils droit du grand-père est le pivot.

    // Si son grand père n'existe pas alors la racine devient le Pivot.(On regarde dans insertion ?)
    Pivot->fg = parent;
    parent = Pivot;
}
void Arbre_ARN::rotationDroite(Noeud_ARN *&parent)
{
    Noeud_ARN *Pivot = parent->fg;
    parent->fg = Pivot->fd;
    Pivot->fd = parent;
    parent = Pivot;
}
void Arbre_ARN::test_arbre_RN()
{

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
    insere_element(100);
    cout << "Debut insere 45" << endl;
    insere_element(45);
    sleep(1);
    insere_element(32);
    insere_element(29);
    insere_element(3);
    sleep(10);
}