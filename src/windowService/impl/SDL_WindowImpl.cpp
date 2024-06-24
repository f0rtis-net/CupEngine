//
// Created by Иван Караваев on 23.06.2024.
//

#include "SDL_WindowImpl.h"
#include <iostream>
#include <utility>
#include "../../eventManager/impl/SdlEventManager.h"

void SDL_WindowImpl::open() {
    this->windowHandler = std::shared_ptr<SDL_Window>(SDL_CreateWindow(this->config->windowName.c_str(),
                                           SDL_WINDOWPOS_UNDEFINED,
                                           SDL_WINDOWPOS_UNDEFINED,
                                           this->config->width,
                                           this->config->height,
                                              this->config->flags), SDL_DestroyWindow);

    if (this->windowHandler == nullptr) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    this->renderer->initialize(this->windowHandler.get());

    this->windowIsOpened = true;
}

void SDL_WindowImpl::close() {
    this->windowHandler.reset();
}

void SDL_WindowImpl::resizeTo(int width, int height) {

}

SDL_WindowImpl::SDL_WindowImpl(std::unique_ptr<SdlWindowConfig> config) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        exit(1);
    }

    this->config = std::move(config);
    this->windowIsOpened = false;
}

SDL_WindowImpl::~SDL_WindowImpl() {
    SDL_Quit();
}

void SDL_WindowImpl::renderCycle(std::function<void()> renderCode) {
    auto context = std::make_unique<SDLEventContext>(nullptr, this->windowIsOpened);

    while(this->windowIsOpened) {
        SDL_Event e;
        while(SDL_PollEvent(&e) > 0) {
            context.get()->sdlEvent = &e;

            this->manager->notify(context.get());

            this->renderer->render(renderCode);
        }
    }
}

void SDL_WindowImpl::setRender(std::shared_ptr<IRenderer> render) {
    this->renderer = render;
}

void SDL_WindowImpl::setEventManager(std::shared_ptr<IEventManager> manager) {
    this->manager = manager;
}
