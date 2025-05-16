#include <iostream>

int main() {
    const int TAILLE = 10; // tu peux changer la taille si tu veux
    int tableau[TAILLE];
    int somme = 0;

    std::cout << "Entrez " << TAILLE << " entiers :" << std::endl;

    for (int i = 0; i < TAILLE; ++i) {
        std::cout << "Entier " << i + 1 << " : ";
        std::cin >> tableau[i];

        if (tableau[i] % 2 == 0) {
            somme += tableau[i]; // ajoute à la somme si pair
        }
    }

    std::cout << "La somme des elements pairs est : " << somme << std::endl;

    return 0;
}
