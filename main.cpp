#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include "eventManager/impl/SdlEventManagerTest.h"

void initSDL(SDL_Window** window, SDL_GLContext* context) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        exit(1);
    }

    // Create window with OpenGL context
    *window = SDL_CreateWindow("SDL2 OpenGL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL);
    if (!*window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    // Create OpenGL context
    *context = SDL_GL_CreateContext(*window);
    if (!*context) {
        std::cerr << "Failed to create OpenGL context: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(*window);
        SDL_Quit();
        exit(1);
    }

    // Initialize GLEW
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW: " << glewGetErrorString(err) << std::endl;
        SDL_GL_DeleteContext(*context);
        SDL_DestroyWindow(*window);
        SDL_Quit();
        exit(1);
    }
}

void render() {
    // Set clear color to red
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char* argv[]) {
    SDL_Window* window = nullptr;
    SDL_GLContext context;

    initSDL(&window, &context);

    bool running = true;
    SDL_Event event;

    CSDLEventManagerTest handler = CSDLEventManagerTest();

    handler.registerHandler([&](EventContext_t<SDL_Event>* event){
        if(event->eventContext.key.keysym.sym != SDLK_q)
            return;

        std::cout << "called quitEvent" << std::endl;

        running = false;
    });

    handler.registerHandler([&](EventContext_t<SDL_Event>* event){
        if(event->eventContext.key.keysym.sym != SDLK_w)
            return;

        std::cout << "called key event by key w" << std::endl;
    });

    while (running) {
        while (SDL_PollEvent(&event)) {
           handler.notify(new EventContext_t(event));
        }

        render();

        // Swap the window buffer
        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
