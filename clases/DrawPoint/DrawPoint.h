#ifndef DRAWPOINT_H
#define DRAWPOINT_H

#include <SDL.h>

class DrawPoint {
public:
    // Constructor
    DrawPoint(SDL_Renderer* renderer, SDL_Color color);

    // Método para dibujar un punto en las coordenadas (x, y)
    void draw(int x, int y);

private:
    SDL_Renderer* renderer;
    SDL_Color pointColor;
};

// Constructor implementation
DrawPoint::DrawPoint(SDL_Renderer* renderer, SDL_Color color) {
    this->renderer = renderer;
    this->pointColor = color;

    void draw(int x, int y);

}

// Method to draw a point at coordinates (x, y)
void DrawPoint::draw(int x, int y) {
    SDL_SetRenderDrawColor(renderer, pointColor.r, pointColor.g, pointColor.b, pointColor.a);
    SDL_RenderDrawPoint(renderer, x, y);
}

#endif // DRAWPOINT_H
