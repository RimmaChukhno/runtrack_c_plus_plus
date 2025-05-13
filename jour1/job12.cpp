#include <iostream>

int main() {
    int valeur, somme = 0;

    std::cout << "Entrez 5 entiers :" << std::endl;

    for (int i = 0; i < 5; ++i) {
        std::cin >> valeur;
        somme += valeur;
    }

    double moyenne = static_cast<double>(somme) / 5;
    std::cout << "La moyenne des 5 entiers est : " << moyenne << std::endl;

    return 0;
}
