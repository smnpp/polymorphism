/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 21 novembre 2023
    copyright            : (C) 2023 par H. ASRI, N. CATHERINE, J. HABBA, S. PERRET
    e-mail               : hazim.asri@insa-lyon.fr, noam.catherine@insa-lyon.fr, jassir.habba@insa-lyon.fr, simon.perret@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if !defined(GESTIONFICHIER_H)
#define GESTIONFICHIER_H


//--------------------------------------------------- Interfaces utilisées
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------

//------------------------------------------------------------------------

class GestionFichier
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques

    GestionFichier() {};
    // Mode d'emploi :
    // 
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    virtual ~GestionFichier() {};
    // Mode d'emploi :
    // Destructeur de Trajet
    // Contrat :
    //

	void SauvegarderFichier(Catalogue **catalogue, const string &nomFichier);
	// Mode d'emploi :
    // Destructeur de Trajet
    // Contrat :
    //

	void ChargerFichier(Catalogue **catalogue, const string &nomFichier);
	// Mode d'emploi :
    // Destructeur de Trajet
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE
private:
	bool OuvrirFichier(const string &nomFichier);
    // Mode d'emploi :
    // Destructeur de Trajet
    // Contrat :
    //

	void FermerFichier();
    // Mode d'emploi :
    // Destructeur de Trajet
    // Contrat :
    //

//----------------------------------------------------- Attributs protégés
protected:
	fstream fic;

//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
};

//----------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
