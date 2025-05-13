#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <memory>
#include <algorithm>
#include <iomanip>

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

    static void trierColonie() {
        std::sort(colonie.begin(), colonie.end(), [](const std::shared_ptr<Pingouin>& a, const std::shared_ptr<Pingouin>& b) {
            return a->tempsParcours() < b->tempsParcours();
        });
    }

public:
    static std::vector<std::shared_ptr<Pingouin>> colonie;
    static std::list<std::string> lieuxRencontre;

    Pingouin(const std::string& nom, double vitesseNage, double vitesseMarche, double vitesseGlisse)
        : Aquatique(vitesseNage), Terrestre(vitesseMarche), nom(nom), vitesseGlisse(vitesseGlisse) {}

    static std::shared_ptr<Pingouin> creer(const std::string& nom, double nage, double marche, double glisse) {
        std::shared_ptr<Pingouin> p = std::make_shared<Pingouin>(nom, nage, marche, glisse);
        colonie.push_back(p);
        trierColonie();
        return p;
    }

    ~Pingouin() {
        auto it = std::remove_if(colonie.begin(), colonie.end(),
            [this](const std::shared_ptr<Pingouin>& ptr) { return ptr.get() == this; });
        colonie.erase(it, colonie.end());
        std::cout << nom << " est supprime de la colonie." << std::endl;
        trierColonie();
    }

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
        trierColonie();
    }

    double tempsParcours() const {
        double t = 0.0;
        if (vitesseGlisse > 0) t += 15.0 / vitesseGlisse;
        if (vitesseMarche > 0) t += 20.0 / vitesseMarche;
        if (vitesseNage > 0)   t += 50.0 / vitesseNage;
        if (vitesseMarche > 0) t += 15.0 / vitesseMarche;
        return t;
    }

    static void afficherTempsParcours() {
        std::cout << "\n=== Temps de parcours des pingouins (du plus rapide au plus lent) ===\n";
        for (const auto& p : colonie) {
            if (p) {
                std::cout << std::fixed << std::setprecision(2);
                std::cout << p->nom << " : " << p->tempsParcours() << " secondes." << std::endl;
            }
        }
    }

    // Méthodes pour les lieux de rencontre
    static void ajouterLieu(const std::string& lieu) {
        lieuxRencontre.push_back(lieu);
        std::cout << "Lieu ajoute : " << lieu << std::endl;
    }

    static void retirerLieu(const std::string& lieu) {
        lieuxRencontre.remove(lieu);
        std::cout << "Lieu retire : " << lieu << std::endl;
    }

    static void afficherLieux() {
        std::cout << "\n--- Lieux de rencontre ---\n";
        if (lieuxRencontre.empty()) {
            std::cout << "(aucun lieu enregistre)\n";
        } else {
            for (const auto& lieu : lieuxRencontre) {
                std::cout << "- " << lieu << std::endl;
            }
        }
    }
};

// Initialisation des variables statiques
std::vector<std::shared_ptr<Pingouin>> Pingouin::colonie;
std::list<std::string> Pingouin::lieuxRencontre;

int main() {
    // Création de lieux de rencontre
    Pingouin::ajouterLieu("lac");
    Pingouin::ajouterLieu("glacier");
    Pingouin::ajouterLieu("banquise");

    Pingouin::afficherLieux();

    // Création de pingouins
    {
        auto tux = Pingouin::creer("Tux", 2.5, 1.2, 3.0);
        auto lulu = Pingouin::creer("Lulu", 2.0, 1.5, 2.5);
        auto speedy = Pingouin::creer("Speedy", 3.0, 2.0, 4.0);

        tux->presente();
        lulu->presente();
        speedy->presente();

        Pingouin::afficherTempsParcours();
    }

    std::cout << "\nApres destruction du bloc, taille de la colonie : "
              << Pingouin::colonie.size() << std::endl;

    // Suppression d'un lieu
    Pingouin::retirerLieu("glacier");
    Pingouin::afficherLieux();

    return 0;
}
