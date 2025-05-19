#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
private:
    static int nbTotalAnimaux;

public:
    Animal(); // constructeur

    virtual void crier() const = 0;
    virtual void manger() const = 0;
    virtual ~Animal() = default;

    // Méthode statique pour obtenir le nombre total
    static int getTotalAnimaux();
};

#endif // ANIMAL_HPP
