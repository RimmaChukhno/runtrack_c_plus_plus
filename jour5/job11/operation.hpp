#ifndef OPERATION_HPP
#define OPERATION_HPP

#include <iostream>

class Operation {
private:
    float valeur;

public:
    // Constructeur
    Operation(float val = 0);

    // Surcharge des opérateurs
    Operation operator+(const Operation& autre) const;
    Operation operator-(const Operation& autre) const;
    Operation operator*(const Operation& autre) const;
    Operation operator/(const Operation& autre) const;

    // Affichage
    void afficher() const;

    // Getter
    float getValeur() const;
};

#endif // OPERATION_HPP
