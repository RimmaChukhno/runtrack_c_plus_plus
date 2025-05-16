#include <iostream>
#include <cstring> // pour strlen

int main() {
    const int TAILLE_MAX = 100;
    char tab[TAILLE_MAX];

    std::cout << "Entrez une chaine de caracteres : "; //hello
    std::cin.getline(tab, TAILLE_MAX); 

    // Affichage du contenu caractère par caractère
    std::cout << "Contenu du tableau tab[] : " << std::endl;
    for (int i = 0; tab[i] != '\0'; ++i) {
        std::cout << "tab[" << i << "] = '" << tab[i] << "'" << std::endl;
    }

    // Vérification du caractère de fin
    std::cout << "Caractere de fin : tab[" << strlen(tab) << "] = '\\0'" << std::endl;

    return 0;
}
