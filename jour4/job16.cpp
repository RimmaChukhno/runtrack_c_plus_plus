#include <iostream>

int main() {
    int tab[] = {7, 2, 15, 4, 9};         // Tableau initial
    int taille = sizeof(tab) / sizeof(tab[0]);

    int max = tab[0];                    // Initialisation avec le premier élément

    for (int i = 1; i < taille; ++i) {   // Parcours du reste du tableau
        if (tab[i] > max) {
            max = tab[i];               // Mise à jour si on trouve plus grand
        }
    }

    std::cout << "La valeur maximale est : " << max << std::endl;

    return 0;
}
