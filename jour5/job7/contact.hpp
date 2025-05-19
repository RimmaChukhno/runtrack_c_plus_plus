#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
private:
    std::string nom;
    int numero;

public:
    // Constructeur principal
    Contact(const std::string& nom, int numero);

    // Constructeur de copie
    Contact(const Contact& autre);

    // Setter pour modifier le numéro
    void setNumero(int nouveauNumero);

    // Affichage des infos du contact
    void afficher() const;
};

#endif // CONTACT_HPP
