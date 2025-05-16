#include <iostream>
#include <string>

using namespace std;

int main() {
    string chaine1, chaine2;
    
    cout << "Entrez la premiere chaine : ";
    getline(cin, chaine1);
    
    cout << "Entrez la deuxieme chaine : ";
    getline(cin, chaine2);
    
    cout << "Resultat : " << (chaine1 != chaine2) << endl;
    
    return 0;
}