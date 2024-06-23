//
// Created by Иван Караваев on 23.06.2024.
//

#ifndef CUPENGINE_SDL_WINDOWIMPL_H
#define CUPENGINE_SDL_WINDOWIMPL_H

#include "../window.h"
#include "SdlWindowConfig.h"

#include <SDL2/SDL.h>
#include <string>


class SDL_WindowImpl : public IWindow {
    SDL_Window* windowHandler = nullptr;
    SdlWindowConfig* config;
    bool windowIsOpened;
    IRenderer* renderer = nullptr;
    IEventListener* listener = nullptr;
public:
    explicit SDL_WindowImpl(SdlWindowConfig* config);
    ~SDL_WindowImpl();
    void open() override;
    void close() override;
    void setEventListener(IEventListener* listener) override;
    void setRender(IRenderer* render) override;
    void resizeTo(int width, int height) override;
    void renderCycle(std::function<void()> renderCode) override;
};


#endif //CUPENGINE_SDL_WINDOWIMPL_H
