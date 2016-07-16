#include "stdafx.h"
#include "OpeningMode.h"
#include "WindowUtil.h"

#include "Rectangle.h"
#include "GameManager.h"
#include "Input.h"

const WCHAR* szStory[] = { 
	{L"어떠한 자들에겐 이 세상이 혼돈 그 자체겠지만, 또 어떤 자들에겐 삶 자체가 혼돈이다."},
	{L"신을 숭배하고 의지하는 자들이 있는가하면, 어떤 사람들에겐 신을 원망한다."},
	{L"어떠한 국가들은 몇십년의 전쟁으로 시들어가고, 어떠한 국가는 그 전쟁으로 인하여 큰 성장을 이룩한다."},
	{L""},
	{L"이 이야기는 두 강대국의 기나긴 전쟁으로 인해 피폐해져가는 한 도시에서 시작된다."},
	{L""},
	{L"성주는 마을의 장년 청년은 물론, 소년들까지 대다수가 징병되고,"},
	{L"얼마 남지 않은 노인과 꼬마 아이들까지 징병하라는 본국의 명령에 급히 신하들을 소집한다."},
	{L""},
	{L"이렇게 지속된 전쟁에서 돌아온 자들은 불구가 되거나, 전쟁 후유증에 시달리는 자들 뿐."},
	{L""},
	{L"얼마 남지 않은 꼬마아이들 까지 징병한다면 이 성도 죽은 거나 다름 없게 된다."},
	{L""},
	{L"그런 상황까진 막기 위해 머리를 쓰게 되고..."},
	{L""},
	{L"역병이 돌았다는 회신으로 징병을 거부한다."},
	{L""},
	{L"허나 이 과정에서 한 신하의 배신으로, 반역죄로 몰리고 성주는 배반자로 오인받아 본국의 공격을 받게 되고..."},
	{L""},
	{L"결국 소년 병사들과 근위대가 맞서 싸우지만, 본국의 강력한 군대 앞에 패배한다."},
	{L""},
	{L"패전 후 불타버린 성을 보며, 살아남은 자들은 복수를 꿈꾸게 되는데..."},
};

namespace RM
{

OpeningMode::OpeningMode(light::weak_raw_ptr<light::view::DirectX> directX)
	: light::view::Mode(ModeID::OPENING, directX)
	, m_StoryLine(0)
{

}

OpeningMode::~OpeningMode()
{

}

void OpeningMode::Begin()
{
}

void OpeningMode::End()
{
}

void OpeningMode::Render()
{
	

	static const int TEXT_SIZE = 20;

	light::POSITION_INT position(0, TEXT_SIZE);
	for(int i = 0; i < m_StoryLine; ++i)
	{
		DrawString(szStory[i], position, TEXT_SIZE);
		position.Y( position.Y() + TEXT_SIZE + TEXT_SIZE / 2);
	}

	static BYTE alpha = 255;
	DWORD rgb = D3DCOLOR_RGBA(0, 0, 0, alpha);
	DrawString(_T("엔터키를 누르면 캐릭터 선택창으로 넘어갑니다."), light::POSITION_INT(580, 720), TEXT_SIZE, rgb);
	alpha -= 5;
	alpha %= 255;
}

void OpeningMode::RenderPostUI()
{
	
}

void OpeningMode::Logic()
{
	
	WEAK_GAME Game = RM::GameManager::Instance()->GetGame();
	RM::WEAK_PLAYER Player = RM::GameManager::Instance()->GetPlayer();

	if( light::Input::Keyboard::Pressing(VK_RETURN) )
	{
		ChangeMode(ModeID::SETTING);
	}

	DWORD curtick = GetTickCount();
	static DWORD lasttick = curtick;
	if ( 1000 <= curtick - lasttick)
	{
		++m_StoryLine;
		if( _countof(szStory) <= m_StoryLine )
		{
			m_StoryLine = _countof(szStory);
			return;
		}

		if( _tcslen(szStory[m_StoryLine]) <= 0)
		{
			++m_StoryLine; // 빈 문장은 바로 건너 뛰게~
		}

		lasttick = curtick;
	}
}

} // namespace RM