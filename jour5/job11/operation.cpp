#include "Operation.hpp"

Operation::Operation(float val) : valeur(val) {}

Operation Operation::operator+(const Operation& autre) const {
    return Operation(this->valeur + autre.valeur);
}

Operation Operation::operator-(const Operation& autre) const {
    return Operation(this->valeur - autre.valeur);
}

Operation Operation::operator*(const Operation& autre) const {
    return Operation(this->valeur * autre.valeur);
}

Operation Operation::operator/(const Operation& autre) const {
    if (autre.valeur == 0) {
        std::cerr << "Erreur : division par zero !" << std::endl;
        return Operation(0);
    }
    return Operation(this->valeur / autre.valeur);
}

void Operation::afficher() const {
    std::cout << "Resultat : " << valeur << std::endl;
}

float Operation::getValeur() const {
    return valeur;
}
