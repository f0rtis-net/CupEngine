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
    std::shared_ptr<SDL_Window> windowHandler;
    std::unique_ptr<SdlWindowConfig> config;
    bool windowIsOpened;
    std::shared_ptr<IRenderer> renderer;
    std::shared_ptr<IEventManager> manager;
public:
    explicit SDL_WindowImpl(std::unique_ptr<SdlWindowConfig> config);
    ~SDL_WindowImpl();
    void open() override;
    void close() override;
    void setEventManager(std::shared_ptr<IEventManager> manager) override;
    void setRender(std::shared_ptr<IRenderer> render) override;
    void resizeTo(int width, int height) override;
    void renderCycle(std::function<void()> renderCode) override;
};


#endif //CUPENGINE_SDL_WINDOWIMPL_H
