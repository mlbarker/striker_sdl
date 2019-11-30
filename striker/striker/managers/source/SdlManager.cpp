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

    if ((m_surfaceTest = Load("assets/test/Icon_BoxingGlove_128.bmp")) == nullptr)
    {
        std::cout << "Initialize() failed: " << SDL_GetError() << std::endl;
        return false;
    }

    // SDL initialization was successful
    return true;
}

void SdlManager::ProcessEvents(SDL_Event* event)
{
    while (SDL_PollEvent(event))
    {
        HandleEvents(event);
    }
}

void SdlManager::Render()
{
    Draw(m_surfaceDisplay, m_surfaceTest, 0, 0);
    Draw(m_surfaceDisplay, m_surfaceTest, 300, 300, 0, 0, 100, 100);

    SDL_UpdateWindowSurface(m_window);
}

void SdlManager::Shutdown()
{
    SDL_FreeSurface(m_surfaceTest);
    m_surfaceTest = nullptr;

    SDL_FreeSurface(m_surfaceDisplay);
    m_surfaceDisplay = nullptr;

    SDL_Quit();
}

bool SdlManager::IsSdlRunning()
{
    return m_sdlRunning;
}

SDL_Surface* SdlManager::Load(const std::string& file)
{
    SDL_Surface* surfaceTemp = nullptr;
    SDL_Surface* surfaceReturn = nullptr;

    if ((surfaceTemp = SDL_LoadBMP(file.c_str())) == nullptr)
    {
        std::cout << "Load() failed: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    surfaceReturn = SDL_ConvertSurface(surfaceTemp, m_surfaceDisplay->format, 0);
    SDL_FreeSurface(surfaceTemp);

    return surfaceReturn;
}

bool SdlManager::Draw(SDL_Surface* surfaceDestination, SDL_Surface* surfaceSource, int32_t x, int32_t y)
{
    if (surfaceDestination == nullptr || surfaceSource == nullptr)
    {
        return false;
    }

    SDL_Rect rectDestination;
    rectDestination.x = x;
    rectDestination.y = y;

    SDL_BlitSurface(surfaceSource, nullptr, surfaceDestination, &rectDestination);

    return true;
}

bool SdlManager::Draw(SDL_Surface* surfaceDestination, SDL_Surface* surfaceSource, int32_t x, int32_t y, int32_t x2, int32_t y2, int32_t w, int32_t h)
{
    if (surfaceDestination == nullptr || surfaceSource == nullptr)
    {
        return false;
    }

    SDL_Rect rectDestination;
    rectDestination.x = x;
    rectDestination.y = y;

    SDL_Rect rectSource;
    rectSource.x = x2;
    rectSource.y = y2;
    rectSource.w = w;
    rectSource.h = h;

    SDL_BlitSurface(surfaceSource, &rectSource, surfaceDestination, &rectDestination);

    return true;
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
