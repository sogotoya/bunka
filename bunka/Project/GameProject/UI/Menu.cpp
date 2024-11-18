#include "Menu.h"
#include "Game/Game.h"
#include "Game/GameData.h"
Menu::Menu() :Base(eType_Scene)
{
	//メニュー背景
	m_menu = COPY_RESOURCE("Menu", CImage);
	m_menu.SetSize(1920, 1080);
	//1枠
	m_sute1 = COPY_RESOURCE("Waku", CImage);
	m_sute1.SetSize(100, 100);
	m_sute1.SetCenter(50, 100);
	m_pos = CVector2D(600, 600);
	m_sute1.SetPos(600, 600);
	m_rect = CRect(-50, -100, 50, 0);

	
}


void Menu::Update()
{
	/*switch (PUSH(CInput::eMouseL))
	{
		case m_sute1:
			GameData::s_score=1;
			break;
		//case :
	}*/
	if(PUSH(CInput::eMouseL))
	{
		//マウスの座標
		CVector2D p = CInput::GetMousePoint();
		//マウスとメニューの枠との判定
		CRect rect2 = CRect(
			m_pos.x + m_rect.m_left,
			m_pos.y + m_rect.m_top,
			m_pos.x + m_rect.m_right,
			m_pos.y + m_rect.m_bottom);

		//矩形同士の判定
		if (p.x <= rect2.m_right && p.x >= rect2.m_left &&
			p.y <= rect2.m_bottom && p.y >= rect2.m_top)
			{
				//
				Base:KillAll();
				Base::Add(new Game());
			};
	
	}
}

void Menu::Draw()
{
	m_menu.Draw();
	m_sute1.Draw();
	DrawRect();
}







/*Menu::Botan::Botan() :Base(eType_Scene)
{
	m_aikon = COPY_RESOURCE("Maru", CImage);
	m_aikon.SetSize(100, 100);
	m_aikon.SetCenter(50, 100);
	m_pos = CVector2D(700, 700);
	m_aikon.SetPos(700, 700);
	m_rect = CRect(-50, -100, 50, 0);
	m_aikon.Draw();
}*/


