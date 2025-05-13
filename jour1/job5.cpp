#include <iostream>

int main() {
    int num1, num2, produit;

    //saisir les deux nombres
    std::cout << "Entrez le premier nombre: ";
    std::cin >> num1;

    std::cout << "Entrez le deuxième nombre: ";
    std::cin >> num2;

    // Multiplier les deux nombres
    produit = num1 * num2;

    // résultat de la multiplication
    std::cout << " " << num1 << " * " << num2 << " = " << produit << std::endl;

    return 0;
}
