#include "stdafx.h"
#include "RMPlayer.h"

#include "MetaData.h"
#include "RMCharacter.h"
#include "RMParty.h"

#include <algorithm>

namespace RM
{

Player::Player()
    : m_Party(new Party)
{

}

Player::~Player()
{

}

void Player::AddCharacter(const SHARED_CHARACTER& character)
{
	m_vector_Character.push_back(character);
}

} // namespace RM