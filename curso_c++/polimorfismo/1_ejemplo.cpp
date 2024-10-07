#include <iostream>

class Animal {
public:
    void hacerSonido() {
        std::cout << "Algún sonido de animal" << std::endl;
    }
    virtual void comer() {
        std::cout << "El animal come" << std::endl;
    }
};

class Perro : public Animal {
public:
    Perro(){

        std::cout << "Perro Constructor was created"  << std::endl;
    }
    void hacerSonido() {
        std::cout << "Guau" << std::endl;
    }
    void comer() override{
        std::cout << "El perro come" << std::endl;
    }
};

class Gato : public Animal {
public:
    Gato(){

        std::cout << "Gato Constructor was created"  << std::endl;
    }
    void hacerSonido()  {
        std::cout << "Miau" << std::endl;
    }
    void comer() override{
        std::cout << "El gato come" << std::endl;
    }
};

int main() {
    Animal* animal1 = new Perro();
    Animal* animal2 = new Gato();
    
    animal1->hacerSonido();  // Salida: Algún sonido de animal
    animal2->hacerSonido();  // Salida: Algún sonido de animal

    Animal* chapo = new Perro();
    Animal* angora = new Gato();

    chapo->comer();
    angora->comer();

    delete animal1;
    delete animal2;

    return 0;
}