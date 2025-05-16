#include <iostream>
#include <string>

int main() {
    // Tableau statique de fruits
    std::string fruit[5] = {"Pomme", "Banane", "Fraise", "Orange", "Mangue"};

    std::cout << "Cinq fruits de votre choix. :\n";
    for (const auto& f : fruit) {
        std::cout << "- " << f << std::endl;
    }

    // Demander combien de fruits préférés
    int tailleFavoris;
    std::cout << "\nCombien de fruits preferez-vous ? ";
    std::cin >> tailleFavoris;

    // Validation d'entrée
    while (std::cin.fail() || tailleFavoris <= 0) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Entrez un nombre entier positif : ";
        std::cin >> tailleFavoris;
    }

    // Allocation dynamique
    std::string* favoris = new std::string[tailleFavoris];

    // Saisie des favoris
    std::cout << "\nEntrez vos fruits favoris :\n";
    for (int i = 0; i < tailleFavoris; ++i) {
        std::cout << "Fruit " << i + 1 << " : ";
        std::cin >> favoris[i];
    }

    // Affichage
    std::cout << "\nVos fruits favoris sont :\n";
    for (int i = 0; i < tailleFavoris; ++i) {
        std::cout << "- " << favoris[i] << std::endl;
    }

    // Libération de la mémoire
    delete[] favoris;

    return 0;
}
