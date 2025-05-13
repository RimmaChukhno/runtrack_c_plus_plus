#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

class Aquatique {
protected:
    double vitesseNage;

public:
    Aquatique(double vitesse) : vitesseNage(vitesse) {}
    virtual void nage() {
        std::cout << "Je nage a " << vitesseNage << " m/s." << std::endl;
    }
    void setVitesseNage(double vitesse) {
        vitesseNage = vitesse;
    }
};

class Terrestre {
protected:
    double vitesseMarche;

public:
    Terrestre(double vitesse) : vitesseMarche(vitesse) {}
    virtual void marche() {
        std::cout << "Je marche a " << vitesseMarche << " m/s." << std::endl;
    }
    void setVitesseMarche(double vitesse) {
        vitesseMarche = vitesse;
    }
};

class Pingouin : public Aquatique, public Terrestre, public std::enable_shared_from_this<Pingouin> {
private:
    std::string nom;
    double vitesseGlisse;

public:
    // Vecteur statique public des pingouins
    static std::vector<std::shared_ptr<Pingouin>> colonie;

    // Constructeur principal
    Pingouin(const std::string& nom, double vitesseNage, double vitesseMarche, double vitesseGlisse)
        : Aquatique(vitesseNage), Terrestre(vitesseMarche), nom(nom), vitesseGlisse(vitesseGlisse) {
        // Ajoute à la colonie après création via make_shared
        // Ne pas utiliser shared_from_this() ici — doit être appelé après construction
    }

    // Factory method pour forcer l’utilisation de shared_ptr
    static std::shared_ptr<Pingouin> creer(const std::string& nom, double nage, double marche, double glisse) {
        std::shared_ptr<Pingouin> p = std::make_shared<Pingouin>(nom, nage, marche, glisse);
        colonie.push_back(p);
        return p;
    }

    // Destructeur
    ~Pingouin() {
        auto it = std::remove_if(colonie.begin(), colonie.end(),
            [this](const std::shared_ptr<Pingouin>& ptr) { return ptr.get() == this; });
        colonie.erase(it, colonie.end());
        std::cout << nom << " est supprime de la colonie." << std::endl;
    }

    // Constructeur par copie
    Pingouin(const Pingouin& autre)
        : Aquatique(autre.vitesseNage), Terrestre(autre.vitesseMarche),
          nom(autre.nom), vitesseGlisse(autre.vitesseGlisse) {
        // Ne pas ajouter automatiquement les copies à la colonie ici
    }

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

// Initialisation du vecteur statique
std::vector<std::shared_ptr<Pingouin>> Pingouin::colonie;

int main() {
    {
        auto tux = Pingouin::creer("Tux", 2.5, 1.2, 3.0);
        tux->presente();
        tux->nage();
        tux->marche();
        tux->glisse();

        std::cout << "\nNombre de pingouins dans la colonie : " << Pingouin::colonie.size() << std::endl;

        auto copieTux = std::make_shared<Pingouin>(*tux);
        copieTux->setVitesseNage(3.0);
        copieTux->setVitesseGlisse(4.0);
        copieTux->presente();
        copieTux->nage();
        copieTux->glisse();
        // copieTux n'est pas ajouté automatiquement à la colonie
    }

    std::cout << "\nApres destruction du bloc : " << Pingouin::colonie.size() << " pingouins dans la colonie." << std::endl;

    return 0;
}
