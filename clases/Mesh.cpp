
#include "Mesh.h"
#include "Line.h"

// Definir la función draw de la malla
void Mesh::draw() {
    for (const auto& face : faces) {
        // Dibujar triángulos para cada cara (asumiendo que cada cara es un triángulo)
        Line::line(glm::vec3(vertices[face.vertexIndices[0]].coordinates), 
                   glm::vec3(vertices[face.vertexIndices[1]].coordinates));
        Line::line(glm::vec3(vertices[face.vertexIndices[1]].coordinates), 
                   glm::vec3(vertices[face.vertexIndices[2]].coordinates));
        Line::line(glm::vec3(vertices[face.vertexIndices[2]].coordinates), 
                   glm::vec3(vertices[face.vertexIndices[0]].coordinates));
    }
}
