#include "stdafx.h"
#include "RMParty.h"

#include "RMCharacter.h"

namespace RM
{

Party::Party()
{

}

Party::~Party()
{

}

void Party::AddCharacter(const WEAK_CHARACTER& character)
{
	character->SetParty(this);
	m_map_Character.insert(MAP_CHARACTER::value_type(character->GetIndex(), character));
	m_map_AliveCharacter.insert(MAP_CHARACTER::value_type(character->GetIndex(), character));
}

bool Party::isExist(const WEAK_CHARACTER& character)
{
	return m_map_Character.find(character->GetIndex()) != m_map_Character.end();
}

void Party::Die(WEAK_CHARACTER character)
{
	m_map_AliveCharacter.erase(character->GetIndex());
}

bool Party::isAllDie()
{
	return m_map_AliveCharacter.empty();
}

WEAK_CHARACTER Party::Rand_Alive(INT variable, INT variable_detail)
{
	MAP_CHARACTER::iterator it = m_map_AliveCharacter.begin();
	for(size_t i = 0; i < rand() % m_map_AliveCharacter.size(); ++i)
	{
		++it;
	}
	return it->second;
}

WEAK_CHARACTER Party::High(INT variable, INT variable_detail)
{
	MAP_CHARACTER::iterator it = m_map_AliveCharacter.begin();
	for(size_t i = 0; i < rand() % m_map_AliveCharacter.size(); ++i)
	{
		++it;
	}
	return it->second;
}

WEAK_CHARACTER Party::Low(INT variable, INT variable_detail)
{
	MAP_CHARACTER::iterator it = m_map_AliveCharacter.begin();
	for(size_t i = 0; i < rand() % m_map_AliveCharacter.size(); ++i)
	{
		++it;
	}
	return it->second;
}

WEAK_CHARACTER Party::MoreThan(INT variable, INT variable_detail)
{
	MAP_CHARACTER::iterator it = m_map_AliveCharacter.begin();
	for(size_t i = 0; i < rand() % m_map_AliveCharacter.size(); ++i)
	{
		++it;
	}
	return it->second;
}

WEAK_CHARACTER Party::LessThan(INT variable, INT variable_detail)
{
	MAP_CHARACTER::iterator it = m_map_AliveCharacter.begin();
	for(size_t i = 0; i < rand() % m_map_AliveCharacter.size(); ++i)
	{
		++it;
	}
	return it->second;
}


WEAK_CHARACTER Party::Similar(INT variable, INT variable_detail)
{
	MAP_CHARACTER::iterator it = m_map_AliveCharacter.begin();
	for(size_t i = 0; i < rand() % m_map_AliveCharacter.size(); ++i)
	{
		++it;
	}
	return it->second;
}

WEAK_CHARACTER Party::Same(INT variable, INT variable_detail)
{
	MAP_CHARACTER::iterator it = m_map_AliveCharacter.begin();
	for(size_t i = 0; i < rand() % m_map_AliveCharacter.size(); ++i)
	{
		++it;
	}
	return it->second;
}

} // namespace RM