#include <iostream>
#include <chrono>
#include <thread>


using namespace std::chrono_literals;
using namespace std::chrono;

int main(){

    auto day = 720 * std::chrono::hours(1);
    auto my_seconds = std::chrono::seconds(day);
    std::cout << "Cantidad de segundos en 1 dia " << my_seconds.count()<< std::endl;
    auto year = std::chrono::duration_cast<std::chrono::minutes>(my_seconds);
    std::cout << "Cantidad años en un 1 día " << year.count()<< std::endl;
    return 0;
}