#include <iostream>
#include <string>

std::string convertString(const std::string &input) {
    std::string result;
    bool toUpper = true; // Inicializamos en true para que el primer carácter sea mayúscula

    for (char ch : input) {
        if (ch == '_') {
            toUpper = true;
        } else {
            result += toUpper ? std::toupper(ch) : ch;
            toUpper = false;
        }
    }

    return result;
}

int main() {
    std::string input = "hola_como_vas";
    std::string output = convertString(input);
    std::cout << output << std::endl;  // Imprime "HolaComoVas"
    return 0;
}
