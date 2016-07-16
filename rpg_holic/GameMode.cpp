#include "stdafx.h"
#include "GameMode.h"

#include "RMMap.h"
#include "RMCharacter.h"
#include "RMPlayer.h"
#include "RMParty.h"

#include "Input.h"

#include "TilePainter.h"

#include "GameManager.h"
#include <boost/bind.hpp>

#pragma comment(lib, "winmm.lib")

namespace RM
{

static const INT UNIT = 4;

GameMode::GameMode(light::weak_raw_ptr<light::view::DirectX> directX)
	: light::view::Mode(ModeID::GAME, directX)
	, light::view::Scroll(WINDOW_WIDTH, WINDOW_HEIGHT, UNIT, TILE_SIZE * 8)
{
}

GameMode::~GameMode()
{

}

void GameMode::Begin()
{
	m_Game = RM::GameManager::Instance()->GetGame();

	WEAK_PLAYER player = RM::GameManager::Instance()->GetPlayer();

	m_TilePainter.reset(new light::view::TilePainterScroll(m_x, m_y, light::RECT_INT(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT)));
	m_TilePainter->Load(m_direct_x, _T(".\\Map\\Test.map"));

	if(m_TilePainter->Width() * TILE_SIZE < MAX_SCROLL_X || 
		m_TilePainter->Height() * TILE_SIZE < MAX_SCROLL_Y )
	{
		ASSERT_MSG(0, "맵 설정 파일 크기 오류.");
	}

	SetLength(m_TilePainter->Width() * TILE_SIZE, m_TilePainter->Height() * TILE_SIZE);
	
	m_Character.reset(player->GetCharacter(0));
	m_Character->SetTilePainter(m_TilePainter.get());
	m_Character->SetUnit(UNIT);
	m_Character->Load();
	m_Character->SetPosition(light::POSITION_INT(TILE_SIZE * 2, TILE_SIZE * 2));
}

void GameMode::End()
{
}

void GameMode::Render()
{
	m_TilePainter->Render();

	std::wstringstream stream_scroll;
	stream_scroll << _T("ScrollX:") << m_x << _T(" ScrollY:") << m_y;
	DrawString(stream_scroll.str(), light::POSITION_INT(800, 20), 12);

	std::wstringstream stream_character;
	stream_character << _T("CharacterX:") << m_Character->GetPosition().X() << _T(" CharacterY:") << m_Character->GetPosition().Y();
	DrawString(stream_character.str(), light::POSITION_INT(800, 50), 12);

	light::POSITION_INT position((LONG)m_Character->GetPosition().X(), (LONG)m_Character->GetPosition().Y());
 	m_TilePainter->AdjustPosition(position);
	position -= light::POSITION_INT(0, 16); // 16은 캐릭터윗둥
	m_Character->Draw(position);
}

void GameMode::RenderPostUI()
{
	
}

void GameMode::Logic()
{
	if(light::Input::Keyboard::Pressing(VK_UP))
	{
		m_Character->SetDirection(Direction::UP);
	}
	else if(light::Input::Keyboard::Pressing(VK_DOWN))
	{
		m_Character->SetDirection(Direction::DOWN);
	}
	else if(light::Input::Keyboard::Pressing(VK_LEFT))
	{
		m_Character->SetDirection(Direction::LEFT);
	}
	else if(light::Input::Keyboard::Pressing(VK_RIGHT))
	{
		m_Character->SetDirection(Direction::RIGHT);
	}

	m_Character->Logic(); // SetDirection에서 애니메이션 루프 다시 돌리므로, 이게 위에 있어야함.
	Process(light::POSITION_INT((LONG)m_Character->GetPosition().X() - m_x, (LONG)m_Character->GetPosition().Y() - m_y));
}

} // namespace RM