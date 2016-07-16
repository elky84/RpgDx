#pragma once

#include "RMTypeDefinition.h"
#include <vector>

namespace RM
{

class Map
{
public:
	static const int WIDTH = 1920;
	static const int HEIGHT = 640;

public:
	Map();
	~Map();

public:
	void SetParty(const WEAK_VECTOR_PARTY vectorParty)
	{
		m_vector_Party = vectorParty;
	}

private:
	WEAK_VECTOR_PARTY m_vector_Party;
};

} // namespace RM