#include <iostream>

int main(){
    int a = 10;
    int &referencia = a;

    std::cout << "Valor de a: " << a << std::endl;
    std::cout << "Dirección de a: " << &a << std::endl;
    std::cout << "Valor de referencia: " << referencia << std::endl;
    std::cout << "Dirección de referencia: " << &referencia << std::endl;

    return 0;
}