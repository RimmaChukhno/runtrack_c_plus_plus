#include <iostream>

int main() {
    char c = '\x01';       // ch = 1
    short int p = 10;      // sp = 10

    int x = p + 3;        // 13
    int y = c + 1;        // 2
    int z = p + c;       // 11
    int w = 3 * p + 5 * c; // 35


    std::cout << "char c = '\\x01' => " << static_cast<int>(c) << std::endl;
    std::cout << "short int p = 10 => " << p << std::endl;

    std::cout << "x = p + 3 => " << x << std::endl;
    std::cout << "y = c + 1 => " << y << std::endl;
    std::cout << "z = p + c => " << z << std::endl;
    std::cout << "w = 3 * p + 5 * c => " << w << std::endl;
    
    return 0;
}
