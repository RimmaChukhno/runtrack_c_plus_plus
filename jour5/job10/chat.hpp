#ifndef CHAT_HPP
#define CHAT_HPP

#include "Animal.hpp"
#include <string>

class Chat : public Animal {
public:
    void crier() const override;
    void manger() const override;

    // Nouvelle version surchargée avec paramètre
    void manger(const std::string& nourriture);
};

#endif // CHAT_HPP
