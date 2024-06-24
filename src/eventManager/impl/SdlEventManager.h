//
// Created by Иван Караваев on 21.06.2024.
//

#ifndef CUPENGINE_SDLEVENTMANAGER_H
#define CUPENGINE_SDLEVENTMANAGER_H
#include "../EventManager.h"
#include "SDL2/SDL.h"
#include <list>

class SDLEventContext : public IEventContext {
public:
    SDL_Event* sdlEvent;
    bool& windowOpened;
    explicit SDLEventContext(SDL_Event* event, bool& windowOpened) : sdlEvent(event), windowOpened(windowOpened) {}
};

class CSDLEventManager : public IEventManager {
    std::list< std::function<void(IEventContext*)> > handlers;
public:
    void notify(IEventContext* event) override {
        for(auto& listener : this->handlers)
            listener(event);
    }

    void registerHandler(std::function<void(IEventContext*)> accepter) override {
        this->handlers.push_back(accepter);
    }

    void unregisterHandler(std::function<void(IEventContext*)> accepter) override {
        //this->handlers.remove(accepter);
    }
};

#endif //CUPENGINE_SDLEVENTMANAGER_H
