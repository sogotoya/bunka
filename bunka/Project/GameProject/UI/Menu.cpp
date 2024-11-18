#include "Menu.h"
#include "Game/Game.h"
#include "Game/GameData.h"
Menu::Menu() :Base(eType_Scene)
{
	//ÉÅÉjÉÖÅ[îwåi
	m_menu = COPY_RESOURCE("Menu", CImage);
	m_menu.SetSize(1920, 1080);
	//òg
	m_sute1 = COPY_RESOURCE("Waku", CImage);
	m_sute1.SetSize(100, 100);
	m_sute1.SetCenter(50, 100);
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
		Base:KillAll();
		Base::Add(new Game());
	}
}

void Menu::Draw()
{
	m_menu.Draw();
	m_sute1.Draw();
	DrawRect();
}


