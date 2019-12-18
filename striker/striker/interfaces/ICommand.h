#ifndef _ICOMMAND_H
#define _ICOMMAND_H

#include <memory>
#include "GameActor.h"

class ICommand
{
public:
    virtual ~ICommand() {}
    virtual void Execute(std::shared_ptr<GameActor> actor) = 0;
    virtual bool IsNull() = 0;
};

#endif
