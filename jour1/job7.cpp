#include <iostream>

int main() {
    int nombre;

    // saisir un entier
    std::cout << "Entrez un nombre entier : ";
    std::cin >> nombre;

    // Vérifier si le nombre est pair ou impair
    if (nombre % 2 == 0) {
        std::cout << "Le nombre " << nombre << " est pair." << std::endl;
    } else {
        std::cout << "Le nombre " << nombre << " est impair." << std::endl;
    }

    return 0;
}
