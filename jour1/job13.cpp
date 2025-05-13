#include <iostream>
#include <cmath> 
int main() {
    int N;
    long long somme = 0;

    std::cout << "Entrez un entier N (N >= 5) : ";
    std::cin >> N;

    if (N < 5) {
        std::cout << "Erreur : N doit être supérieur ou egal a 5." << std::endl;
        return 1;
    }

    for (int i = 5; i <= N; ++i) {
        somme += static_cast<long long>(pow(i, 3)); // i^3
    }

    std::cout << "La somme des cubes de 5^3 a " << N << "^3 est : " << somme << std::endl;

    return 0;
}
