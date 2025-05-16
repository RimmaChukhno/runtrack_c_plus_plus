#include <iostream>
#include <string>
#include <vector>

struct Destination {
    std::string nom;
    float tempsVol; // en heures
};

// Fonction pour afficher les informations
void afficherDestinations(const std::vector<Destination*>& destinations) {
    std::cout << "\nListe des destinations :\n";
    for (const auto& dest : destinations) {
        std::cout << "- " << dest->nom << " (" << dest->tempsVol << " h depuis Marseille)\n";
    }
}

// Fonction pour modifier les données
void modifierDestinations(std::vector<Destination*>& destinations) {
    std::cout << "\nModification des donnees :\n";
    for (auto& dest : destinations) {
        std::cout << "Modifier la destination \"" << dest->nom << "\" ? (o/n) : ";
        char choix;
        std::cin >> choix;
        if (choix == 'o' || choix == 'O') {
            std::cout << "Nouvelle destination : ";
            std::cin >> dest->nom;
            std::cout << "Nouveau temps de vol : ";
            std::cin >> dest->tempsVol;
        }
    }
}

int main() {
    std::vector<Destination*> destinations;
    int nb;

    std::cout << "Combien de destinations souhaitez-vous entrer ? ";
    std::cin >> nb;

    while (std::cin.fail() || nb <= 0) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Veuillez entrer un entier positif : ";
        std::cin >> nb;
    }

    for (int i = 0; i < nb; ++i) {
        auto* dest = new Destination;
        std::cout << "\nDestination " << i + 1 << " :\n";
        std::cout << "Nom : ";
        std::cin >> dest->nom;
        std::cout << "Temps de vol (en heures) : ";
        std::cin >> dest->tempsVol;
        destinations.push_back(dest);
    }

    afficherDestinations(destinations);
    modifierDestinations(destinations);
    afficherDestinations(destinations);

    // Libération de la mémoire
    for (auto& ptr : destinations) {
        delete ptr;
    }

    return 0;
}
