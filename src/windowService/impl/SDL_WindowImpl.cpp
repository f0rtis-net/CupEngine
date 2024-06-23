//
// Created by Иван Караваев on 23.06.2024.
//

#include "SDL_WindowImpl.h"
#include <iostream>
#include "../../eventManager/impl/SdlEventManagerTest.h"

void SDL_WindowImpl::open() {
    this->windowHandler = SDL_CreateWindow(this->config->windowName.c_str(),
                                           SDL_WINDOWPOS_UNDEFINED,
                                           SDL_WINDOWPOS_UNDEFINED,
                                           this->config->width,
                                           this->config->height,
                                              this->config->flags);

    if (this->windowHandler == nullptr) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    this->renderer->initialize(this->windowHandler);

    this->windowIsOpened = true;
}

void SDL_WindowImpl::close() {
    SDL_DestroyWindow(this->windowHandler);
}

void SDL_WindowImpl::resizeTo(int width, int height) {

}

SDL_WindowImpl::SDL_WindowImpl(SdlWindowConfig* config) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        exit(1);
    }

    this->config = config;
    this->windowIsOpened = false;
}

SDL_WindowImpl::~SDL_WindowImpl() {
    SDL_Quit();
}

void SDL_WindowImpl::renderCycle(std::function<void()> renderCode) {
    while(this->windowIsOpened) {
        SDL_Event e;
        while(SDL_PollEvent(&e) > 0) {
            SDLEventContext* context = new SDLEventContext(&e);

            this->listener->notify(context);

            this->renderer->render(renderCode);

            delete context;
        }
    }
}

void SDL_WindowImpl::setRender(IRenderer *render) {
    this->renderer = render;
}

void SDL_WindowImpl::setEventListener(IEventListener *listener) {
    this->listener = listener;
}
