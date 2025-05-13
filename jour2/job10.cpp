#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <memory>
#include <algorithm>
#include <iomanip>
#include <chrono>
#include <set>        // multiset et set


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

    std::map<std::string, int> competences;
    std::set<std::weak_ptr<Pingouin>, std::owner_less<std::weak_ptr<Pingouin>>> amis;
    std::unordered_map<std::string, std::string> journal;
    std::multiset<double> tempsCompetitions;

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
        std::cout << "\n=== Temps de parcours des pingouins ===\n";
        for (const auto& p : colonie) {
            std::cout << std::fixed << std::setprecision(2)
                      << p->nom << " : " << p->tempsParcours() << " s" << std::endl;
        }
    }

    // Lieux de rencontre
    static void ajouterLieu(const std::string& lieu) {
        lieuxRencontre.push_back(lieu);
    }

    static void retirerLieu(const std::string& lieu) {
        lieuxRencontre.remove(lieu);
    }

    static void afficherLieux() {
        std::cout << "\nLieux de rencontre :\n";
        for (const auto& lieu : lieuxRencontre) {
            std::cout << "- " << lieu << std::endl;
        }
    }

    // Compétences
    void ajouterCompetence(const std::string& nomComp, int niveau) {
        competences[nomComp] = niveau;
    }

    void modifierCompetence(const std::string& nomComp, int niveau) {
        if (competences.count(nomComp)) competences[nomComp] = niveau;
    }

    void supprimerCompetence(const std::string& nomComp) {
        competences.erase(nomComp);
    }

    void listerCompetences() const {
        std::cout << "\nCompetences de " << nom << " :\n";
        for (const auto& [k, v] : competences) {
            std::cout << "- " << k << ": niveau " << v << std::endl;
        }
    }

    // Amis
    void ajouterAmi(std::shared_ptr<Pingouin> ami) {
        if (ami.get() != this) amis.insert(ami);
    }

    void retirerAmi(std::shared_ptr<Pingouin> ami) {
        amis.erase(ami);
    }

    void listerAmis() const {
        std::cout << "\nAmis de " << nom << " :\n";
        for (const auto& wp : amis) {
            if (auto sp = wp.lock()) {
                std::cout << "- " << sp->nom << std::endl;
            }
        }
    }

    // Journal d'aventures
    void ajouterEntreeJournal(const std::string& date, const std::string& description) {
        journal[date] = description;
    }

    void modifierEntreeJournal(const std::string& date, const std::string& nouvelleDescription) {
        if (journal.count(date)) {
            journal[date] = nouvelleDescription;
        }
    }

    void supprimerEntreeJournal(const std::string& date) {
        journal.erase(date);
    }

    void afficherJournal() const {
        std::cout << "\nJournal de " << nom << " :\n";
        for (const auto& [date, desc] : journal) {
            std::cout << "- " << date << " : " << desc << std::endl;
        }
    }

    // Compétitions : gestion des temps
    void enregistrerTemps(double temps) {
        tempsCompetitions.insert(temps);
    }

    void afficherTempsCompetitions() const {
        std::cout << "\nTemps enregistres pour " << nom << " (competitions) :\n";
        for (double t : tempsCompetitions) {
            std::cout << "- " << std::fixed << std::setprecision(2) << t << " s" << std::endl;
        }
    }
};

// Initialisation des membres statiques
std::vector<std::shared_ptr<Pingouin>> Pingouin::colonie;
std::list<std::string> Pingouin::lieuxRencontre;

int main() {
    auto p1 = Pingouin::creer("Tux", 2.5, 1.2, 3.0);
    auto p2 = Pingouin::creer("Lulu", 2.0, 1.5, 2.5);

    p1->ajouterEntreeJournal("2025-05-13", "Exploration du glacier.");
    p1->ajouterEntreeJournal("2025-05-14", "Nage dans le lac polaire.");
    p1->afficherJournal();

    p1->ajouterAmi(p2);
    p1->listerAmis();

    p1->enregistrerTemps(45.8);
    p1->enregistrerTemps(43.2);
    p1->enregistrerTemps(47.1);
    p1->afficherTempsCompetitions();

    Pingouin::afficherTempsParcours();
}
