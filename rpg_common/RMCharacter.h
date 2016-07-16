#pragma once

#include "RMTypeDefinition.h"
#include <vector>
#include "MetaData.h"

#include "Instance/Class.h"
#include "Animation2D.h"

namespace light
{

namespace view
{

class TilePainter;

} // namespace view

} // namespace light

namespace RM
{

struct Direction
{
	enum Type
	{
		NONE = -1,
		DOWN = 0,
		LEFT,
		RIGHT,
		UP,
	};
};

class Character
{
public:
	Character(light::weak_raw_ptr<light::view::DirectX> directX, const CHARACTER_INDEX index);
	~Character();

	void SetUnit(const INT Unit)
	{
		m_Unit = Unit;
	}

	void SetPosition(const light::POSITION_INT& position)
	{
		m_Position = position;
	}

	void SetTilePainter(light::weak_raw_ptr<light::view::TilePainter> tilePainter)
	{
		m_TilePainter.reset(tilePainter);
	}

	light::POSITION_INT& GetPosition()
	{
		return m_Position;
	}

	INT X() const
	{
		return m_Position.X();
	}

	INT Y() const
	{
		return m_Position.Y();
	}

	void Load();

	void SetParty(WEAK_PARTY squad)
	{
		m_Party = squad;
	}

	void SetTribe(ExcelData::Tribe& _tribe);

	ExcelData::WEAK_TRIBE GetTribe() const
	{
		return m_Tribe;
	}

	Instance::Class& GetClass()
	{
		return m_Class;
	}

	void Render();

	CHARACTER_INDEX GetIndex() const
	{
		return m_Index;
	}

	void Image(const std::wstring& image)
	{
		m_Image = image;
	}

	const std::wstring& Image()
	{
		return m_Image;
	}

	void Draw(light::POSITION_INT Pos);

	void SetDirection(Direction::Type direction);

	void Logic();

private:
	INT m_Unit;

	DWORD m_Move;

	Instance::Class m_Class;

	CHARACTER_INDEX m_Index;

	light::POSITION_INT m_Position;

	ExcelData::UNIQUE_TRIBE m_Tribe;

	WEAK_PARTY m_Party;

	std::wstring m_Image;

	light::view::Animation2D m_Animation;

	light::weak_raw_ptr<light::view::DirectX> m_direct_x;

	Direction::Type m_Direction;

	light::weak_raw_ptr<light::view::TilePainter> m_TilePainter;
};

} // namespace RM