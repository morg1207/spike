#include "iostream"
#include "functional"

void say_hello(std::string name) noexcept {

    std::cout << "Hello world !" << name <<" \n";
}

void invoke(std::function<void(std::string)> func) noexcept{

    func("Hola");
}

int main(){
    invoke(say_hello);
    std::cout<< "Hello world" << std::endl;

}