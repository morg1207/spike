#include "iostream"


int main(){


    std::cout<< "Operador ternario" << std::endl;

    int x = 2 ;

    std::cout << "EL valor de x es del tipo "<< ((x%2) ? "par": "impar") << std::endl;
}