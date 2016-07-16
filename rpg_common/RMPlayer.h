#pragma once

#include "RMTypeDefinition.h"
#include <vector>

namespace RM
{

class Player
{
public:
	typedef std::vector<SHARED_CHARACTER> VECTOR_CHARACTER;

public:
	Player();
	~Player();

	void AddCharacter(const SHARED_CHARACTER& character);

	WEAK_PARTY GetParty()
	{
		return m_Party;
	}

	VECTOR_CHARACTER& VectorCharacter()
	{
		return m_vector_Character;
	}

	WEAK_CHARACTER GetCharacter(int index)
	{
		return m_vector_Character[index];
	}

public:

	void Name(const std::wstring& str)
	{
		m_Name = str;
	}

	const std::wstring& Name() const
	{
		return m_Name;
	}

private:
	std::wstring m_Name;

	UNIQUE_PARTY m_Party;

	VECTOR_CHARACTER m_vector_Character;
};

} // namespace RM