/* Game.cpp
*
* This contains the main implementation of the 
* flow of the game. The execution of the application
* begins here.
*
* ImperfectlyCoded © 2019
*/

#include "Game.h"
#include "SdlManager.h"

int32_t Game::Execute()
{
    if (!Initialize())
    {
        return -1;
    }

    // the main loop of the game
    SDL_Event event;
    while (m_isRunning)
    {
        Events(&event);
        Update();
        Render();
    }

    Shutdown();

    return 0;
}

// entry point of the game application
int main(int argc, char* argv[])
{
    Game game;

    return game.Execute();
}
