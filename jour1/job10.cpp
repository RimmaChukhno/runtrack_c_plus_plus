#include <iostream>

int main() {
    double prixHT, kilos, tva, prixTTC;

    // Saisie du prix HT par kilo
    std::cout << "Entrez le prix HT d'un kilo de carottes (Euro) : ";
    std::cin >> prixHT;

    // Saisie du nombre de kilos
    std::cout << "Entrez le nombre de kilos de carottes : ";
    std::cin >> kilos;

    // Saisie du taux de TVA (en pourcentage)
    std::cout << "Entrez le taux de TVA (ex : 15 pour 15%) : ";
    std::cin >> tva;

    // Calcul du prix TTC
    prixTTC = prixHT * kilos * (1 + tva / 100);

    // Affichage du résultat
    std::cout << "Le prix TTC pour " << kilos << " kg de carottes est : " << prixTTC << " Euro" << std::endl;

    return 0;
}
