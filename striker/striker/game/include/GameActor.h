#ifndef _GAMEACTOR_H
#define _GAMEACTOR_H

class GameActor
{
public:
    GameActor();
    virtual ~GameActor();

private:
    int32_t velocity = 0;
    int32_t m_x = 0;
    int32_t m_y = 0;
};

#endif
