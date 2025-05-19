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
    // Constructeurs
    Joueur();
    Joueur(int posX, int posY);
    Joueur(int posX, int posY, const std::string& nomJoueur);

    // Méthodes de manipulation avec this
    void setX(int x);
    void setY(int y);
    void setNom(const std::string& nom);

    int getX() const;
    int getY() const;
    std::string getNom() const;

    // Déplacement et affichage
    void deplacer(int dx, int dy);
    void afficherPosition() const;
};

#endif // JOUEUR_HPP
