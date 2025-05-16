#include <iostream>

int main() {
    int var1 = 5, var2 = 10, var3 = 15;

    // Création des pointeurs
    int* ptr1 = &var1;
    int* ptr2 = &var2;
    int* ptr3 = &var3;

    std::cout << "Valeurs initiales :" << std::endl;
    std::cout << "var1 = " << var1 << ", var2 = " << var2 << ", var3 = " << var3 << std::endl;

    // Modification des valeurs via pointeurs
    *ptr1 = 50;
    *ptr2 = 100;
    *ptr3 = 150;

    std::cout << "Valeurs modifiees :" << std::endl;
    std::cout << "var1 = " << var1 << ", var2 = " << var2 << ", var3 = " << var3 << std::endl;

    return 0;
}
