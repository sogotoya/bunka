#include "Menu.h"
#include "Game/Game.h"
/*Menu::Menu() :Base(eType_Scene)
{
	//ƒƒjƒ…[”wŒi
	m_menu = COPY_RESOURCE("Menu", CImage);
	m_menu.SetSize(1920, 1080);
	//˜g
	m_waku = COPY_RESOURCE("Waku", CImage);
	m_waku.SetPos(56, 316);
	//CImage Menu::m_waku;
	//int men
	char* name[]{
		"menyu1",
		"menyu2",
		"menyu3",
		"menyu4",
		"menyu5",
		"menyu6",
		"menyu7",
		"menyu8",
		"menyu9",
		"menyu10",
	};
	for (int i = 0; i < 10; i++)
	{
		m_box[i] = COPY_RESOURCE(name[i], CImage);
		m_box[i].SetSize(256 / 2, 256 / 2);
		m_box[i].SetPos(312 + 300 * (i % 5), 332 + 256 * (i / 5));
		m_box[i].SetRect(0, 0, 128, 128);
	}
}

void Menu::Update()
{
	if (PUSH(CInput::eRight))
	{
		stagenumbar += 1;
		if (stagenumbar == 10)
		{
			stagenumbar = 9;
		}
	}

	if (PUSH(CInput::eLeft))
	{
		stagenumbar -= 1;
		if (stagenumbar < 0)
		{
			stagenumbar = 0;
		}
	}

	if (PUSH(CInput::eDown))
	{
		stagenumbar += 5;
		if (stagenumbar == 10)
		{

		}
	}
	if (PUSH(CInput::eUp))
	{
		stagenumbar -= 5;
		if (stagenumbar < 0)
		{
			stagenumbar += 5;
		}
	}
	if (m_cnt++ > 60 && PUSH(CInput::eButton5))
	{
		Base::KillAll();
		Stagenumber::stagenumber = stagenumbar;
		Base::Add(new Game());
	}
}

void Menu::Draw()
{
	m_menu.Draw();
	for (int i = 0; i < 10; i++) 
	{
		{
			m_box[i].Draw();
		}
	}
	m_waku.SetPos(m_box[stagenumbar].m_pos);
	m_waku.Draw();
	DrawRect();
}*/
