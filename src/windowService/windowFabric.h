//
// Created by Иван Караваев on 23.06.2024.
//

#ifndef CUPENGINE_WINDOWFABRIC_H
#define CUPENGINE_WINDOWFABRIC_H

#include "window.h"
#include <string>

class CWindowFabric {
    std::string rednererName;
public:
    explicit CWindowFabric(std::string rednererName);
    IWindow* getRealisation();
};


#endif //CUPENGINE_WINDOWFABRIC_H
