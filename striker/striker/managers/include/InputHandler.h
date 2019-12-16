#ifndef _INPUTHANDLER_H
#define _INPUTHANDLER_H

#include <memory>

class InputHandler
{
public:
    std::shared_ptr<ICommand> HandleInput();
};

#endif
