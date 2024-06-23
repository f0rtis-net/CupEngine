//
// Created by Иван Караваев on 23.06.2024.
//

#ifndef CUPENGINE_SDLWINDOWCONFIG_H
#define CUPENGINE_SDLWINDOWCONFIG_H
#include <string>

struct SdlWindowConfig {
    std::string windowName;
    int width;
    int height;
    uint32_t flags;
};

#endif //CUPENGINE_SDLWINDOWCONFIG_H
