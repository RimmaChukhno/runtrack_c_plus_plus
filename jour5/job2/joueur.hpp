#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <iostream>

class Joueur {
private:
    int x;
    int y;

public:
    //  Constructeur pour initialiser x et y
    Joueur(int posX, int posY);

    // Méthode pour déplacer le joueur
    void deplacer(int dx, int dy);

    // Méthode pour afficher la position
    void afficherPosition() const;
};

#endif // JOUEUR_HPP
