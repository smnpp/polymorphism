/*************************************************************************
                           Noeud  -  description
                             -------------------
    début                : 21 novembre 2023
    copyright            : (C) 2023 par H. ASRI, N. CATHERINE, J. HABBA, S. PERRET
    e-mail               : hazim.asri@insa-lyon.fr, noam.catherine@insa-lyon.fr, jassir.habba@insa-lyon.fr, simon.perret@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Noeud> (fichier Noeud.h) ----------------
#ifndef NOEUD_H
#define NOEUD_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Noeud>
// Représente un nœud dans une liste chaînée.
//
//------------------------------------------------------------------------
class Noeud
{
public:
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
    Noeud *GetNoeudSuivant() const;
    // Mode d'emploi :
    // Obtient le nœud suivant
    // Contrat :
    //

    void SetNoeudSuivant(Noeud *suivant);
    // Mode d'emploi :
    // Modifie le noeud suivant
    // Contrat :
    //

    Trajet *GetTrajet() const;
    // Mode d'emploi :
    // Obtient le trajet associé au nœud
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Noeud(Noeud *suivant, Trajet *trajet);
    // Mode d'emploi :
    // suivant : Le pointeur vers le nœud suivant
    // trajet : Le trajet associé au nœud
    // Contrat :
    //

    // Destructeur de Noeud.
    virtual ~Noeud();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE
private:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    Noeud *noeud;   // Pointeur vers le nœud suivant.
    Trajet *trajet; // Trajet associé au nœud.
};

//------------------------------ Autres définitions dépendantes de <Noeud>

#endif // NOEUD_H
