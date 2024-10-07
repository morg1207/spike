#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono;
using namespace std;

int main(){

    auto start_time = steady_clock::now();
    auto duration = seconds(5);
    auto rate = milliseconds(200);
    cout<< "Init program";
    while( steady_clock::now() - start_time <duration){

        cout<< duration_cast<seconds>(steady_clock::now() - start_time).count()<<endl;
        std::this_thread::sleep_for(rate);

    }
}