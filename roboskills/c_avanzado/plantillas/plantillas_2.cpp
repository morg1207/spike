
#include <iostream>
#include <string>

template <typename T>
class MiClase {
public:
    MiClase(T valor) : valor_(valor) {}
    T getValor() const { return valor_; }
private:
    T valor_;
};

int main() {
    MiClase<int> obj1(42);
    MiClase<std::string> obj2("Hola");

    std::cout << obj1.getValor() << std::endl;    // 42
    std::cout << obj2.getValor() << std::endl;    // Hola
    return 0;
}