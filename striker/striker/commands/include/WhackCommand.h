#ifndef _WHACKCOMMAND_H
#define _WHACKCOMMAND_H

#include "ICommand.h"

class WhackCommand : public ICommand
{
public:
    void Execute(std::shared_ptr<GameActor> actor) override;
    bool IsNull() override;
};

#endif // _WHACKCOMMAND_H
