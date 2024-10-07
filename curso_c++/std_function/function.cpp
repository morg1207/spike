#include <iostream>
#include <functional>

int function( int x){
    std::cout << "El valor de entrada es" << x << std::endl;
    return x;
}

int main(){

    std::function<int(int)> wr_function = function;
    wr_function(4);
    return 0;
}