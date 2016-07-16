#include "stdafx.h"
#include "RMTurn.h"

#include "RMCharacter.h"
#include "RMAction.h"

#include "RMParty.h"

#include "RMMap.h"

#include "RMGame.h"

namespace RM
{

Turn::Turn()
{

}

Turn::~Turn()
{

}

void Turn::SetGame(WEAK_GAME game)
{
	m_Game = game;
}

void Turn::DecideTurn()
{
	VECTOR_PARTY& vectorParty = m_Game->VectorParty();
	for each( WEAK_PARTY squad in vectorParty )
	{
		for each( const Party::MAP_CHARACTER::value_type val in squad->MapCharacter() )
		{
			WEAK_CHARACTER character = val.second;

			Action* action = new Action();
			action->SetGame(m_Game);
			m_vector_Action.push_back(SHARED_ACTION(action));
		}
	}
}

void Turn::ActionTurn()
{
	for each(WEAK_ACTION action in m_vector_Action)
	{
		action->Update();
	}

	m_vector_Action.clear();
}

} // namespace RM