#include <iostream>

int main() {
    const int TAILLE = 10;
    int T[TAILLE];
    int compteur = 0;

    std::cout << "Entrez 10 entiers :" << std::endl;
    for (int i = 0; i < TAILLE; ++i) {
        std::cout << "Entier " << i + 1 << " : ";
        std::cin >> T[i];

        if (T[i] >= 5) {
            compteur++;
        }
    }

    std::cout << "Nombre d'entiers >= 5 : " << compteur << std::endl;

    return 0;
}

