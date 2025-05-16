#include <iostream>
#include <string>
#include <cctype>

bool formatHeureValide(const std::string& heure) {
    if (heure.length() != 5) return false;

    return std::isdigit(heure[0]) &&
           std::isdigit(heure[1]) &&
           heure[2] == 'h' &&
           std::isdigit(heure[3]) &&
           std::isdigit(heure[4]);
}

int main() {
    std::string saisie;
    std::cout << "Entrez une heure au format XXhXX : ";
    std::cin >> saisie;

    if (formatHeureValide(saisie)) {
        std::cout << "Format valide !" << std::endl;
    } else {
        std::cout << "Format invalide !" << std::endl;
    }

    return 0;
}
