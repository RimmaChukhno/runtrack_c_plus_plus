#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <memory>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <ctime>

class Aquatique {
protected:
    double vitesseNage;
public:
    Aquatique(double vitesse) : vitesseNage(vitesse) {}
    virtual void nage() const { std::cout << "Je nage a " << vitesseNage << " m/s.\n"; }
    void setVitesseNage(double vitesse) { vitesseNage = vitesse; }
    double getVitesseNage() const { return vitesseNage; }
    virtual ~Aquatique() = default;  // Добавляем виртуальный деструктор
};

class Terrestre {
protected:
    double vitesseMarche;
public:
    Terrestre(double vitesse) : vitesseMarche(vitesse) {}
    virtual void marche() const { std::cout << "Je marche a " << vitesseMarche << " m/s.\n"; }
    void setVitesseMarche(double vitesse) { vitesseMarche = vitesse; }
    double getVitesseMarche() const { return vitesseMarche; }
    virtual ~Terrestre() = default;  // Добавляем виртуальный деструктор
};

class Pingouin : public Aquatique, public Terrestre, public std::enable_shared_from_this<Pingouin> {
private:
    std::string nom;
    double vitesseGlisse;
    std::map<std::string, int> competences;
    std::unordered_map<std::string, std::string> journal;
    std::set<std::weak_ptr<Pingouin>, std::owner_less<std::weak_ptr<Pingouin>>> amis;
    std::multiset<double> tempsCompetition;
    std::unordered_set<std::string> tresors;

    Pingouin(const std::string& nom, double nage, double marche, double glisse)
        : Aquatique(nage), Terrestre(marche), nom(nom), vitesseGlisse(glisse) {}

public:
    static std::vector<std::shared_ptr<Pingouin>> colony;
    static std::list<std::string> lieuxRencontre;
    static std::unordered_map<std::string, std::string> lieuTresors;

    static std::shared_ptr<Pingouin> create(const std::string& nom, double nage, double marche, double glisse) {
        auto p = std::shared_ptr<Pingouin>(new Pingouin(nom, nage, marche, glisse));
        colony.push_back(p);
        sortColony();
        return p;
    }

    ~Pingouin() {
        colony.erase(std::remove_if(colony.begin(), colony.end(),
            [this](const std::shared_ptr<Pingouin>& p) { return p.get() == this; }), colony.end());
    }

    void presente() const { std::cout << "Je suis " << nom << " le pingouin.\n"; }
    void nage() const override { std::cout << nom << " nage a " << vitesseNage << " m/s.\n"; }
    void marche() const override { std::cout << nom << " marche a " << vitesseMarche << " m/s.\n"; }
    void glisse() const { std::cout << nom << " glisse a " << vitesseGlisse << " m/s.\n"; }

    void setVitesseGlisse(double v) { vitesseGlisse = v; }
    double getVitesseGlisse() const { return vitesseGlisse; }

    double tempsParcours() const {
        return 15.0 / vitesseGlisse + 35.0 / vitesseMarche + 50.0 / vitesseNage;
    }

    static void afficherClassement() {
        for (const auto& p : colony) {
            std::cout << p->nom << ": " << p->tempsParcours() << " s\n";
        }
    }

    static void sortColony() {
        std::sort(colony.begin(), colony.end(), [](const auto& a, const auto& b) {
            return a->tempsParcours() < b->tempsParcours();
        });
    }

 // Lieux de rencontre
    static void ajouterLieu(const std::string& lieu) { lieuxRencontre.push_back(lieu); }
    static void retirerLieu(const std::string& lieu) { lieuxRencontre.remove(lieu); }
    static void associerTresorAuLieu(const std::string& lieu, const std::string& tresor) {
        lieuTresors[lieu] = tresor;
    }

    // Competences
    void ajouterCompetence(const std::string& nom, int niveau) { competences[nom] = niveau; }
    void modifierCompetence(const std::string& nom, int niveau) { competences[nom] = niveau; }
    void supprimerCompetence(const std::string& nom) { competences.erase(nom); }
    void listerCompetences() const {
        for (const auto& [k, v] : competences) {
            std::cout << k << ": niveau " << v << "\n";
        }
    }

    // Journal
    void ajouterEntreeJournal(const std::string& date, const std::string& desc) { journal[date] = desc; }
    void supprimerEntreeJournal(const std::string& date) { journal.erase(date); }
    void afficherJournal() const {
        for (const auto& [d, t] : journal) {
            std::cout << d << ": " << t << "\n";
        }
    }

    // Amis
    void ajouterAmi(std::shared_ptr<Pingouin> ami) { amis.insert(ami); }
    void retirerAmi(std::shared_ptr<Pingouin> ami) { amis.erase(ami); }

    // Temps en competition
    void ajouterTemps(double temps) { tempsCompetition.insert(temps); }
    void afficherTempsCompetition() const {
        for (double t : tempsCompetition) std::cout << t << " s\n";
    }

    // Tresors
    void ajouterTresor(const std::string& lieu) { tresors.insert(lieu); }
    void retirerTresor(const std::string& lieu) { tresors.erase(lieu); }
    void listerTresors() const {
        for (const auto& t : tresors) std::cout << t << "\n";
    }

    void visiterLieu(const std::string& lieu) {
        std::cout << nom << " visite " << lieu << ".\n";
        auto it = lieuTresors.find(lieu);
        if (it != lieuTresors.end() && (std::rand() % 2 == 0)) { // 50% chance
            tresors.insert(it->second);
            std::cout << nom << " a trouve un tresor : " << it->second << "!\n";
        } else {
            std::cout << nom << " n'a rien trouve cette fois.\n";
        }
    }
};

std::vector<std::shared_ptr<Pingouin>> Pingouin::colony;
std::list<std::string> Pingouin::lieuxRencontre;
std::unordered_map<std::string, std::string> Pingouin::lieuTresors;

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    auto p1 = Pingouin::create("Tux", 2.0, 1.5, 3.0);
    auto p2 = Pingouin::create("Lolo", 1.8, 1.8, 3.5);

    p1->ajouterCompetence("Plongeon", 5);
    p1->ajouterEntreeJournal("2025-05-13", "Visite d'un glacier.");
    p1->ajouterAmi(p2);
    p1->ajouterTemps(25.4);
    p1->ajouterTemps(24.1);
    p1->ajouterTresor("Ile Mysterieuse");

    Pingouin::ajouterLieu("lac");
    Pingouin::ajouterLieu("glacier");
    Pingouin::associerTresorAuLieu("glacier", "Cristal Ancien");
    Pingouin::associerTresorAuLieu("lac", "Perle Bleue");

    p1->visiterLieu("glacier");
    p1->visiterLieu("lac");

    Pingouin::afficherClassement();

    return 0;
}