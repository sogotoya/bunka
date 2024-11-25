#include "Menu.h"
#include "Game/Game.h"
#include "Game/GameData.h"
#include "Game/Map.h"
#include "Game/Player.h"
#include"Game/count.h"
#include "Game/Field.h"
#include "Game/BlockManager.h"
#include "Game/Block.h"
Menu::Menu() :Base(eType_Menu)
{
	//メニュー背景
	m_menu = COPY_RESOURCE("Menu", CImage);
	
	m_menu.SetSize(1920, 1080);
	//メニュー画像生成
	for (int i = 1; i < 5; i++)
	{
		//Base::Add(m_waku[i] = new Waku("Maru", CVector2D(200 * i, 400), i + 1));
		Base::Add(m_waku[i] = new Waku("Maru", CVector2D(200*i, 400),i));
		Base::Add(m_waku[1] = new Waku("stagewaku1", CVector2D(200, 400), 1));
	}
}


void Menu::Update()
{
	
}

void Menu::Draw()
{
	m_menu.Draw();
	
}

Menu::Waku::Waku(char* imgname, CVector2D pos,int stagen):Base(eType_Waku)
{
	m_pos = pos;
	//何ステージ選択
	m_stagen = stagen;
	m_sute= COPY_RESOURCE(imgname, CImage);
	m_sute.SetSize(100, 100);
	m_sute.SetCenter(50, 100);
	m_rect = CRect(-50, -100, 50, 0);
}

void Menu::Waku::Update()
{
	//マウスがメニューをクリックしたときの判定
	if (PUSH(CInput::eMouseL))
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
			GameData::s_score = m_stagen;
			Base::Add(new Game());
			
			//SelectKill(eType_Menu);
			SelectKill(eType_Waku);
		};

	}
}

void Menu::Waku::Draw()
{
	m_sute.SetPos(m_pos);
	m_sute.Draw();
}
