#include <iostream>

int main() {
    int tab[] = {10, 20, 30, 40, 50};
    const int taille = sizeof(tab) / sizeof(tab[0]);

    for (int i = 0; i < taille; ++i) {
        std::cout << "Adresse de tab[" << i << "] = " << &tab[i]
                  << ", Valeur = " << tab[i] << std::endl;
    }

    return 0;
}
