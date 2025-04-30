#include <iostream>
#include <chrono>
#include <thread>
using namespace std::chrono_literals;

int main() {

    int list[400];
    for (size_t i = 0; i < 400; i++)
    {
        list[i] = rand();
    }
    std::cout << "La lista es "<< std::endl;
    for (size_t i = 0; i < 400; i++)
    {
        std::cout << list[i] << " ";
    }
    auto start = std::chrono::steady_clock::now();
    

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::nano> elapsed = end - start;

    std::cout << "Minimum measured time: " << elapsed.count() << " ns\n";
    return 0;
}
