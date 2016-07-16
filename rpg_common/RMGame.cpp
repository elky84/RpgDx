#include "stdafx.h"
#include "RMGame.h"

#include "RMParty.h"
#include "RMMap.h"

#include "RMTurn.h"
#include "RMCharacter.h"
#include "RMAction.h"

namespace RM
{

Game::Game()
    : m_Turn(new Turn)
{
	m_Turn->SetGame(this);
}

Game::~Game()
{

}

void Game::on_update()
{
	m_Turn->DecideTurn();
	m_Turn->ActionTurn();
}

void Game::Add(const WEAK_PARTY squad)
{
	m_vector_Party->push_back(squad);
}

} // namespace RM