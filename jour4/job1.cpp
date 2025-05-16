#include <iostream>

int main() {
    int number = 2019;
    int* ptr = &number;  // pointeur vers la variable number

    std::cout << "La Valeur de number est : " << *ptr << std::endl;

    return 0;
}
