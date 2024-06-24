//
// Created by Иван Караваев on 24.06.2024.
//

#include "OpenGLSDLRender.h"
#include <GL/glew.h>

void OpenGLRenderer::render(std::function<void()> renderCode) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    renderCode();
    SDL_GL_SwapWindow(static_cast<SDL_Window*>(window));
}

void OpenGLRenderer::initialize(void *window) {
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