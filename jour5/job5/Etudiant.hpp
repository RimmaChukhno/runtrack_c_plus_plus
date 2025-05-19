#ifndef ETUDIANT_HPP
#define ETUDIANT_HPP

#include <string>

class Etudiant {
private:
    std::string nom;
    std::string prenom;
    int age;
    int matricule;

public:
    // Constructeur avec liste d'initialisation
    Etudiant(const std::string& nom, const std::string& prenom, int age, int matricule);

    // Optionnel : accesseurs pour tester
    std::string getNom() const;
    std::string getPrenom() const;
    int getAge() const;
    int getMatricule() const;
};

#endif // ETUDIANT_HPP
