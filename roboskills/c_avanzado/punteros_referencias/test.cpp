#include <iostream>

int main(){

    int variable = 100;
    int *puntero = &variable;               //son dos objetos distintos
    int &referencia = variable;

    referencia = 200;

    std::cout << "Valor de variable: " << variable << std::endl;
    std::cout << "Dirección de variable: " << &variable << std::endl;
    std::cout << "Valor de puntero: " << puntero << std::endl;
    std::cout << "Dirección de puntero: " << &puntero << std::endl;
    std::cout << "Valor de referencia: " << referencia << std::endl;
    std::cout << "Dirección de referencia: " << &referencia << std::endl;
    std::cout << "----------------------------"  << std::endl;
    int variable2 = 300;
    referencia = variable2;                 //variable y referencia son exactamente lo mismo
    puntero = &variable2;

    std::cout << "Valor de referencia: " << referencia << std::endl;
    std::cout << "Dirección de referencia: " << &referencia << std::endl;

    std::cout << "----------------------------"  << std::endl;
    std::cout << "Valor de puntero: " << puntero << std::endl;
    std::cout << "Dirección de puntero: " << &puntero << std::endl;
    return 0;


}