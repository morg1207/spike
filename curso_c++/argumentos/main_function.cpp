#include <iostream>
#include <cstdlib>  // Para usar std::atoi()

int main(int argc, char *argv[]) {
    // argc cuenta la cantidad de argumentos, el primer argumento (argv[0]) es el nombre del programa
    if (argc < 3) {
        std::cerr << "Uso: " << argv[0] << " num1 num2 ... numN\n";
        return 1; // Error si no hay suficientes argumentos
    }

    int suma = 0;

    // Recorremos todos los argumentos a partir de argv[1], ya que argv[0] es el nombre del programa
    for (int i = 1; i < argc; ++i) {
        suma += std::atoi(argv[i]); // Convertimos cada argumento de cadena a entero
    }

    std::cout << "La suma de los números es: " << suma << std::endl;
    return 0;
}