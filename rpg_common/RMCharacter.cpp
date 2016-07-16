#include "stdafx.h"
#include "RMCharacter.h"

#include "MetaData.h"

#include "RMParty.h"

#include "TilePainter.h"

namespace RM
{

Character::Character(light::weak_raw_ptr<light::view::DirectX> directX, const CHARACTER_INDEX index)
	: m_direct_x(directX)
	, m_Index(index)
	, m_Direction(Direction::DOWN)
	, m_Unit(0)
	, m_Move(0)
    , m_Tribe(new ExcelData::Tribe)
{

}

Character::~Character()
{
}

void Character::SetTribe(ExcelData::Tribe& _tribe)
{
	*m_Tribe = _tribe;
}

void Character::Load()
{
 	m_Animation.Load(m_direct_x, _T(".\\Character\\Template.ani"), m_Image);
	m_Animation.Stop();
}

void Character::Draw(light::POSITION_INT Pos)
{
	m_Animation.Position(Pos);
	m_Animation.Draw(m_Direction);
}

void Character::Logic()
{
	if( m_Move <= 0 )
	{
		return;
	}

	--m_Move;

	m_Animation.Update();

	light::POSITION_INT Temp = m_Position;

	switch( m_Direction )
	{
	case Direction::LEFT:
		m_Position.X(std::max(m_Position.X() - m_Unit, 0));
		break;
	case Direction::RIGHT:
		m_Position.X(std::min(m_Position.X() + m_Unit, MAX_SCROLL_X - TILE_SIZE));
		break;
	case Direction::UP:
		m_Position.Y(std::max(m_Position.Y() - m_Unit, 0));
		break;
	case Direction::DOWN:
		m_Position.Y(std::min(m_Position.Y() + m_Unit, MAX_SCROLL_Y - TILE_SIZE));
		break;
	}

	INT X_Surplus = m_Position.X() % TILE_SIZE;
	INT Y_Surplus = m_Position.Y() % TILE_SIZE;

	INT X = m_Position.X() / TILE_SIZE;
	INT Y = m_Position.Y() / TILE_SIZE;

	const light::view::TileProperty& property = m_TilePainter->Property(X, Y);
	if(property.Type != 0)
	{
		m_Position = Temp;
	}

	if(X_Surplus != 0)
	{
		const light::view::TileProperty& property = m_TilePainter->Property(X + 1, Y);
		if(property.Type != 0)
		{
			m_Position = Temp;
		}
	}
		
	if(Y_Surplus != 0)
	{
		const light::view::TileProperty& property = m_TilePainter->Property(X, Y + 1);
		if(property.Type != 0)
		{
			m_Position = Temp;
		}		
	}

	if(X_Surplus != 0 &&
		Y_Surplus != 0)
	{
		const light::view::TileProperty& property = m_TilePainter->Property(X + 1, Y + 1);
		if(property.Type != 0)
		{
			m_Position = Temp;
		}
	}
}

void Character::SetDirection(Direction::Type direction)
{
	INT X_Surplus = m_Position.X() % TILE_SIZE;
	INT Y_Surplus = m_Position.Y() % TILE_SIZE;
	switch( m_Direction )
	{
	case Direction::LEFT:
	case Direction::RIGHT:
		m_Move = TILE_SIZE / m_Unit - X_Surplus / m_Unit;
		break;
	case Direction::UP:
	case Direction::DOWN:
		m_Move = TILE_SIZE / m_Unit - Y_Surplus / m_Unit;;
		break;
	}

	m_Animation.Play();
	if( m_Direction != direction || m_Animation.NowPlaying() == false)
	{
		m_Animation.reset();
	}

	m_Direction = direction;
}


} // namespace RM