#include <functional>
#include <chrono>
#include <iostream>
#include <future>
#include <thread>

using namespace std::chrono_literals;

int myService(std::future<int> & fu){
    std::cout << "Mi servicio 1 se inicializo"<< std::endl;
    int x = fu.get();
    std::cout << "La promesa fue cumplida: "<< std::endl;
    std::cout << "El valor recibido es: " << x << std::endl;
    std::this_thread::sleep_for(100ms);
    return 0;
}

void myService2(std::promise<int> & pro){
    std::cout << "Mi servicio 2 se inicializo" << std::endl;
    std::this_thread::sleep_for(200ms);

    pro.set_value(10);
    std::cout << "La promesa fue enviada" << std::endl;
}

int main(){

    std::promise<int> pro;
    
    std::future<int> fu = pro.get_future();

    std::thread t1(myService, std::ref(fu));
    std::thread t2(myService2,std::ref(pro));

    t1.join();
    t2.join();

    return 0;
}