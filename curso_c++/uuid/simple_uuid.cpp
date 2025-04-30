#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>

int main() {
    // Generador de UUID
    boost::uuids::uuid uuid = boost::uuids::random_generator()();

    // Convierte a string y muestra el UUID
    std::cout << "UUID generado: " << uuid << std::endl;

    return 0;
}
