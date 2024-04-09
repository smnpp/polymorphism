/*************************************************************************
                           Liste  -  description
                             -------------------
    début                : 21 novembre 2023
    copyright            : (C) 2023 par H. ASRI, N. CATHERINE, J. HABBA, S. PERRET
    e-mail               : hazim.asri@insa-lyon.fr, noam.catherine@insa-lyon.fr, jassir.habba@insa-lyon.fr, simon.perret@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Liste> (fichier Liste.h) ----------------
#ifndef LISTE_H
#define LISTE_H

//--------------------------------------------------- Interfaces utilisées
#include "Noeud.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Liste> :
// Représente une liste chaînée de nœuds
//
//------------------------------------------------------------------------



class Liste
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
    void Ajouter(Trajet * elem);
    // Mode d'emploi :
    // Ajoute un élément à la fin de la liste.
    // elem : Le trajet à ajouter.
    // Contrat :

    void Afficher() const;
    // Mode d'emploi :
    // Affiche la liste
    // 
    // Contrat :

    Noeud* GetTete() const;
    // Mode d'emploi :
    // Récupère la tete de la liste
    // 
    // Contrat :

    Noeud* GetNoeud(int index) const;
    // Mode d'emploi :
    // Récupère le noeud  à l'index en paramètre de la liste
    // 
    // Contrat :

    int GetTaille() const;
    // Mode d'emploi :
    // Récupère la taille de la liste
    // 
    // Contrat :

    bool Equals(const Liste *liste) const;
    // Mode d'emploi :
    // Vérifie si la liste est égal à une autre liste.
    // 
    // Contrat :

//-------------------------------------------- Constructeurs - destructeur
    Liste();
    // Mode d'emploi :
    // Initialise la liste avec un pointeur de tête nul.
    // Contrat :
    //

    virtual ~Liste();
    // Mode d'emploi :
    // Libère la mémoire occupée par tous les nœuds de la liste.
    // Contrat :
    //

             
//------------------------------------------------------------------ PRIVE        
protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    int taille;
    Noeud* tete; // Pointeur vers le premier nœud de la liste.
};

#endif // LISTE.H
