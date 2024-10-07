/*   Asignacion dinamica de arreglos
new : Reserva el numero de bytes solicitado por la declaracion
delete : Libera una cantidad de memoria asignado anteriormente

*/


#include <iostream>
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;


void perdir_notas();

int cant_notas, *calif;

int main(){



   return 0; 
}

void pedir_notas(){
    cout <<  "Ingrese la cantidad de notas a ingresar";
    cin >> cant_notas;
    calif = new int[cant_notas];
    for(int i =0; i<cant_notas; i++){

        printf("Ingrese la nota numero %u  \n",cant_notas);
        cin >> calif[i];

    }
}