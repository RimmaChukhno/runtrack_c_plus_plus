#include "Chat.hpp"
#include <iostream>

void Chat::crier() const {
    std::cout << "Miaou!" << std::endl;
}

// Version sans paramètre
void Chat::manger() const {
    std::cout << "Le chat mange du poisson." << std::endl;
}

// Version avec paramètre
void Chat::manger(const std::string& nourriture) {
    if (nourriture == "des croquettes") {
        std::cout << "Le chat mange des croquettes." << std::endl;
    } else {
        std::cout << "Le chat mange " << nourriture << "." << std::endl;
    }
}
