#pragma once

#include "RMTypeDefinition.h"

#include <map>

namespace RM
{

class Party
{
public:
	typedef std::map<CHARACTER_INDEX, WEAK_CHARACTER> MAP_CHARACTER;

public:
	Party();
	~Party();

	void AddCharacter(const WEAK_CHARACTER& character);

	bool isExist(const WEAK_CHARACTER& character);

	bool isAllDie();

	void Die(WEAK_CHARACTER character);

	MAP_CHARACTER& MapCharacter()
	{
		return m_map_Character;
	}

	MAP_CHARACTER& MapAliveCharacter()
	{
		return m_map_AliveCharacter;
	}

public:
	WEAK_CHARACTER Rand_Alive(INT variable, INT variable_detail);

	WEAK_CHARACTER High(INT variable, INT variable_detail);
	WEAK_CHARACTER Low(INT variable, INT variable_detail);
	WEAK_CHARACTER MoreThan(INT variable, INT variable_detail);
	WEAK_CHARACTER LessThan(INT variable, INT variable_detail);
	WEAK_CHARACTER Similar(INT variable, INT variable_detail);
	WEAK_CHARACTER Same(INT variable, INT variable_detail);

private:
	MAP_CHARACTER m_map_Character;

	MAP_CHARACTER m_map_AliveCharacter;
};

} // namespace RM