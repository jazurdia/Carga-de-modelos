
#include "SDL.h" // Asegúrate de que la ruta al archivo de cabecera de SDL sea correcta
#include "glm/glm.hpp"
#include "Line.h"
#include <cmath>

// Supongamos que tenemos una superficie global de SDL donde dibujaremos
extern SDL_Surface* surface; // Esta variable debe ser definida en otro lugar

// Función para establecer el color de un píxel en la superficie de SDL
void draw_pixel(int x, int y) {
    if (x < 0 || x >= surface->w || y < 0 || y >= surface->h) {
        return; // Verificar que estamos dentro de los límites de la superficie
    }

    Uint32 color = SDL_MapRGB(surface->format, 255, 255, 255); // Color blanco

    Uint32* pixels = (Uint32*)surface->pixels;
    pixels[(y * surface->w) + x] = color;
}

// Implementación de la clase Line con el algoritmo de Bresenham
void Line::pixel(int x, int y) {
    draw_pixel(x, y); // Ahora llama a la nueva función draw_pixel
}

void Line::line(const glm::vec3& start, const glm::vec3& end) {
    // El resto del código del algoritmo de Bresenham...
    int x1 = std::round(start.x), y1 = std::round(start.y);
    int x2 = std::round(end.x), y2 = std::round(end.y);

    int dx = std::abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
    int dy = -std::abs(y2 - y1), sy = y1 < y2 ? 1 : -1; 
    int err = dx + dy, e2; /* error value e_xy */
    
    for (;;) { /* loop */
        pixel(x1, y1);
        if (x1 == x2 && y1 == y2) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x1 += sx; } /* e_xy+e_x > 0 */
        if (e2 <= dx) { err += dx; y1 += sy; } /* e_xy+e_y < 0 */
    }
}
