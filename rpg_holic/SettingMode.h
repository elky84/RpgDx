#pragma once

#include "Mode.h"
#include "GuiButton.h"

namespace RM
{

class SettingMode : public light::view::Mode
{
public:
	SettingMode(light::weak_raw_ptr<light::view::DirectX> directX);

	virtual ~SettingMode();

	virtual void Begin();

	virtual void End();

	virtual void Render();

	virtual void RenderPostUI();

	virtual void Logic();

private:
	void RenderCharacter(WEAK_CHARACTER character, light::POSITION_INT& position);

	bool SetButton(const std::wstring& image, light::POSITION_INT position, const int n);

private:
	RM::SHARED_CHARACTER m_PickCharacter;

	std::vector<light::view::GuiButton> m_gui_buttons;

};

} // namespace RM