#include <iostream>
#include <vector>

// Función que recibe un vector por referencia constante
void imprimirVector(const std::vector<int>& vec) {
    // Recorremos el vector y mostramos sus elementos
    for (int valor : vec) {
        std::cout << valor << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Creamos un vector grande
    std::vector<int> datos = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Pasamos el vector a la función por referencia constante
    imprimirVector(datos);

    int a = 2;
    int &ref = a;
    std::cout << "Valor de a: " << a << std::endl;
    std::cout << "Valor de a: " << ref << std::endl;

    std::cout << "Valor de a: " << &a << std::endl;
    std::cout << "Valor de a: " << &ref << std::endl;

    int *p = &a;
    std::cout << "Valor de p: " << p << std::endl;
    std::cout << "Valor de p: " << &p << std::endl;
    return 0;
}