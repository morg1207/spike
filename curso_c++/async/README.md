La librería `std::future` en C++ permite manejar tareas asíncronas y sincronización entre hilos. Es especialmente útil cuando quieres ejecutar una tarea en un hilo distinto y, en algún momento, recuperar su resultado sin bloquear el hilo principal. 

Aquí te explico el concepto:

1. **`std::future`**: es un objeto que representa un valor que estará disponible en el futuro. Con `future`, puedes acceder a un valor que será calculado por otro hilo en algún momento, pero el acceso está sincronizado para asegurar que no intentes leerlo hasta que esté listo. 

2. **Estado compartido**: tanto el `future` como el "proveedor" (que podría ser un objeto `promise`, `packaged_task`, o una llamada a `async`) tienen acceso a un "estado compartido". Este estado compartido es el lugar donde el valor se almacena cuando la tarea ha terminado de ejecutarse, o donde se almacena un error si la tarea falla.

3. **Proveedores**: existen tres maneras de "proveer" un valor a un `future`:
   - **`std::promise`**: es un objeto que puedes usar para asignar el valor que se usará en un `future`. Tú configuras el valor de `promise` y, cuando esté listo, el `future` podrá acceder a él.
   - **`std::packaged_task`**: encapsula una función o tarea que se puede ejecutar en otro hilo y se puede asociar con un `future`. Cuando la tarea termina, el resultado queda disponible en el `future`.
   - **`std::async`**: lanza una función asíncronamente (en otro hilo) y automáticamente asocia su resultado con un `future`.

4. **Sincronización y acceso asíncrono**: el `future` y el proveedor trabajan juntos en sincronía sobre el estado compartido. Esto significa que:
   - El proveedor "notifica" al `future` cuando el valor está listo.
   - El `future` espera hasta que el proveedor haya completado su tarea, de forma que no intenta leer un valor que aún no ha sido calculado.

Por ejemplo, si lanzas una tarea con `std::async`, este ejecuta la tarea en un hilo diferente y devuelve un `future`. Puedes consultar el `future` para ver si el resultado está listo y usar el método `.get()` para obtener el valor (lo cual bloqueará el hilo que llama hasta que el resultado esté disponible).

Esto permite dividir las tareas en hilos independientes y sincronizarlas sin problemas, manejando así la ejecución asíncrona de manera ordenada.

## 1. std::future
### 1.1 Funciones miembro
#### 1.1.1 Wait for:

Función que espera un determinado tiempo para comprobar el **shared state** si esta listo antes deque em tiempo culmine, la función hace un **break** en la espera y sale automáticamente.

Parameters
```c++
rel_time
```

return value
```c++
return future_status::ready
return future_satatus::timeout

```

## 1. std::promise

Este texto describe cómo funcionan los objetos `std::promise` y `std::future` en C++. A continuación, te explicaré cada parte en detalle para que comprendas cómo interactúan y cuál es su propósito.

### Promesas y Futuros

1. **Definición de `std::promise`**:
   - Una promesa (`std::promise<T>`) es un objeto que puede almacenar un valor de tipo `T`, que será recuperado por un objeto de tipo `std::future<T>`. 
   - Su función principal es proporcionar un mecanismo de sincronización entre hilos, permitiendo que un hilo (el productor) establezca un valor que será utilizado por otro hilo (el consumidor).

2. **Creación y Estado Compartido**:
   - Al construir un objeto `std::promise`, este se asocia a un nuevo estado compartido. Este estado es donde se almacenará el valor o la excepción que se puede generar.
   - Este estado compartido es esencial porque permite que el valor se almacene de manera que sea accesible desde diferentes hilos.

3. **Asociación con `std::future`**:
   - Para asociar el estado compartido a un objeto `std::future`, se llama a `get_future()` en la promesa.
   - Después de esta llamada, tanto la promesa como el futuro comparten el mismo estado compartido:
     - **Promesa**: Se considera el proveedor asíncrono que tiene la responsabilidad de establecer un valor en el estado compartido en algún momento.
     - **Futuro**: Es un objeto que permite recuperar el valor del estado compartido. Si el valor aún no está listo, el `future` puede bloquear el hilo que lo invoca hasta que el valor esté disponible.

4. **Vida Útil del Estado Compartido**:
   - La vida útil del estado compartido se mantiene mientras exista al menos un objeto asociado a él. Esto significa que el estado compartido no se destruirá hasta que todos los objetos (promesa y futuro, por ejemplo) que lo usan sean destruidos o liberados.
   - Esto es importante porque permite que el futuro continúe accediendo al valor incluso si la promesa que lo creó ha sido destruida, siempre que el futuro siga existiendo.

### Ejemplo de Flujo de Trabajo

Aquí hay un ejemplo simplificado para ilustrar cómo se utilizan `std::promise` y `std::future`:

```cpp
#include <iostream>
#include <thread>
#include <future>
#include <chrono>

void producer(std::promise<int>& prom) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simula una tarea que toma tiempo
    prom.set_value(100); // Cumple la promesa con el valor 100
}

void consumer(std::future<int>& fut) {
    int result = fut.get(); // Bloquea hasta que el valor esté disponible
    std::cout << "Received: " << result << std::endl; // Imprime el valor recibido
}

int main() {
    std::promise<int> prom;         // Crea una promesa
    std::future<int> fut = prom.get_future(); // Obtiene el futuro asociado

    std::thread prodThread(producer, std::ref(prom)); // Hilo productor
    std::thread consThread(consumer, std::ref(fut));   // Hilo consumidor

    prodThread.join(); // Espera a que el hilo productor termine
    consThread.join(); // Espera a que el hilo consumidor termine

    return 0;
}
```

### Descripción del Ejemplo

1. **Hilo Productor** (`producer`):
   - Simula un trabajo que tarda 2 segundos utilizando `std::this_thread::sleep_for`.
   - Luego, llama a `set_value(100)` en la promesa, que establece el valor en el estado compartido.

2. **Hilo Consumidor** (`consumer`):
   - Llama a `fut.get()`, que bloquea la ejecución hasta que el hilo productor cumple la promesa y el valor está disponible.
   - Una vez que el valor está listo, se imprime.

### Resumen

- La promesa actúa como un proveedor asíncrono que establece un valor, mientras que el futuro actúa como un mecanismo de retorno asíncrono que recupera ese valor.
- El estado compartido garantiza que ambos objetos (promesa y futuro) puedan sincronizarse de manera efectiva, permitiendo que un hilo espere de forma segura hasta que otro hilo establezca el valor. 
- La vida útil del estado compartido es independiente de la vida útil de la promesa, lo que proporciona flexibilidad en el manejo de la sincronización entre hilos.
### 1.1 Funciones miembro
#### 1.1.1 Get Future:

Parameters
```c++
rel_time
```

return value
```c++
return future_status::ready
return future_satatus::timeout

```