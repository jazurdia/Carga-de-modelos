#include <iostream>
#include <SDL.h>
#include "DrawPoint.h"

int main() {
    // Inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Error al inicializar SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Crear una ventana SDL
    SDL_Window* window = SDL_CreateWindow("Dibujar Punto", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Error al crear la ventana: " << SDL_GetError() << std::endl;
        return 2;
    }

    // Crear un renderizador
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Error al crear el renderizador: " << SDL_GetError() << std::endl;
        return 3;
    }

    // Color para el punto
    SDL_Color puntoColor = {255, 0, 0, 255};  // Rojo

    // Crear un objeto DrawPoint
    DrawPoint drawPoint(renderer, puntoColor);

    // Dibujar un punto en las coordenadas (400, 300)
    drawPoint.draw(400, 300);

    // Actualizar la ventana
    SDL_RenderPresent(renderer);

    // Esperar hasta que se cierre la ventana
    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
    }

    // Liberar recursos
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
