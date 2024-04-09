/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 21 novembre 2023
    copyright            : (C) 2023 par H. ASRI, N. CATHERINE, J. HABBA, S. PERRET
    e-mail               : hazim.asri@insa-lyon.fr, noam.catherine@insa-lyon.fr, jassir.habba@insa-lyon.fr, simon.perret@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Catalogue::Ajouter(Trajet *trajet)
{
    liste->Ajouter(trajet);
    #ifdef MAP
        cout << "Appel au ajouter de <Catalogue>" << endl;
    #endif
}//----- Fin de Méthode


void Catalogue::AfficherCatalogue() const
{
    liste->Afficher();
    #ifdef MAP
        cout << "Appel au afficherCatalogue de <Catalogue>" << endl;
    #endif
} //----- Fin de Méthode


//send 0 if not found, 1 if found
int Catalogue::RechercherSimple(char *depart, char *arrive) const 
{
    #ifdef MAP
        cout << "Appel au rechercherSimple de <Catalogue>" << endl;
    #endif
    Noeud *noeud = liste->GetTete();

    int count = 0;

    while (noeud != NULL)
    {
        const Trajet *trajet = noeud->GetTrajet();
        
        // Compare le départ et l'arrivée du trajet avec les paramètres
        if (!strcmp(trajet->GetArrive(), arrive) && !strcmp(trajet->GetDepart(), depart))
        {
            // Affiche le trajet correspondant
            cout << "Trajet trouve : ";
            noeud->GetTrajet()->Afficher();
            cout << endl;
            count++;
        }

        noeud = noeud->GetNoeudSuivant();
    }
    return count;
} //----- Fin de Méthode

// retourne 1 si un duplique trajet est trouvé et 0 sinon
int Catalogue::VerifierDupliquer(Trajet * trajet) const
 {
    #ifdef MAP
        cout << "Appel au verifierDupliquer de <Catalogue>" << endl;
    #endif
    Noeud *noeud = liste->GetTete();
    
    while(noeud != NULL)
    {
        const Trajet *t = noeud->GetTrajet();
        if(trajet->Equals(t))
        {
            return 1; // si un duplique trajet est trouvé
        }
        noeud = noeud->GetNoeudSuivant();
    }
    return 0; // si aucun duplique trajet n'est trouvé

}//----- Fin de Méthode

void Catalogue::RechercherAvancee(char* debut, char* fin) const
{
    char *visited[100]; // Assumption: there will be no more than 100 cities
    int visitedCount = 0;
    Trajet *currentPath[100]; // Assumption: there will be no more than 100 trajets in a path
    int pathCount = 0;
    int count = 0;

    rechercherTransitif(debut, fin, visited, visitedCount, currentPath, pathCount, count);

    
}//----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue() : liste(new Liste())
{
    #ifdef MAP
        cout << "Appel au constructeur de <Catalogue>" << endl;
    #endif
} //----- Fin de Catalogue


Catalogue::~Catalogue()
{
    delete liste;
    #ifdef MAP
        cout
            << "Appel au destructeur de <Catalogue>" << endl;
    #endif
    // Le destructeur de Catalogue libérera automatiquement la mémoire utilisée par la Liste
} //----- Fin de ~Catalogue

Liste * Catalogue::GetListe() const
{
    return liste;
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

// Cette fonction recherche tous les trajets possibles entre deux villes en utilisant un algorithme de recherche en profondeur.
bool Catalogue::rechercherTransitif(const char *depart, const char *arrive, char **visited, int &visitedCount, Trajet **currentPath, int &pathCount, int &count) const
{
    // Vérifie si la ville de départ a déjà été visitée.
    for (int i = 0; i < visitedCount; i++)
    {
        if (strcmp(visited[i], depart) == 0)
        {
            return false; // Si la ville a déjà été visitée, on retourne false pour éviter les boucles.
        }
    }

    // Ajoute la ville de départ à la liste des villes visitées.
    visited[visitedCount] = new char[strlen(depart) + 1];
    strcpy(visited[visitedCount], depart);
    visitedCount++;

    // Parcourt tous les trajets du catalogue.
    Noeud *noeud = liste->GetTete();
    while (noeud != NULL)
    {
        Trajet* trajet = noeud->GetTrajet();
        // Si le trajet commence par la ville de départ, on l'ajoute au chemin actuel.
        if (strcmp(trajet->GetDepart(), depart) == 0)
        {
            currentPath[pathCount] = trajet;
            pathCount++;

            // Si le trajet se termine par la ville d'arrivée, on a trouvé un trajet.
            if (strcmp(trajet->GetArrive(), arrive) == 0)
            {
                count++; // Incrémente le compteur de trajets trouvés.
                std::cout << "Trajet trouve : ";
                // Affiche le trajet trouvé.
                for (int i = 0; i < pathCount; i++)
                {
                    currentPath[i]->Afficher();
                    if (i < pathCount - 1)
                    {
                        std::cout << " - ";
                    }
                }
                std::cout << std::endl;
            }
            else
            {
                // Si le trajet ne se termine pas par la ville d'arrivée, on continue la recherche à partir de la ville d'arrivée du trajet.
                rechercherTransitif(trajet->GetArrive(), arrive, visited, visitedCount, currentPath, pathCount, count);
            }

            // Retire le trajet du chemin actuel.
            pathCount--;
        }
        noeud = noeud->GetNoeudSuivant();
    }

    // Retire la ville de départ de la liste des villes visitées.
    visitedCount--;

    for (int i = 0; i <= visitedCount; i++) {
        delete[] visited[i];
    }

    delete[] visited;
    return false; // Retourne false pour continuer la recherche.
}//----- Fin de Méthode
