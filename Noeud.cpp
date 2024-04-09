/*************************************************************************
                           Noeud  -  description
                             -------------------
    début                : 21 novembre 2023
    copyright            : (C) 2023 par H. ASRI, N. CATHERINE, J. HABBA, S. PERRET
    e-mail               : hazim.asri@insa-lyon.fr, noam.catherine@insa-lyon.fr, jassir.habba@insa-lyon.fr, simon.perret@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Noeud> (fichier Noeud.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Noeud.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// Obtient le nœud suivant.
Noeud *Noeud::GetNoeudSuivant() const
{
    return noeud;
} //----- Fin de Méthode GetNoeudSuivant



// Modifier le pointeur du nœud suivant
void Noeud::SetNoeudSuivant(Noeud *suivant)
{
    noeud = suivant;
} //----- Fin de Méthode SetNoeudSuivant

// Obtient le trajet associé au nœud.
Trajet *Noeud::GetTrajet() const
{
    return trajet;
} //----- Fin de Méthode GetTrajet


//-------------------------------------------- Constructeurs - destructeur
Noeud::Noeud(Noeud *suivant, Trajet *trajet) : noeud(suivant), trajet(trajet)
{
    #ifdef MAP
        cout << "Appel au constructeur de <Noeud>" << endl;
    #endif
} //----- Fin de Noeud

Noeud::~Noeud()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Noeud>" << endl;
    #endif
} //----- Fin de ~Noeud


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
