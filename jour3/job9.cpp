#include <iostream>
#include <string>

// Fonction qui vérifie si str1 est contenu dans str2
bool estIncluse(const std::string& str1, const std::string& str2) {
    return str2.find(str1) != std::string::npos;
}

int main() {
    std::string chaine1, chaine2;

    std::cout << "Entrez la premiere chaine : ";
    std::getline(std::cin, chaine1);

    std::cout << "Entrez la deuxieme chaine : ";
    std::getline(std::cin, chaine2);

    if (estIncluse(chaine1, chaine2)) {
        std::cout << "Resultat : vrai (la premiere chaine est incluse dans la deuxieme)" << std::endl; //chat
    } else {
        std::cout << "Resultat : faux (la premiere chaine n'est pas incluse)" << std::endl;//chat noire
    }

    return 0;
}
