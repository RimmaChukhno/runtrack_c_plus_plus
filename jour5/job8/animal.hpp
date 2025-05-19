#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

// Classe abstraite
class Animal {
public:
    virtual void crier() const = 0;   // Méthode pure
    virtual void manger() const = 0;  // Méthode pure
    virtual ~Animal() = default;      // Destructeur virtuel
};

#endif // ANIMAL_HPP
