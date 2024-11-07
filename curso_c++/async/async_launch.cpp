#include <iostream>
#include <future>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

int square(int x){
    std::this_thread::sleep_for(10s); // Pausa en el hilo creado por async
    return x * x;
}

int main(){
    // Especificamos std::launch::async para asegurar que el cálculo ocurra en un hilo separado
    std::future<int> async = std::async(std::launch::async, square, 12);

    std::cout << "Hello world\n"; // Se imprime de inmediato, sin esperar al cálculo de square

    // Puedes esperar y obtener el resultado cuando lo necesites
    int result = async.get();
    std::cout << "El resultado es: " << result << std::endl;

    return 0;
}