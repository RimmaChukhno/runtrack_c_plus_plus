#include <iostream>

struct Point {
    int x;
    int y;
};

int main() {
    Point p = {10, 20};       // initialisation de la structure
    Point* ptr = &p;          // pointeur vers la structure

    std::cout << "Avant modification :" << std::endl;
    std::cout << "x = " << ptr->x << ", y = " << ptr->y << std::endl;

    // Modification des membres via le pointeur
    ptr->x = 100;
    ptr->y = 200;

    std::cout << "Apres modification :" << std::endl;
    std::cout << "x = " << ptr->x << ", y = " << ptr->y << std::endl;

    return 0;
}
