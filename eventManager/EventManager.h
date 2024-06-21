//
// Created by Иван Караваев on 21.06.2024.
//

#ifndef CUPENGINE_EVENTMANAGER_H
#define CUPENGINE_EVENTMANAGER_H

#include <functional>

template<typename T>
struct EventContext_t {
    T eventContext;
    explicit EventContext_t(T context) {
        this->eventContext = context;
    }
};

template<typename T>
class IEventListener {
public:
    virtual ~IEventListener() = default;
    virtual void notify(EventContext_t<T>* event) = 0;
    virtual void registerHandler(std::function<void(EventContext_t<T>*)> handler) = 0;
    virtual void unregisterHandler(std::function<void(EventContext_t<T>*)> handler) = 0;
};

#endif //CUPENGINE_EVENTMANAGER_H
