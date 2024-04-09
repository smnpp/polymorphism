/*************************************************************************
                           Liste  -  description
                             -------------------
    début                : 21 novembre 2023
    copyright            : (C) 2023 par H. ASRI, N. CATHERINE, J. HABBA, S. PERRET
    e-mail               : hazim.asri@insa-lyon.fr, noam.catherine@insa-lyon.fr, jassir.habba@insa-lyon.fr, simon.perret@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Liste> (fichier Liste.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Liste.h"
#include "TrajetSimple.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// Ajoute un élément à la fin de la liste.
void Liste::Ajouter(Trajet *trajet)
{
    #ifdef MAP
        cout << "Appel au ajouter de <Liste>" << endl;
    #endif

    Noeud * noeud = new Noeud(NULL, trajet);
    taille++; //increment taille

    if (tete == NULL)
    {
        tete = noeud; // Si la liste est vide, le nouvel élément devient le premier
        return;
    }

    Noeud *temp = tete;
    while (temp->GetNoeudSuivant() != NULL)
    {
        temp = temp->GetNoeudSuivant();
    }

    temp->SetNoeudSuivant(noeud);
    // Ajouter le nouvel élément à la fin de la liste
}//----- Fin de Méthode Ajouter

// Affichage Liste
void Liste::Afficher() const
{
    #ifdef MAP
        cout << "Appel au afficher de <Liste>" << endl;
    #endif
    int count = 0;
    Noeud *temp = tete;
    while (temp != NULL)
    {
        const Trajet *trajet = temp->GetTrajet();

        cout << count + 1 << " : ";
        trajet->Afficher();
        cout << endl;
        temp = temp->GetNoeudSuivant();

        count++;
    }
}//----- Fin de Méthode Afficher

// Récupère la tete de la liste
Noeud *Liste::GetTete() const
{
    return tete;
}//----- Fin de Méthode GetTete

// Récupère le noeud à l'index en paramètre
Noeud *Liste::GetNoeud(int index) const
{
    Noeud *temp = tete;
    int i = 0;
    while (temp != NULL)
    {
        if (i == index)
        {
            return temp;
        }
        temp = temp->GetNoeudSuivant();
        i++;
    }
    return NULL;
}//----- Fin de Méthode GetNoeud

// Ajoute un élément à la fin de la liste.
int Liste::GetTaille() const
{
    return taille;
}//----- Fin de Méthode GetTaille

// Test si deux listes sont égals
bool Liste::Equals(const Liste *liste) const
{
    #ifdef MAP
        cout << "Appel au equals de <Liste>" << endl;
    #endif
    if (taille != liste->GetTaille())
    {
        return false;
    }

    Noeud *noeud = tete;
    Noeud *n = liste->GetTete();

    while (noeud != NULL)
    {
        Trajet *trajet = noeud->GetTrajet();
        Trajet *trajet2 = n->GetTrajet();

        if (!trajet->Equals(trajet2))
        {
            return false;
        }

        noeud = noeud->GetNoeudSuivant();
        n = n->GetNoeudSuivant();
    }

    return true;
}//----- Fin de Méthode Equals


//-------------------------------------------- Constructeurs - destructeur
Liste::Liste()
{
    tete = NULL; // Initialise la liste avec un pointeur de tête nul.
    taille = 0;

    #ifdef MAP
        cout << "Appel au constructeur de <Liste>" << endl;
    #endif
} //----- Fin de Liste

Liste::~Liste()
{
    Noeud *courant = tete;
    while (courant != NULL)
    {
        Noeud *suivant = courant->GetNoeudSuivant();
        delete courant->GetTrajet();
        delete courant;
        courant = suivant;
    }

    #ifdef MAP
        cout << "Appel au destructeur de <Liste>" << endl;
    #endif
} //----- Fin de ~Liste

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
