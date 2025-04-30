#ifndef NODE_H
#define NODE_H

#include <string>
#include <map>
#include <functional>
#include <queue>
#include "message.h"

class Node {
public:
    // Constructor
    Node(const std::string& name);

    // Publicar un mensaje en un tópico
    void publish(const std::string& topic, const Message& msg);

    // Suscribirse a un tópico
    void subscribe(const std::string& topic, std::function<void(const Message&)> callback);

    // Procesar mensajes recibidos
    void spin();

private:
    std::string name;  // Nombre del nodo
    std::map<std::string, std::queue<Message>> topics;  // Colas de mensajes por tópico
    std::map<std::string, std::function<void(const Message&)>> callbacks;  // Callbacks por tópico
};

#endif // NODE_H