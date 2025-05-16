#include <iostream>
#include <string>
#include <vector>

struct Staff {
    std::string nom;
    std::string prenom;
};

struct Etudiant {
    std::string nom;
    std::string prenom;
};

// Fonction pour afficher le nom complet de chaque membre du staff
void afficherStaffComplet(const std::vector<Staff>& staffList) {
    std::cout << "\nNoms complets du staff :\n";
    for (const auto& s : staffList) {
        std::cout << "- " << s.prenom << " " << s.nom << std::endl;
    }
}

int main() {
    // Création des membres du staff
    Staff staff1 = {"Cordial", "Alicia"};
    Staff staff2 = {"Malardier", "Pierre"};

    std::cout << "Prenoms du staff :\n";
    std::cout << "- " << staff1.prenom << std::endl;
    std::cout << "- " << staff2.prenom << std::endl;

    // Saisie des étudiants
    int nbEtudiants;
    std::cout << "\nCombien d'etudiants voulez-vous entrer ? ";
    std::cin >> nbEtudiants;

    // Validation de l'entrée
    while (std::cin.fail() || nbEtudiants <= 0) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Veuillez entrer un entier positif : ";
        std::cin >> nbEtudiants;
    }

    std::vector<Etudiant> listeEtudiants(nbEtudiants);

    // Remplissage de la liste
    for (int i = 0; i < nbEtudiants; ++i) {
        std::cout << "\nEtudiant " << i + 1 << ":\n";
        std::cout << "Nom : ";
        std::cin >> listeEtudiants[i].nom;
        std::cout << "Prenom : ";
        std::cin >> listeEtudiants[i].prenom;
    }

    // Affichage des prénoms
    std::cout << "\nPrenoms des etudiants :\n";
    for (const auto& etu : listeEtudiants) {
        std::cout << "- " << etu.prenom << std::endl;
    }

    return 0;
}
