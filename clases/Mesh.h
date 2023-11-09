
#ifndef MESH_H
#define MESH_H

#include <vector>
#include "Vertex.h"
#include "Face.h"

class Mesh {
public:
    std::vector<Vertex> vertices;
    std::vector<Face> faces;

    // Agregar un vértice a la malla
    void addVertex(const Vertex& vertex) {
        vertices.push_back(vertex);
    }

    // Agregar una cara a la malla
    void addFace(const Face& face) {
        faces.push_back(face);
    }

    // Dibujar la malla
    void draw();
};

#endif // MESH_H
