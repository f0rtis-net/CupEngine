//
// Created by Иван Караваев on 23.06.2024.
//

#include "windowFabric.h"
#include <iostream>
#include <utility>
#include "impl/SDL_WindowImpl.h"

IWindow* CWindowFabric::getRealisation() {
    if(this->rednererName == "sdl") {
        auto config = std::make_unique<SdlWindowConfig>( SdlWindowConfig{"cupEngine", 500, 500, SDL_WINDOW_OPENGL});
        return new SDL_WindowImpl(std::move(config));
    }

    std::cerr << "Got invalid type for implementation: " << this->rednererName << std::endl;
    exit(1);
}

CWindowFabric::CWindowFabric(std::string rednererName) {
    this->rednererName = std::move(rednererName);
}