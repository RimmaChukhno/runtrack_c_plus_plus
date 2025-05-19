#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <iostream>

class Joueur {
private:
    int x;
    int y;

public:
    // Constructeur
    Joueur(int posX = 0, int posY = 0);

    // Méthode pour déplacer le joueur
    void deplacer(int dx, int dy);

    // Méthode pour afficher la position
    void afficherPosition() const;
};

#endif // JOUEUR_HPP
