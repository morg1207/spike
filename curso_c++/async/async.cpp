#include <iostream>
#include <future>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

int square(int x){
    //std::this_thread::sleep_for(10s); // Pausa en el hilo creado por async
    return x * x;
}

int main(){

    std::future<int> asyncFunction = std::async(&square, 12);

    for (int i = 0; i < 10; i++)
    {
        /* code */
        std::cout << square(i) << std::endl;
    }
    

    std::cout << "Hello world\n"; // Se imprime de inmediato, sin esperar al cálculo de square


    int result = asyncFunction.get();
    std::cout << "El resultado es: " << result << std::endl;

    return 0;
}