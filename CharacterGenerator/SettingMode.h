#pragma once

#include "Mode.h"
#include "GuiButton.h"

namespace ExcelData
{

class TendencyTest;

} // namespace ExcelData

namespace Instance
{

class Tendency;

} // namespace Instance

namespace RM
{

class SettingMode : public light::view::Mode
{
public:
	SettingMode(light::weak_raw_ptr<light::view::DirectX> directX);

	virtual ~SettingMode();

private:
	virtual void Begin();

	virtual void End();

	virtual void Render();

	virtual void RenderPostUI();

	virtual void Logic();

private:
	void RenderCharacter(WEAK_CHARACTER character, light::POSITION_INT& position);

	bool SetButton(const std::wstring& image, light::POSITION_INT position, const int n);

private:
	void ResetTendencyTest();

	void TendencyTest();

	void CharacterList();

	bool Answer(const light::view::Gui* pGuiButton);

	int AnswerNo(const light::view::Gui* pGuiButton);

private:
	std::unique_ptr< ExcelData::TendencyTest > m_TendencyTest;

private:
  	light::view::GuiButton m_Answer[4];

	std::vector<light::view::GuiButton> m_gui_buttons;

	std::vector<ExcelData::TendencyTest> m_vectorTendencyTest;

	std::unique_ptr< Instance::Tendency > m_Tendency;

};

} // namespace RM