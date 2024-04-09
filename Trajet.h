/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 21 novembre 2023
    copyright            : (C) 2023 par H. ASRI, N. CATHERINE, J. HABBA, S. PERRET
    e-mail               : hazim.asri@insa-lyon.fr, noam.catherine@insa-lyon.fr, jassir.habba@insa-lyon.fr, simon.perret@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if !defined(TRAJET_H)
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Classe Abstraite dont hérite TrajetSimple et TrajetCompose
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC
public:
//----------------------------------------------------- Méthodes publiques
    virtual void Afficher() const = 0;
    // Mode d'emploi :
    // Add function definition for 'Afficher'
    // Contrat :
    //

    const char *GetDepart() const;
    // Mode d'emploi :
    // Get la chaine de caractère de la ville de départ
    // Contrat :
    //
    

    const char *GetArrive() const;
    // Mode d'emploi :
    // Get la chaine de caractère de la ville d'arrive
    // Contrat :
    //
    

    virtual bool Equals(const Trajet *trajet) const;
    // Mode d'emploi :
    // 
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    virtual ~Trajet();
    // Mode d'emploi :
    // Destructeur de Trajet
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Attributs protégés
    Trajet(const char *depart, const char *arrive);
    // Mode d'emploi :
    //
    // Contrat :
    //

//----------------------------------------------------- Méthodes protégées
    char *depart;
    char *arrive;
};

//----------------------------- Autres définitions dépendantes de <Trajet>

#endif // TRAJET_H
