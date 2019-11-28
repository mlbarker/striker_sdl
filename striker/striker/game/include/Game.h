/* Game.h
*
* This manages the flow of any game utilitizing
* the SDL API.
*
* ImperfectlyCoded © 2019
*/

#ifndef _GAME_H
#define _GAME_H

#include <memory>
#include "SdlManager.h"

class Game
{
public:
    Game() {}
    ~Game() {}

    // starts the game application
    int32_t Execute();

public:
    // starts up and allocates memory for all 
    // resources necessary to get the game started
    //
    // Returns true if successful, false otherwise
    bool Initialize();

    // processes events from SDL
    //
    // param event  the event to use for polling the event queue
    void Events(SDL_Event* event);

    // updates all game data based on the polled events
    void Update();

    // redraws the screen based on the updated game data
    void Render();

    // clears and releases all resources back to the OS
    void Shutdown();

private:

    // the SDL manager
    std::unique_ptr<SdlManager> m_sdl = nullptr;

    // determines if this application is running
    bool m_isRunning = true;
};

#endif // _GAME_H
