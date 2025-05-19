#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include <iostream>
#include <string>

class Joueur {
private:
    int x;
    int y;
    std::string nom;

public:
    // Constructeur par défaut
    Joueur();

    // Constructeur avec x et y
    Joueur(int posX, int posY);

    // Constructeur avec x, y et nom
    Joueur(int posX, int posY, const std::string& nomJoueur);

    // Méthode pour déplacer le joueur
    void deplacer(int dx, int dy);

    // Méthode pour afficher la position et le nom
    void afficherPosition() const;
};

#endif // JOUEUR_HPP
