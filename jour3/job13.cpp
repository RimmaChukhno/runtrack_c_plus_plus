#include <iostream>

int main() {
    const int TAILLE1 = 5;
    const int TAILLE2 = 5;
    const int TAILLE3 = TAILLE1 + TAILLE2;

    int tab1[TAILLE1] = {1, 3, 5, 7, 9};
    int tab2[TAILLE2] = {2, 4, 6, 8, 10};
    int tabFusion[TAILLE3];

    int i = 0, j = 0, k = 0;

    // Fusion des deux tableaux triés
    while (i < TAILLE1 && j < TAILLE2) {
        if (tab1[i] < tab2[j]) {
            tabFusion[k++] = tab1[i++];
        } else {
            tabFusion[k++] = tab2[j++];
        }
    }

    // Copie du reste de tab1
    while (i < TAILLE1) {
        tabFusion[k++] = tab1[i++];
    }

    // Copie du reste de tab2
    while (j < TAILLE2) {
        tabFusion[k++] = tab2[j++];
    }

    // Affichage du tableau fusionné
    std::cout << "Tableau fusionne : ";
    for (int i = 0; i < TAILLE3; ++i) {
        std::cout << tabFusion[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
