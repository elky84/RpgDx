#pragma once

#include "Singleton.h"
#include "RMGame.h"

namespace RM
{

class GameManager : public light::Singleton<GameManager>
{
public:
    GameManager();
    ~GameManager();

    WEAK_GAME GetGame()
    {
        return m_Game;
    }

    void SetPlayer(const SHARED_PLAYER player);

    WEAK_PLAYER GetPlayer();

private:
    UNIQUE_GAME m_Game;

    SHARED_PLAYER m_Player;
};

} // namespace RM