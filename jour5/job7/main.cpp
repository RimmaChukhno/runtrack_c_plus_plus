#include "Contact.hpp"

int main() {
    // Création des contacts originaux
    Contact contact1("Alice", 123456);
    Contact contact2("Bob", 654321);
    Contact contact3("Charlie", 111222);

    // Création des copies
    Contact copie1 = contact1;
    Contact copie2 = contact2;
    Contact copie3 = contact3;

    // Modification des numéros des copies
    copie1.setNumero(999999);
    copie2.setNumero(888888);
    copie3.setNumero(777777);

    // Affichage des originaux
    std::cout << "Contacts originaux :\n";
    contact1.afficher();
    contact2.afficher();
    contact3.afficher();

    // Affichage des copies
    std::cout << "\nCopies modifiees :\n";
    copie1.afficher();
    copie2.afficher();
    copie3.afficher();

    return 0;
}
