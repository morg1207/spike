#include <iostream>

void stackExample() {
    int a = 5; // 'a' está en el stack
    std::cout << "Stack (a): " << a << std::endl;
    std::cout << "Dirección de stack: " << &a << std::endl;
    
    int b = 5; // 'a' está en el stack
    std::cout << "Stack (b): " << b << std::endl;
    std::cout << "Dirección de stack: " << &b << std::endl;
    // 'a' se libera automáticamente al salir de la función
}

void heapExample() {
    int* b = new int[1000]; // 'b' apunta a memoria en el heap
    std::cout << "Heap (*b): " << *b << std::endl;
    std::cout << "Dirección de Heap (*b): " << b << std::endl;
    

    int* c = new int(10); // 'b' apunta a memoria en el heap
    std::cout << "Heap (*c): " << *c << std::endl;
    std::cout << "Dirección de Heap (*c): " << c << std::endl;

    delete b; // Liberamos la memoria manualmente
    delete c; // Liberamos la memoria manualmente
}

int main() {
    stackExample();
    heapExample();
    return 0;
}