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
#include <memory>
#include "EventManager.h"

class SdlManager
{
public:
    SdlManager() {}
    ~SdlManager();

    // Starts up SDL and creates the window and display
    //
    // param windowTitle  the title text that is displayed on the window
    // param eventManager  the derived manager to process all overriden events
    bool Initialize(const std::string& windowTitle, std::shared_ptr<EventManager> eventManager);

    // Processes all the events in the event queue
    //
    // param event  the current event to be processed
    void ProcessEvents(SDL_Event* event);
    void ProcessEvents(std::vector<SDL_Event*>& events);

    void Render();

    // Releases all resources allocated
    void Shutdown();

    // Returns true if SDL is running, false otherwise
    bool IsSdlRunning();

    SDL_Surface* Load(const std::string& file);

    // Draws the loaded image onto the screen
    //
    // param surfaceDestination  the draw target
    // param surfaceSource  the surfacae to be copied from
    // param x  the x position to draw
    // param y  the y position to draw
    bool Draw(SDL_Surface* surfaceDestination, SDL_Surface* surfaceSource, int32_t x, int32_t y);

    // Draws part of the loaded image onto the screen
    // param surfaceDestination  the draw target
    // param surfaceSource  the surfacae to be copied from
    // param x  the x position to draw
    // param y  the y position to draw
    // param x2  the x position start drawing the rect clip
    // param y2  the y position start drawing the rect clip
    // param w  the width to draw the rect clip
    // param h  the height to draw the rect clip
    bool Draw(SDL_Surface* surfaceDestination, SDL_Surface* surfaceSource, int32_t x, int32_t y, int32_t x2, int32_t y2, int32_t w, int32_t h);

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

    SDL_Surface* m_surfaceTest = nullptr;

    // the passed in event manager
    std::shared_ptr<EventManager> m_eventManager = nullptr;

    // determines if SDL is running
    bool m_sdlRunning = true;
};

#endif // _SDL_MANAGER_H
