/* SdlManager.h
*
* Manages SDL for use with the game.
*
* ImperfectlyCoded © 2019
*/

#ifndef _SDL_MANAGER_H
#define _SDL_MANAGER_H

#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>

class SdlManager
{
public:
    SdlManager() {}
    ~SdlManager() {}

    // Starts up SDL and creates the window and display
    //
    // param windowTitle  the title text that is displayed on the window
    bool Initialize(const std::string& windowTitle);

    // Processes all the events in the event queue
    //
    // param event  the current event to be processed
    void ProcessEvents(SDL_Event* event);

    // Releases all resources allocated
    void Shutdown();

    // Returns true if SDL is running, false otherwise
    bool IsSdlRunning();

private:
    // Starts up SDL
    bool InitSdl();

    // Starts up the window for SDL
    bool InitWindow(const std::string& windowTitle);

    // Starts preparing the display for rendering
    bool InitDisplay();

    // Processes the different events in the event queue
    void HandleEvents(SDL_Event* event);

    // Specificially handles the SDL_QUIT event
    void HandleQuitEvent(SDL_Event* event);


    // the SDL window
    SDL_Window* m_window = nullptr;

    // the display surface for the window
    SDL_Surface* m_surfaceDisplay = nullptr;

    // determines if SDL is running
    bool m_sdlRunning = true;
};

#endif // _SDL_MANAGER_H
