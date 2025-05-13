#include <iostream>

int main() {
    // Job 0 - Suppression des parenthèses superflues
    int a, x = 2, y = 3, b = 1, c = 4, d = 5, i = 1, n = 6, p = 7;

    a = x + 5;
    std::cout << "a = (x + 5) "  << std::endl;

    a = x = y + 2;
    std::cout << "a = (x = y) + 2 "  << std::endl;

    a = (x == y);
    std::cout << "a = (x == y)  "  << std::endl;

    a = (b < x && c < d);
    std::cout << "(a < b)  && (c < d) "  << std::endl;

    a = i++ * (n + p);
    std::cout << "(i++) * (n + p) "  << std::endl;

return 0;
}