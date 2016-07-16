#pragma once

#include "RMTypeDefinition.h"

#include <vector>

namespace RM
{

class Turn
{
public:
	Turn();
	~Turn();

	void DecideTurn();
	void ActionTurn();

	void SetGame(WEAK_GAME game);

private:
	WEAK_GAME m_Game;

	std::vector<WEAK_CHARACTER> m_vector_Character;

	std::vector<SHARED_ACTION> m_vector_Action;
};

} // namespace RM