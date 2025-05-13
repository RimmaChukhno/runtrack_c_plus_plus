#include <iostream>

int main() {
    int nombre;

    // saisir un nombre
    std::cout << "Entrez un nombre pour afficher sa table de multiplication : ";
    std::cin >> nombre;

    // Afficher la table de multiplication de 1 à 10
    std::cout << "Table de multiplication de " << nombre << " :" << std::endl;
    for (int i = 1; i <= 10; ++i) {
        std::cout << nombre << " x " << i << " = " << nombre * i << std::endl;
    }

    return 0;
}
