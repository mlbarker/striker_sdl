/* SdlManager.cpp
*
* The implementation to handle SDL for use with the game.
*
* ImperfectlyCoded © 2019
*/

#include <iostream>
#include "SdlManager.h"

bool SdlManager::Initialize(const std::string& windowTitle)
{
    if (!InitSdl())
    {
        std::cout << "Initialize() failed: " << SDL_GetError() << std::endl;
        return false;
    }

    if (!InitWindow(windowTitle))
    {
        std::cout << "Initialize() failed: " << SDL_GetError() << std::endl;
        return false;
    }

    if (!InitDisplay())
    {
        std::cout << "Initialize() failed: " << SDL_GetError() << std::endl;
        return false;
    }

    // SDL initialization was successful
    return true;
}

void SdlManager::Shutdown()
{
    SDL_Quit();
}

bool SdlManager::IsSdlRunning()
{
    return m_sdlRunning;
}

bool SdlManager::InitSdl()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "InitSdl() failed: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

bool SdlManager::InitWindow(const std::string& windowTitle)
{
    if ((m_window = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL)) == nullptr)
    {
        std::cout << "InitWindow() failed on window creation: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

bool SdlManager::InitDisplay()
{
    if ((m_surfaceDisplay = SDL_GetWindowSurface(m_window)) == nullptr)
    {
        std::cout << "InitDisplay() failed on retrieving window's surface: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void SdlManager::ProcessEvents(SDL_Event* event)
{
    while (SDL_PollEvent(event))
    {
        HandleEvents(event);
    }
}

void SdlManager::HandleEvents(SDL_Event* event)
{
    HandleQuitEvent(event);
}

void SdlManager::HandleQuitEvent(SDL_Event* event)
{
    if (event->type == SDL_QUIT)
    {
        m_sdlRunning = false;
    }
}
