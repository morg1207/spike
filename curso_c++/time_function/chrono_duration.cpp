#include <iostream>
#include <chrono>
#include <type_traits>
#include <thread>



using namespace std::chrono_literals;
int main() {
    // Obtener el tipo de duration del reloj del sistema
    using SystemClockDuration = std::chrono::system_clock::duration;
    
    // Verificar que SystemClockDuration sea de tipo duration
    if (std::is_same<SystemClockDuration, std::chrono::duration<int64_t, std::nano>>::value) {
        std::cout << "system_clock::duration es de tipo nanosegundos." << std::endl;
    } else {
        std::cout << "system_clock::duration es de otro tipo." << std::endl;
    }

    // Crear un time_point con el reloj del sistema
    std::chrono::time_point<std::chrono::system_clock> tp;
    
    // Imprimir la duración desde el epoch en segundos
    auto duration_since_epoch = tp.time_since_epoch();
    std::cout << "Duración desde el epoch (nanosegundos): " 
              << duration_since_epoch.count() 
              << " nanosegundos." << std::endl;

    // Convertir la duración a segundos
    auto seconds_since_epoch = std::chrono::duration_cast<std::chrono::seconds>(duration_since_epoch);
    std::cout << "Duración desde el epoch (segundos): " 
              << seconds_since_epoch.count() 
              << " segundos." << std::endl;

    // Duracion - > tipo simple ue almacena una duración de tiempo, iteración de horas o personalizados
    printf("Deteniendo hilo x 5s egundos \n ");
    std::chrono::seconds five_seconds = std::chrono::seconds(5);
    std::this_thread::sleep_for(five_seconds);
    printf("Finalizado \n");

    printf("Deteniendo hilo x 10 segundo \n");
    std::chrono::duration<int64_t, std::ratio<1, 10>> decima_segundo(10);
    std::this_thread::sleep_for(decima_segundo);
    printf("Finalizado \n");

    printf("Deteniendo hilo 1 tiempo de 5s \n");
    std::chrono::duration<int32_t, std::ratio<5,1>> five_seconts_unit(1);
    std::this_thread::sleep_for(five_seconts_unit);
    printf("Finalizado \n");

    std::chrono::duration<int32_t, std::ratio<5,1>> five_seconts_unit = std::chrono::duration<int32_t, std::ratio<5,1>>(2);
    

    return 0;
}