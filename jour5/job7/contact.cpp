#include "Contact.hpp"

Contact::Contact(const std::string& nom, int numero)
    : nom(nom), numero(numero) {}

Contact::Contact(const Contact& autre)
    : nom(autre.nom), numero(autre.numero) {}

void Contact::setNumero(int nouveauNumero) {
    this->numero = nouveauNumero;
}

void Contact::afficher() const {
    std::cout << "Nom : " << nom << " - Numero : " << numero << std::endl;
}
