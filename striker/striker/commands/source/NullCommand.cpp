#include "NullCommand.h"

void NullCommand::Execute(std::shared_ptr<GameActor> actor)
{

}

bool NullCommand::IsNull()
{
    return false;
}