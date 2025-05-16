#include <iostream>

int main()
{
    int x = 12;   // variable x
    int &ref = x; // référence à x

    std::cout << "Valeur initiale de x : " << x << std::endl;

    ref = 42; // Modification de x via la référence

    std::cout << "Valeur modifiée de x via la référence : " << x << std::endl;

    return 0;
}
