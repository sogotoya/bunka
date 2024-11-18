#pragma once
#include "Base/Base.h"

class Menu :public Base
{
private:
	CImage m_menu;
	CImage m_sute1;
	

public:
	Menu();
	void Update();
	void Draw();
};