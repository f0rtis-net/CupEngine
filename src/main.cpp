#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <iostream>

#include "eventManager/impl/SdlEventManager.h"
#include "windowService/windowFabric.h"
#include "render/impl/OpenGLSDLRender.h"


int main(int argc, char* argv[]) {
    CWindowFabric windowFabric = CWindowFabric("sdl");

    IWindow* window = windowFabric.getRealisation();

    window->setRender(std::make_shared<OpenGLRenderer>());

    auto manager = std::make_shared<CSDLEventManager>();

    manager->registerHandler([](IEventContext* context){
        auto* casted = reinterpret_cast<SDLEventContext*>(context);

        if(casted->sdlEvent->key.keysym.sym != SDLK_w)
            return;

        std::cout << "Hello world from handler!" << std::endl;
    });

    manager->registerHandler([](IEventContext* context){
        auto* casted = reinterpret_cast<SDLEventContext*>(context);

        if(casted->sdlEvent->key.keysym.sym != SDLK_q)
            return;

        casted->windowOpened = false;
    });

    window->setEventManager(manager);

    window->open();

    window->renderCycle([](){
        glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
    });

    window->close();

    return 0;
}
