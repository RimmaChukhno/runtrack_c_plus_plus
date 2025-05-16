#include <iostream>

int main() {
    int a = 10;
    int b = 25;

    std::cout << "Avant l'echange :" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    // Pointeurs vers les variables
    int* ptrA = &a;
    int* ptrB = &b;

    // Échange via pointeurs
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;

    std::cout << "Apres l'echange :" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    return 0;
}
