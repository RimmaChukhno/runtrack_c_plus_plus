#include <iostream>
#include <string>

class Aquatique {
protected:
    double vitesseNage; // en m/s

public:
    Aquatique(double vitesse) : vitesseNage(vitesse) {}

    virtual void nage() { // <- virtual
        std::cout << "Je nage a " << vitesseNage << " m/s." << std::endl;
    }

    void setVitesseNage(double vitesse) {
        vitesseNage = vitesse;
    }
};

class Terrestre {
protected:
    double vitesseMarche; // en m/s

public:
    Terrestre(double vitesse) : vitesseMarche(vitesse) {}

    virtual void marche() { // <- virtual
        std::cout << "Je marche a " << vitesseMarche << " m/s." << std::endl;
    }

    void setVitesseMarche(double vitesse) {
        vitesseMarche = vitesse;
    }
};

class Pingouin : public Aquatique, public Terrestre {
private:
    std::string nom;
    double vitesseGlisse; // en m/s (nouvel attribut)

public:
    Pingouin(const std::string& nom, double vitesseNage, double vitesseMarche, double vitesseGlisse)
        : Aquatique(vitesseNage), Terrestre(vitesseMarche), nom(nom), vitesseGlisse(vitesseGlisse) {}

    Pingouin(const Pingouin& autre)
        : Aquatique(autre.vitesseNage), Terrestre(autre.vitesseMarche),
          nom(autre.nom), vitesseGlisse(autre.vitesseGlisse) {}

    void presente() {
        std::cout << "Je suis " << nom << " le pingouin." << std::endl;
    }

    void nage() override {
        std::cout << nom << " nage a " << vitesseNage << " m/s." << std::endl;
    }

    void marche() override {
        std::cout << nom << " marche a " << vitesseMarche << " m/s." << std::endl;
    }

    void glisse() {
        std::cout << nom << " glisse a " << vitesseGlisse << " m/s." << std::endl;
    }

    void setVitesseGlisse(double vitesse) {
        vitesseGlisse = vitesse;
    }
};

int main() {
    Pingouin tux("Tux", 2.5, 1.2, 3.0);
    tux.presente();
    tux.nage();
    tux.marche();
    tux.glisse();

    // Test du constructeur par copie
    Pingouin copieTux = tux;
    copieTux.setVitesseNage(3.0); // Modification de la vitesse
    copieTux.setVitesseGlisse(4.0);
    std::cout << "\nCopie de Tux :" << std::endl;
    copieTux.presente();
    copieTux.nage();
    copieTux.glisse();

    return 0;
}
