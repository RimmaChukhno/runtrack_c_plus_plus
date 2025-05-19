#include "Joueur.hpp"

int main() {
    // Constructeur par défaut
    Joueur joueur1;
    joueur1.afficherPosition();

    // Constructeur avec x et y
    Joueur joueur2(5, 10);
    joueur2.afficherPosition();

    // Constructeur avec x, y et nom
    Joueur joueur3(3, 7, "Alex");
    joueur3.afficherPosition();

    return 0;
}
