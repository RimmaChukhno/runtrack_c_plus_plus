#ifndef CHAT_HPP
#define CHAT_HPP

#include "Animal.hpp"

class Chat : public Animal {
public:
    void crier() const override;
    void manger() const override;
};

#endif // CHAT_HPP
