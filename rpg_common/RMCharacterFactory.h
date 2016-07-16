#pragma once

#include "RMTypeDefinition.h"


namespace light
{

namespace view
{

class DirectX;

} // namespace view

} // namespace light

namespace RM
{

class CharacterFactory
{
public:
	static SHARED_CHARACTER Pick(light::weak_raw_ptr<light::view::DirectX> directX);

public:
	static CHARACTER_INDEX m_Index;
};

} // namespace RM