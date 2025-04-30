#include <iostream>
#include <functional>
#include <vector>

// Plantilla para un Publicador (Publisher)
template <typename T>
class Publisher {
public:
    // Método para publicar un mensaje
    void publish(const T& message) {
        std::cout << "Publicando: " << message << std::endl;
    }
};

// Función principal
int main() {
    // Crear un publicador para enteros
    Publisher<int> intPublisher;
    intPublisher.publish(42); // Salida: "Publicando: 42"

    // Crear un publicador para strings
    Publisher<std::string> stringPublisher;
    stringPublisher.publish("Hola, mundo!"); // Salida: "Publicando: Hola, mundo!"

    return 0;
}