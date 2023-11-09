
#ifndef FACE_H
#define FACE_H

#include <vector>
#include <array>

// Definir la estructura Face que almacena índices de vértices para un triángulo
struct Face {
    std::vector<std::array<int, 3>> vertexIndices;

    // Constructor que añade un triángulo a la cara
    Face(int v1, int v2, int v3) {
        addTriangle(v1, v2, v3);
    }

    // Función para añadir un triángulo a la cara
    void addTriangle(int v1, int v2, int v3) {
        // Ajustar los índices para comenzar desde 0
        vertexIndices.push_back({v1 - 1, v2 - 1, v3 - 1});
    }
};

#endif // FACE_H
