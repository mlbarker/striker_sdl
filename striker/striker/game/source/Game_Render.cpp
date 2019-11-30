/* Game_Render.cpp
*
* This is where all the rendering happens
* after all thhe game updates have been executed.
*
* ImperfectlyCoded © 2019
*/

#include "Game.h"
#include "SdlManager.h"

void Game::Render()
{
    m_sdl->Render();
}
