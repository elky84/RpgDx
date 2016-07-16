#include "stdafx.h"
#include "RMAction.h"

#include "RMCharacter.h"
#include "RMMap.h"

#include "RMGame.h"

namespace RM
{

Action::Action()
{

}

Action::~Action()
{

}

void Action::Set(WEAK_CHARACTER character, WEAK_CHARACTER target)
{
	m_Character = character;
	m_Target = target;
}

bool Action::Update()
{
	return false;
}

} // namespace RM