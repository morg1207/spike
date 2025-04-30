#include <iostream>

// Espacio de nombres para operaciones matemáticas
namespace Matematicas {
    int suma(int a, int b) {
        return a + b;
    }

    int resta(int a, int b) {
        return a - b;
    }
}

// Espacio de nombres para operaciones de texto
namespace Texto {
    std::string concatenar(const std::string& a, const std::string& b) {
        return a + b;
    }
}

// Usar el espacio de nombres Matematicas
using namespace Matematicas;

// Función principal
int main() {
    // Ahora no es necesario usar Matematicas::
    std::cout << "Suma: " << suma(5, 3) << std::endl;       // Salida: 8
    std::cout << "Resta: " << resta(5, 3) << std::endl;     // Salida: 2

    // Todavía necesitamos usar Texto::
    std::cout << "Concatenación: " << Texto::concatenar("Hola, ", "mundo!") << std::endl; // Salida: Hola, mundo!

    return 0;
}