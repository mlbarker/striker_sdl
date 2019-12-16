/* Game_Initialize.cpp
*
* This contains the main implementation of the
* flow of the game. The execution of the application
* begins here.
*
* ImperfectlyCoded � 2019
*/

#include "Game.h"
#include "SdlManager.h"

bool Game::Initialize()
{
    m_sdl = std::make_unique<SdlManager>();
    m_eventManager = std::make_shared<EventManager>();
    m_sdl->Initialize("window", m_eventManager);

    return true;
}
