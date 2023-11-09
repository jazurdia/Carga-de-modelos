#include "DrawPoint.h"

// Constructor implementation
DrawPoint::DrawPoint(SDL_Renderer* renderer, SDL_Color color, int screenWidth, int screenHeight) {
    this->renderer = renderer;
    this->pointColor = color;
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
}

// Method to draw a point at a position represented by glm::vec3
void DrawPoint::draw(glm::vec3 position) {
    // Convertimos las coordenadas de glm a las de SDL, ignorando la componente z
    int x = static_cast<int>(position.x);
    int y = static_cast<int>(position.y);
    
    // Comprobamos si el punto está dentro de los límites de la pantalla
    if (x >= 0 && y >= 0 && x < screenWidth && y < screenHeight) {
        SDL_SetRenderDrawColor(renderer, pointColor.r, pointColor.g, pointColor.b, pointColor.a);
        SDL_RenderDrawPoint(renderer, x, y);
    }
    // Si el punto está fuera de la pantalla, no hacemos nada (SDL ya maneja esto, pero evitamos llamadas innecesarias)
}
