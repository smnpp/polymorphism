/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 21 novembre 2023
    copyright            : (C) 2023 par H. ASRI, N. CATHERINE, J. HABBA, S. PERRET
    e-mail               : hazim.asri@insa-lyon.fr, noam.catherine@insa-lyon.fr, jassir.habba@insa-lyon.fr, simon.perret@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ----------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetSimple::Afficher() const {
    cout << "(TS) de " << depart << " a " << arrive << " en " << transport;
} //----- Fin de Méthode Afficher

const char* TrajetSimple::GetTransport() const{
    return transport;
} //----- Fin de Méthode GetTransport

bool TrajetSimple::Equals(const Trajet *trajet) const
{
    #ifdef MAP
        cout << "Appel au equals de <TrajetSimple>" << endl;
    #endif
    const TrajetSimple *trajetSimple = dynamic_cast<const TrajetSimple *>(trajet);
    if(trajetSimple != NULL)
    {
        return !strcmp(trajetSimple->GetDepart(), depart) && 
            !strcmp(trajetSimple->GetArrive(), arrive) && 
            !strcmp(trajetSimple->GetTransport(), transport);
    }
    return false;
} //----- Fin de Méthode Equals


//-------------------------------------------- Constructeurs - destructeur
TrajetSimple::TrajetSimple(const char* newDepart, const char* newArrive, const char* newTransport) : Trajet(newDepart, newArrive){
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetSimple>" << endl;
    #endif

    transport = new char[strlen(newTransport) + 1];
    strcpy(transport, newTransport);
} //----- Fin de TrajetSimple

TrajetSimple::~TrajetSimple () {
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetSimple>" << endl;
    #endif
    delete[] transport;
} //----- Fin de ~TrajetSimple
