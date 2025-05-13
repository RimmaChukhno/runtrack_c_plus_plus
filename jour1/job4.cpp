#include <iostream>

int main() {
    int num1, num2, somme;

    //saisir les deux nombres
    std::cout << "premier nombre: ";
    std::cin >> num1;

    std::cout << "deuxieme nombre: ";
    std::cin >> num2;

    // Additionner les deux nombres
    somme = num1 + num2;

    //résultat de l'addition
    std::cout << " " << num1 << " + " << num2 << " = " << somme << std::endl;

    return 0;
}
