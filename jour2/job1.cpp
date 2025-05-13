#include <iostream>
#include <string>

class Aquatique {
protected:
    double vitesseNage; // en m/s

public:
    Aquatique(double vitesse) : vitesseNage(vitesse) {}
    
    virtual void nage() {
        std::cout << "Je nage a " << vitesseNage << " m/s." << std::endl;
    }
    
    virtual ~Aquatique() = default;
};

class Terrestre {
protected:
    double vitesseMarche; // en m/s

public:
    Terrestre(double vitesse) : vitesseMarche(vitesse) {}
    
    virtual void marche() {
        std::cout << "Je marche a " << vitesseMarche << " m/s." << std::endl;
    }
    
    virtual ~Terrestre() = default;
};

class Pingouin : public Aquatique, public Terrestre {
private:
    std::string nom;

public:
    Pingouin(const std::string& nom, double vitesseNage, double vitesseMarche)
        : Aquatique(vitesseNage), Terrestre(vitesseMarche), nom(nom) {}
    
    void presente() {
        std::cout << "Je suis un pingouin." << std::endl;
    }
    
    // On peut redéfinir les méthodes si nécessaire
    void nage() override {
        std::cout << nom << " nage a " << vitesseNage << " m/s." << std::endl;
    }
    
    void marche() override {
        std::cout << nom << " marche a " << vitesseMarche << " m/s." << std::endl;
    }
};

int main() {
    Pingouin tux("Pingouin", 2.5, 1.2);
    tux.presente();
    tux.nage();
    tux.marche();
    
    return 0;
}