#include <iostream>
void mostrar(const int& valor) {
    // valor = 10; // Error: no se puede modificar una referencia constante
    std::cout << "Valor: " << valor << std::endl;
}

int main() {
    int x = 5;
    mostrar(x); // Pasamos 'x' por referencia constante

    return 0;
}