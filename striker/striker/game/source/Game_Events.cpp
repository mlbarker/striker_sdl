/* Game_Events.cpp
*
* This contains the implementation of the
* event loop and processing events for the game.
*
* ImperfectlyCoded © 2019
*/

#include "Game.h"
#include "SdlManager.h"

void Game::Events(SDL_Event* event)
{
    m_sdl->ProcessEvents(event);

    // check this due to the SDL_QUIT event
    m_isRunning = m_sdl->IsSdlRunning();
}
