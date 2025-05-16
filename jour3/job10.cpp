#include <iostream>
#include <string>
#include <algorithm> 

int main() {
    std::string string;
    std::string string2 = "Bonjour";

    std::cout << "Entrez une chaine de caracteres : ";
    std::getline(std::cin, string);

    // Tri lexicographique (ordre alphabétique)
    if (string > string2) {
        std::swap(string, string2); 
    }

    std::cout << "Chaines triees dans l'ordre lexicographique :" << std::endl;
    std::cout << string << std::endl;
    std::cout << string2 << std::endl;

    return 0;
}
