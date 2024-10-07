#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <vector>
using namespace std::chrono;
int main(){

    auto time_point = std::chrono::system_clock::now();
    auto elapse_time = std::chrono::duration_cast<std::chrono::hours>(time_point.time_since_epoch());

    std::cout << elapse_time.count() << "\n";

    auto old =  std::chrono::steady_clock::now();
    std::vector<int> v(50'000'000);
    std::cout << "count std  " <<std::count_if(v.begin() ,v.end(),[](int i){return i==0;}) << "\n";

    auto dur = std::chrono::steady_clock::now() - old;

    auto dur_micro= std::chrono::duration_cast<microseconds>(dur);
    auto dur_milli = std::chrono::duration_cast<milliseconds>(dur);

    std::cout<< "dur count  " << dur.count() << "\n";
    std::cout<< "count of duration in milliseconds  " << dur_milli.count() << "\n";
    std::cout<< "count of duration in microseconds  " << dur_micro.count() << "\n";

    return 0; 
}