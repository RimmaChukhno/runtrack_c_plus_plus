#include <iostream>

int main() {
    int a, b, c;

    // Saisie des trois entiers
    std::cout << " premier nombre : ";
    std::cin >> a;

    std::cout << " deuxieme nombre : ";
    std::cin >> b;

    std::cout << "troisieme nombre : ";
    std::cin >> c;

    // Comparaison pour trouver le plus grand
    int max = a;

    if (b > max) {
        max = b;
    }

    if (c > max) {
        max = c;
    }

    std::cout << "Le plus grand nombre est : " << max << std::endl;

    return 0;
}
