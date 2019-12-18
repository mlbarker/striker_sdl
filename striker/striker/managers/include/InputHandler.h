#ifndef _INPUTHANDLER_H
#define _INPUTHANDLER_H

#include <memory>
#include "ICommand.h"

class InputHandler
{
public:
    void Initialize();
    std::shared_ptr<ICommand> HandleInput();

private:
    // input
    std::shared_ptr<ICommand> m_leftMouseButton = nullptr;
    std::shared_ptr<ICommand> m_rightMouseButton = nullptr;
};

#endif
