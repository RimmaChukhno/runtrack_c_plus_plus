#include "Chien.hpp"
#include "Chat.hpp"
#include "Animal.hpp"
#include <iostream>

int main() {
    Chien chien1;
    Chat chat1;

    std::cout << "Chien :\n";
    chien1.crier();
    chien1.manger();

    std::cout << "\nChat :\n";
    chat1.crier();
    chat1.manger(); // version sans paramètre
    chat1.manger("du poisson");
    chat1.manger("des croquettes");

    std::cout << "\nNombre total d'animaux crees : "
              << Animal::getTotalAnimaux() << std::endl;

    return 0;
}
