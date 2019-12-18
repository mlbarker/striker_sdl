#ifndef _THROWCOMMAND_H
#define _THROWCOMMAND_H

#include "ICommand.h"

class ThrowCommand : public ICommand
{
public:
    void Execute(std::shared_ptr<GameActor> actor) override;
    bool IsNull() override;
};

#endif // _THROWCOMMAND_H
