#include <iostream>
#include <thread>
#include <future>
#include <chrono>

// Función que simula una tarea en el hilo productor
void realizarCalculo(std::promise<int> prom) {
    std::cout << "Hilo 1: Realizando cálculo..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));  // Simula una tarea de 3 segundos

    int resultado = 42;  // Resultado del cálculo
    prom.set_value(resultado);  // Establece el resultado en la promesa
    std::cout << "Hilo 1: Cálculo terminado, resultado guardado en promise." << std::endl;
}

// Función que espera el resultado en el hilo consumidor
void obtenerResultado(std::future<int> fut) {
    std::cout << "Hilo 2: Esperando el resultado del cálculo..." << std::endl;
    
    // El hilo consumidor se bloquea hasta que el resultado esté listo
    int resultado = fut.get();  // Esto se desbloquea cuando `hilo1` llama a set_value
    
    std::cout << "Hilo 2: Resultado recibido: " << resultado << std::endl;
}

int main() {
    // Crear una promesa de tipo int
    std::promise<int> prom;

    // Obtener el future asociado a la promesa
    std::future<int> fut = prom.get_future();

    // Lanzar el hilo productor que realiza el cálculo
    std::thread hilo1(realizarCalculo, std::move(prom));

    // Lanzar el hilo consumidor que espera el resultado
    std::thread hilo2(obtenerResultado, std::move(fut));

    // Esperar a que ambos hilos terminen
    hilo1.join();
    hilo2.join();

    return 0;
}