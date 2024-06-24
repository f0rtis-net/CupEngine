//
// Created by Иван Караваев on 23.06.2024.
//

#ifndef CUPENGINE_WINDOW_H
#define CUPENGINE_WINDOW_H

#include <functional>
#include "../eventManager/EventManager.h"
#include "../render/BasicRender.h"

class IWindow {
public:
    virtual void open() = 0;
    virtual void close() = 0;
    virtual void resizeTo(int width, int height) = 0;
    virtual void setEventManager(std::shared_ptr<IEventManager> manager) = 0;
    virtual void setRender(std::shared_ptr<IRenderer> render) = 0;
    virtual void renderCycle(std::function<void()> renderCode) = 0;
};

#endif //CUPENGINE_WINDOW_H
