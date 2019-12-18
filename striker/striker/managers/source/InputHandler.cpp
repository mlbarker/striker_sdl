#include "InputHandler.h"
#include "WhackCommand.h"
#include "ThrowCommand.h"

void InputHandler::Initialize()
{
    // need to make these buttons null commands until
    // they are bound by through the bind methods
    m_leftMouseButton = std::make_shared<WhackCommand>();
    m_rightMouseButton = std::make_shared<ThrowCommand>();
}

std::shared_ptr<ICommand> InputHandler::HandleInput()
{
    return nullptr;
}