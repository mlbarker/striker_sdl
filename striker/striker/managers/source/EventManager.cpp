#include "EventManager.h"

EventManager::EventManager()
{
}

EventManager::~EventManager()
{
}

void EventManager::OnEvent(SDL_Event* event)
{
    switch (event->type)
    {
    case SDL_KEYDOWN:
        OnKeyDown(event->key.keysym, event->key.keysym.mod, event->key.keysym.scancode);
        break;

    case SDL_KEYUP:
        OnKeyUp(event->key.keysym, event->key.keysym.mod, event->key.keysym.scancode);
        break;

    case SDL_MOUSEMOTION:
        OnMouseMove(event->motion.x, event->motion.y, event->motion.xrel, event->motion.yrel, 
                    (event->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0, 
                    (event->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0,
                    (event->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
        break;

    case SDL_MOUSEBUTTONDOWN:
        switch (event->button.button)
        {
        case SDL_BUTTON_LEFT:
            OnLButtonDown(event->button.x, event->button.y);
            break;

        case SDL_BUTTON_RIGHT:
            OnRButtonDown(event->button.x, event->button.y);
            break;

        case SDL_BUTTON_MIDDLE:
            OnMButtonDown(event->button.x, event->button.y);
            break;
        }
        break;

    case SDL_JOYAXISMOTION:
        OnJoyAxis(event->jaxis.which, event->jaxis.axis, event->jaxis.value);
        break;

    case SDL_JOYBALLMOTION:
        OnJoyBall(event->jball.which, event->jball.ball, event->jball.xrel, event->jball.yrel);
        break;

    case SDL_JOYHATMOTION:
        OnJoyHat(event->jhat.which, event->jhat.hat, event->jhat.value);
        break;

    case SDL_JOYBUTTONDOWN:
        OnJoyButtonDown(event->jbutton.which, event->jbutton.button);
        break;

    case SDL_JOYBUTTONUP:
        OnJoyButtonUp(event->jbutton.which, event->jbutton.button);
        break;

    case SDL_QUIT:
        OnExit();
        break;

    case SDL_SYSWMEVENT:
        break;

    case SDL_WINDOWEVENT_RESIZED:
        OnResize(event->window.data1, event->window.data2);
        break;

    case SDL_WINDOWEVENT_EXPOSED:
        OnExpose();
        break;

    default:
        OnUser(event->user.type, event->user.code, event->user.data1, event->user.data2);
    }
}

void EventManager::OnKeyDown(SDL_Keysym sym, Uint16 mod, SDL_Scancode scancode)
{
}

void EventManager::OnKeyUp(SDL_Keysym sym, Uint16 mod, SDL_Scancode scancode)
{
}

void EventManager::OnMouseMove(int32_t mX, int32_t mY, int32_t relX, int32_t relY, bool left, bool right, bool middle)
{
}

void EventManager::OnMouseWheel(bool up, bool down)
{
}

void EventManager::OnLButtonDown(int32_t mX, int32_t mY)
{
}

void EventManager::OnLButtonUp(int32_t mX, int32_t mY)
{
}

void EventManager::OnRButtonDown(int32_t mX, int32_t mY)
{
}

void EventManager::OnRButtonUp(int32_t mX, int32_t mY)
{
}

void EventManager::OnMButtonDown(int32_t mX, int32_t mY)
{
}

void EventManager::OnMButtonUp(int32_t mX, int32_t mY)
{
}

void EventManager::OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value)
{
}

void EventManager::OnJoyButtonDown(Uint8 which, Uint8 button)
{
}

void EventManager::OnJoyButtonUp(Uint8 which, Uint8 button)
{
}

void EventManager::OnJoyHat(Uint8 which, Uint8 hat, Uint8 value)
{
}

void EventManager::OnJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel)
{
}

void EventManager::OnMinimize()
{
}

void EventManager::OnRestore()
{
}

void EventManager::OnResize(int32_t w, int32_t h)
{
}

void EventManager::OnExpose()
{
}

void EventManager::OnExit()
{
}

void EventManager::OnUser(Uint8 type, int32_t code, void* data1, void* data2)
{
}
