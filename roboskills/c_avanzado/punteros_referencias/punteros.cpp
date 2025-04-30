#include "iostream"

int main() {
    int a = 10;
    int *puntero = &a;

    std::cout << "Valor de a: " << a << std::endl;
    std::cout << "Dirección de a: " << &a << std::endl;
    std::cout << "Valor de puntero: " << puntero << std::endl;
    std::cout << "Dirección de puntero: " << &puntero << std::endl;
    std::cout << "Valor al que apunta puntero: " << *puntero << std::endl;

    return 0;
}