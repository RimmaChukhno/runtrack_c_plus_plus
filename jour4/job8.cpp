#include <iostream>
#include <string>

int main() {
    std::string tab[] = {"2019", "La Plateforme", "3.14", "Etudiants"};
    const int taille = sizeof(tab) / sizeof(tab[0]);

    for (int i = 0; i < taille; ++i) {
        std::cout << "Adresse de tab[" << i << "] = " << &tab[i]
                  << ", Valeur = " << tab[i] << std::endl;
    }

    return 0;
}
