
#ifndef LINE_H
#define LINE_H

#include <glm/glm.hpp>

class Line {
public:
    static void pixel(int x, int y);
    static void line(const glm::vec3& start, const glm::vec3& end);
};

#endif // LINE_H
