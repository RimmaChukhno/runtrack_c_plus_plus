#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

struct Note {
    std::string nom;
    std::string prenom;
    float note;
};

// Affiche le menu
void afficherMenu() {
    std::cout << "\n Menu:\n";
    std::cout << "1. Ajouter une note\n";
    std::cout << "2. Afficher la liste des notes\n";
    std::cout << "3. Supprimer une note d'une etudiant\n";
    std::cout << "4. Afficher la moyenne des notes\n";
    std::cout << "5. Quitter\n";
    std::cout << "Choix : ";
}

// Affiche toutes les notes
void afficherNotes(const std::vector<Note>& notes) {
    if (notes.empty()) {
        std::cout << "Aucune note enregistrée.\n";
        return;
    }

    std::cout << "\nListe des notes :\n";
    for (const auto& n : notes) {
        std::cout << n.prenom << " " << n.nom << " : " << std::fixed << std::setprecision(2) << n.note << std::endl;
    }
}

// Supprime une note par nom/prénom
void supprimerNote(std::vector<Note>& notes) {
    std::string nom, prenom;
    std::cout << "Nom de l'etudiant a supprimer : ";
    std::cin >> nom;
    std::cout << "Prenom de l'etudiant a supprimer : ";
    std::cin >> prenom;

    bool trouve = false;
    for (auto it = notes.begin(); it != notes.end(); ++it) {
        if (it->nom == nom && it->prenom == prenom) {
            notes.erase(it);
            std::cout << "Note supprimee.\n";
            trouve = true;
            break;
        }
    }
    if (!trouve) {
        std::cout << "Etudiant non trouve.\n";
    }
}

// Calcule et affiche la moyenne
void afficherMoyenne(const std::vector<Note>& notes) {
    if (notes.empty()) {
        std::cout << "Aucune note pour calculer la moyenne.\n";
        return;
    }

    float somme = 0;
    for (const auto& n : notes) {
        somme += n.note;
    }

    float moyenne = somme / notes.size();
    std::cout << "Moyenne des notes : " << std::fixed << std::setprecision(2) << moyenne << std::endl;
}

int main() {
    std::vector<Note> listeNotes;
    int choix;

    do {
        afficherMenu();
        std::cin >> choix;

        switch (choix) {
            case 1: {
                Note n;
                std::cout << "Nom : ";
                std::cin >> n.nom;
                std::cout << "Prenom : ";
                std::cin >> n.prenom;

                std::cout << "Note : ";
                while (!(std::cin >> n.note)) {
                    std::cin.clear(); // 
                    std::cin.ignore(1000, '\n'); // 
                    std::cout << "Entree invalide. Veuillez entrer une note valide : ";
                }

                listeNotes.push_back(n);
                std::cout << "Note ajoutee.\n";
                break;
            }
            case 2:
                afficherNotes(listeNotes);
                break;
            case 3:
                supprimerNote(listeNotes);
                break;
            case 4:
                afficherMoyenne(listeNotes);
                break;
            case 5:
                std::cout << "Au revoir !\n";
                break;
            default:
                std::cout << "Choix invalide, veuillez reessayer.\n";
        }

    } while (choix != 5);

    return 0;
}
