#ifndef _ABRE_
#define _ABRE_

#include "element.h"
#include "Noeud.h"

class Arbre
{
    public :
        // Constructeur de mon Arbre. 
        Arbre();
        
        ~Arbre();
        // Constructeur par copie à partir d'un Arbre.
        Arbre(const Arbre& l);
        
        // Recherche un élément dans un arbre binaire et retourne l'adresse vers ce Noeud.
        bool rechercheElement(const Elem& e) const;

        // Appel récursif sur l'abre à partir de l'adresse racine de l'arbre.
        bool recherche_a_partir_Noeud(Noeud* n, const Elem& e) const;

        // Insere l'élément e que l'on prend dans le main.
        void insere_element(const Elem& e);
        // Procédure récursive qui va ajouter l'élément à l'endroit le plus profond de la branche gauche ou droite.
        Noeud* insere_element_partir_Noeud(Noeud* n,const Elem& e);
        
        // Propose un menu pour l'utilisateur qui peut choisir le type d'affichage (Infixe, postfixe, préfixe).
        void menu_choix_affichage_arbre() const;

        // Procédure pour mettre un peu d'arborescence.
        void espacement_affichage_arbre(const int& profondeur) const;

        // Procédure d'affichage infixe.
        void affichage_Infixe() const;
        void affichage_Infixe_Noeud(Noeud* n, int &profondeur) const;
        
        // Procédure d'affichage PostFixe.
        void affichage_PostFixe() const;
        void affichage_PostFixe_Noeud(Noeud* n, int &profondeur) const;

        // Procédure d'affichage Prefixe.
        void affichage_Prefixe() const;
        void affichage_Prefixe_Noeud(Noeud* n, int &profondeur) const;

        // Supprime l'élément e que l'on passe en paramètre.
        void supprime_element(const Elem& e);

        // Fonction recursive sur les noeuds pour trouver l'élément à supprimer et réorganiser l'arbre.
        Noeud* supprime_depuis_noeud(Noeud* n, const Elem& e);

        // Va regarder dans la partie la plus à gauche du noeud pour trouver la valeur la plus petite du noeud pour satisfaire la propriété de l'ABR.
        Noeud* valeur_plus_petite_depuis_noeud(Noeud*& n);
        
        // Procédure qui va appeler vide_noeud(rec)
        void vide();
        // Procédure réc qui va faire un parcours postfixe pour supprimer tous les éléments de l'arbre.
        Noeud* vide_noeud(Noeud* n);

        // Dis si l'arbre est vide
        bool est_vide()const;
        // Va faire les appels récursif sur les branches de l'arbre que l'on veut copier et créer un 
        Noeud* recopie_arbre(Noeud* n,Noeud*& noeud_parcours_abr);

        Arbre& operator= (const Arbre& l);

        // Procédure permettant de faire des tests sur les fonctions et procédures sur les arbres.
        void tests_arbre();
    protected:
        Noeud* racine; // Premier élément de l'arbre.
        int hauteur;
};

#endif