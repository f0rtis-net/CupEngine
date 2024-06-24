//
// Created by Иван Караваев on 21.06.2024.
//

#ifndef CUPENGINE_EVENTMANAGER_H
#define CUPENGINE_EVENTMANAGER_H

#include <functional>

class IEventContext {
public:
    virtual ~IEventContext() = default;
};

class IEventManager {
public:
    virtual ~IEventManager() = default;
    virtual void notify(IEventContext* event) = 0;
    virtual void registerHandler(std::function<void(IEventContext*)> handler) = 0;
    virtual void unregisterHandler(std::function<void(IEventContext*)> handler) = 0;
};

#endif //CUPENGINE_EVENTMANAGER_H
