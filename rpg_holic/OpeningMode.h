#pragma once

#include "Mode.h"

namespace RM
{

class OpeningMode : public light::view::Mode
{
public:
	OpeningMode(light::weak_raw_ptr<light::view::DirectX> directX);

	virtual ~OpeningMode();

	virtual void Begin();

	virtual void End();

	virtual void Render();

	virtual void RenderPostUI();

	virtual void Logic();

private:
	int m_StoryLine;
};

} // namespace RM