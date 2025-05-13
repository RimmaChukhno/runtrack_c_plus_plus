#include <iostream>

int main() {
    int annee;

    // d'entrer une année
    std::cout << "Entrez une annee : ";
    std::cin >> annee;

    // Vérifier si l'année est bissextile
    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0)) {
        std::cout << annee << " est une annee bissextile." << std::endl;
    } else {
        std::cout << annee << " n'est pas une annee bissextile." << std::endl;
    }

    return 0;
}
