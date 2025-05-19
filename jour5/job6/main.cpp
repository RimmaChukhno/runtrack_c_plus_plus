#include "Personne.hpp"

int main() {
    // Création de plusieurs types de personnages
    Personne guerrier("Thor", 150, 0.3f);
    Personne mage("Merlin", 80, 0.1f);
    Personne archer("Legolas", 100, 0.2f);

    // Affichage initial
    guerrier.afficherInfos();
    mage.afficherInfos();
    archer.afficherInfos();

    // Modifications
    mage.setPointsDeVie(90);       // le mage gagne de la vie
    archer.setDefense(0.25f);      // l’archer améliore sa défense
    guerrier.setNom("Odin");       // changement de nom

    std::cout << "\nApres modifications :\n";
    guerrier.afficherInfos();
    mage.afficherInfos();
    archer.afficherInfos();

    return 0;
}
