#ifndef _NULLCOMMAND_H
#define _NULLCOMMAND_H

#include "ICommand.h"

class NullCommand : public ICommand
{
public:
    void Execute(std::shared_ptr<GameActor> actor) override;
    bool IsNull() override;
};

#endif // _NULLCOMMAND_H
