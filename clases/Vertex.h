#ifndef VERTEX_H
#define VERTEX_H

#include <glm/glm.hpp>
#include <iostream>

// Clase Vertex que puede manejar 2, 3 y 4 dimensiones utilizando GLM
class Vertex {
public:
    glm::vec4 coordinates; // Almacenamos las coordenadas como un glm::vec4 para flexibilidad

    // Constructor directo desde glm::vec4
    explicit Vertex(const glm::vec4& coords) : coordinates(coords) {}

    // Constructores sobrecargados para diferentes tamaños de vértices
    Vertex(float x, float y) : coordinates(x, y, 0.0f, 1.0f) {}
    Vertex(float x, float y, float z) : coordinates(x, y, z, 1.0f) {}
    Vertex(float x, float y, float z, float w) : coordinates(x, y, z, w) {}

    // Operador de suma que suma los vértices
    Vertex operator+(const Vertex& other) const {
        return Vertex(coordinates + other.coordinates);
    }

    // Operador de multiplicación por escalar
    Vertex operator*(float scalar) const {
        return Vertex(coordinates * scalar);
    }

    // Función para imprimir un vértice
    friend std::ostream& operator<<(std::ostream& os, const Vertex& vertex) {
        os << '(' << vertex.coordinates.x << ", " << vertex.coordinates.y
           << ", " << vertex.coordinates.z << ", " << vertex.coordinates.w << ')';
        return os;
    }
};

#endif // VERTEX_H
