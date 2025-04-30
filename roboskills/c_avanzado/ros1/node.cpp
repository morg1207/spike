#include "node.h"

Node::Node(const std::string& name) : name(name) {}

void Node::publish(const std::string& topic, const Message& msg) {
    topics[topic].push(msg);  // Añadir mensaje a la cola del tópico
}

void Node::subscribe(const std::string& topic, std::function<void(const Message&)> callback) {
    callbacks[topic] = callback;  // Registrar callback para el tópico
}

void Node::spin() {
    while (true) {
        for (auto& [topic, queue] : topics) {
            while (!queue.empty()) {
                Message msg = queue.front();
                queue.pop();
                if (callbacks.find(topic) != callbacks.end()) {
                    callbacks[topic](msg);  // Llamar al callback con el mensaje
                }
            }
        }
    }
}