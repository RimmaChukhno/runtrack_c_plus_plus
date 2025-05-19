#include "Joueur.hpp"

int main() {
    Joueur joueur(5, 10); // Position initiale

    joueur.afficherPosition();

    joueur.deplacer(2, -3); // Déplacement vers la droite et vers le bas
    joueur.afficherPosition();

    joueur.deplacer(-1, 4); // Déplacement vers la gauche et vers le haut
    joueur.afficherPosition();

    return 0;
}
