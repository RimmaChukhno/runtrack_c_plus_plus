#include <iostream>
#include "Etudiant.hpp"

int main() {
    Etudiant etu("Dupont", "Jean", 21, 12345);

    std::cout << "Nom : " << etu.getNom() << std::endl;
    std::cout << "Prenom : " << etu.getPrenom() << std::endl;
    std::cout << "Age : " << etu.getAge() << std::endl;
    std::cout << "Matricule : " << etu.getMatricule() << std::endl;

    return 0;
}
