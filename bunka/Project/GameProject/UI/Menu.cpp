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
	//���j���[�w�i
	m_menu = COPY_RESOURCE("Menu", CImage);
	
	m_menu.SetSize(1920, 1080);
	//���j���[�摜����
	//char name[�z��][������]
	char name[5][32] = { "stagewaku1", "map2", "map3", "map4", "map5",};
	for (int i = 0; i < 5; i++)
	{
		Base::Add(m_waku[i] = new Waku(name[i], CVector2D(180 + 390 * i, 600), i + 1));
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
	//���X�e�[�W�I��
	m_stagen = stagen;
	m_sute= COPY_RESOURCE(imgname, CImage);
	m_sute.SetSize(280, 180);
	m_sute.SetCenter(140, 180);
	m_rect = CRect(-140, -180, 140, 0);
}

void Menu::Waku::Update()
{
	//�}�E�X�����j���[���N���b�N�����Ƃ��̔���
	if (PUSH(CInput::eMouseL))
	{
		//�}�E�X�̍��W
		CVector2D p = CInput::GetMousePoint();
		//�}�E�X�ƃ��j���[�̘g�Ƃ̔���
		CRect rect2 = CRect(
			m_pos.x + m_rect.m_left,
			m_pos.y + m_rect.m_top,
			m_pos.x + m_rect.m_right,
			m_pos.y + m_rect.m_bottom);

		//��`���m�̔���
		if (p.x <= rect2.m_right && p.x >= rect2.m_left &&
			p.y <= rect2.m_bottom && p.y >= rect2.m_top)
		{
			GameData::s_score = m_stagen;
			KillAll();
			Base::Add(new Game());
			
		};

	}
}

void Menu::Waku::Draw()
{
	m_sute.SetPos(m_pos);
	m_sute.Draw();
}
