//
// Created by Иван Караваев on 24.06.2024.
//

#ifndef CUPENGINE_OPENGLSDLRENDER_H
#define CUPENGINE_OPENGLSDLRENDER_H
#include "../BasicRender.h"
#include "SDL2/SDL.h"

class OpenGLRenderer : public IRenderer {
    SDL_Window* window  = nullptr;
public:
    void initialize(void* window) override;

    void render(std::function<void()> renderCode) override;
};

#endif //CUPENGINE_OPENGLSDLRENDER_H
