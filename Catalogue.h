/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 21 novembre 2023
    copyright            : (C) 2023 par H. ASRI, N. CATHERINE, J. HABBA, S. PERRET
    e-mail               : hazim.asri@insa-lyon.fr, noam.catherine@insa-lyon.fr, jassir.habba@insa-lyon.fr, simon.perret@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#ifndef CATALOGUE_H
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Liste.h"
#include "Noeud.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include <cstring>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Référencement de tous les trajets disponible à l'utilisateur
//
//------------------------------------------------------------------------
class Catalogue
{
//----------------------------------------------------------------- PUBLIC
public:

//----------------------------------------------------- Méthodes publiques
    void Ajouter(Trajet *trajet);
    // Mode d'emploi :
    // Ajoute un trajet au catalogue
    // Contrat :
    //

    void AfficherCatalogue() const;
    // Mode d'emploi :
    // Affiche le catalogue
    // Contrat :
    //

    int RechercherSimple(char *debut, char *fin) const;
    // Mode d'emploi :
    // Rechercher simple
    // Contrat :
    //

    void RechercherAvancee(char *debut, char *fin) const;
    // Mode d'emploi :
    // Rechercher avancée pour les trajets complexe
    // Contrat :
    //

    int VerifierDupliquer(Trajet * trajet) const;
    // Mode d'emploi :
    // Verifier qu'il n'existe pas déjà ce trajet
    // Contrat :
    //

    Liste * GetListe() const;

//-------------------------------------------- Constructeurs - destructeur
    Catalogue();
    // Mode d'emploi :
    // Constructeur de Catalogue
    // Contrat :
    //

    // Destructeur de Catalogue
    ~Catalogue();
    // Mode d'emploi :
    // Destructeur de Catalogue
    // Contrat :
    //


//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    bool rechercherTransitif(const char *depart, const char *arrive, char **visited, int &visitedCount, Trajet **currentPath, int &pathCount, int &count) const;

//----------------------------------------------------- Attributs protégés
    Liste *liste;
};

//-------------------------------- Autres définitions dépendantes de <Catalogue>

#endif // CATALOGUE_H
