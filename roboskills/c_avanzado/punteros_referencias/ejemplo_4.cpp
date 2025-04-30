#include <iostream>
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;
    std::cout << "Antes del swap: x = " << x << ", y = " << y << std::endl; // Salida: 5, 10

    swap(x, y); // Intercambiamos 'x' e 'y' usando referencias
    std::cout << "Después del swap: x = " << x << ", y = " << y << std::endl; // Salida: 10, 5

    return 0;
}