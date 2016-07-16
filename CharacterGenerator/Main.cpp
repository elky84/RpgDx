#include "stdafx.h"
#include "Main.h"

#include "SettingMode.h"

#include "ExcelLoader.h"

#include "GameManager.h"
#include "RMMap.h"
#include "RMPlayer.h"

Main::Main(const std::wstring& strProgramName, const std::wstring& strArg)
	: light::EnvironmentManager(strProgramName, strArg)
{
}

Main::~Main()
{
}

bool Main::initialize()
{
	if( FALSE == m_direct_x.Init(get_program_name(), light::view::DEFAULT_FPS, TRUE) )
	{
		LOG_ERROR(_T("%s DirectX Init Failed."), __FUNCTIONW__);
		return false;
	}

    if (FALSE == m_direct_x.LoadFont(_T("Arita-medium.ttf")))
    {
		LOG_ERROR(_T("DirectX::LoadFont() Failed"));
		return false;
	}

	if( false == light::excel::Loader::Instance()->Load() )
	{
        LOG_ERROR(L"light::excel::Loader::Instance()->Load() failed");
        return false;
	}

	new RM::GameManager;

	m_direct_x.RegisterMode(new RM::SettingMode(&m_direct_x));

	m_direct_x.ActiveMode(RM::ModeID::SETTING);

	LOG_INFO(_T("%s Start %s Success"), __FUNCTIONW__, get_program_name());
	on_complete();
	return true;
}

void Main::on_update()
{
	m_direct_x.on_update();
}

void Main::release()
{
	LOG_INFO(_T("%s %s"), __FUNCTIONW__, get_program_name());
	if(RM::GameManager::Instance())
	{
		delete RM::GameManager::Instance();
	}
}
