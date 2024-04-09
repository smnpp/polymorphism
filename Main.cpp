#include <iostream>
#include <cstring>
#include <cstdlib>
#include <climits>

using namespace std;

#include "GestionFichier.h"
#include "TrajetCompose.h"
#include "TrajetSimple.h"
#include "Catalogue.h"
#include "Liste.h"

static void Message();

int main()
{
    Message();

    char transport[100];
    char debut[100];
    char fin[100];

    string file;

    int choix;

    Catalogue *cat = new Catalogue(); // Creation d'une instance de la classe Catalogue
    GestionFichier gestionFichier;

    do
    {
        cout << "Menu :\n"
             << "\n"
             << "\t1: Rechercher un trajet simplement\n"
             << "\t2: Rechercher un trajet de maniere avancee\n"
             << "\t3: Ajouter un trajet au catalogue\n"
             << "\t4: Afficher le catalogue\n"
             << "\t5: Charger fichier\n"
             << "\t6: Sauvegarder catalogue\n"
             << "\t0: Quitter\n"
             << endl;

        cout << " > ";


        if (!(cin >> choix))
        {
            cin.clear();// Clear the error state
            cin.ignore(INT_MAX, '\n'); // Ignore invalid input
            choix = -1; // Set to an invalid value to continue the loop
        }

        switch (choix)
        {
            int parcours;

            case 0:
                break;

            case 1:
                cout << "Recherche simple :\n"
                    << endl;

                cout << "Ville de depart\n"
                    << " > ";
                cin >> debut;

                cout << "Ville de fin\n"
                    << " > ";
                cin >> fin;

                cout << "Recherche simple :\n"
                    << endl;

                parcours = cat->RechercherSimple(debut, fin);
                if (parcours == 0)
                {
                    cout << "Trajet non trouve\n";
                }
                break;

            case 2:
                cout << "Recherche avancee :\n"
                    << endl;

                cout << "Ville de depart\n"
                << " > ";
                cin >> debut;
        
                cout << "Ville de fin\n"
                << " > ";
                cin >> fin;


                cout << "Recherche avancee :\n"
                    << endl;
                cat->RechercherAvancee(debut, fin);
                cout << "\n";
                break;

            case 3 : {
                
                int ajout = 0;

                do
                {
                    cout << "Voulez-vous ajouter un trajet simple ou complexe ?\n"
                        << "\n"
                        << "\t1: Simple\n"
                        << "\t2: Complexe\n"
                        << "\t0: Menu\n"
                        << endl;
                        
                    cout << " > ";

                    if (!(cin >> ajout))
                    {
                        cin.clear();// Clear the error state
                        cin.ignore(INT_MAX, '\n'); // Ignore invalid input
                        ajout = -1; // Set to an invalid value to continue the loop
                    }


                    switch(ajout)
                    {
                        case 0:
                            break;
                        case 1:
                        {
                            cout << "Ajout d'un trajet simple :\n"
                                << "\n"
                                << "Ville de depart\n"
                                << " > ";
                            cin >> debut;

                            cout << "Ville de fin\n"
                                << " > ";
                            cin >> fin;

                            cout << "Moyen de transport\n"
                                << " > ";
                            cin >> transport;

                            TrajetSimple * trajet = new TrajetSimple(debut, fin, transport);

                            if (!cat->VerifierDupliquer(trajet))
                            {
                                cat->Ajouter(trajet);
                            }
                            else
                            {
                                cout << "Trajet simple deja existant\n";
                                delete trajet;
                            }

                        }
                            break;
                        case 2 : 
                        {

                            int flag = 0;

                            TrajetSimple * trajet;
                            Liste * liste = new Liste();

                            char debutIndicator[100];
                            char finIndicator[100];

                            cout << "Ajout d'un trajet complexe : \n"
                                << "\n";

                            cout << "Ville de depart\n"
                                << " > ";
                            cin >> debut;

                            cout << "Ville prochaine\n"
                                << " > ";
                            cin >> fin;

                            cout << "Moyen de transport\n"
                                << " > ";
                            cin >> transport;


                            trajet = new TrajetSimple(debut, fin, transport);
                            liste->Ajouter(trajet);

                            strcpy(debutIndicator, debut);

                            do
                            {
                                cout << "Ajout d'un trajet complexe : \n"
                                    << "\n";

                                cout << "Voulez-vous ajouter un autre trajet ?\n"
                                    << "\n"
                                    << "\t1: Oui\n"
                                    << "\t2: Non\n"
                                    << "\t3: Annuler\n"
                                    << endl;

                                cout << " > ";
                                cin >> flag;

                                if(flag == 2) {
                                    strcpy(finIndicator, fin);
                                }

                                if(flag == 1) {
                                    strcpy(debut,fin);

                                    cout << "Ville prochaine\n"
                                        << " > ";
                                    cin >> fin;

                                    cout << "Moyen de transport\n"
                                        << " > ";
                                    cin >> transport;

                                    trajet = new TrajetSimple(debut, fin, transport);
                                    liste->Ajouter(trajet);

                                }

                            } while(flag == 1);
                            
                            TrajetCompose * trajetCompose = new TrajetCompose(debutIndicator, finIndicator, liste);

                            if(flag != 3) {
                                if (!cat->VerifierDupliquer(trajetCompose)) 
                                {
                                    cat->Ajouter(trajetCompose);
                                } 
                                else 
                                {
                                    cout << "Trajet compose deja existant\n";
                                    delete trajetCompose;
                                }
                            } else {
                                cout << "Ajout annule\n";
                            }
                        }

                            break;

                        default:
                            cout << "Choix incorrect\n";
                    }
                } while (ajout != 0); 
                
            }
                break;
            case 4:
                cout << "Affichage du catalogue :\n"
                    << endl;
                cat->AfficherCatalogue();
                break;
            
            case 5:
                cout << "Chargement du fichier :\n"
                    << endl;

                cout << "Nom fichier\n"
                << " > ";
                cin >> file;
                gestionFichier.ChargerFichier(&cat, file);

                break;

            case 6:
                cout << "Sauvegarde du catalogue :\n"
                    << endl;

                cout << "Nom fichier\n"
                << " > ";
                cin >> file;
                gestionFichier.SauvegarderFichier(&cat, file);

                break;


            default:
                cout << "Choix incorrect\n";
        }

    } while (choix != 0);


    cout << "Au revoir\n"
         << endl;

    delete cat;
    return 0;
}

static void Message()
{
    cout << "__________      .__                                    .__    .__                \n"
         << "\\______   \\____ |  | ___.__. _____   _________________ |  |__ |__| ______ _____  \n"
         << " |     ___/  _ \\|  |<   |  |/     \\_/ __ \\_  __ \\____ \\|  |  \\|  |/  ___//     \\ \n"
         << " |    |  (  <_> )  |_\\___  |  Y Y  \\  ___/|  | \\/  |_> >   Y  \\  |\\___ \\|  Y Y  \\\n"
         << " |____|   \\____/|____/ ____|__|_|  /\\___  >__|  |   __/|___|  /__/____  >__|_|  /\n\n\n\n";         
}


