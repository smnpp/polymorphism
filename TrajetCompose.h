/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 21 novembre 2023
    copyright            : (C) 2023 par H. ASRI, N. CATHERINE, J. HABBA, S. PERRET
    e-mail               : hazim.asri@insa-lyon.fr, noam.catherine@insa-lyon.fr, jassir.habba@insa-lyon.fr, simon.perret@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------
#if !defined(TRAJETCOMPOSE_H)
#define TRAJETCOMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
#include "TrajetSimple.h"
#include "Liste.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// Représentation d'un trajet dit "compose" dans le catalogue des trajet
//
//------------------------------------------------------------------------


class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
    const Liste *GetListe() const;
    // Mode d'emploi :
    //
    // Contrat :
    //
	
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
	
//-------------------------------------------- Constructeurs - destructeur
	TrajetCompose(const char *depart, const char *arrive, Liste *liste);
    // Mode d'emploi :
    //
    // Contrat :
    //
	virtual ~TrajetCompose();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	Liste *liste;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // TRAJETCOMPOSE_H
