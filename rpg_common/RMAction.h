#pragma once

#include "RMTypeDefinition.h"

#include <vector>

namespace RM
{

class Action
{
public:
	Action();
	~Action();

	WEAK_CHARACTER GetCharacter() const
	{
		return m_Character;
	}

	void SetGame(WEAK_GAME game)
	{
		m_Game = game;
	}

	void Set(WEAK_CHARACTER character, WEAK_CHARACTER target);

	bool Update();

private:
	WEAK_GAME m_Game;

	WEAK_CHARACTER m_Character;

	WEAK_CHARACTER m_Target;
};

} // namespace RM