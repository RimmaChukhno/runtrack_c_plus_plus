#include "Chien.hpp"
#include "Chat.hpp"
#include "Animal.hpp"
#include <iostream>

int main() {
    Chien chien1;
    Chat chat1;
    Chien chien2;
    Chat chat2;
    Chien chien3;

    std::cout << "Nombre total d'animaux crees : "
              << Animal::getTotalAnimaux() << std::endl;

    return 0;
}
