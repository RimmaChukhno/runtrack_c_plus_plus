#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <iomanip> // для std::setprecision

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
    // Colonie de tous les pingouins
    static std::vector<std::shared_ptr<Pingouin>> colonie;

    // Constructeur principal
    Pingouin(const std::string& nom, double vitesseNage, double vitesseMarche, double vitesseGlisse)
        : Aquatique(vitesseNage), Terrestre(vitesseMarche), nom(nom), vitesseGlisse(vitesseGlisse) {}

    // Factory method obligatoire pour gérer les shared_ptr + colonie
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

    // Calcul du temps pour parcourir la piste
    double tempsParcours() const {
        double temps = 0.0;
        if (vitesseGlisse > 0) temps += 15.0 / vitesseGlisse;
        if (vitesseMarche > 0) temps += 20.0 / vitesseMarche;
        if (vitesseNage > 0) temps += 50.0 / vitesseNage;
        if (vitesseMarche > 0) temps += 15.0 / vitesseMarche;
        return temps;
    }

    // Affiche le temps de chaque pingouin
    static void afficherTempsParcours() {
        std::cout << "\n== Temps de parcours pour chaque pingouin ==\n";
        for (const auto& p : colonie) {
            if (p) {
                std::cout << std::fixed << std::setprecision(2);
                std::cout << p->nom << " : " << p->tempsParcours() << " secondes." << std::endl;
            }
        }
    }
};

// Initialisation du vecteur statique
std::vector<std::shared_ptr<Pingouin>> Pingouin::colonie;

int main() {
    {
        auto tux = Pingouin::creer("Tux", 2.5, 1.2, 3.0);
        auto lulu = Pingouin::creer("Lulu", 2.0, 1.5, 2.5);

        tux->presente();
        lulu->presente();

        Pingouin::afficherTempsParcours();
    }

    std::cout << "\nApres destruction du bloc : " << Pingouin::colonie.size() << " pingouins dans la colonie." << std::endl;

    return 0;
}
