#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main() {
    // Initialisation du générateur de nombres aléatoires
    srand(time(0));
    
    // Génération du nombre mystère entre 0 et 100
    int nombreMystere = rand() % 101;
    
    // Nombre de chances (vous pouvez modifier cette valeur)
    const int chancesMax = 10;
    int chancesRestantes = chancesMax;
    
    cout << "Bienvenue dans le jeu du Nombre Mystere !" << endl;
    cout << "Je pense a un nombre entre 0 et 100." << endl;
    cout << "Vous avez " << chancesMax << " tentatives pour le trouver." << endl;
    
    while (chancesRestantes > 0) {
        int proposition;
        cout << "\nIl vous reste " << chancesRestantes << " chance(s)." << endl;
        cout << "Quelle est votre proposition ? ";
        
        // Vérification de l'entrée utilisateur
        while (!(cin >> proposition)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entree invalide. Veuillez entrer un nombre entre 0 et 100: ";
        }
        
        // Vérification que le nombre est dans l'intervalle
        if (proposition < 0 || proposition > 100) {
            cout << "Le nombre doit etre entre 0 et 100 !" << endl;
            continue;
        }
        
        // Comparaison avec le nombre mystère
        if (proposition < nombreMystere) {
            cout << "Trop petit !" << endl;
        } else if (proposition > nombreMystere) {
            cout << "Trop grand !" << endl;
        } else {
            // Le joueur a trouvé le nombre
            cout << "\nBravo ! Vous avez trouve le nombre mystere (" 
                 << nombreMystere << ") en " 
                 << (chancesMax - chancesRestantes + 1) << " tentative(s) !" << endl;
            return 0;
        }
        
        chancesRestantes--;
    }
    
    // Le joueur a épuisé toutes ses chances
    cout << "\nDommage ! Vous avez epuise toutes vos chances." << endl;
    cout << "Le nombre mystere etait : " << nombreMystere << endl;
    
    return 0;
}