
#include "SDL.h"
#include "clases/Line.h" // Asegúrate de que la ruta al archivo de cabecera sea correcta
#include "clases/Triangle.h" // Incluir la clase Triangle
#include "clases/Face.h" // Incluir la estructura Face
#include "clases/Mesh.h" // Incluir la clase Mesh
#include <glm/glm.hpp>
#include <iostream>

SDL_Surface* surface = nullptr;

int main(int argc, char* argv[]) {
    // Inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL no pudo inicializar: %s", SDL_GetError());
        return -1;
    }

    // Crear una ventana de SDL
    SDL_Window* window = SDL_CreateWindow("Mesh Test - Triangulated Cube", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
    if (!window) {
        SDL_Log("No se pudo crear la ventana: %s", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    // Crear una superficie en la ventana
    surface = SDL_GetWindowSurface(window);

    // Crear una malla y agregar vértices y caras trianguladas
    Mesh cube;
    cube.addVertex(Vertex(1.125986f, 0.781798f, -1.058748f)); // Vértice 0
    cube.addVertex(Vertex(0.074502f, -0.860990f, -1.501048f)); // Vértice 1
    cube.addVertex(Vertex(1.568286f, 0.015753f, 0.735004f)); // Vértice 2
    cube.addVertex(Vertex(0.516802f, -1.627034f, 0.292704f)); // Vértice 3
    cube.addVertex(Vertex(-0.516802f, 1.627034f, -0.292704f)); // Vértice 4
    cube.addVertex(Vertex(-1.568286f, -0.015753f, -0.735004f)); // Vértice 5
    cube.addVertex(Vertex(-0.074502f, 0.860990f, 1.501048f)); // Vértice 6
    cube.addVertex(Vertex(-1.125986f, -0.781798f, 1.058748f)); // Vértice 7

    // Agregar caras trianguladas (los índices ya están ajustados para comenzar en 0)
    cube.addFace(Face({4, 2, 0}));
    cube.addFace(Face({2, 7, 3}));
    cube.addFace(Face({6, 5, 7}));
    cube.addFace(Face({1, 7, 5}));
    cube.addFace(Face({0, 3, 1}));
    cube.addFace(Face({4, 1, 5}));
    cube.addFace(Face({4, 6, 2}));
    cube.addFace(Face({2, 6, 7}));
    cube.addFace(Face({6, 4, 5}));
    cube.addFace(Face({1, 3, 7}));
    cube.addFace(Face({0, 2, 3}));
    cube.addFace(Face({4, 0, 1}));

    // Dibujar el cubo
    cube.draw();

    // Actualizar la superficie de la ventana
    SDL_UpdateWindowSurface(window);
    SDL_Delay(2000); // Esperar 2 segundos antes de cerrar la ventana


    // Esperar un evento para cerrar
    SDL_Event e;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }
    }

    // Limpiar antes de salir
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
