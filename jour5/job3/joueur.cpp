#include "Joueur.hpp"

// Constructeur par défaut
Joueur::Joueur() : x(0), y(0), nom("Inconnu") {}

// Constructeur avec x et y
Joueur::Joueur(int posX, int posY) : x(posX), y(posY), nom("Inconnu") {}

// Constructeur avec x, y et nom
Joueur::Joueur(int posX, int posY, const std::string& nomJoueur) 
    : x(posX), y(posY), nom(nomJoueur) {}

void Joueur::deplacer(int dx, int dy) {
    x += dx;
    y += dy;
}

void Joueur::afficherPosition() const {
    std::cout << "Joueur : " << nom << " | Position : (" << x << ", " << y << ")" << std::endl;
}
