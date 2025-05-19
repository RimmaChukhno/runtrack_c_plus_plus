#include "Joueur.hpp"

int main() {
    Joueur joueur1;
    joueur1.afficherPosition();

    joueur1.setX(2);
    joueur1.setY(4);
    joueur1.setNom("Leo");
    joueur1.afficherPosition();

    std::cout << "Nom : " << joueur1.getNom()
              << " | X = " << joueur1.getX()
              << " | Y = " << joueur1.getY() << std::endl;

    return 0;
}
