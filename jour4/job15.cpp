#include <iostream>

int main() {
    int tab[] = {1, 2, 3, 4, 5};   // Création du tableau

    std::cout << "Valeurs du tableau :" << std::endl;

    for (int& valeur : tab) {     // Boucle avec référence
        std::cout << valeur << " ";
    }

    std::cout << std::endl;

    return 0;
}
