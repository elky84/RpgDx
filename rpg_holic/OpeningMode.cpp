#include "stdafx.h"
#include "OpeningMode.h"
#include "WindowUtil.h"

#include "Rectangle.h"
#include "GameManager.h"
#include "Input.h"

const WCHAR* szStory[] = { 
	{L"��� �ڵ鿡�� �� ������ ȥ�� �� ��ü������, �� � �ڵ鿡�� �� ��ü�� ȥ���̴�."},
	{L"���� �����ϰ� �����ϴ� �ڵ��� �ִ°��ϸ�, � ����鿡�� ���� �����Ѵ�."},
	{L"��� �������� ��ʳ��� �������� �õ���, ��� ������ �� �������� ���Ͽ� ū ������ �̷��Ѵ�."},
	{L""},
	{L"�� �̾߱�� �� ���뱹�� �⳪�� �������� ���� ������������ �� ���ÿ��� ���۵ȴ�."},
	{L""},
	{L"���ִ� ������ ��� û���� ����, �ҳ����� ��ټ��� ¡���ǰ�,"},
	{L"�� ���� ���� ���ΰ� ���� ���̵���� ¡���϶�� ������ ��ɿ� ���� ���ϵ��� �����Ѵ�."},
	{L""},
	{L"�̷��� ���ӵ� ���￡�� ���ƿ� �ڵ��� �ұ��� �ǰų�, ���� �������� �ô޸��� �ڵ� ��."},
	{L""},
	{L"�� ���� ���� �������̵� ���� ¡���Ѵٸ� �� ���� ���� �ų� �ٸ� ���� �ȴ�."},
	{L""},
	{L"�׷� ��Ȳ���� ���� ���� �Ӹ��� ���� �ǰ�..."},
	{L""},
	{L"������ ���Ҵٴ� ȸ������ ¡���� �ź��Ѵ�."},
	{L""},
	{L"�㳪 �� �������� �� ������ �������, �ݿ��˷� ������ ���ִ� ����ڷ� ���ι޾� ������ ������ �ް� �ǰ�..."},
	{L""},
	{L"�ᱹ �ҳ� ������ �����밡 �¼� �ο�����, ������ ������ ���� �տ� �й��Ѵ�."},
	{L""},
	{L"���� �� ��Ÿ���� ���� ����, ��Ƴ��� �ڵ��� ������ �޲ٰ� �Ǵµ�..."},
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
	DrawString(_T("����Ű�� ������ ĳ���� ����â���� �Ѿ�ϴ�."), light::POSITION_INT(580, 720), TEXT_SIZE, rgb);
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
			++m_StoryLine; // �� ������ �ٷ� �ǳ� �ٰ�~
		}

		lasttick = curtick;
	}
}

} // namespace RM