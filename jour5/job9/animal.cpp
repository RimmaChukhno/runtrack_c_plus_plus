#include "Animal.hpp"

// Initialisation de la variable statique
int Animal::nbTotalAnimaux = 0;

// Constructeur : incrémente le compteur
Animal::Animal() {
    ++nbTotalAnimaux;
}

int Animal::getTotalAnimaux() {
    return nbTotalAnimaux;
}
