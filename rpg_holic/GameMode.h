#pragma once

#include "Mode.h"

#include <vector>

#include "RMGame.h"

#include "Animation2D.h"
#include "Sprite2D.h"
#include "GuiButton.h"
#include "GuiGroup.h"

#include "Scroll.h"

namespace light
{

namespace view
{

class TilePainter;
class DirectX;

} // namespace view

} // namespace light

namespace RM
{

class GameMode 
	: public light::view::Mode
	, public light::view::Scroll
{
public:
	GameMode(light::weak_raw_ptr<light::view::DirectX> directX);

	virtual ~GameMode();

	virtual void Begin();

	virtual void End();

	virtual void Render();

	virtual void RenderPostUI();

	virtual void Logic();

private:
	WEAK_GAME m_Game;

	light::view::Sprite2D m_Tile;

	light::view::GuiButton m_Buttons[3];

	WEAK_CHARACTER m_Character;

	std::unique_ptr<light::view::TilePainter> m_TilePainter;

	light::POSITION_INT m_Position;
};

} // namespace RM