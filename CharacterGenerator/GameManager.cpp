#include "stdafx.h"
#include "GameManager.h"

#include "RMMap.h"
#include "RMPlayer.h"

namespace RM
{

GameManager::GameManager()
    : m_Game(new Game)
    , m_Player(new Player)
{

}

GameManager::~GameManager()
{

}

void GameManager::SetPlayer(const SHARED_PLAYER player)
{
    m_Player = player;
}

WEAK_PLAYER GameManager::GetPlayer()
{
    return m_Player;
}

} // namespace RM