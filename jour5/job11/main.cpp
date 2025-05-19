#include "Operation.hpp"

int main() {
    Operation op1(10);
    Operation op2(5);

    Operation somme = op1 + op2;
    Operation diff = op1 - op2;
    Operation produit = op1 * op2;
    Operation division = op1 / op2;

    std::cout << "Addition : ";
    somme.afficher();

    std::cout << "Soustraction : ";
    diff.afficher();

    std::cout << "Multiplication : ";
    produit.afficher();

    std::cout << "Division : ";
    division.afficher();

    return 0;
}
