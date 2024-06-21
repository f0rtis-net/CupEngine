//
// Created by Иван Караваев on 21.06.2024.
//

#ifndef CUPENGINE_SDLEVENTMANAGERTEST_H
#define CUPENGINE_SDLEVENTMANAGERTEST_H
#include "../EventManager.h"
#include <SDL2/SDL.h>
#include <list>

class CSDLEventManagerTest : public IEventListener<SDL_Event> {
    std::list< std::function<void(EventContext_t<SDL_Event>*)> > handlers;
public:
    void notify(EventContext_t<SDL_Event>* event) override {
        for(auto& listener : this->handlers)
            listener(event);
    }

    void registerHandler(std::function<void(EventContext_t<SDL_Event>*)> accepter) override {
        this->handlers.push_back(accepter);
    }

    void unregisterHandler(std::function<void(EventContext_t<SDL_Event>*)> accepter) override {
        //this->handlers.remove(accepter);
    }
};

#endif //CUPENGINE_SDLEVENTMANAGERTEST_H
