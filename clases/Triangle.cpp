
#include "Triangle.h"
#include "Line.h"

void Triangle::triangle(const glm::vec3& A, const glm::vec3& B, const glm::vec3& C) {
    Line::line(A, B);
    Line::line(B, C);
    Line::line(C, A);
}
