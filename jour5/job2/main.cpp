#include "Joueur.hpp"

int main() {
    // Création d'un joueur avec position initiale x=0, y=0
    Joueur joueur(0, 0);

    joueur.afficherPosition();

    joueur.deplacer(3, 4);
    joueur.afficherPosition();

    joueur.deplacer(-2, 1);
    joueur.afficherPosition();

    return 0;
}
