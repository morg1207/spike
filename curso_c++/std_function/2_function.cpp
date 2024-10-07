#include <cstdio>
#include <iostream>
#include <functional>
#include <string>
#include <algorithm>
#include <vector>

void say_hello(std::string name) noexcept {

    std::cout << "Hello world !" << name <<" \n";
}

void invoke(std::function<void(std::string)> func) noexcept{

    func("Hola");
}

void print_number(int number)noexcept{

    number *= 2;
    std::cout << "Number is "<< number << std::endl;
}

int main()
{
    invoke(say_hello);
    std::vector numbers{1,2,3,4,5};
    std::for_each(numbers.begin(), numbers.end(), print_number );
    return 0;
}
