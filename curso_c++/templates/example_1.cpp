#include <iostream>

template <typename T>
T sumar(T a, T b) {
    return a + b;
}

int main() {
    int entero1 = 5, entero2 = 10;
    double doble1 = 3.5, doble2 = 2.5;

    // Sumar enteros
    std::cout << "La suma de enteros es: " << sumar<int>(entero1, entero2) << std::endl;

    // Sumar doubles
    std::cout << "La suma de doubles es: " << sumar<double>(doble1, doble2) << std::endl;

    return 0;
}