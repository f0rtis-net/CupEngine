#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <iostream>

#include "eventManager/impl/SdlEventManagerTest.h"
#include "windowService/windowFabric.h"

class OpenGLRenderer : public IRenderer {
    SDL_Window* window  = nullptr;
public:
    void initialize(void* window) override {
        this->window = static_cast<SDL_Window*>(window);

        SDL_GLContext context = SDL_GL_CreateContext(this->window);
        if (!context) {
            exit(1);
        }

        glewExperimental = GL_TRUE;
        if (glewInit() != GLEW_OK) {
            exit(1);
        }
    }

    void render(std::function<void()> renderCode) override {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        renderCode();
        SDL_GL_SwapWindow(static_cast<SDL_Window*>(window));
    }
};

int main(int argc, char* argv[]) {
    CWindowFabric windowFabric = CWindowFabric("sdl");

    IWindow* window = windowFabric.getRealisation();

    window->setRender(new OpenGLRenderer());

    CSDLEventManagerTest manager = CSDLEventManagerTest();

    manager.registerHandler([](IEventContext* context){
        auto* casted = reinterpret_cast<SDLEventContext*>(context);

        if(casted->sdlEvent->key.keysym.sym != SDLK_w)
            return;

        std::cout << "Hello world from handler!" << std::endl;
    });

    window->setEventListener(&manager);

    window->open();

    window->renderCycle([](){
        glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
    });

    window->close();

    return 0;
}
