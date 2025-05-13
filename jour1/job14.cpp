#include <iostream>

int main() {
    int nombre, inverse = 0;

    std::cout << "Entrez un nombre entier : ";
    std::cin >> nombre;

    int original = nombre; // nombre d'origine

    while (nombre != 0) {
        int chiffre = nombre % 10;        // Extraire le dernier chiffre
        inverse = inverse * 10 + chiffre; // Ajouter au nombre inversé
        nombre /= 10;                     // Supprimer le dernier chiffre
    }

    std::cout << "Le nombre inverse de " << original << " devient : " << inverse << std::endl;

    return 0;
}
