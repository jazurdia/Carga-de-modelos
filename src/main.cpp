#include <iostream>
#include <SDL.h>
#include "gl.h"

// testing functions in gl.h

void testDrawPoint() {
    Point p = {glm::vec3(100, 100, 0)};
    setColor({255, 0, 0, 255});
    drawPoint(p);
}

void testDrawTriangle(){
    Triangle t = {glm::vec3(45, 382, 0), glm::vec3(200, 200, 0), glm::vec3(100, 100, 0)};
    setColor({0, 0, 255, 255});
    drawTriangle(t);
}


// Una función main que cree una ventana de SDL y inicie un main loop de renderizado
int main(int arcg, char* argv[]) {
    // Inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create window
    window = SDL_CreateWindow("Flat Shading", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    // Check if window was created
    if (window == nullptr) {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool quit = false; // Loop flag

    // Event handler
    SDL_Event e;

    // While application is running
    while (!quit) {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            // User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Clear screen
        SDL_SetRenderDrawColor(renderer, clearColor.r, clearColor.g, clearColor.b, clearColor.a);
        SDL_RenderClear(renderer);

        // testing functions
        testDrawPoint();
        testDrawTriangle();


        // Update screen
        SDL_RenderPresent(renderer);
    }

    return 0;
}