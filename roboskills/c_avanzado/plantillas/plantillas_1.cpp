
/*template <typename T>
T suma(T a, T b) {
    return a + b;
}*/


#include <iostream>

template <typename T>
T suma(T a, T b) {
    return a + b;
}

int main() {
    std::cout << suma<int>(3, 4) << std::endl;        // Usa int
    std::cout << suma<float>(3.5, 4.2) << std::endl;    // Usa double
    return 0;
}