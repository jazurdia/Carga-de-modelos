#include <iostream>
#include <SDL.h>

void render(SDL_Renderer* renderer);

// Función para crear una ventana de SDL y ejecutar un bucle de renderizado
int main(int argc, char* argv[]) {
    // Inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "Error al inicializar SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Crear una ventana SDL
    SDL_Window* window = SDL_CreateWindow("Renderizado de Gráficos", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
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

    // Main loop de renderizado
    bool quit = false;
    SDL_Event e;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Lógica de actualización aquí

        // Renderizar
        render(renderer); // Llamar a la función de renderizado

        // Actualizar la ventana
        SDL_RenderPresent(renderer);
    }

    // Liberar recursos
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

// Función de renderizado que tiene acceso al SDL_Renderer
void render(SDL_Renderer* renderer) {
    // Lógica de dibujo aquí

    // Por ejemplo, dibujar un rectángulo rojo en el centro de la ventana
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Color rojo
    SDL_Rect rect = {300, 250, 200, 100}; // Coordenadas y dimensiones del rectángulo
    SDL_RenderFillRect(renderer, &rect);
}
