//
// Created by Иван Караваев on 24.06.2024.
//

#ifndef CUPENGINE_BASICRENDER_H
#define CUPENGINE_BASICRENDER_H

#include <functional>

class IRenderer {
public:
    virtual ~IRenderer() {}
    virtual void initialize(void* window) = 0;
    virtual void render(std::function<void()> renderCode) = 0;
};

#endif //CUPENGINE_BASICRENDER_H
