#include <iostream>       // std::cout
#include <functional>     // std::ref
#include <thread>         // std::thread
#include <future>         // std::promise, std::future


int my_service(int x){

    std::cout << "Servicio inicializado" << std::endl;
    for (long int i = 0; i < 10000000; i++)
    {
        i++;
    }
    
    return x*x;
}
using namespace std::chrono_literals;
int main(){

    std::cout<< "Se inicializo el programa" << std::endl;

    std::future<int> fu = std::async(my_service,10);

    while(1){
        std::cout << "Hilo principal detenido" << std::endl;
        std::this_thread::sleep_for(100ms);
        auto result = fu.wait_for(1ms);
        if( result == std::future_status::ready){
            std::cout << "El servicio se completo" << std::endl;
            break;
        }
    }

    int x = fu.get();
    std::cout << "El valor devuelto es: "<< x << std::endl;
    return 0;
}