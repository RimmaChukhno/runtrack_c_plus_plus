#include "Chien.hpp"
#include "Chat.hpp"

int main() {
    Chien monChien;
    Chat monChat;

    std::cout << "Chien :\n";
    monChien.crier();
    monChien.manger();

    std::cout << "\nChat :\n";
    monChat.crier();
    monChat.manger();

    return 0;
}
