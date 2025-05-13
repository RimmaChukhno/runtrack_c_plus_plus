#include <iostream>

int main() {
    int n, m, temp;

    // Saisie des deux entiers
    std::cout << "Entrez la valeur de n : ";
    std::cin >> n;

    std::cout << "Entrez la valeur de m : ";
    std::cin >> m;

    // Affichage avant l'échange
    std::cout << "\n Avant l'echange :" << std::endl;
    std::cout << "n = " << n << ", m = " << m << std::endl;

    // Échange des valeurs
    temp = n;
    n = m;
    m = temp;

    // Affichage après l'échange
    std::cout << "\n Apres l'echange :" << std::endl;
    std::cout << "n = " << n << ", m = " << m << std::endl;

    return 0;
}
