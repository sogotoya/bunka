#pragma once
#include "Base/Base.h"

class Menu :public Base
{
	//ƒƒjƒ…[˜gŠÖ˜A
	class Waku :public Base
	{
	private:
		CImage m_sute;
		int m_stagen;
	public:
		
		Waku(char* imgname,CVector2D pos, int stagen);
		void Update();
		void Draw();
	};

private:
	CImage m_menu;
	Waku *m_waku[4];

public:
	Menu();
	void Update();
	void Draw();
};