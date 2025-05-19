#include "Etudiant.hpp"

// Constructeur avec liste d'initialisation
Etudiant::Etudiant(const std::string& nom, const std::string& prenom, int age, int matricule)
    : nom(nom), prenom(prenom), age(age), matricule(matricule) {}

// Getters
std::string Etudiant::getNom() const {
    return nom;
}

std::string Etudiant::getPrenom() const {
    return prenom;
}

int Etudiant::getAge() const {
    return age;
}

int Etudiant::getMatricule() const {
    return matricule;
}
