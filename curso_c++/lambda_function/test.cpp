#include <iostream>
#include <functional>

void ejecutar_funcion(std::function<void()> f) {
    f(); // Llama a la función pasada como parámetro
}

void ejecutar_función_con_lambda(std::function<void()> lb_param ){
    lb_param();
}


int main() {
    std::string message = "Print ouf of lambda";
    std::cout << message << "\n";
    auto f = [message](){ std::cout << "Lambda print " << message << "\n"; };
    f();
    //----------------------------------------------------------------------
    auto f_1 = [](int a , int b){
        printf("la suma es igual a %u \n", a+b);
        return a+b;
    };

    f_1(2,3);
    //----------------------------------------------------------------------
    int contador = 0;
    auto f_2 = [&contador](){
        printf("El valor del contador es %u \n",contador);
    };
    f_2();
    contador++;
    f_2();
    //----------------------------------------------------------------------
    ejecutar_función_con_lambda(f_2);
    //----------------------------------------------------------------------
    auto f_3 = [](){

        return "hola";
    };
    std::string message_1 = f_3();
    printf("el mensaje es %s \n ",message_1.c_str());
    //----------------------------------------------------------------------

    // Creamos un vector de enteros
    std::vector<int> numeros = {1, 2, 3, 4, 5};

    // Usamos std::for_each con una lambda para imprimir los elementos del vector
    std::for_each(numeros.begin(), numeros.end(), [](int &n) {
        n+=1;
        std::cout << n << " ";
    });
    // pasam,os por referencia el parámetro n
    std::for_each(numeros.begin(), numeros.end(), [](int &n) {
        n+=1;
        std::cout << n << " ";
    });
    std::cout << std::endl;
    //----------------------------------------------------------------------
    int valor = 5;
    auto lambda_mutable = [valor]() mutable{
        valor +=10;
        std::cout << "Dentro de la lambda, valor modificado es: " << valor << std::endl;
    };

    lambda_mutable();
    // Imprimimos el valor original fuera de la lambda
    std::cout << "Fuera de la lambda, valor original es: " << valor << std::endl;
    //--------------------------- 8 . Mutable modificando valor -------------------------------------

    int valor_8 = 5;
    auto lambda_mutable = [valor_8]() mutable{
        valor_8 +=10;
        std::cout << "Dentro de la lambda, valor modificado es: " << valor_8 << std::endl;
    };

    lambda_mutable();
    // Imprimimos el valor original fuera de la lambda
    std::cout << "Fuera de la lambda, valor original es: " << valor << std::endl;


   //--------------------------- 9 . Lambda y punteros a función -------------------------------------

    auto lambda_mul = [](int a, int b) {
        return a*b;
        std::cout << "El valor de la multiplicación es: " << a*b << std::endl;
    };

    std::function<int(int,int)> function_ptr = lambda_mul;
    
    int resultado = function_ptr(6,7);
    

    return 0;
    
}