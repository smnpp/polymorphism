/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 21 novembre 2023
    copyright            : (C) 2023 par H. ASRI, N. CATHERINE, J. HABBA, S. PERRET
    e-mail               : hazim.asri@insa-lyon.fr, noam.catherine@insa-lyon.fr, jassir.habba@insa-lyon.fr, simon.perret@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ----------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h" 
#include <cstring>

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::Afficher() const
{
    #ifdef MAP
        cout << "Appel au afficher de <TrajetCompose>" << endl;
    #endif

    Noeud *noeud = liste->GetTete();
    cout << "(TC)";
    while(noeud != NULL)
    {
        const TrajetSimple *trajet = dynamic_cast<const TrajetSimple *>(noeud->GetTrajet());
        cout << " de " << trajet->GetDepart() << " a " << trajet->GetArrive() << " en " << trajet->GetTransport();

        if(noeud->GetNoeudSuivant() != NULL) 
        cout << " - ";

        noeud = noeud->GetNoeudSuivant();
    }
} //----- Fin de Méthode Afficher


const Liste *TrajetCompose::GetListe() const
{
    #ifdef MAP
        cout << "Appel au getter liste de <TrajetCompose>" << endl;
    #endif
    return liste;
} //----- Fin de Méthode GetListe


bool TrajetCompose::Equals(const Trajet *trajet) const
{
    #ifdef MAP
        cout << "Appel au equals de <TrajetCompose>" << endl;
    #endif
    const TrajetCompose *trajetCompose = dynamic_cast<const TrajetCompose *>(trajet);

    if(trajetCompose != NULL)
    {
        if(!strcmp(trajetCompose->GetDepart(), depart) && !strcmp(trajetCompose->GetArrive(), arrive))
        {
            if(trajetCompose->GetListe()->GetTaille() == liste->GetTaille())
            {
                Noeud *noeud = liste->GetTete();
                Noeud *other = trajetCompose->GetListe()->GetTete();
                while(noeud != NULL)
                {
                    if(!noeud->GetTrajet()->Equals(other->GetTrajet()))
                    {
                        return false;
                    }
                    noeud = noeud->GetNoeudSuivant();
                    other = other->GetNoeudSuivant();
                }
                return true;
            }
        }
    }
    return false;
} //----- Fin de Méthode Equals

//-------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose(const char *depart, const char *arrive, Liste *liste) : Trajet(depart, arrive)
{
    #ifdef MAP
        cout << "Appel au constructeur de <TrajetCompose>" << endl;
    #endif
    this->liste = new Liste();
    for(int i = 0; i < liste->GetTaille(); i++) // copie profonde
    {
        this->liste->Ajouter(liste->GetNoeud(i)->GetTrajet());
    }

    this->depart = new char[strlen(depart) + 1];
    this->arrive = new char[strlen(arrive) + 1];

    strcpy(this->depart, depart);
    strcpy(this->arrive, arrive);
} //----- Fin de TrajetCompose

TrajetCompose::~TrajetCompose()
{
    #ifdef MAP
        cout << "Appel au destructeur de <TrajetCompose>" << endl;
    #endif
    delete[] depart;
    delete[] arrive;
    delete liste;
} //----- Fin de ~TrajetCompose
