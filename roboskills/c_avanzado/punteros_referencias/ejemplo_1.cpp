#include <iostream>
int main() {
    int x = 10;
    int& ref = x; // 'ref' es una referencia a 'x'

    std::cout << "x: " << x << std::endl;       // Salida: 10
    std::cout << "ref: " << ref << std::endl;   // Salida: 10

    ref = 20; // Modificamos 'x' a través de 'ref'
    std::cout << "x después de modificar ref: " << x << std::endl; // Salida: 20

    return 0;
}