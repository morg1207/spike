#include "iostream"
using namespace std;

struct structura_corredor
{
    string nombre;
    int edad;
    string sexo;
    string club;
    string categoria;
};
void print_corredor(structura_corredor corredor){
    std::cout << "Datos del corredor : " << std::endl;
    std::cout << "Nombre : " << corredor.nombre << std::endl;
    std::cout << "Edad : " << corredor.edad << std::endl;
    std::cout << "Sexo : " << corredor.sexo << std::endl;
    std::cout << "Club : " << corredor.club << std::endl;
    std::cout << "Categoria : " << corredor.categoria << std::endl;
}

int main(){
    structura_corredor corredor;

    std::cout << "Ingrese los datos del corredor : " << std::endl;
    std::cout << "Nombre : " << std::endl;
    std::cin >> corredor.nombre;
    std::cout << "Edad : " << std::endl;
    std::cin >> corredor.edad;
    std::cout << "Sexo : " << std::endl;
    std::cin >> corredor.sexo;
    std::cout << "Club : " << std::endl;
    std::cin >> corredor.club;
    if(corredor.edad <= 18){
        corredor.categoria = "Juvenil";
    }else if(corredor.edad <= 40){
        corredor.categoria = "Senior";  
    }else{  
        corredor.categoria = "Veterano";
    }   
    print_corredor(corredor);
}

