#pragma once
#include "Base/Base.h"

class Menu :public Base
{
	class Botan :public Base 
	{
	private:
		 static CImage m_aikon;
	public:
		Botan();
	};

private:
	CImage m_menu;
	CImage m_sute1;
	

public:
	Menu();
	void Update();
	void Draw();
};