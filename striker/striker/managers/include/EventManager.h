/* EventManager.h
*
* Manages SDL Events for use with the game.
*
* ImperfectlyCoded © 2019
*/

#ifndef _EVENTMANANGER_H
#define _EVENTMANANGER_H

#include <SDL.h>

class EventManager
{
public:
    EventManager();
    virtual ~EventManager();

    virtual void OnEvent(SDL_Event* event);
    virtual void OnKeyDown(SDL_Keysym sym, Uint16 mod, SDL_Scancode scancode);
    virtual void OnKeyUp(SDL_Keysym sym, Uint16 mod, SDL_Scancode scancode);
    virtual void OnMouseMove(int32_t mX, int32_t mY, int32_t relX, int32_t relY, bool left, bool right, bool middle);
    virtual void OnMouseWheel(bool up, bool down);
    virtual void OnLButtonDown(int32_t mX, int32_t mY);
    virtual void OnLButtonUp(int32_t mX, int32_t mY);
    virtual void OnRButtonDown(int32_t mX, int32_t mY);
    virtual void OnRButtonUp(int32_t mX, int32_t mY);
    virtual void OnMButtonDown(int32_t mX, int32_t mY);
    virtual void OnMButtonUp(int32_t mX, int32_t mY);
    virtual void OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value);
    virtual void OnJoyButtonDown(Uint8 which, Uint8 button);
    virtual void OnJoyButtonUp(Uint8 which, Uint8 button);
    virtual void OnJoyHat(Uint8 which, Uint8 hat, Uint8 value);
    virtual void OnJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel);
    virtual void OnMinimize();
    virtual void OnRestore();
    virtual void OnResize(int32_t w, int32_t h);
    virtual void OnExpose();
    virtual void OnExit();
    virtual void OnUser(Uint8 type, int32_t code, void* data1, void* data2);
};

#endif // _EVENTMANAGER_H
