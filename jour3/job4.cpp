#include <iostream>
#include <string>

int main() {
    std::string phrase = "Vive la plateforme !";
    int longueur = phrase.length(); // ou phrase.size()
    
    std::cout << "La taille est " << longueur << std::endl;
    
    return 0;
}