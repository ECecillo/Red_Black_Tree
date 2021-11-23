#include <iostream>
#include <chrono>
#include <cstdio> //fopen, fclose, fread, fwrite, feof
#include <stdio.h>
#include <cstdlib> //exit
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <fstream>
#include <vector>

#include "arbre_ARN.h"
#include "arbre.h"

#ifndef PERFORMANCE_H
#define PERFORMANCE_H

class Perfomance_Class
{
    public:
        Perfomance_Class();
        Perfomance_Class(char &choix_collection);
        ~Perfomance_Class();
        // Procédure qui va demander à l'utilisateur le nombre de Collection et le nombre d'élément à insérer dans chacune des collections.
        void choix_test_performance();
        // Procédure qui va tester la collection et retourner son temps d'insertion.
        void Test_Perfomance_Collection();

        void Perfomance_Arbre_Rouge_Noir(const int& pas, vector<float>&);
        // 
        void Perfomance_Arbre_Binaire(const int& pas, vector<float>&); 

        void Creer_Fichier(string &nom_Fichier, const vector <float>& temps_collection);
    private:
        int Nombre_element_ajouter;
        int nombre_collection;
        char type_collection_test;
};

#endif