#pragma once

#include "EnvironmentManager.h"
#include "Direct2D.h"

#include <memory>

namespace RM
{

class GameManager;

} // namespace RM

class Main : public light::EnvironmentManager
{
public:
	Main(const std::wstring& strProgramName, const std::wstring& strArg);
	~Main();

private:
	virtual bool initialize();
	virtual void on_update();
	virtual void release();

private:
	std::unique_ptr<RM::GameManager> m_GameManager;

	light::view::Direct2D m_direct_x;
};
