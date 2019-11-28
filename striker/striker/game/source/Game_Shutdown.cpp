/* Game_Shutdown.cpp
*
* This handles releasing all resources prior to 
* the application exiting.
*
* ImperfectlyCoded © 2019
*/

#include "Game.h"
#include "SdlManager.h"

void Game::Shutdown()
{
    m_sdl.reset(nullptr);
}
