/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 21 novembre 2023
    copyright            : (C) 2023 par H. ASRI, N. CATHERINE, J. HABBA, S. PERRET
    e-mail               : hazim.asri@insa-lyon.fr, noam.catherine@insa-lyon.fr, jassir.habba@insa-lyon.fr, simon.perret@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------
#if !defined(TRAJETSIMPLE_H)
#define TRAJETSIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include <cstring>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Représentation d'un trajet dit "simple" dans le catalogue des trajet
//
//------------------------------------------------------------------------

class TrajetSimple : public Trajet 
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques

    virtual bool Equals(const Trajet *trajet) const;
    // Mode d'emploi :
    // 
    // Contrat :
    //

    virtual void Afficher() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    const char* GetTransport() const;
    // Mode d'emploi :
    // Récupère le moyen de transport pour un trajet simple
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    TrajetSimple (const char* depart, const char* arrive, const char* transport);
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual ~TrajetSimple();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    char* transport;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // TRAJETCOMPOSE_H

