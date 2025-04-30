#include "node.h"
#include <iostream>

void callback(const Message& msg) {
    std::cout << "I heard: [" << msg.data << "]" << std::endl;
}

int main(int argc, char **argv) {
    Node node("listener");  // Crear un nodo
    node.subscribe("chatter", callback);  // Suscribirse al tópico "chatter"

    // Publicar un mensaje en el tópico "chatter"
    Message msg;
    msg.data = "Hello, world!";
    node.publish("chatter", msg);
    
    msg.data = "Hello, world1!";
    node.publish("chatter", msg);

    // Procesar mensajes
    node.spin();

    return 0;
}