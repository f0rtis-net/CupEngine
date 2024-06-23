//
// Created by Иван Караваев on 23.06.2024.
//

#ifndef CUPENGINE_WINDOW_H
#define CUPENGINE_WINDOW_H

#include <functional>
#include "../eventManager/EventManager.h"

class IRenderer {
public:
    virtual ~IRenderer() {}
    virtual void initialize(void* window) = 0;
    virtual void render(std::function<void()> renderCode) = 0;
};

class IWindow {
public:
    virtual void open() = 0;
    virtual void close() = 0;
    virtual void resizeTo(int width, int height) = 0;
    virtual void setEventListener(IEventListener* listener) = 0;
    virtual void setRender(IRenderer* render) = 0;
    virtual void renderCycle(std::function<void()> renderCode) = 0;
};

#endif //CUPENGINE_WINDOW_H
