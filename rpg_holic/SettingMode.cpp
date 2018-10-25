#include "stdafx.h"
#include "SettingMode.h"
#include "WindowUtil.h"

#include "Rectangle.h"
#include "GameManager.h"
#include "Input.h"

#include "RMCharacter.h"
#include "RMCharacterFactory.h"
#include "RMGame.h"
#include "RMPlayer.h"
#include "RMMap.h"
#include "RMParty.h"

static const int PHOTO_FRAME_WIDTH = 38;
static const int PHOTO_FRAME_HEIGHT = 52;

namespace RM
{

SettingMode::SettingMode(light::weak_raw_ptr<light::view::DirectX> directX)
	: light::view::Mode(ModeID::SETTING, directX)
{

}

SettingMode::~SettingMode()
{

}

void SettingMode::Begin()
{
	m_gui_buttons.resize(MAX_DECK + 1);
}

void SettingMode::End()
{
}

void SettingMode::RenderCharacter(WEAK_CHARACTER character, light::POSITION_INT& position)
{
	DWORD color = D3DCOLOR_RGBA(0, 0, 0, 255);

	std::wstringstream strstream;
	strstream << _T("Class: ")
		<< character->GetClass().Name() 
		<< _T(" Tribe: ") 
		<< character->GetTribe()->Name()
		<< _T(" Hp:") << character->GetClass().Hp()
		<< _T(" Agi:") << character->GetClass().Agi()
		<< _T(" Luck:") << character->GetClass().Luck()
		<< _T(" Str:") << character->GetClass().Str()
		<< _T(" Phy:") << character->GetClass().Phy()
		<< _T(" Int:") << character->GetClass().Int()
		<< _T(" Wis:") << character->GetClass().Wis()
		<< _T(" Speed:") << character->GetClass().Speed();

	DrawString(strstream.str(), position, 20, color);

	position.Y(position.Y() + PHOTO_FRAME_HEIGHT);
}

bool SettingMode::SetButton(const std::wstring& image, light::POSITION_INT position, const int n)
{
	if( false == m_gui_buttons[n].Create(m_direct_x, std::wstring(_T(".\\Character\\Template.spr")), image, NULL, position) )
	{
		return false;
	}

	m_gui_buttons[n].Set();
	return true;
}

void SettingMode::Render()
{
	DrawString(_T("캐릭터를 고르세요. (카드 뽑기 : Space Bar)"), light::POSITION_INT(0, 0), 32);

	DrawString(_T("뽑은 캐릭터는 아래와 같습니다. 이 캐릭터를 선택하시려면 Enter 키를 눌러주세요."), light::POSITION_INT(0, 40), 20);

	light::POSITION_INT position(PHOTO_FRAME_WIDTH, GAME_UI_TOP + 20);
	if(m_PickCharacter.get())
	{
		RenderCharacter(m_PickCharacter, position);
	}

	DrawString(_T("선택된 캐릭터 목록"), light::POSITION_INT(0, GAME_UI_TOP + 20 + PHOTO_FRAME_HEIGHT), 20);
	position.Y(GAME_UI_TOP + PHOTO_FRAME_HEIGHT + 20 + PHOTO_FRAME_HEIGHT);

	WEAK_GAME Game = RM::GameManager::Instance()->GetGame();
	RM::WEAK_PLAYER Player = RM::GameManager::Instance()->GetPlayer();
	for each( RM::WEAK_CHARACTER character in Player->VectorCharacter() )
	{
		RenderCharacter(character, position);
	}
}

void SettingMode::RenderPostUI()
{
	
}

void SettingMode::Logic()
{
	
	WEAK_GAME Game = RM::GameManager::Instance()->GetGame();
	RM::WEAK_PLAYER Player = RM::GameManager::Instance()->GetPlayer();

	if( light::Input::Keyboard::Pressing(VK_SPACE) )
	{
  		m_PickCharacter = RM::CharacterFactory::Pick(m_direct_x);
		light::POSITION_INT position(GAME_UI_LEFT, GAME_UI_TOP);

		auto& mapImage = light::excel::Loader::Instance()->find<ExcelData::ImageData>()->Map();
		m_PickCharacter->Image(mapImage[rand() % mapImage.size() + 1].Name());

		SetButton(m_PickCharacter->Image(), position, 0);
	}

	if(m_PickCharacter.get())
	{
		if( light::Input::Keyboard::Pressing(VK_RETURN) )
		{
			light::POSITION_INT position(GAME_UI_LEFT, 60 + GAME_UI_TOP + PHOTO_FRAME_HEIGHT * (Player->VectorCharacter().size() + 1));
			SetButton(m_PickCharacter->Image(), position, Player->VectorCharacter().size() + 1);
			Player->AddCharacter(m_PickCharacter);

			m_gui_buttons[0].Release();
			m_PickCharacter.reset();
		}
	}

	if(MAX_DECK <= Player->VectorCharacter().size())
	{
		ChangeMode(ModeID::GAME);
		return;
	}
}

} // namespace RM
