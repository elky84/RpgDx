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

#include <boost/bind.hpp>

static const int PHOTO_FRAME_WIDTH = 38;
static const int PHOTO_FRAME_HEIGHT = 52;

namespace RM
{

SettingMode::SettingMode(light::weak_raw_ptr<light::view::DirectX> directX)
	: light::view::Mode(ModeID::SETTING, directX)
{
	m_Answer[0].Create(m_direct_x, _T("TendencyTest\\Answer.spr"), boost::bind(&SettingMode::Answer, this, &m_Answer[0]), light::POSITION_INT(100, 200));
	m_Answer[1].Create(m_direct_x, _T("TendencyTest\\Answer.spr"), boost::bind(&SettingMode::Answer, this, &m_Answer[1]), light::POSITION_INT(100, 260));
	m_Answer[2].Create(m_direct_x, _T("TendencyTest\\Answer.spr"), boost::bind(&SettingMode::Answer, this, &m_Answer[2]), light::POSITION_INT(100, 320));
	m_Answer[3].Create(m_direct_x, _T("TendencyTest\\Answer.spr"), boost::bind(&SettingMode::Answer, this, &m_Answer[3]), light::POSITION_INT(100, 380));
}

SettingMode::~SettingMode()
{

}

void SettingMode::Begin()
{
	m_gui_buttons.resize(MAX_DECK + 1);
	auto& mapTendencyTest = light::excel::Loader::Instance()->find<ExcelData::TendencyTestData>()->Map();

	for each(auto val in mapTendencyTest)
	{
		m_vectorTendencyTest.push_back(val.second);
	}

	m_Tendency.reset(new Instance::Tendency());

	ResetTendencyTest();
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
	if( false == m_gui_buttons[n].Create(m_direct_x, std::wstring(_T(".\\Image\\Template.spr")), image, NULL, position) )
	{
		return false;
	}

	m_gui_buttons[n].Set();
	return true;
}


int SettingMode::AnswerNo(const light::view::Gui* pGuiButton)
{
	for(int n = 0; n < _countof(m_Answer); ++n)
	{
		if( &m_Answer[n] == pGuiButton)
		{
			return n;
		}
	}
	return -1;
}

bool SettingMode::Answer(const light::view::Gui* pGuiButton)
{
	UNREFERENCED_PARAMETER(pGuiButton);
	int n = AnswerNo(pGuiButton);
	if( n ==  -1 )
		return false;
	
	switch(m_TendencyTest->VectorTendencyType()[n])
	{
	case Enum::TendencyType::Aggressive:
		m_Tendency->Aggressive(m_Tendency->Aggressive() + m_TendencyTest->VectorTendencyValue()[n]);
		break;
	case Enum::TendencyType::Initiative:
		m_Tendency->Initiative(m_Tendency->Initiative() + m_TendencyTest->VectorTendencyValue()[n]);
		break;
	case Enum::TendencyType::Thoughtful:
		m_Tendency->Thoughtful(m_Tendency->Thoughtful() + m_TendencyTest->VectorTendencyValue()[n]);
		break;
	case Enum::TendencyType::Godliness:
		m_Tendency->Godliness(m_Tendency->Godliness() + m_TendencyTest->VectorTendencyValue()[n]);
		break;
	case Enum::TendencyType::Talent:
		m_Tendency->Talent(m_Tendency->Talent() + m_TendencyTest->VectorTendencyValue()[n]);
		break;
	case Enum::TendencyType::Ambition:
		m_Tendency->Ambition(m_Tendency->Ambition() + m_TendencyTest->VectorTendencyValue()[n]);
		break;
	}

	ResetTendencyTest();
	return true;
}

void SettingMode::ResetTendencyTest()
{
	m_TendencyTest.reset();

	if(m_vectorTendencyTest.empty())
	{
		for(int n = 0; n < _countof(m_Answer); ++n)
			m_Answer[n].Hide();

		//WEAK_GAME Game = RM::GameManager::Instance()->GetGame();
		RM::WEAK_PLAYER Player = RM::GameManager::Instance()->GetPlayer();
		while( Player->VectorCharacter().size() < MAX_DECK )
		{
			RM::SHARED_CHARACTER PickCharacter = RM::CharacterFactory::Pick(m_direct_x);
			auto& mapImage = light::excel::Loader::Instance()->find<ExcelData::ImageData>()->Map();
			PickCharacter->Image(mapImage[rand() % mapImage.size() + 1].Name());

			light::POSITION_INT position(GAME_UI_LEFT, 60 + GAME_UI_TOP + PHOTO_FRAME_HEIGHT * (Player->VectorCharacter().size() + 1));
			SetButton(PickCharacter->Image(), position, Player->VectorCharacter().size() + 1);
			Player->AddCharacter(PickCharacter);

			m_gui_buttons[0].Release();
			PickCharacter.reset();
		}

		return;
	}

	ExcelData::TendencyTest* pTendencyTest = new ExcelData::TendencyTest();

	int rand_value = rand() % m_vectorTendencyTest.size();

	*pTendencyTest = m_vectorTendencyTest[rand_value];
	m_TendencyTest.reset(pTendencyTest);

	m_vectorTendencyTest.erase(m_vectorTendencyTest.begin() + rand_value);

	for(int n = 0; n < _countof(m_Answer); ++n)
	{
		m_Answer[n].Message(m_TendencyTest->VectorAnswer()[n], 24);
	}
}

void SettingMode::TendencyTest()
{
	if(m_TendencyTest.get() == NULL)
		return;

	light::POSITION_INT position(30, 20);
	DrawString(m_TendencyTest->Question(), position, light::RECT_INT(30, 0, 950, 200), 28);
	position.Y(position.Y() + 60);
}

void SettingMode::CharacterList()
{
	light::POSITION_INT position(PHOTO_FRAME_WIDTH, GAME_UI_TOP + PHOTO_FRAME_HEIGHT + 20 + PHOTO_FRAME_HEIGHT);
	DrawString(_T("선택된 캐릭터 목록"), light::POSITION_INT(0, GAME_UI_TOP + 20 + PHOTO_FRAME_HEIGHT), 20);

	RM::WEAK_PLAYER Player = RM::GameManager::Instance()->GetPlayer();
	for each( RM::WEAK_CHARACTER character in Player->VectorCharacter() )
	{
		RenderCharacter(character, position);
	}
}

void SettingMode::Render()
{
	RM::WEAK_PLAYER Player = RM::GameManager::Instance()->GetPlayer();
	if( false == Player->VectorCharacter().empty() )
	{
		TendencyTest();
	}
	else
	{
		CharacterList();
	}
}

void SettingMode::RenderPostUI()
{
	
}

void SettingMode::Logic()
{
}

} // namespace RM
