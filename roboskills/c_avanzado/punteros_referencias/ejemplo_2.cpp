#include <iostream>
void incrementar(int& valor) {
    valor++; // Modificamos la variable original
}

int main() {
    int x = 5;
    std::cout << "x antes de incrementar: " << x << std::endl; // Salida: 5

    incrementar(x); // Pasamos 'x' por referencia
    std::cout << "x después de incrementar: " << x << std::endl; // Salida: 6

    return 0;
}