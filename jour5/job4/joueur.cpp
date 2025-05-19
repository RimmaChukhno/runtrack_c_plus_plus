#include "Joueur.hpp"

// Constructeurs
Joueur::Joueur() : x(0), y(0), nom("Inconnu") {}
Joueur::Joueur(int posX, int posY) : x(posX), y(posY), nom("Inconnu") {}
Joueur::Joueur(int posX, int posY, const std::string& nomJoueur) 
    : x(posX), y(posY), nom(nomJoueur) {}

// Setters
void Joueur::setX(int x) {
    this->x = x;
}

void Joueur::setY(int y) {
    this->y = y;
}

void Joueur::setNom(const std::string& nom) {
    this->nom = nom;
}

// Getters
int Joueur::getX() const {
    return this->x;
}

int Joueur::getY() const {
    return this->y;
}

std::string Joueur::getNom() const {
    return this->nom;
}

// Déplacement
void Joueur::deplacer(int dx, int dy) {
    this->x += dx;
    this->y += dy;
}

// Affichage
void Joueur::afficherPosition() const {
    std::cout << "Joueur : " << this->nom << " | Position : ("
              << this->x << ", " << this->y << ")" << std::endl;
}
