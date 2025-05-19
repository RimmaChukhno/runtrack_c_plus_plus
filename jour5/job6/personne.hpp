#ifndef PERSONNE_HPP
#define PERSONNE_HPP

#include <string>
#include <iostream>

class Personne {
private:
    std::string nom;
    int pointsDeVie;
    float defense;

public:
    // Constructeur avec liste d'initialisation
    Personne(const std::string& nom, int pv, float defense);

    // Méthodes pour afficher les infos
    void afficherInfos() const;

    // Méthodes pour modifier les valeurs
    void setNom(const std::string& nouveauNom);
    void setPointsDeVie(int nouveauxPV);
    void setDefense(float nouvelleDefense);

    // Méthodes d'accès (optionnel)
    std::string getNom() const;
    int getPointsDeVie() const;
    float getDefense() const;
};

#endif // PERSONNE_HPP
