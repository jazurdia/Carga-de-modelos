#ifndef DRAWPOINT_H
#define DRAWPOINT_H

#include <SDL.h>
#include <glm/vec3.hpp>

// Clase para dibujar puntos en la pantalla usando SDL
class DrawPoint {
private:
    SDL_Renderer* renderer;
    SDL_Color pointColor;
    int screenWidth, screenHeight;

public:
    // Constructor
    DrawPoint(SDL_Renderer* renderer, SDL_Color color, int screenWidth, int screenHeight);

    // Método para dibujar un punto en las coordenadas (x, y), ahora usando glm::vec3
    void draw(glm::vec3 position);
};

#endif // DRAWPOINT_H
