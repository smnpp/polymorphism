/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 21 novembre 2023
    copyright            : (C) 2023 par H. ASRI, N. CATHERINE, J. HABBA, S. PERRET
    e-mail               : hazim.asri@insa-lyon.fr, noam.catherine@insa-lyon.fr, jassir.habba@insa-lyon.fr, simon.perret@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

// Méthode pour récupéré le départ du trajet
const char* Trajet::GetDepart() const {
    return depart;
} //----- Fin de Méthode GetDepart

// Méthode pour récupéré l'arrive du trajet
const char* Trajet::GetArrive() const {
    return arrive;
} //----- Fin de Méthode GetArrive

bool Trajet::Equals(const Trajet* trajet) const {
    #ifdef MAP
        cout << "Appel au equals de <Trajet>" << endl;
    #endif
    return !strcmp(trajet->GetDepart(), depart) && 
        !strcmp(trajet->GetArrive(), arrive);
} //----- Fin de Méthode Equals

//-------------------------------------------- Constructeurs - destructeur
Trajet::Trajet(const char* newDepart, const char* newArrive) {
    #ifdef MAP
        cout << "Appel au constructeur de <Trajet>" << endl;
    #endif

    depart = new char[strlen(newDepart) + 1];
    arrive = new char[strlen(newArrive) + 1];
    strcpy(depart, newDepart);
    strcpy(arrive, newArrive);
} //----- Fin de Trajet

Trajet::~Trajet () {
    #ifdef MAP
        cout << "Appel au destructeur de <Trajet>" << endl;
    #endif
    delete[] depart;
    delete[] arrive;
} //----- Fin de ~Trajet

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
