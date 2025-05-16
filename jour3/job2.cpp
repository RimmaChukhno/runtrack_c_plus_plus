#include <iostream>
#include <string>

bool estVoyelle(char c) {
    c = std::tolower(static_cast<unsigned char>(c));
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main() {
    std::string phrase = "vive la plateforme !";
    std::string resultat = "";

    for (char c : phrase) {
        if (!estVoyelle(c)) {
            resultat += c; // On ajoute le caractère s'il n'est pas une voyelle
        }
    }

    std::cout << resultat << std::endl;

    return 0;
}
