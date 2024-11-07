#include <iostream>       // Para std::cout
#include <functional>     // Para std::ref
#include <thread>         // Para std::thread
#include <future>         // Para std::promise y std::future
#include <chrono>         // Para std::chrono

void print_int(std::future<int>& fut) {
    int x = fut.get();  // Bloquea hasta que el valor esté disponible
    std::cout << "Value: " << x << '\n';
}

void async_task(std::promise<int>& prom) {
    // Simulamos un retraso en el cálculo
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Espera 2 segundos
    prom.set_value(42);  // Cumple la promesa con el valor 42
}

int main() {
    std::promise<int> prom;                      // Crea una promesa
    std::future<int> fut = prom.get_future();    // Obtiene un futuro asociado a la promesa

    std::thread th1(print_int, std::ref(fut));  // Crea un hilo que ejecuta print_int

    std::thread th2(async_task, std::ref(prom)); // Crea un hilo que ejecuta async_task

    th1.join();  // Espera a que th1 termine
    th2.join();  // Espera a que th2 termine
    return 0;
}
