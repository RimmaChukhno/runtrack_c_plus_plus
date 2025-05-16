#include <iostream>
#include <string>
#include <cctype> 

int main() {
    std::string phrase = "vive la plateforme !";

    for (char& c : phrase) {
        c = std::toupper(static_cast<unsigned char>(c)); // conversion en majuscule
    }

    std::cout << phrase << std::endl; // Affiche

    return 0;
}
