#include "module/performance.h"

Perfomance_Class::Perfomance_Class()
{
    type_collection_test = '\0';
    Nombre_element_ajouter = 0;
    nombre_collection = 0;
}
Perfomance_Class::~Perfomance_Class()
{
    type_collection_test = '\0';
    Nombre_element_ajouter = 0;
    nombre_collection = 0;
}
Perfomance_Class::Perfomance_Class(char &choix_collection) : type_collection_test(choix_collection)
{
}
void Perfomance_Class::choix_test_performance()
{
    cout << "Saisir le nombre d'Arbre à Initialiser" << endl;
    cin >> nombre_collection;
    cout << "Saisir le nombre d'élément que vous voulez insérer pour tester les perfomances des arbres" << endl;
    cin >> Nombre_element_ajouter;
}
void Perfomance_Class::Test_Perfomance_Collection()
{
    choix_test_performance();
    string choix;
    vector<float> temps_perf;
    // moyenne total : Temps total pour insérer 1 élément dans N arbre.
    // moyenne_insertion : Temps pour insérer un élément dans N arbre.
    if (type_collection_test == '1') // Arbre binaire de base.
    {
        cout << "Choisir le PAS pour savoir à partir de combien d'insertion on sauvegarde le temps :" << endl;
        cin >> choix;
        Perfomance_Arbre_Binaire(atoi(choix.c_str()), temps_perf);
        // On va écrire ce temps dans un fichier.
        string nomF = "data/performance_ABR.txt";
        Creer_Fichier(nomF, temps_perf, atoi(choix.c_str()));
    }
    else if (type_collection_test == '2') // Arbre Rouge et noir.
    {
        cout << "Choisir le PAS pour savoir à partir de combien d'insertion on sauvegarde le temps : " << endl;
        cin >> choix;
        Perfomance_Arbre_Rouge_Noir(atoi(choix.c_str()), temps_perf);
        // On va écrire ce temps dans un fichier.
        string nomF = "data/performance_ARN.txt";
        Creer_Fichier(nomF, temps_perf, atoi(choix.c_str()));
    }
    return;
}
void Perfomance_Class::Perfomance_Arbre_Rouge_Noir(const int &pas, vector<float> &tab_temps)
{
    float temps_insertion = 0;
    // Tableau de collection.
    Arbre_ARN tab_Arbre_test[nombre_collection];

    chrono::time_point<std::chrono::system_clock> start, end;
    for (int i = 0; i < Nombre_element_ajouter; i++)
    {
        // Pour chaque élément à ajouter on fait une insertion dans tous les arbres du tableau.
        start = chrono::system_clock::now();
        cout << i << endl;
        for (int j = 0; j < nombre_collection; j++)
        {
            // 1. On insere n élément dans l'arbre tab[i].
            tab_Arbre_test[j].insere_element(rand());
        }
        end = chrono::system_clock::now();
        // On calcule le temps passer pour une insertion dans N arbre de taille équivalente.
        float elapsed_microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count();
        // Le temps pour une insertion dans N arbres de taille n équivalent est sauvegardé.
        temps_insertion += elapsed_microseconds;

        if ((i) != 0 && (i % pas) == 0)
        { // Je sauvegarde le temps pour n % B.
            // Pour n arbre à n % B je sauvegarde le temps d'insertion.
            tab_temps.push_back(temps_insertion / nombre_collection);
        }
    }
    // A la sortie dans tab_temps on doit avoir tous les chronos pour un certains (nombre d'élément % pas) pour N arbres.
}
void Perfomance_Class::Perfomance_Arbre_Binaire(const int &pas, vector<float> &tab_temps)
{
    float temps_insertion = 0;
    // Tableau de collection.
    Arbre tab_Arbre_test[nombre_collection];

    chrono::time_point<std::chrono::system_clock> start, end;
    for (int i = 0; i < Nombre_element_ajouter; i++)
    {
        // Pour chaque élément à ajouter on fait une insertion dans tous les arbres du tableau.
        start = chrono::system_clock::now();
        cout << i << endl;
        for (int j = 0; j < nombre_collection; j++)
        {
            // 1. On insere n élément dans l'arbre tab[i].
            tab_Arbre_test[j].insere_element(rand());
        }
        end = chrono::system_clock::now();
        // On calcule le temps passer pour une insertion dans N arbre de taille équivalente.
        float elapsed_microseconds = chrono::duration_cast<chrono::microseconds>(end - start).count();
        // Le temps pour une insertion dans N arbres de taille n équivalent est sauvegardé.
        temps_insertion += elapsed_microseconds;

        if ((i) != 0 && (i % pas) == 0)
        { // Je sauvegarde le temps pour n % B.
            // Pour n arbre à n % B je sauvegarde le temps d'insertion.
            tab_temps.push_back(temps_insertion / nombre_collection);
        }
    }
    // A la sortie dans tab_temps on doit avoir tous les chronos pour un certains (nombre d'élément % pas) pour N arbres.
}
void Perfomance_Class::Creer_Fichier(string &nom_fichier, const vector<float> &temps, const int &pas)
{
    //nom_fichier = "../" + nom_fichier;
    struct stat buffer;
    bool file_exist = (stat(nom_fichier.c_str(), &buffer) == 0);

    if (file_exist)
    { // Si le fichier existait déjà on va le supprimer pour éviter des conflits et éviter de devoir à gérer la création de plusieurs fichier selon un patern.
        if (remove(nom_fichier.c_str()) != 0)
        {
            cout << "Erreur dans la suppression du fichier" << endl;
        }
        else
            cout << "Fichier Supprimer." << endl;
    }
    ofstream myfile(nom_fichier);

    int n_pour_temps = pas; 

    if (myfile.is_open())
    {
        myfile << "# 'nb element' 'Temps' \n";
        for (const auto& valeur_index : temps)
        {
            myfile << n_pour_temps;
            myfile << " ";
            myfile << valeur_index;
            myfile << "\n";

            n_pour_temps+= pas;
        }
        myfile.close();
    }
    else
    {
        cout << "Erreur au niveau de l'écriture du fichier" << endl;
    }
    cout << "Fin de l'écriture dans le fichier perforamcn" << endl;
}