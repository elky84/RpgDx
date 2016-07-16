#pragma once

#include "RMTypeDefinition.h"

#include <vector>

namespace RM
{

class Game
{
public:
	static const int MAX_TEAM = 2;

public:
	Game();
	~Game();

public:
	WEAK_MAP GetMap()
	{
		return m_Map;
	}

	void on_update();

	void Add(const WEAK_PARTY squad);

	VECTOR_PARTY& VectorParty()
	{
		return *m_vector_Party.get();
	}

private:
	UNIQUE_TURN m_Turn;

	UNIQUE_MAP m_Map;

	UNIQUE_VECTOR_PARTY m_vector_Party;
};

} // namespace RM