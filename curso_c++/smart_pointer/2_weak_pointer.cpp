#include <iostream>
#include <memory>  // Necesario para std::shared_ptr, std::weak_ptr, y std::enable_shared_from_this

class MiClase : public std::enable_shared_from_this<MiClase> {
public:
    void metodoCompartido() {
        std::cout << "Método de MiClase llamado.\n";
    }

    std::weak_ptr<MiClase> obtenerWeakPtr() {
        return weak_from_this(); // Devuelve un weak_ptr al objeto actual
    }
};

int main() {
    // Crear un shared_ptr que gestiona el objeto
    auto sp1 = std::make_shared<MiClase>();

    // Obtener un weak_ptr al objeto
    std::weak_ptr<MiClase> wp = sp1->obtenerWeakPtr();

    // Verificar si el weak_ptr puede bloquearse
    if (auto sp2 = wp.lock()) { // `lock()` devuelve un shared_ptr si el objeto aún existe
        sp2->metodoCompartido(); // Usamos el objeto de manera segura
    } else {
        std::cout << "El objeto ya no existe.\n";
    }

    // Una vez que eliminamos el último `shared_ptr`, el objeto se destruye.
    sp1.reset(); // Libera el objeto

    // Intentamos bloquear de nuevo el weak_ptr después de liberar el shared_ptr
    if (auto sp3 = wp.lock()) {
        sp3->metodoCompartido();
    } else {
        std::cout << "El objeto ya no existe después de liberar el shared_ptr.\n";
    }

    return 0;
}