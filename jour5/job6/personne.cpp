#include "Personne.hpp"

Personne::Personne(const std::string& nom, int pv, float defense)
    : nom(nom), pointsDeVie(pv), defense(defense) {}

void Personne::afficherInfos() const {
    std::cout << "Nom : " << nom 
              << " | PV : " << pointsDeVie 
              << " | Defense : " << defense << std::endl;
}

void Personne::setNom(const std::string& nouveauNom) {
    this->nom = nouveauNom;
}

void Personne::setPointsDeVie(int nouveauxPV) {
    this->pointsDeVie = nouveauxPV;
}

void Personne::setDefense(float nouvelleDefense) {
    this->defense = nouvelleDefense;
}

std::string Personne::getNom() const {
    return nom;
}

int Personne::getPointsDeVie() const {
    return pointsDeVie;
}

float Personne::getDefense() const {
    return defense;
}
