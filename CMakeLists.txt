cmake_minimum_required(VERSION 3.27)
project(CupEngine)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenGL REQUIRED)

# GLEW
link_libraries(${OPENGL_LIBRARIES})

set(GLEW_H ${PROJECT_SOURCE_DIR}/deps/includes)
include_directories(${GLEW_H})

set(GLEW_LINK ${PROJECT_SOURCE_DIR}/deps/lib/glew/libGLEW.2.2.0.dylib)
link_libraries(${GLEW_LINK})

#SDL
set (SDL_H ${PROJECT_SOURCE_DIR}/deps/includes)
include_directories (${SDL_H})

set(SDL_LIB ${PROJECT_SOURCE_DIR}/deps/lib/sdl/libSDL2-2.0.0.dylib)
link_libraries(${SDL_LIB})


# Execute compilation command
set(SOURCE_FILES src/main.cpp
        src/eventManager/EventManager.h
        src/eventManager/impl/SdlEventManagerTest.h
        src/windowService/window.h
        src/windowService/windowFabric.cpp
        src/windowService/windowFabric.h
        src/windowService/impl/SDL_WindowImpl.cpp
        src/windowService/impl/SDL_WindowImpl.h
        src/windowService/impl/SdlWindowConfig.h)
add_executable(CupEngine ${SOURCE_FILES})