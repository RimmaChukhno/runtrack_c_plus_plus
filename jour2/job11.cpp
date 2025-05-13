#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <algorithm>

class Aquatique {
protected:
    double vitesseNage;

public:
    Aquatique(double vitesse) : vitesseNage(vitesse) {}
    virtual ~Aquatique() = default;

    virtual void nage() const {
        std::cout << "Je nage a " << vitesseNage << " m/s." << std::endl;
    }

    void setVitesseNage(double vitesse) {
        vitesseNage = vitesse;
    }

    double getVitesseNage() const {
        return vitesseNage;
    }
};

class Terrestre {
protected:
    double vitesseMarche;

public:
    Terrestre(double vitesse) : vitesseMarche(vitesse) {}
    virtual ~Terrestre() = default;

    virtual void marche() const {
        std::cout << "Je marche a " << vitesseMarche << " m/s." << std::endl;
    }

    void setVitesseMarche(double vitesse) {
        vitesseMarche = vitesse;
    }

    double getVitesseMarche() const {
        return vitesseMarche;
    }
};

class Pingouin : public Aquatique, public Terrestre, public std::enable_shared_from_this<Pingouin> {
private:
    std::string nom;
    double vitesseGlisse;

    std::map<std::string, int> skills;
    std::unordered_map<std::string, std::string> journal;
    std::set<std::weak_ptr<Pingouin>, std::owner_less<std::weak_ptr<Pingouin>>> friends;
    std::multiset<double> times;
    std::unordered_set<std::string> treasures;

public:
    static std::vector<std::shared_ptr<Pingouin>> colony;
    static std::list<std::string> meetups;

    Pingouin(const std::string& nom, double nage, double marche, double glisse)
        : Aquatique(nage), Terrestre(marche), nom(nom), vitesseGlisse(glisse) {}


    // Pour l'allocation avec shared_ptr
    static std::shared_ptr<Pingouin> create(const std::string& nom, double nage, double marche, double glisse) {
        auto p = std::shared_ptr<Pingouin>(new Pingouin(nom, nage, marche, glisse));
        return p;
    }

    ~Pingouin() {
        colony.erase(std::remove_if(colony.begin(), colony.end(),
            [this](const std::shared_ptr<Pingouin>& p) {
                return p.get() == this;
            }), colony.end());
}


    void presente() const {
        std::cout << "Je suis " << nom << " le pingouin." << std::endl;
    }

    void nage() const override {
        std::cout << nom << " nage a " << vitesseNage << " m/s." << std::endl;
    }

    void marche() const override {
        std::cout << nom << " marche a " << vitesseMarche << " m/s." << std::endl;
    }

    void glisse() const {
        std::cout << nom << " glisse a " << vitesseGlisse << " m/s." << std::endl;
    }

    void setVitesseGlisse(double vitesse) {
        vitesseGlisse = vitesse;
        sortColony();
    }

    double getVitesseGlisse() const {
        return vitesseGlisse;
    }

    double tempsParcours() const {
        double tGlisse = 15.0 / vitesseGlisse;
        double tPlat = (20.0 + 15.0) / vitesseMarche;
        double tNage = 50.0 / vitesseNage;
        return tGlisse + tPlat + tNage;
    }

    void enregistrerTemps() {
        times.insert(tempsParcours());
    }

    void afficherTemps() const {
        std::cout << nom << " - temps enregistres : ";
        for (auto t : times) {
            std::cout << t << "s ";
        }
        std::cout << std::endl;
    }

    static void afficherClassement() {
        std::cout << "\n Classement des pingouins :" << std::endl;
        for (const auto& p : colony) {
            std::cout << p->nom << " - " << p->tempsParcours() << " s" << std::endl;
        }
    }

    // Compétences
    void ajouterCompetence(const std::string& nom, int niveau) {
        skills[nom] = niveau;
    }

    void modifierCompetence(const std::string& nom, int niveau) {
        if (skills.count(nom)) skills[nom] = niveau;
    }

    void supprimerCompetence(const std::string& nom) {
        skills.erase(nom);
    }

    void listerCompetences() const {
        std::cout << nom << " - Competences : ";
        for (const auto& [nom, niveau] : skills) {
            std::cout << nom << " (niveau " << niveau << "), ";
        }
        std::cout << std::endl;
    }

    // Journal
    void ajouterJournal(const std::string& date, const std::string& description) {
        journal[date] = description;
    }

    void afficherJournal() const {
        std::cout << nom << " - Journal :\n";
        for (const auto& [date, desc] : journal) {
            std::cout << "[" << date << "] " << desc << "\n";
        }
    }

    // Amis
    void ajouterAmi(std::shared_ptr<Pingouin> ami) {
        friends.insert(ami);
    }

    void retirerAmi(std::shared_ptr<Pingouin> ami) {
        friends.erase(ami);
    }

    void afficherAmis() const {
        std::cout << nom << " - Amis : ";
        for (auto& wp : friends) {
            if (auto sp = wp.lock()) {
                std::cout << sp->nom << ", ";
            }
        }
        std::cout << std::endl;
    }

    // Meetups
    static void ajouterMeetup(const std::string& lieu) {
        meetups.push_back(lieu);
    }

    static void retirerMeetup(const std::string& lieu) {
        meetups.remove(lieu);
    }

    static void afficherMeetups() {
        std::cout << " Lieux de rencontre : ";
        for (auto& lieu : meetups) {
            std::cout << lieu << ", ";
        }
        std::cout << std::endl;
    }

    // Trésors
    void ajouterTresor(const std::string& lieu) {
        treasures.insert(lieu);
    }

    void retirerTresor(const std::string& lieu) {
        treasures.erase(lieu);
    }

    void afficherTresors() const {
        std::cout << nom << " - Tresors : ";
        for (auto& t : treasures) {
            std::cout << t << ", ";
        }
        std::cout << std::endl;
    }

private:
    static void sortColony() {
        std::sort(colony.begin(), colony.end(), [](const std::shared_ptr<Pingouin>& a, const std::shared_ptr<Pingouin>& b) {
            return a->tempsParcours() < b->tempsParcours();
        });
    }
};

// Définition des statiques
std::vector<std::shared_ptr<Pingouin>> Pingouin::colony;
std::list<std::string> Pingouin::meetups;

int main() {
    auto tux = Pingouin::create("Tux", 2.5, 1.5, 3.0);
    auto lolo = Pingouin::create("Lolo", 2.0, 2.0, 4.0);

    tux->ajouterAmi(lolo);
    tux->ajouterCompetence("Glisse", 3);
    tux->ajouterJournal("2025-05-13", "Trouve un tresor sous la glace !");
    tux->ajouterTresor("île secrete");

    tux->enregistrerTemps();
    tux->afficherTemps();

    Pingouin::ajouterMeetup("lac");
    Pingouin::afficherMeetups();
    Pingouin::afficherClassement();

    return 0;
}
