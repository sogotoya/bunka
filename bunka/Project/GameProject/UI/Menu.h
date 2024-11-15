#pragma once
#include "Base/Base.h"

class Menu :public Base 
{
private:
	CImage m_menu;
	CImage m_waku;

public:
	Menu(const CVector2D& pos);
	void Update();
	void Draw();
};