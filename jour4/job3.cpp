#include <iostream>
#include <cstring> // pour strlen

int main() {
    char str[100];

    std::cout << "Entrez une chaine de caracteres : "; //Laplateforme
    std::cin.getline(str, 100);

    // Pointeurs pour parcourir la chaîne
    char* debut = str;
    char* fin = str + strlen(str) - 1;

    // Inversion avec pointeurs
    while (debut < fin) {
        char temp = *debut;
        *debut = *fin;
        *fin = temp;

        debut++;
        fin--;
    }

    std::cout << "Chaine inversee : " << str << std::endl; //emrofetalpaL

    return 0;
}
