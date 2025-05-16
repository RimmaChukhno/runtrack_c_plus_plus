#include <iostream>

int main() {
    int taille;

    std::cout << "Entrez la taille du tableau : ";
    std::cin >> taille;

    // Allocation dynamique
    int* tab = new int[taille];

    // Saisie des valeurs
    for (int i = 0; i < taille; ++i) {
        std::cout << "Entrez l'element " << i << " : ";
        std::cin >> tab[i];
    }

    // Affichage des valeurs
    std::cout << "Contenu du tableau :" << std::endl;
    for (int i = 0; i < taille; ++i) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;

    // Libération de la mémoire
    delete[] tab;

    return 0;
}
